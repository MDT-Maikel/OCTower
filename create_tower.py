#! /usr/bin/env python

import os
import shutil
import fnmatch


# create tower directory based on version name
with open("Version.txt", "r") as content_file:
    version = content_file.read()
tower_dir = "../OCTowerV" + version + ".ocs"
## TODO: query replacing existing directory
if os.path.exists(tower_dir):
	shutil.rmtree(tower_dir)
if not os.path.exists(tower_dir):
	os.makedirs(tower_dir)


# copy main scenario files into the new directory
print "copying main scenario ..."
shutil.copy("Version.txt", tower_dir)
shutil.copy("Authors.txt", tower_dir)
shutil.copy("DescUS.txt", tower_dir)
shutil.copy("DescDE.txt", tower_dir)
shutil.copy("Scenario.txt", tower_dir)
shutil.copy("Script.c", tower_dir)


# copy tower objects into the new directory
print "copying tower objects ..."
shutil.copytree("TowerObjects.ocd", tower_dir + "/TowerObjects.ocd")


# loop over all rooms and copy sections and room object
for room_dir in os.listdir("."):
	if fnmatch.fnmatch(room_dir, "Room*.ocs") and not fnmatch.fnmatch(room_dir, "RoomTemplate.ocs"):

		# get room name
		room_name = room_dir.split(".")[0][4:]
		print "copying room " + room_name + " ..."

		# copy room object
		for object_dir in os.listdir(room_dir):
			if fnmatch.fnmatch(object_dir, "Room*.ocd"):
				shutil.copytree(room_dir + "/" + object_dir, tower_dir + "/Room" + room_name + ".ocd")

		# copy room map and stored objects
		sect_dir = tower_dir + "/Sect" + room_name + ".ocg"
		os.makedirs(sect_dir)
		for sect_file in os.listdir(room_dir):
			print sect_file
			if fnmatch.fnmatch(sect_file, "Scenario.txt") or fnmatch.fnmatch(sect_file, "Map*.bmp") or fnmatch.fnmatch(sect_file, "Objects.c"):
				shutil.copy(room_dir + "/" + sect_file, sect_dir);
