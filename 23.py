#!/usr/bin/env python
import sys
import time


starttime = time.clock()

def isAbundantNum(num) :
    s = 1
    begin = 2
    step = 1
    if num % 2 != 0 :
        begin = 3
        step = 2
    for i in range(begin, int(num ** 0.5) + 1, step) :
        if num % i == 0 :
            s += i
            s += num//i
    if int(num ** 0.5) ** 2 == num:
        s += int(num ** 0.5)
    if s > num :
        return True
    return False

number = [1 for i in range(0, 28124)]
abundant_number = []
for i in range(12, 28124) :
    if isAbundantNum(i) :
        abundant_number.append(i)

for i in range(0, len(abundant_number)) :
    for j in range(i, len(abundant_number)) :
        point = abundant_number[i] + abundant_number[j]
        if point > 28123 :
            continue
        #print(str(abundant_number[i]) + " + " + str(abundant_number[j]) + "=" + str(point))
        number[point] = 0

print(sum([i for i in range(1, 28124) if number[i] == 1]))
print(time.clock() - starttime)
