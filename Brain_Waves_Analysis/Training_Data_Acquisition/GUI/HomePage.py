from tkinter import *

class HomePage(Frame):
	def __init__(self, parent, controller):
		Frame.__init__(self, parent)

		Label(self, text="Cerebro")


		teamFrame = Frame(self)
		teamFrame.grid(column=1, sticky=(W, S))

		Label(self, text="A project by:").grid(column=1, row=1, sticky=W)
		Label(self, text="Vinicius de A. L. e Souza").grid(column=1, row=2, sticky=W)
		Label(self, text="Yongsun Lin").grid(column=1, row=3, sticky=W)
		
		