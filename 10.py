#!/usr/bin/python3
import time

def isPrime(i) :
    if i < 2 :  return False
    if i < 4 :  return True
    if i % 2 == 0 or i % 3 == 0 :  return False
    f = 5
    while f <= i**0.5 :
        if i % f == 0 or i % (f + 2) == 0 :  return False
        f += 6
    return True


starttime = time.clock()
sum = 2
i = 1
while i < 2000000 :
    i += 2
    if isPrime(i) :
        sum += i
print(sum)
print(time.clock() - starttime)
