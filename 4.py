import math
import time
starttime=time.clock()
i=997
q=1000
while i>=100 and q>999:
  x=0
  j=i
  while j!=0 :
    x=x*10+j%10
    j=j/10
  x=x+i*1000
  q=int(math.sqrt(x))
  while q<=999:
    if x%q==0 and x/q>=100 :
      print x,q,x/q
      break
    q=q+1
  i=i-1
print time.clock()-starttime
