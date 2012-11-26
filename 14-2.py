#!/usr/bin/python2
import time

starttime = time.clock()

record = [1] #records the number of terms for each value of n, record[n] is the number of terms in n's sequence
 
for x in xrange(1, 1000000):
    n = x
    terms = 1
    while n > 1:
        if n < len(record): #checks if n had begun a previous sequence
            terms += record[n] #adds the terms from that sequence, saving a lot of time.
            break
        elif n % 2 == 0:
            n /= 2
            terms += 1
        elif n % 2 != 0:
            n = 3 * n + 1
            terms += 1
    record.append(terms)
print record.index(max(record))
print time.clock() - starttime
