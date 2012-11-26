#!/usr/bin/env python

n = 2
fn = 1
fn_1 = 1

while fn < 10 ** 999 :
    n, fn, fn_1 = (n+1, fn + fn_1, fn)
print(n)
