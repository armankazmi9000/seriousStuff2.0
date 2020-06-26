import re
from cs50 import get_float

while True:
    coins = get_float("Change: ")
    if coins > 0:
        break
print(coins)
coins = coins * 100    

c = 0

while coins >= 0:
    if coins >= 25:
        c = c + 1
        coins = coins - 25
    elif coins >= 10:
        c = c + 1
        coins = coins - 10
    elif coins >= 5:
        c = c + 1
        coins = coins - 5
    else:
        c = c + 1
        coins = coins - 1
    
print(c)