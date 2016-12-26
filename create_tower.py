#! /usr/bin/env python

import os
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
	print "copying room " + room_name + " ..."
	
	# check against double room names
	if room_name in room_names:
		print "ERROR: room name (" + room_name + ") already used."
		print "WARNING: room " + room_name + " will not be included."

	# copy room object
	room_obj_dir = tower_dir + "/Room" + room_name + ".ocd"
	for object_dir in os.listdir(room_dir):
		if fnmatch.fnmatch(object_dir, "Room*.ocd"):
			shutil.copytree(room_dir + "/" + object_dir, room_obj_dir)

	# copy room map and stored objects
	sect_dir = tower_dir + "/Sect" + room_name + ".ocg"
	os.makedirs(sect_dir)
	for sect_file in os.listdir(room_dir):
		# copy scenario settings
		if fnmatch.fnmatch(sect_file, "Scenario.txt"):
			shutil.copy(room_dir + "/" + sect_file, sect_dir)
			# modify scenario.txt to only have the needed settings
			with open(sect_dir + "/" + sect_file, "r") as f:
				lines = f.readlines()
			with open(sect_dir + "/" + sect_file, "w") as f:
				for line in lines:
					if not re.match("Icon=*", line) and not re.match("Title=*", line) and not re.match("Version=*", line) and not re.match("Origin=*", line):
						f.write(line)
		# copy scenario map, objects and string tables
		if fnmatch.fnmatch(sect_file, "Map*.bmp") or fnmatch.fnmatch(sect_file, "Objects.c") or fnmatch.fnmatch(sect_file, "StringTbl*.txt"):
			shutil.copy(room_dir + "/" + sect_file, sect_dir)
		# append map script to room control script object.
		if fnmatch.fnmatch(sect_file, "Map.c"):
			with open(room_dir + "/" + sect_file, "r") as map_file:
				with open(tower_dir + "/Room" + room_name + ".ocd/Script.c", "a") as script_file:
					for line in map_file.readlines():
						if not re.match("#include *", line):
							script_file.write(line)	

	# check the newly created room, remove if the checks were not satisfied
	if not check_room(room_name, tower_dir):
		shutil.rmtree(room_obj_dir)
		shutil.rmtree(sect_dir)
		print "WARNING: room " + room_name + " will not be included."
	# add to list of room names
	else:
		room_names.append(room_name)


# checks the basics of a room returns if the room is ok
def check_room(room_name, tower_dir):
	# to store whether room is ok
	room_ok = True
	# open room control object defcore
	with open(tower_dir + "/Room" + room_name + ".ocd/DefCore.txt", "r") as f:
		lines = f.readlines()
		# check room object id
		for line in lines:
			if re.match("id=*", line) and not re.match("id=Room" + room_name, line):
				print "ERROR: Room control object DefCore.txt has wrong id, found " + line.replace("\n", "") + ", expected id=Room" + room_name + "."
				room_ok = False

	# open room control object script
	with open(tower_dir + "/Room" + room_name + ".ocd/Script.c", "r") as f:
		lines = f.readlines()
		for line in lines:
			# check room section
			if re.match("public func GetRoomSection()*", line) and not re.search(room_name, line):
				print "ERROR: Room control object Script.c has wrong section, found " + line.replace("\n", "") + ", expected public func GetRoomSection() { return \"" + room_name + "\"; }."
				room_ok = False
			# room id (either double or excluded)
			if re.match("public func GetRoomID()*", line):
				room_id = re.search("\"[a-zA-Z]+\"", line).group(0).replace("\"", "")
				if room_id in room_ids:
					print "ERROR: Room control object Script.c has duplicate ID, found " + line.replace("\n", "") + ", expected public func GetRoomID() { return \"??\"; }."
					room_ok = False
				elif isinstance(args.exclude, list) and room_id in args.exclude:
					print "EXCLUDE: Room with id = " + room_id + " will be excluded as requested."
					room_ok = False
			# difficulty
			if re.match("public func GetRoomDifficulty()*", line):
				room_diff = re.search("return [0-9]+;", line).group(0).replace(";", "")[7:]
				if room_diff in room_diffs:
					print "ERROR: Room control object Script.c has duplicate difficulty, found " + line.replace("\n", "") + ", expected public func GetRoomDifficulty() { return \"?\"; }."
					room_ok = False
			# room author(s)
			if re.match("public func GetRoomAuthor()*", line):
				room_author = re.search("return \"[^\"]+\";", line).group(0).replace(";", "")[7:]

	# store some room properties
	if room_ok:
		room_ids.append(room_id)
		room_diffs.append(room_diff)
		room_authors.append(room_author)
	
	# print room settings
	if args.verbose and room_ok:
		print "room properties: id = " + room_id + ", difficulty = " + room_diff

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
args = parser.parse_args()

# store room names, id's and difficulties
room_names = []
room_ids = []
room_diffs = []
room_authors = []

# create tower directory based on version name
with open("Version.txt", "r") as content_file:
    version = content_file.read()
tower_dir = "../OCTowerV" + version + ".ocs"
## TODO: query replacing existing directory
if os.path.isfile(tower_dir):
	os.remove(tower_dir)
elif os.path.exists(tower_dir):
	shutil.rmtree(tower_dir)
os.makedirs(tower_dir)

# log which version is created
print "creating tower scenario version " + version
print "==========================================="

# copy main scenario files into the new directory
print "copying main scenario ..."
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

# copy tower objects into the new directory
print "copying tower objects ..."
shutil.copytree("TowerObjects.ocd", tower_dir + "/TowerObjects.ocd")

# copy empty scenario section into the new directory
print "copying empty scenario section ..."
shutil.copytree("SectEmpty.ocg", tower_dir + "/SectEmpty.ocg")

# loop over all rooms and copy sections and room object
print "==========================================="
for room_dir in os.listdir("."):
	if fnmatch.fnmatch(room_dir, "Room*.ocs") and not fnmatch.fnmatch(room_dir, "RoomTemplate.ocs"):
		copy_room(room_dir, tower_dir)

# pack the scenario folder if required
if args.pack:
	print "==========================================="
	print "packing scenario folder ..."
	try:
		subprocess.call(["c4group", tower_dir, "-p"])
	except OSError as e:
		print "ERROR: failed to run c4group."

# if verbose option create the list of rooms sorted according to difficulty
if args.verbose:
	print "==========================================="
	print "list of rooms ..."
	print "==========================================="
	print "---------------------------------------------------------------------------"
	print "| Diff | Room name                | ID | Author(s)                        |"
	print "---------------------------------------------------------------------------"
	# create a list of rooms
	rooms = []
	for index in range(0, len(room_names) - 1):
		rooms.append([room_diffs[index], room_names[index], room_ids[index], str(room_authors[index])])
	rooms.sort(key = lambda r: int(r[0]))
	for room in rooms:
		print "| " + " " * (4 - len(room[0])) + room[0] + " | " + room[1] + " " * (24 - len(room[1])) + " | " + room[2] + " | " + room[3] + " " * (32 - len(room[3])) + " |"
	print "---------------------------------------------------------------------------"

# finished
print "==========================================="
print "finished"


