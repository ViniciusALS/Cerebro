import argparse
import time
import numpy as np

import brainflow
from brainflow.board_shim import BoardShim, BrainFlowInputParams
from brainflow.data_filter import DataFilter, FilterTypes, AggOperations

def create_parser_argument_list():

	parser = argparse.ArgumentParser()
    # use docs to check which parameters are required for specific board, e.g. for Cyton - set serial port
	parser.add_argument('--timeout', type=int, help='timeout for device discovery or connection', required=False, default=0)
	parser.add_argument('--ip-port', type=int, help='ip port', required=False, default=0)
	parser.add_argument('--ip-protocol', type=int, help='ip protocol, check IpProtocolType enum', required=False, default=0)
	parser.add_argument('--ip-address', type=str, help='ip address', required=False, default='')
	parser.add_argument('--serial-port', type=str, help='serial port', required=False, default='')
	parser.add_argument('--mac-address', type=str, help='mac address', required=False, default='')
	parser.add_argument('--other-info', type=str, help='other info', required=False, default='')
	parser.add_argument('--streamer-params', type=str, help='streamer params', required=False, default='')
	parser.add_argument('--serial-number', type=str, help='serial number', required=False, default='')
	parser.add_argument('--board-id', type=int, help='board id, check docs to get a list of supported boards', required=True)
	parser.add_argument('--file', type=str, help='file', required=False, default='')
    
	arguments = parser.parse_args()

	return arguments


def sets_brainflow_input_parameters(arguments):
	parameters = BrainFlowInputParams()

	parameters.ip_port = arguments.ip_port
	parameters.serial_port = arguments.serial_port
	parameters.mac_address = arguments.mac_address
	parameters.other_info = arguments.other_info
	parameters.serial_number = arguments.serial_number
	parameters.ip_address = arguments.ip_address
	parameters.ip_protocol = arguments.ip_protocol
	parameters.timeout = arguments.timeout
	parameters.file = arguments.file

	return parameters


def main():
    BoardShim.enable_dev_board_logger()

    arguments = create_parser_argument_list()

    parameters = sets_brainflow_input_parameters(arguments)

    board = BoardShim(arguments.board_id, parameters)
    board.prepare_session()

    # board.start_stream () # use this for default options
    board.start_stream(45000, arguments.streamer_params)
    time.sleep(10)
    # data = board.get_current_board_data (256) # get latest 256 packages or less, doesnt remove them from internal buffer
    data = board.get_board_data()  # get all data and remove it from internal buffer
    board.stop_stream()
    board.release_session()

    print(data)


if __name__ == "__main__":
    main()