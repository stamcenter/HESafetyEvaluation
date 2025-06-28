#!/usr/bin/env python3
#this file is to measure memory bandwith wile exponentially scaling array.
# I have set my threadcount to a default value of 10 because at 10 the mmory bandwith becomes settled down.
# create a function that has a loop. Multiply the value of the array size by 1024 everytime to scale quick
# recompile the code and run the simple_stream
# when the numer of i is set, simple_stream should be executed and the output gotten.
# extract the value of best rate and store alongside the value of i in a file. 

#second function to plot the graph. 
# read the file and use the value of i for x axis and value of bandwidth for y-axis to plot a graph using matliplots./

import subprocess
import csv
import pandas as pd
import matplotlib.pyplot as plt
import random
#import numpy as np

def collect_data():
	array_data = []
	header = ['#', 'securityParam', 'x1','x2','x3',
		   'bgvkeygenRtime','bgvencryptTime', 'bgvMultTime', 'bgvAddTime','bgvDecryptTime',
		   'bfvkeygenRtime','bfvencryptTime', 'bfvMultTime', 'bfvAddTime','bfvDecryptTime',
		   'ckkskeygenRtime','ckksencryptTime', 'ckksMultTime', 'ckksAddTime','ckksDecryptTime',
	]
	
	j=0
	i = 0
	securityParams = ['8192','16384','32768']
	
	while i<200:
		x1 = random.randrange(1, 1000)
		x2 = random.randrange(1, 1000)
		x3 = random.randrange(1, 1000)
		j =0
		substr_time = "ms"
		while j<3:
			data = subprocess.run(["./sealexamples", str(x1), str(x2), str(x3), str(securityParams[j])],  capture_output=True)
			data = data.stdout.decode('utf-8')
			data = data.split(" ")
			data = ' '.join(data).split()
			bgvkeygenRtime = data[2].replace(substr_time, "")
			bgvencryptTime = data[4].replace(substr_time, "")
			bgvMultTime = data[6].replace(substr_time, "")
			bgvAddTime = data[8].replace(substr_time, "")
			bgvDecryptTime = data[10].replace(substr_time, "")

			bfvkeygenRtime = data[13].replace(substr_time, "")
			bfvencryptTime = data[15].replace(substr_time, "")
			bfvMultTime = data[17].replace(substr_time, "")
			bfvAddTime = data[19].replace(substr_time, "")
			bfvDecryptTime = data[21].replace(substr_time, "")

			ckkskeygenRtime = data[24].replace(substr_time, "")
			ckksencryptTime = data[26].replace(substr_time, "")
			ckksMultTime = data[28].replace(substr_time, "")
			ckksAddTime = data[30].replace(substr_time, "")
			ckksDecryptTime = data[32].replace(substr_time, "")
			
			array_data.append([i, securityParams[j], x1, x2, x3, 
					  bgvkeygenRtime, bgvencryptTime, bgvMultTime, bgvAddTime, bgvDecryptTime,
					  bfvkeygenRtime, bfvencryptTime, bfvMultTime, bfvAddTime, bfvDecryptTime,
					  ckkskeygenRtime, ckksencryptTime, ckksMultTime, ckksAddTime, ckksDecryptTime,
					  ])
			j+=1
		i+=1
	
	# name of csv file 
	filename = "seal_generated_data.csv"
	# writing to csv file
	with open(filename, 'w') as csvfile: 
		csvwriter = csv.writer(csvfile)
		csvwriter.writerow(header)
		csvwriter.writerows(array_data)

def averaging_data():
	securityParams = ['8192','16384','32768']
	header = ['#', 'securityParam', 'x1','x2','x3',
		   'bgvkeygenRtime','bgvencryptTime', 'bgvMultTime', 'bgvAddTime','bgvDecryptTime',
		   'bfvkeygenRtime','bfvencryptTime', 'bfvMultTime', 'bfvAddTime','bfvDecryptTime',
		   'ckkskeygenRtime','ckksencryptTime', 'ckksMultTime', 'ckksAddTime','ckksDecryptTime',
	]

	array_data = []
	df = pd.read_csv("seal_generated_data.csv", usecols=header)
	grouped_data = df.groupby('securityParam')
	for group_name, group_df in grouped_data:
		column_averages = group_df.mean()
		array_data.append(column_averages)
	filename = "seal_averages.csv"
	with open(filename, 'w') as csvfile: 
		csvwriter = csv.writer(csvfile)
		csvwriter.writerow(header)
		csvwriter.writerows(array_data)

#Ploting All Graphs seperately
def graph_separately_display():
	colors = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black']
	df = pd.read_csv("seal_averages.csv")
	for i, column in  enumerate(df.columns):
		plt.figure()  # Create a new figure for each plot
		plt.plot(df[column], color=colors[i % len(colors)])
		plt.title(column) 
		plt.xlabel("Index")
		plt.ylabel("Value") 
		plt.grid(True) 
		plt.show() 

def graph_one():
	colors = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black']
	df = pd.read_csv("seal_averages.csv")
	plt.figure(figsize=(10, 6))  # Set the figure size
	for column, color in zip(df.columns, plt.cm.tab10.colors):
		plt.plot(df[column], label=column, color=color)
		plt.title("All Columns on the Same Graph")
		plt.xlabel("Index")
		plt.ylabel("Value") 
		plt.grid(True) 
		plt.legend()
		plt.show()

collect_data()
averaging_data()
# graph_scattered_display()
# graph_separately_display()
# graph_one()
