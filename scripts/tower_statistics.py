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
from datetime import datetime

# program arguments
parser = argparse.ArgumentParser(description='Analyzes the statistics of Tower of Despair rounds.')
parser.add_argument('-v', '--verbose', action='store_true', help='verbose')
args = parser.parse_args()

# get statistics database
urllib.urlretrieve("http://league.openclonk.org/statistics.sqlite", "statistics.sqlite")

# open the database
conn = sqlite3.connect('statistics.sqlite')

# get the statistics for all games
stats = conn.execute("SELECT date_ended,statistics from games")

# init different statistics
room_attempt_duration = {}
room_success_rate = {}
room_player_ratings = {}
room_player_ranking = {}

# loop over all games in the database
for stat in stats:
	# Look at next game if no statistics have been found
	if not stat[1]:
		continue
	# get the date of this game
	date = datetime.strptime(stat[0][0:19], '%Y-%m-%dT%H:%M:%S')
	# decode statistics
	stat = stat[1].decode()

	# get tower version
	tower_version = 0
	tower_data = re.search("\"Statistics_TowerData\":\{[\{\}a-zA-Z0-9:,\"]*\}", stat)
	if tower_data != None:
		tower_data = ast.literal_eval(tower_data.group(0).split(":", 1)[1])
		if "TowerVersion" in tower_data:
			tower_version = tower_data["TowerVersion"]

	# room duration statistics	
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

	# room attempt statistics	
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

	# room rating statistics	
	room_rating = re.search("\"Statistics_RoomRating\":\{[\{\}a-zA-Z0-9:,\"]*\}", stat)
	if room_rating != None:
		room_rating_data = re.findall("\"Room[a-zA-Z]*\":\{[a-zA-Z0-9:,\"]*\}", room_rating.group(0))
		for data in room_rating_data:
			room = re.search("Room[a-zA-Z]+", data).group(0)
			ratings = ast.literal_eval(re.search("\{[a-zA-Z0-9:,\"]*\}", data).group(0))
			if not room in room_player_ratings:
				room_player_ratings[room] = {}
			for player in ratings:
				if player in room_player_ratings[room]:
					if room_player_ratings[room][player]["date"] > date:
						continue
				room_player_ratings[room][player] = {"date": date, "rating": ratings[player]}
				
# process data
for room in room_attempt_duration:
	room_attempt_duration[room] = numpy.mean(room_attempt_duration[room]) / 36
for room in room_success_rate:
	room_success_rate[room] = 100.0 * room_success_rate[room]["success"] / (room_success_rate[room]["success"] + room_success_rate[room]["failed"])
for room, data in room_player_ratings.iteritems():
	ratings = [rating["rating"] for player, rating in data.iteritems()]
	room_player_ratings[room] = {"rating": numpy.mean(ratings), "vote_cnt": len(ratings)}

# print room data
print "---------------------------------------------------------------------------"
print "| Room name                | Time (mm:ss) | Succes rate | Rating | Vote # |"
print "---------------------------------------------------------------------------"
for room in room_attempt_duration:
	m, s = divmod(round(room_attempt_duration[room]), 60)
	time = "%02d:%02d" % (m, s)
	rate = "%.2f" % room_success_rate[room]
	rating = "---"
	nr_votes = "0"
	if room in room_player_ratings:
		rating = "%.1f" % room_player_ratings[room]["rating"]
		nr_votes = "%d" % room_player_ratings[room]["vote_cnt"]
	print "| " + room + " " * (25 - len(room)) + "|" + " " * (13 - len(time)) + time + " |" + " " * (11 - len(rate)) + rate + "% |" + " " * (7 - len(rating)) + rating + " |" + " " * (7 - len(nr_votes)) + nr_votes + " |"
print "---------------------------------------------------------------------------"

# close the database
conn.close()
