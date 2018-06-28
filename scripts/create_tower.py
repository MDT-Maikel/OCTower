#! /usr/bin/env python

import os
import sys
import shutil
import fnmatch
import re
import argparse
import subprocess


#############
# functions #
#############

# copies a room from room_dir to tower_dir
def copy_room(room_dir, tower_dir):
	# get room name
	room_name = room_dir.split(".")[0][4:]
	print("copying room %s ..." % room_name)

	# check against double room names
	if room_name in room_names:
		print("ERROR: room name (%s) already used." % room_name)
		print("WARNING: room %s will not be included." % room_name)

	# copy room object
	room_obj_dir = os.path.join(tower_dir, "Room%s.ocd" % room_name)
	for object_dir in os.listdir(room_dir):
		if fnmatch.fnmatch(object_dir, "Room*.ocd"):
			shutil.copytree(os.path.join(room_dir, object_dir), room_obj_dir)

	# copy room map and stored objects
	sect_dir = os.path.join(tower_dir, "Sect%s.ocg" % room_name)
	os.makedirs(sect_dir)
	for sect_file in os.listdir(room_dir):
		# copy scenario settings
		if fnmatch.fnmatch(sect_file, "Scenario.txt"):
			shutil.copy(os.path.join(room_dir, sect_file), sect_dir)
			# modify scenario.txt to only have the needed settings
			with open(os.path.join(sect_dir, sect_file), "r") as f:
				lines = f.readlines()
			with open(os.path.join(sect_dir, sect_file), "w") as f:
				for line in lines:
					if not re.match("Icon=*", line) and not re.match("Title=*", line) and not re.match("Version=*", line) and not re.match("Origin=*", line):
						f.write(line)
		# copy scenario map, objects and string tables
		if fnmatch.fnmatch(sect_file, "Map*.bmp") or fnmatch.fnmatch(sect_file, "Objects.c") or fnmatch.fnmatch(sect_file, "StringTbl*.txt"):
			shutil.copy(os.path.join(room_dir, sect_file), sect_dir)
		# append map script to room control script object.
		if fnmatch.fnmatch(sect_file, "Map.c"):
			with open(os.path.join(room_dir, sect_file), "r") as map_file:
				with open(os.path.join(tower_dir, "Room%s.ocd" % room_name, "Script.c"), "a") as script_file:
					for line in map_file.readlines():
						if not re.match("#include *", line):
							script_file.write(line)

	# check the newly created room, remove if the checks were not satisfied
	if not check_room(room_name, tower_dir):
		shutil.rmtree(room_obj_dir)
		shutil.rmtree(sect_dir)
	# add to list of room names
	else:
		room_names.append(room_name)

	return


