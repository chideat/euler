import time
import math
starttime = time.clock()

l = 2
i = 1
n = 3
while  i < 10001 :
    j = math.sqrt(n) 
    flag = 1
    f = 5
    while f <= j:
        if n%f == 0 or n%(f + 2) == 0 :
            flag = 0
            break
        f += 6
    if flag :
        i += 1
        l = n
    n += 2
print(l)
print(time.clock()-starttime)
