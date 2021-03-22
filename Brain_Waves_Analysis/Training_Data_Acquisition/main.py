from src.GUI import GUI
from src.Board import Board 
import time
import random
import os
import numpy as np


def main():
	state = chooseRandomState()
	
	for _ in range(10):
		state = chooseRandomState(state)
		samplePath = determinesNextSamplePath(state)
		sample = acquireSample(state)
		saveSample(sample, samplePath)
	

def determinesNextSamplePath(state):
	samplesDir = "C:/Users/vinic/Documents/Humber College/Capstone/code/Cerebro/Brain_Waves_Analysis/Training_Data_Acquisition/samples"
	stateSamplesDir = os.path.join(samplesDir, state)

	listOfSamples = os.listdir(stateSamplesDir)
	
	listOfSamples.remove('.gitkeep')

	listOfSamples.sort() 
	
	if not listOfSamples:
		sampleFileName = "0.csv"
	
	else:
		lastSample = str(listOfSamples[-1])
		lastSampleNumber = int(lastSample.replace('.csv', ''))
		sampleFileName = str(lastSampleNumber + 1)

	sampleFileName = os.path.join(stateSamplesDir, sampleFileName)

	return sampleFileName

def acquireSample(state):
	gui = GUI()
	board = Board()

	board.startDataAcquisition()
	gui.loadImage(state)
	time.sleep(10)

	sample = board.getEGG_Data()
	board.releaseBoardSession()
	gui.closeImage()

	return sample

def saveSample(sample, samplePath):
	np.savetxt(samplePath, sample, delimiter=', ', newline='\n', fmt='%f')

def chooseRandomState(prevState = "rest"):
	states = [
		"moveBothHands",
		"moveLeftHand",
		"moveRightHand",
		"rest"
	]	

	if prevState in states: 
		states.remove(prevState)

	return random.choice(states)


if __name__ == "__main__":
    main()