# checks the basics of a room returns if the room is ok
def check_room(room_name, tower_dir):
	# to store whether room is ok
	room_ok = True
	# open room control object defcore
	with open(os.path.join(tower_dir, "Room%s.ocd" % room_name, "DefCore.txt"), "r") as f:
		lines = f.readlines()
		# check room object id
		for line in lines:
			if re.match("id=*", line) and not re.match("id=Room%s" % room_name, line):
				print("ERROR: Room control object DefCore.txt has wrong id, found %s, expected id=Room%s." % (line.replace("\n", ""), room_name))
				room_ok = False

	# open room control object script
	with open(os.path.join(tower_dir, "Room%s.ocd" % room_name, "Script.c"), "r") as f:
		lines = f.readlines()
		for line in lines:
			# check room section
			if re.match("public func GetRoomSection()*", line) and not re.search(room_name, line):
				print('ERROR: Room control object Script.c has wrong section, found %s, expected public func GetRoomSection() { return "%s"; }.' % (line.replace("\n", ""), room_name))
				print("WARNING: room %s will not be included." % room_name)
				room_ok = False
			# room id (either double, excluded or explicitly included)
			if re.match("public func GetRoomID()*", line):
				room_id = re.search("\"[a-zA-Z]+\"", line).group(0).replace("\"", "")
				if room_id in room_ids:
					print("ERROR: Room control object Script.c has duplicate ID, found %s, expected public func GetRoomID() { return \"??\"; }." % line.replace("\n", ""))
					print("WARNING: room %s will not be included." % room_name)
					room_ok = False
				elif isinstance(args.exclude, list) and room_id in args.exclude:
					print("EXCLUDE: Room with id = %s will be excluded as requested." % room_name)
					room_ok = False
				elif isinstance(args.include, list) and not room_id in args.include:
					print("INCLUDE: Room with id = %s is not on the inclusion list and will be excluded as requested." % room_name)
					room_ok = False
			# difficulty
			if re.match("public func GetRoomDifficulty()*", line):
				room_diff = re.search("return [0-9]+;", line).group(0).replace(";", "")[7:]
				if room_diff in room_diffs:
					print("ERROR: Room control object Script.c has duplicate difficulty, found %s, expected public func GetRoomDifficulty() { return \"?\"; }." % line.replace("\n", ""))
					print("WARNING: room %s will not be included." % room_name)
					room_ok = False
			# room author(s)
			if re.match("public func GetRoomAuthor()*", line):
				room_author = re.search("return \"[^\"]+\";", line).group(0).replace(";", "").replace("\"", "")[7:]

	# store some room properties
	if room_ok:
		room_ids.append(room_id)
		room_diffs.append(room_diff)
		room_authors.append(room_author)

	# print(room settings)
	if args.verbose and room_ok:
		print("room properties: id = %s, difficulty = %s" % (room_id, room_diff))

	# return whether the room is ok
	return room_ok


###############
# main script #
###############

# argument parser
parser = argparse.ArgumentParser(description='Create the tower scenario from the repository version.')
parser.add_argument('-p', '--pack', action='store_true', help='create a packed scenario folder if c4group is available')
parser.add_argument('-v', '--verbose', action='store_true', help='print more information')
parser.add_argument('-e', '--exclude', nargs='+', help='exclude rooms based on their id, get by using verbose option')
parser.add_argument('-i', '--include', nargs='+', help='include rooms based on their id, get by using verbose option, only included rooms will now be in the room')
parser.add_argument('-t', '--template', action='store_true', help='create room template')
args = parser.parse_args()

# check for conflicting arguments
if isinstance(args.exclude, list) and isinstance(args.include, list):
	print("ERROR: both room inclusion (-i/--include) and exclusion (-e/--exclude) list specified, only one allowed simultaneously.")
	sys.exit(0)

# store room names, id's and difficulties
room_names = []
room_ids = []
room_diffs = []
room_authors = []

# create tower directory based on version name
if not os.path.isfile("Version.txt"):
	print("ERROR: Version.txt file not found, be sure to run the script from the tower path.")
	sys.exit(0)
with open("Version.txt", "r") as content_file:
	version = content_file.read()
tower_dir = os.path.join("..", "OCTowerV%s.ocs" % version)
## TODO: query replacing existing directory
if os.path.isfile(tower_dir):
	os.remove(tower_dir)
elif os.path.exists(tower_dir):
	shutil.rmtree(tower_dir)
os.makedirs(tower_dir)

# log which version is created
print("creating tower scenario version " + version)
print("===========================================")

# copy main scenario files into the new directory
print("copying main scenario ...")
shutil.copy("Version.txt", tower_dir)
shutil.copy("Authors.txt", tower_dir)
shutil.copy("Title.txt", tower_dir)
shutil.copy("DescUS.txt", tower_dir)
shutil.copy("DescDE.txt", tower_dir)
shutil.copy("Scenario.txt", tower_dir)
shutil.copy("Teams.txt", tower_dir)
shutil.copy("Script.c", tower_dir)
shutil.copy("Objects.c", tower_dir)
shutil.copy("StringTblUS.txt", tower_dir)
shutil.copy("StringTblDE.txt", tower_dir)
shutil.copy("MapBg.bmp", tower_dir)
shutil.copy("MapFg.bmp", tower_dir)
shutil.copy("Map.c", tower_dir)
shutil.copy("Icon.png", tower_dir)
shutil.copy("Title.jpg", tower_dir)
shutil.copy("Loader1.png", tower_dir)

