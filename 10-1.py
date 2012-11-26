#!/usr/bin/python2
import time
import math

s = time.clock()
print "Problem 10: Find the sum of all the primes below two million."
primes = range(2,3)+ range(3,2000000,2) 
for i in range(3, int(math.sqrt(2000000)+1), 2): 
     primes = filter(lambda x: x == i or x % i, primes)

print "Answer: ", sum(primes)
print time.clock() - s
