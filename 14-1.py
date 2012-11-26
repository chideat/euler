#!/usr/bin/python3
import time

starttime = time.clock()

max = 0
max_n = 0

s = set()
for i in range(999999, 500001, -1) :
    if i in s :
        continue
    else :
        s.add(i)
    n = i
    m = 0
    while n > 8 :
        n = n // 2 if n % 2 == 0 else 3 * n + 1
        s.add(n)
        m += 1
    max, max_n = (i, m) if max_n < m else (max, max_n)
print(max, max_n, time.clock() - starttime)
