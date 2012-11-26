#include <stdio.h>


int main() {
    char *num_0_9[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char *num_tens[] = {"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *num_tys[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *num_hundard = "hundard";
    char *num_thousand = "thousand";
    char *num_and = "and";

    unsigned sum_1_99;
    unsigned sum_100_999;
    unsigned sum_1000;

    sum_1000 = strlen(num_thousand);
    sum_1_99 = 
