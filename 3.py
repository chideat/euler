import time
starttime = time.clock()
i=600851475143
j=3
while 1 :
    if i==j:
        break
    if i%j==0:
        i=i/j
    else:
        j=j+2
print(i)
print(time.clock()-starttime)
