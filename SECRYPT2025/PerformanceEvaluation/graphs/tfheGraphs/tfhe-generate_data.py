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
	header = ['#', 'openkeygenRtime', 'openencryptTime', 'openANDGate', 'openORGate', 'openXORGate', 'openDecryptTime',
		   'rskeygenRtime','rsencryptTime', 'rsANDGate', 'rsORGate', 'rsXORGate', 'rsDecryptTime']
	
	j=0
	i = 0
	
	while i<200:
		substr_time = "ms"
		data = subprocess.run(["./open_tfhe"],  capture_output=True)
		data = data.stdout.decode('utf-8')
		data = data.split(" ")
		data = ' '.join(data).split()
		openkeygenRtime = data[1].replace(substr_time, "")
		openencryptTime = data[3].replace(substr_time, "")
		openANDGate = data[5].replace(substr_time, "")
		openORGate = data[7].replace(substr_time, "")
		openXORGate = data[9].replace(substr_time, "")
		openDecryptTime = data[11].replace(substr_time, "")
		
		data = subprocess.run(["./rs_tfhe"],  capture_output=True)
		data = data.stdout.decode('utf-8')
		data = data.split(" ")
		data = ' '.join(data).split()

		rskeygenRtime = data[1].replace(substr_time, "")
		rsencryptTime = data[3].replace(substr_time, "")
		rsANDGate = data[5].replace(substr_time, "")
		rsORGate = data[7].replace(substr_time, "")
		rsXORGate = data[9].replace(substr_time, "")
		rsDecryptTime = data[11].replace(substr_time, "")


		array_data.append([i,openkeygenRtime, openencryptTime, openANDGate, openORGate, openXORGate, openDecryptTime,
					rskeygenRtime, rsencryptTime, rsANDGate, rsORGate, rsXORGate, rsDecryptTime,
					])
		i+=1
	
	# name of csv file 
	filename = "tfhe_generated_data.csv"
	# writing to csv file
	with open(filename, 'w') as csvfile: 
		csvwriter = csv.writer(csvfile)
		csvwriter.writerow(header)
		csvwriter.writerows(array_data)

def averaging_data():
	header = ['#', 'openkeygenRtime', 'openencryptTime', 'openANDGate', 'openORGate', 'openXORGate', 'openDecryptTime',
		   'rskeygenRtime','rsencryptTime', 'rsANDGate', 'rsORGate', 'rsXORGate', 'rsDecryptTime']
	array_data = []
	df = pd.read_csv("tfhe_generated_data.csv", usecols=header)
	column_averages = df.mean()
	array_data.append(column_averages)
	filename = "tfhe_averages.csv"
	with open(filename, 'w') as csvfile: 
		csvwriter = csv.writer(csvfile)
		csvwriter.writerow(header)
		csvwriter.writerows(array_data)

#Ploting All Graphs seperately
def graph_separately_display():
	colors = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black']
	df = pd.read_csv("tfhe_averages.csv")
	for i, column in  enumerate(df.columns):
		plt.figure()  # Create a new figure for each plot
		plt.plot(df[column], color=colors[i % len(colors)])
		plt.title(column) 
		plt.xlabel("Index")
		plt.ylabel("Value") 
		plt.grid(True) 
		plt.show() 

def graph_one():
	colors = ['blue', 'green', 'red', 'cyan', 'magenta', 'yellow', 'black', 'blue', 'green', 'red', 'cyan', 'magenta']
	df = pd.read_csv("tfhe_averages.csv")
	plt.figure(figsize=(10, 6))  # Set the figure size
	for column, color in zip(df.columns, plt.cm.tab10.colors):
		plt.plot(df[column], label=column, color=color)
		plt.title("All Columns on the Same Graph")
		plt.xlabel("Index")
		plt.ylabel("Value") 
		plt.grid(True) 
		plt.legend()
		plt.show()

# collect_data()
# averaging_data()
graph_separately_display()
graph_one()
