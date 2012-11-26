#!/usr/bin/env python

a = 101
b = 1
for i in range(2,a) :
    b *= i
print(sum([int(i) for i in str(b)]))
