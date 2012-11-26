#include <stdio.h>
#include <string.h>

unsigned d(int a) {
    unsigned sum = 1;
    int i;
    for(i = 2;i * i < a;i ++) {
        if(a % i == 0) sum += i, sum += a/i;
    }
    if(i * i == a)
        sum += i;
    return sum;
}

int main(int argc, char **argv ) {
    char a[10000];
    int i;
    unsigned long sum = 0;
    unsigned sum_one = 0,sum_two = 0;
    memset(a, 1, sizeof(a));
    for(i = 2;i < 10000;i ++){
        if(a[i]) {
            sum_one = d(i);
            if(sum_one <= i || sum_one >= 10000)
                continue;
            sum_two = d(sum_one);
            if(sum_two == i) {
                sum += i + sum_one;
                printf("%d -- %d\n", i, sum_one);
                a[i] = 0;
            }
        }
    }
    printf("%ld\n", sum);
    return 0;
}
