
import serial
import time
from tkinter import *


Scom= serial.Serial('COM4',9600)
Scom.timeout=1
root= Tk()
root.geometry("345x200")
root.configure(bg="#858585")  
root.title("SERVO CONTROLS")

def run(i):
    pos=90

    h="h"
        

    Scom.write(i.encode())
    time.sleep(1.5)
    Scom.write(h.encode())
    time.sleep(0.7)
    if i=="r":

        pos+=30
    elif i=="l":
        pos -=30


            

left=Button(root,text=" <<LEFT  ",command= lambda:run("l"),pady=40,padx=52,bg="#f11459",fg= "white").place(x=1,y=1)
right=Button(root,text=" RIGHT>>  ",command= lambda:run("r"),pady=40,padx=48,bg="#f11459",fg= "white").place(x=180,y=1)
reset=Button(root,text=" <<RESET>>  ",command= lambda:run("R"),pady=20,padx=127,bg="#f11459",fg= "white").place(x=5,y=120)
root.mainloop()