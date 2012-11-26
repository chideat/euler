#!/usr/bin/python3

n = 16
p = 0
s = set((1,2,4,8))
while (n - 1) // 3 < 1000000 :
    p = n if n < 1000000 else p
    if (n - 1) % 3 == 0 and ((n - 1) // 3) % 3 != 0 and (n - 1) // 3 not in s :
        n = (n - 1) // 3
    else :
        n *= 2
    s.add(n)
print(p)
