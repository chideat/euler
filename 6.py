import time

starttime = time.clock()

s = 0
all = sum(range(1,101))
for i in range(1,101):
  s += i * (all - i)
print(s)
print(time.clock()-starttime)