# copy sound files into the new directory
print("copying sound files ...")
shutil.copytree("Sound.ocg", os.path.join(tower_dir, "Sound.ocg"))

# copy material files into the new directory
print("copying material files ...")
shutil.copytree("Material.ocg", os.path.join(tower_dir, "Material.ocg"))

# copy tower objects into the new directory
print("copying tower objects ...")
shutil.copytree("TowerObjects.ocd", os.path.join(tower_dir, "TowerObjects.ocd"))

# copy empty scenario section into the new directory
print("copying empty scenario section ...")
shutil.copytree("SectEmpty.ocg", os.path.join(tower_dir, "SectEmpty.ocg"))

# loop over all rooms and copy sections and room object
print("===========================================")
for room_dir in os.listdir("."):
	if fnmatch.fnmatch(room_dir, "Room*.ocs") and not fnmatch.fnmatch(room_dir, "RoomTemplate.ocs"):
		copy_room(room_dir, tower_dir)

# copy stringtables of rooms into scenario one (temporary fix)
strtbl_us = open(os.path.join(tower_dir, "StringTblUS.txt"), "a")
strtbl_de = open(os.path.join(tower_dir, "StringTblDE.txt"), "a")
for sect_dir in os.listdir(tower_dir):
	if fnmatch.fnmatch(sect_dir, "Sect*.ocg"):
		if os.path.isfile(os.path.join(tower_dir, sect_dir, "StringTblUS.txt")):
			f = open(os.path.join(tower_dir, sect_dir, "StringTblUS.txt"), "r")
			strtbl_us.write("\n" + f.read())
		if os.path.isfile(os.path.join(tower_dir, sect_dir, "StringTblDE.txt")):
			f = open(os.path.join(tower_dir, sect_dir, "StringTblDE.txt"), "r")
			strtbl_de.write("\n" + f.read())
strtbl_us.close()
strtbl_de.close()

# pack the scenario folder if required
if args.pack:
	print("===========================================")
	print("packing scenario folder ...")
	try:
		subprocess.call(["c4group", tower_dir, "-p"])
	except OSError as e:
		print("ERROR: failed to run c4group.")

# create template room
if args.template:
	print("===========================================")
	print("create room template ...")
	template_dir = os.path.join("..", "Template.ocg")
	if not os.path.isdir(template_dir):
		os.makedirs(template_dir)
	if os.path.isdir(os.path.join(template_dir, "RoomTemplate.ocs")):
		shutil.rmtree(os.path.join(template_dir, "RoomTemplate.ocs"))
	shutil.copytree(os.path.join("Template.ocg", "RoomTemplate.ocs"), os.path.join(template_dir, "RoomTemplate.ocs"))
	shutil.copytree(os.path.join("RoomTemplate.ocs", "RoomTemplate.ocd"), os.path.join(template_dir, "RoomTemplate.ocs", "RoomTemplate.ocd"))

# if verbose option create the list of rooms sorted according to difficulty
if args.verbose:
	print("===========================================")
	print("list of rooms ...")
	print("===========================================")
	print("---------------------------------------------------------------------------------")
	print("|  #  | Diff | Room name                | ID | Author(s)                        |")
	print("---------------------------------------------------------------------------------")
	# create a list of rooms
	rooms = []
	for index in range(0, len(room_names)):
		rooms.append([room_diffs[index], room_names[index], room_ids[index], str(room_authors[index])])
	rooms.sort(key = lambda r: int(r[0]))
	leftpad = lambda val, length, max_length=100: "%s%s" % (" " * (length - len(val[:max_length])), val[:max_length])
	for index in range(0, len(rooms)):
		room = rooms[index]
		num = str(index + 1)
		print("| %s | %s | %s | %s | %s |" % (
			leftpad(num, 3,),
			leftpad(room[0], 4),
			leftpad(room[1], 24),
			room[2],
			leftpad(room[3], 32, 32)
		))
	print("---------------------------------------------------------------------------------")

# finished
print("===========================================")
print("finished")


