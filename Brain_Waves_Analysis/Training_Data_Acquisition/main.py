from src.GUI import GUI
import src.Cyton_acquisition as Cyton_acquisition
import time
import random



def main():

	state = chooseRandomState()
	gui = GUI(state)

	shouldContinue = True
	while shouldContinue:

		shouldContinue
		state = chooseRandomState(state)
		time.sleep(5)
		gui.loadImage(state)

	gui.closeImage()


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