from tkinter import *
from tkinter import ttk, filedialog


root = Tk()
root.title("Training Data Aquisition GUI")
root.columnconfigure(0, weight=1)
root.rowconfigure(0, weight=1)


mainframe = ttk.Frame(root, padding="3 3 12 12")
mainframe.grid(column=0, row=0, sticky=(N, W, E, S))


ttk.Label(mainframe, text="Cerebro", font="Consolas").grid(column=1, row=1, sticky=W)

ttk.Button(mainframe, text="Start").grid(column=1, row=2, sticky=W)
# foldername = filedialog.


teamFrame = ttk.Frame(mainframe)
teamFrame.grid(column=1, sticky=(W, S))

ttk.Label(teamFrame, text="A project by:").grid(column=1, row=1, sticky=W)
ttk.Label(teamFrame, text="Vinicius de A. L. e Souza").grid(column=1, row=2, sticky=W)
ttk.Label(teamFrame, text="Yongsun Lin").grid(column=1, row=3, sticky=W)


root.mainloop() 