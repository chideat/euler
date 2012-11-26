#!/usr/bin/python3
import time

starttime = time.clock()
limit = 2000000

is_prime = [False for i in range(limit)]

for x in range(1, int(limit ** 0.5) + 1):
    for y in range(1, int(limit ** 0.5) + 1):    
        n = 4 * x ** 2 + y ** 2        
        if (n <= limit) and (n % 12 == 1 or n % 12 == 5):            
            is_prime[n] = not is_prime[n]            
        n = 3 * x ** 2 + y ** 2        
        if (n <= limit) and (n % 12 == 7):
            is_prime[n] = not is_prime[n]
        n = 3 * x ** 2 - y ** 2        
        if (x > y) and (n <= limit) and (n % 12 == 11):
            is_prime[n] = not is_prime[n]

for n in range(5, int(limit ** 0.5)):
    if is_prime[n]:
        k = n ** 2
        while k < limit:
            is_prime[k] = False      
            k += n ** 2
              

s = sum([i for i in range(limit) if is_prime[i]]) + 5
print(s)
print(time.clock() - starttime)
