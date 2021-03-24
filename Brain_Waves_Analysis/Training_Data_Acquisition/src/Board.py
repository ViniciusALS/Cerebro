import time
import numpy as np

import brainflow
from brainflow import BoardIds
from brainflow.board_shim import BoardShim, BrainFlowInputParams


class Board:

	def __init__(self):
		
		self.__board_ID = brainflow.board_shim.BoardIds(BoardIds.CYTON_BOARD)
		self.__parameters = self.__setBoardParameters()
	
		self.__board = self.__setBoard()

		self.__board.prepare_session()

   
	def startDataAcquisition(self):
		self.__board.start_stream()
	

	def getEGG_Data(self):
		self.__board.stop_stream()

		data = self.__board.get_board_data() 

		eeg_channels = BoardShim.get_eeg_channels(self.__board_ID)
		eeg_data = data[eeg_channels]

		return eeg_data
	

	def releaseBoardSession(self):
		self.__board.release_session()

	
	def __setBoardParameters(self):
		parameters = BrainFlowInputParams()
		parameters.serial_port = "COM3"

		return parameters


	def __setBoard(self):
		BoardShim.enable_dev_board_logger()
		return BoardShim(self.__board_ID, self.__parameters)
