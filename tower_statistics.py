#! /usr/bin/env python

import argparse
import matplotlib.pyplot as plt
import numpy
import operator
import re
import sqlite3
import sys
import urllib
import ast

# program arguments
parser = argparse.ArgumentParser(description='Analyzes the statistics of Tower of Despair rounds.')
parser.add_argument('-v', '--verbose', action='store_true', help='verbose')
args = parser.parse_args()

# get statistics database
urllib.urlretrieve("http://league.openclonk.org/statistics.sqlite", "statistics.sqlite")

# open the database
conn = sqlite3.connect('statistics.sqlite')

# get the statistics for all games
stats = conn.execute("SELECT statistics from games")

# init different statistics
room_attempt_duration = {}
room_success_rate = {}
room_player_ranking = {}

# loop over all games in the database
for stat in stats:
	if stat[0] != None:
		stat = stat[0].decode()

		room_duration = re.search("\"Statistics_RoomDuration\":\[[\{\}a-zA-Z0-9:,\"]*\]", stat)
		if room_duration != None:
			room_duration_data = re.findall("\{[a-zA-Z0-9:,\"]*\}", room_duration.group(0))
			for data in room_duration_data:
				duration = int(re.search("[0-9]+", data).group(0))
				room = re.search("Room[a-zA-Z]+", data).group(0)
				if not room in room_attempt_duration:
					room_attempt_duration[room] = []
				room_attempt_duration[room].append(duration)
				#print room + ": " + str(duration)

		room_attempts = re.search("\"Statistics_RoomAttempts\":\{[\{\}a-zA-Z0-9:,\"]*\}", stat)
		if room_attempts != None:
			room_attempts_data = re.findall("\"Room[a-zA-Z]*\":\{[a-zA-Z0-9:,\"]*\}", room_attempts.group(0))
			for data in room_attempts_data:
				room = re.search("Room[a-zA-Z]+", data).group(0)
				counts = ast.literal_eval(re.search("\{[a-zA-Z0-9:,\"]*\}", data).group(0))
				success_count = failed_count = 0
				if "SuccessCount" in counts:
					 success_count = counts["SuccessCount"]
				if "FailedCount" in counts:
					 failed_count = counts["FailedCount"]
				if not room in room_success_rate:
					room_success_rate[room] = {"success": 0, "failed": 0}
				room_success_rate[room]["success"] += success_count
				room_success_rate[room]["failed"] += failed_count
				#print room + " " + str(success_count) + " " + str(failed_count)

		tower_ranking = re.search("\"Statistics_TowerRanking\":\{[\{\}a-zA-Z0-9:,\"]*\}", stat)
		if tower_ranking != None:
			tower_ranking_data = re.findall("\"[a-zA-Z0-9]+\":\{[\{\}a-zA-Z0-9:,\"]*\}", tower_ranking.group(0))
			for data in tower_ranking_data:
				player = re.search("\"[a-zA-Z0-9]+\":\{", data).group(0)
				player = re.search("[a-zA-Z0-9]+", player).group(0)
				if not player in room_player_ranking:
					room_player_ranking[player] = []
				rooms = re.findall("\"Room[a-zA-Z0-9]+\":\{[a-zA-Z0-9:,\"]+\}", data)
				for room in rooms:
					room_name = re.search("Room[a-zA-Z]+", data).group(0)
					room_data = re.search("\{[a-zA-Z0-9:,\"]+\}", room).group(0)
					room_data = room_data.replace("true", "True").replace("false", "False")
					room_data = ast.literal_eval(room_data)
					room_player_ranking[player].append(room_name)
				
# process data
for room in room_attempt_duration:
	room_attempt_duration[room] = numpy.mean(room_attempt_duration[room]) / 36
for room in room_success_rate:
	room_success_rate[room] = 100.0 * room_success_rate[room]["success"] / (room_success_rate[room]["success"] + room_success_rate[room]["failed"])
for player in room_player_ranking:
	room_player_ranking[player] = len(list(set(room_player_ranking[player])))
room_player_ranking_sorted = sorted(room_player_ranking, key=room_player_ranking.get)

# print room data
print "-----------------------------------------------------"
print "| Room name                | Time (s) | Succes rate |"
print "-----------------------------------------------------"
for room in room_attempt_duration:
	time = str(room_attempt_duration[room])
	rate = str(room_success_rate[room])
	print "| " + room + " " * (25 - len(room)) + "|" + " " * (9 - len(time)) + time + " |" + " " * (11 - len(rate)) + rate + "% |"
print "-----------------------------------------------------"

#print player ranking
print "--------------------------------------"
print "|  #  | Player          | # of rooms |"
print "--------------------------------------"
num = 1
for player in room_player_ranking_sorted:
	nr_rooms = str(room_player_ranking[player])
	print "| " + " " * (3 - len(str(num))) + str(num) + " | " + player + " " * (15 - len(player)) + " | " + " " * (10 - len(nr_rooms)) + nr_rooms + " |"
	num += 1
print "--------------------------------------"

# close the database
conn.close()
