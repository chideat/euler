#!/usr/bin/env python

num_0_9 = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
num_teens = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
num_tys = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
num_hundred = "hundred"
num_thousand = "thousand"
num_and = "and"

counts_geiwei = sum([len(i) for i in num_0_9])
counts_teens = sum([len(i) for i in num_teens])
counts_tys = sum([len(i) for i in num_tys])
counts_hundred = len(num_hundred)
counts_thousand = len(num_thousand)
counts_and = len(num_and)

sum_1_99 = counts_geiwei + counts_teens + counts_tys * 10 + counts_geiwei * 8
sum_100_999 = sum_1_99  * 9 + counts_hundred * 100 * 9 + counts_and * 99 * 9 + counts_geiwei * 100
sum_1000 = counts_thousand

print(sum_1_99 + sum_100_999 + sum_1000 + len("one"))
