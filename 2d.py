import os
import time
import random
from copy import deepcopy as dp

def GetGird(H, W):
    Gy = []
    Gird = []
    for i in range(W): Gy += [0]
    for i in range(H): Gird += [dp(Gy)]
    return Gird

def GetRandom(H, W, Gird):
    for y in range(H):
        for x in range(W):
            Gird[y][x] = random.randint(0,1)
    return Gird
            
def GetCount(Gird, x, y, H, W):
    Count = 0
    for i in range(-1, 2):
        for j in range(-1, 2):
            AY = (y + i + H) % H
            AX = (x + j + W) % W
            Count += Gird[AY][AX]
    Count -= Gird[y][x]
    return Count

def Generate(Lifes, Templ, H, W):
    for y in range(H):
        for x in range(W):
            Count = GetCount(Lifes, x, y, H, W)
            if (Lifes[y][x] == 1) and ((Count < 2) or (Count > 3)):
                Templ[y][x] = 0
            elif (Lifes[y][x] == 0) and (Count == 3):
                Templ[y][x] = 1
            else:
                Templ[y][x] = dp(Lifes[y][x])
    return Templ

def Draw(Gird, H, W):
    for y in range(H):
        Screen = ""
        for x in range(W):
            if Gird[y][x]: Screen += "# "
            else: Screen += "  "
        print("\x1b[{};{}H{}".format(y+1, 2, Screen))
            
os.system("clear") # On Linux
#os.system("cls") # On Windows
print("\033[1;99m Game of Life!")
W = 20
H = 20
Templ = GetGird(H, W)
Lifes = GetGird(H, W)
Lifes = GetRandom(H, W, Lifes)
while 1:
    Draw(Lifes, H, W)
    Lifes = dp(Generate(Lifes, Templ, H, W))
    #time.sleep(05)
