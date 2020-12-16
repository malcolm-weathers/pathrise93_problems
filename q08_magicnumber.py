# Generate random numbers using only a function which randomly returns 0 or 1.

import random
import time

def magicnumber():
    x = ''
    for y in range(0,8):
        x += str(random.randint(0,1))
    return int(x,2)

print(magicnumber())
        
