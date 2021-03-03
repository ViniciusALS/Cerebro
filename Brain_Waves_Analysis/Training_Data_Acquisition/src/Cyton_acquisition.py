import time
import numpy as np

import brainflow
from brainflow import BoardIds
from brainflow.board_shim import BoardShim, BrainFlowInputParams
from brainflow.data_filter import DataFilter, FilterTypes, AggOperations



def main():

	board_ID = brainflow.board_shim.BoardIds(BoardIds.CYTON_BOARD)

	parameters = BrainFlowInputParams()
	parameters.serial_port = "COM3"
	
	BoardShim.enable_dev_board_logger()
	
	board = BoardShim(board_ID, parameters)
	board.prepare_session()

   
	board.start_stream()
	time.sleep(10)
  
	data = board.get_board_data() 
	board.stop_stream()
	board.release_session()

	data = [
		data[BoardShim.get_timestamp_channel (board_ID)], 
		data[BoardShim.get_eeg_channels(board_ID)]
	] 

	DataFilter.write_file(data, 'cyton_data.csv', 'w')


if __name__ == "__main__":
    main()