#!/usr/bin/env python3
import time
starttime = time.clock()

result = 0
for f in open("13_data", "r") :
    result += int(f[0:-1])
result = str(result)
print(result, time.clock() - starttime)
