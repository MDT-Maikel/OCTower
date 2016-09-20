#! /usr/bin/env python

import os
import shutil
import fnmatch
import re


#############
# functions #
#############

# copies a room from room_dir to tower_dir
def copy_room(room_dir, tower_dir):
	# get room name
	room_name = room_dir.split(".")[0][4:]
	print "copying room " + room_name + " ..."

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
		# copy scenario map and objects
		if fnmatch.fnmatch(sect_file, "Map*.bmp") or fnmatch.fnmatch(sect_file, "Objects.c"):
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
		print "WARNING: room " + room_name + " will not be included"


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
				print "ERROR: Room control object DefCore.txt has wrong id, found " + line + ", expected id=Room" + room_name + "."
				room_ok = False

	# open room control object script
	with open(tower_dir + "/Room" + room_name + ".ocd/Script.c", "r") as f:
		lines = f.readlines()
		# check room section
		for line in lines:
			if re.match("public func GetRoomSection()*", line) and not re.search(room_name, line):
				print "ERROR: Room control object Script.c has wrong section, found " + line + ", expected public func GetRoomSection() { return \"" + room_name + "\"; }."
				room_ok = False

	# TODO: check room number unique, room name unique.

	# return whether the room is ok
	return room_ok


###############
# main script #
###############

# create tower directory based on version name
with open("Version.txt", "r") as content_file:
    version = content_file.read()
tower_dir = "../OCTowerV" + version + ".ocs"
## TODO: query replacing existing directory
if os.path.exists(tower_dir):
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
print "==========================================="
print "finished"


