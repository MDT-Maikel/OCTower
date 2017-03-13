#! /usr/bin/env python

import os
import shutil
import fnmatch
import re
import numpy
import argparse
import subprocess

import Image as img


#############
# functions #
#############

def get_room_nr(room_dir):
	room_name = room_dir.split(".")[0]
	with open(room_dir + "/" + room_name + ".ocd/Script.c", "r") as f:
		lines = f.readlines()
		for line in lines:
			if re.match("public func GetRoomDifficulty()*", line):
				room_nr = re.search("return [0-9]+;", line).group(0).replace(";", "")[7:]
	return int(room_nr)

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

tower_img_width = 80
tower_img_border = 4
tower_image_scale = 2
tower_img_width *= tower_image_scale

# load all map images
fg_images = []
bg_images = []
for room_dir in os.listdir("."):
	if fnmatch.fnmatch(room_dir, "Room*.ocs") and not fnmatch.fnmatch(room_dir, "RoomTemplate.ocs"):
		if os.path.isfile(room_dir + "/MapFg.bmp"):
			fg_images.append((img.open(room_dir + "/MapFg.bmp"), get_room_nr(room_dir)))
		if os.path.isfile(room_dir + "/MapBg.bmp"):
			bg_images.append((img.open(room_dir + "/MapBg.bmp"), get_room_nr(room_dir)))

# sort images according to room number
fg_images = sorted(fg_images, key = lambda x: x[1], reverse=True)
fg_images = [x[0] for x in fg_images]
bg_images = sorted(bg_images, key = lambda x: x[1], reverse=True)
bg_images = [x[0] for x in bg_images]

# combine foreground and background and insert sky
fg_images = [black_to_transparent(x) for x in fg_images]
bg_images = [black_to_sky(x) for x in bg_images]
cb_images = []
for fg, bg in zip(fg_images, bg_images):
	cb = bg
	cb.paste(fg, (0, 0), fg)
	cb_images.append(cb)

# determine tower image dimensions
tower_img_height = tower_img_border * tower_image_scale
for cb_im in cb_images:
	tower_img_height += (cb_im.size[1] + tower_img_border) * tower_image_scale
tower_image = img.new("RGBA", (tower_img_width + 2 * tower_img_border * tower_image_scale, tower_img_height), "gray")

# place all the images
cnt = 0
height = 0
for cb_im in cb_images:
	size = [x * tower_image_scale for x in cb_im.size]
	tower_image.paste(cb_im.resize(size), (tower_img_border * tower_image_scale, tower_img_border * tower_image_scale + height))
	height += (cb_im.size[1] + tower_img_border) * tower_image_scale

# load base and top image
base_image = img.open("tower_base.png")
new_size = [x * tower_image_scale for x in base_image.size]
base_image = base_image.resize(new_size)
top_image = img.open("tower_top.png")
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
tot_image.save("tower_image.png")

