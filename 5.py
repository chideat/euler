import time
starttime=time.clock()
r=1
s=set()
for i in range(2,21):
  if i in s:
    continue
  f = 0
  for j in s:
    if i % j==0:
    f = 1
    break
if f:
s.add(i)
continue
t=1
while i**t <20:
s.add(i**t)
t=t+1
r = r*i**(t-1)
print r
print time.clock()-starttime