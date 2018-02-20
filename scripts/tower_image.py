#! /usr/bin/env python

import os
import shutil
import fnmatch
import re
import numpy
import argparse
import subprocess

from PIL import Image as img
from PIL import ImageFont as font
from PIL import ImageDraw as draw


#############
# functions #
#############

def get_room_nr(room_dir):
	room_name = room_dir.split("/")[-1]
	room_name = room_name.split(".")[0]
	with open(room_dir + "/" + room_name + ".ocd/Script.c", "r") as f:
		lines = f.readlines()
		for line in lines:
			if re.match("public func GetRoomDifficulty()*", line):
				room_nr = re.search("return [0-9]+;", line).group(0).replace(";", "")[7:]
	return int(room_nr)

def get_room_authors(room_dir):
	room_name = room_dir.split("/")[-1]
	room_name = room_name.split(".")[0]
	with open(room_dir + "/" + room_name + ".ocd/Script.c", "r") as f:
		lines = f.readlines()
		for line in lines:
			if re.match("public func GetRoomAuthor()*", line):
				room_authors = re.search("return \"[0-9A-Za-z\,\&\s]+\";", line).group(0)
				room_authors = room_authors.replace(";", "").replace("\"", "")[7:]
	return room_authors		
		
def black_to_sky(im):
	im = im.convert("RGBA")
	data = numpy.array(im)
	red, green, blue, alpha = data.T
	black_areas = (red == 0) & (blue == 0) & (green == 0)
	data[..., :-1][black_areas.T] = (165, 189, 215)
	return img.fromarray(data)

def black_to_transparent(im):
	im = im.convert("RGBA")
	data = numpy.array(im)
	red, green, blue, alpha = data.T
	black_areas = (red == 0) & (blue == 0) & (green == 0) & (alpha == 255)
	data[...][black_areas.T] = (0, 0, 0, 0)
	return img.fromarray(data)


###############
# main script #
###############

# get the different directories
script_dir = os.getcwd()
tower_dir = os.path.dirname(os.getcwd())
planet_dir = os.path.dirname(os.path.dirname(os.getcwd()))

tower_img_width = 80
tower_img_border = 4
tower_image_scale = 4
tower_img_width *= tower_image_scale

# load all map images
fg_images = []
bg_images = []
room_authors = []
for room_dir in os.listdir(tower_dir):
	room_dir = tower_dir + "/" + room_dir
	if fnmatch.fnmatch(room_dir, "*Room*.ocs") and not fnmatch.fnmatch(room_dir, "*RoomTemplate.ocs"):
		if os.path.isfile(room_dir + "/MapFg.bmp") and os.path.isfile(room_dir + "/MapBg.bmp"):
			fg_images.append((img.open(room_dir + "/MapFg.bmp"), get_room_nr(room_dir)))
			bg_images.append((img.open(room_dir + "/MapBg.bmp"), get_room_nr(room_dir)))
			room_authors.append((get_room_authors(room_dir), get_room_nr(room_dir)))
			print "included " + room_dir
		elif not os.path.isfile(room_dir + "/MapFg.bmp") and not os.path.isfile(room_dir + "/MapBg.bmp") and os.path.isfile(room_dir + "/Map.c"):
			try:
				os.chdir(planet_dir)				
				subprocess.call(["./ocmapgen", room_dir + "/Map.c", room_dir + "/MapFgTemp.png", "--root", planet_dir, "--width", "80"])
				subprocess.call(["./ocmapgen", room_dir + "/Map.c", room_dir + "/MapBgTemp.png", "--bg", "--root", planet_dir, "--width", "80"])
				fg_images.append((img.open(room_dir + "/MapFgTemp.png"), get_room_nr(room_dir)))
				bg_images.append((img.open(room_dir + "/MapBgTemp.png"), get_room_nr(room_dir)))
				os.remove(room_dir + "/MapFgTemp.png")
				os.remove(room_dir + "/MapBgTemp.png")
				room_authors.append((get_room_authors(room_dir), get_room_nr(room_dir)))
				print "included " + room_dir
			except OSError as e:
				print "excluded " + room_dir + " (failed to run ocmapgen)"
				print "ERROR: " + str(e)
		else:
			print "excluded " + tower_dir + room_dir + " (no map found)"

# sort images according to room number
fg_images = sorted(fg_images, key = lambda x: x[1], reverse=True)
fg_images = [x[0] for x in fg_images]
bg_images = sorted(bg_images, key = lambda x: x[1], reverse=True)
bg_images = [x[0] for x in bg_images]
room_authors = sorted(room_authors, key = lambda x: x[1], reverse=True)
room_authors = [x[0] for x in room_authors]

# combine foreground and background and insert sky
fg_images = [black_to_transparent(x) for x in fg_images]
bg_images = [black_to_sky(x) for x in bg_images]
cb_images = []
for fg, bg in zip(fg_images, bg_images):
	cb = bg
	cb.paste(fg, (0, 0), fg)
	cb_images.append(cb)

# determine tower image dimensions
cb_images_resized = []
tower_img_height = tower_img_border * tower_image_scale
for cb_im in cb_images:
	size = list(cb_im.size)
	size[1] = tower_img_width * size[1] / size[0]
	size[0] = tower_img_width
	cb_images_resized.append(cb_im.resize(size))
	tower_img_height += size[1] + tower_img_border * tower_image_scale
tower_image = img.new("RGBA", (tower_img_width + 2 * tower_img_border * tower_image_scale, tower_img_height), "gray")

# add authors to each room image
for cb_im, authors in zip(cb_images_resized, room_authors):
	cb_draw = draw.Draw(cb_im)
	cb_draw.text((1, 0), "Authors: " + authors, (125, 20, 20))
	
# place all the images
cnt = 0
height = 0
for cb_im in cb_images_resized:
	tower_image.paste(cb_im, (tower_img_border * tower_image_scale, tower_img_border * tower_image_scale + height))
	height += cb_im.size[1] + tower_img_border * tower_image_scale

# load base and top image
base_image = img.open(script_dir + "/tower_base.png")
new_size = [x * tower_image_scale for x in base_image.size]
base_image = base_image.resize(new_size)
top_image = img.open(script_dir + "/tower_top.png")
new_size = [x * tower_image_scale for x in top_image.size]
top_image = top_image.resize(new_size)

# combine entrance and tower
mount_point = 60
mount_point *= tower_image_scale
tot_image_wdt = mount_point + tower_image.size[0]
tot_image_hgt = base_image.size[1] + top_image.size[1] + tower_image.size[1]
tot_image = img.new("RGBA", (tot_image_wdt, tot_image_hgt), "black")
tot_image = black_to_sky(tot_image)
tot_image.paste(tower_image, (mount_point, top_image.size[1]))
tot_image.paste(base_image, (0, tot_image.size[1] - base_image.size[1]))
tot_image.paste(top_image, (0, 0))

# save the image
tot_image.save(script_dir + "/tower_image.png")

