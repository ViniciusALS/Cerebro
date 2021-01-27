from tkinter import *

from HomePage import HomePage


class App(Tk):
	def __init__(self, *args, **kwargs):

		Tk.__init__(self, *args, **kwargs)

		MainMenu(self)

		self.title("Training Data Aquisition GUI")
		self.minsize(840, 600)
		self.columnconfigure(0, weight=1)
		self.rowconfigure(0, weight=1)

		mainframe = Frame(self)
		mainframe.pack(side="top", fill="both", expand=True)
		mainframe.grid_rowconfigure(0, weight=1)
		mainframe.grid_columnconfigure(0, weight=1)

		page = HomePage(mainframe, self)
		page.tkraise()


class MainMenu:
	def __init__(self, master):
		menubar = Menu(master)
		filemenu = Menu(menubar, tearoff=0)
		filemenu.add_command(label="Baud Rate", command=master.quit)
		filemenu.add_command(label="Port", command=master.quit)
		menubar.add_cascade(label="Settings", menu=filemenu)
		master.config(menu=menubar)


app = App()
app.mainloop()