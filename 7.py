import time
import math
starttime = time.clock()

l = [2]
i = 1
n = 3
while  i < 10001 :
    j = 0
    flag = 1
    while j < len(l) and l[j] <= math.sqrt(n) :
        if n%l[j] == 0:
            flag = 0
            break
        j += 1
    if flag :
        l.append(n)
        i += 1
    n += 2
print(l[-1])
print(time.clock()-starttime)
