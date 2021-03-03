from src.GUI import GUI
from src.Board import Board 
import time
import random
import numpy as np



def main():

	state = chooseRandomState()
	gui = GUI(state)
	board = Board()


	state = chooseRandomState(state)
	board.startDataAcquisition()
	gui.loadImage(state)
	time.sleep(10)
	egg_data = board.getEGG_Data()
	board.releaseBoardSession()
	gui.closeImage()

	np.savetxt('samples/test2.csv', egg_data, delimiter=',', fmt='%d')

	


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