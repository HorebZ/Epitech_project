#!/usr/bin/env python3

from tkinter import *
import PIL

def active(event):
    key = event.char
    if key in key_value:
        key_value[key] = 0
    return (key_value)

def deactive(event):
    key = event.char
    if key in key_value:
        key_value[key] = 1
    return (key_value)

def movement_ball(ball):
    global x, y, d, b
    print(x,y)
    print("valeur de b : ", b)
    if abs(y) >= d and abs(y) <= (d + 50):
        if abs(x) >= 975 and abs(x) <= 980:
            x = -x
    elif abs(y) >= b and abs(y) <= (b + 50):
        if abs(x) <= 20 and abs(x) >= 10:
            x = -x
    elif abs(x) >= 990 or abs(x) <= 10:
        goal(score2, score1)
        x = 495
        y = 245
    elif abs(y) >= 490 or abs(y) <= 10:
        y = -y
    x = x + 10
    y = y + 10

def movement_r():
    global c, d
    if key_value['o'] == 0 or key_value['l'] == 0:
        if key_value['o'] == 0 and d >= 20:
            d = d - 20
        elif key_value['l'] == 0 and d <= 430:
            d = d + 20
        elif d < 20:
            d = 0
        elif d > 430:
            d = 450

def movement_l():
    global a, b
    if key_value['z'] == 0 or key_value['s'] == 0:
        if key_value['z'] == 0 and b >= 20:
            b = b - 20
        elif key_value['s'] == 0 and b <= 430:
            b = b + 20
        elif b > 430:
            b = 450
        elif b < 20:
            b = 0

def goal(score2, score1):
    global x, h, j
    if abs(x) < 10:
        j = j + 1
        return(j)
    elif abs(x) > 490:
        h = h + 1
        return(h)

def draw():
    canvas.coords(plate_l, a, b, a + 5, b + 50)
    canvas.coords(plate_r, c, d, c + 5, d + 50)
    canvas.coords(ball, abs(x), abs(y), abs(x) + 10, abs(y) + 10)
    canvas.itemconfigure(score1, text = h)
    canvas.itemconfigure(score2, text = j)

def speed():
    movement_l()
    movement_r()
    movement_ball(ball)
    draw()
    window.after(30,speed)

###coords of the ball
x = 495
y = 245
###coords of left plate
a = 10
b = 225
###coords of right plate
c = 985
d = 225
###variable of scores
h = 0
j = 0

key_value = {}
for i in ['z', 's', 'o', 'l']:
    key_value[i] = 1

window = Tk()
window.configure(background = '#212121')

canvas   = Canvas(window, width = 1000, height = 500, bg = "#070914", highlightthickness=0)
mid_line = canvas.create_rectangle(498, 0, 502, 500, fill = "#0c680d")
plate_l  = canvas.create_rectangle(a, b, a + 5, b + 50, fill = "#0c680d")
plate_r  = canvas.create_rectangle(c, d, c + 5, d + 50, fill = "#0c680d")
score1   = canvas.create_text(480, 50, font = "NewAmsterdam", text = str(h), fill = "#0c680d")
score2   = canvas.create_text(520, 50, font = "NewAmsterdam", text = str(j), fill = "#0c680d")
ball     = canvas.create_oval(x, y, x + 20, y + 20, fill = "#0c680d")
canvas.focus_set()
canvas.bind("<Key>", active)
canvas.bind("<KeyRelease>", deactive)
canvas.grid(rowspan = 2, row = 0, columnspan = 3, column = 0, padx = 10)

button_speed = Button(window, text = 'speed up', bg = '#212121', highlightthickness=0, relief = FLAT, command = speed)
button_speed.grid(row = 2, column = 3)

button_exit = Button(window, text = "exit", bg = '#212121', highlightthickness=0, relief = FLAT, command = window.destroy)
button_exit.grid(row = 3, column = 3)

speed()

window.mainloop()
