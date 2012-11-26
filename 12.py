#!/usr/bin/python3

import time
starttime = time.clock()

flag = True
n = 1
second = False
while flag :
    n += 2
    s = (n + 1)*n // 2
    a = n // 2 if n % 2 == 0 else (n + 1)//2
    i = 1
    for j in range(1,a) :
        if s % j == 0 :
            i += 1
        if i > 250 :
            if second:
                print(s)
                flag = False
            n -= 3
            second = True 
            break
    if second and i < 250:
        flag = False
        n += 1
        print((n + 1)*n //2)
        break
print(time.clock() - starttime)
