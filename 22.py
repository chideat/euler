#!/usr/bin/env python


def read() :
    file = open("22.txt","r")
    text = file.read()
    if text[-1] == '\n':
        text = text[0:-1]
    l = text.split(',')
    l.sort()
    return l

total = 0
count = 0
for i in read() :
    tmp = 0
    count += 1
    for j in i[1:-1] :
        tmp += ord(j) - 64
    total = total + tmp * count
print(total)
