from tkinter import *
import tkinter.ttk as ttk


class App(Tk):
	def __init__(self, *args, **kwargs):

		Tk.__init__(self, *args, **kwargs)
		self.title("Training Data Aquisition GUI")
		self.minsize(840, 600)
		self.columnconfigure(0, weight=1)
		self.rowconfigure(0, weight=1)

		mainframe = ttk.Frame(self, padding="3 3 12 12")
		mainframe.grid(column=0, row=0, sticky=(N, W, E, S))


app = App()
app.mainloop()