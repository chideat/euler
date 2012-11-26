#!/usr/bin/python2
import time

starttime = time.clock()
LIMIT = 1000000
CACHESIZE = LIMIT
cache = [0]*(CACHESIZE)

def generate(n):
    N = n
    count = 1
    while n != 1:
        if n%2 == 0:
            n = n/2
        else:
            n = 3*n + 1
        if (n < CACHESIZE and cache[n-1] != 0):
            cache[N-1] = count + cache[n-1]
            return cache[N-1]
        count += 1
    cache[N-1] = count
    return count

max_count = 0
max_n = 0
for n in range(2, LIMIT+1):
    count = generate(n)
    if count > max_count:
        max_count = count
        max_n = n
print max_n

print time.clock() - starttime
