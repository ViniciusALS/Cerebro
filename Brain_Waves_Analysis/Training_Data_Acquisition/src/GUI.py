from PIL import Image
import matplotlib.pyplot as plt
import matplotlib.image as mpimg


class GUI:

	__gui_image = {}
	
	__gui_image["moveBothHands"] = Image.open("Brain_Waves_Analysis/Training_Data_Acquisition/src/resources/moveBoth.png")
	__gui_image["moveLeftHand"] = Image.open("Brain_Waves_Analysis/Training_Data_Acquisition/src/resources/moveLeft.png")
	__gui_image["moveRightHand"] = Image.open("Brain_Waves_Analysis/Training_Data_Acquisition/src/resources/moveRight.png")
	__gui_image["rest"] = Image.open("Brain_Waves_Analysis/Training_Data_Acquisition/src/resources/rest.png")


	def __init__(self):
		self.configureMatplot()


	def configureMatplot(self):
		plt.ion()
		plt.axis('off')
		plt.show()

	
	def loadImage(self, state):
		plt.imshow(self.__gui_image[state])
		self.pausePlotToLoadImage()


	def pausePlotToLoadImage(self): # matplotlib needs to be paused for a fraction of a second
		plt.pause(0.001)			# in order to fully load image.


	def closeImage(self):
		plt.close()
