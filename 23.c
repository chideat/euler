#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

int is_abundant_num(int num) {
    int sum = 1;
    int i = 2;
    int step = 1;
    if(num % 2 != 0){
        i = 3;
        step = 2;
    }
    while(i * i < num) {
        if(num % i == 0) {
            sum += i;
            sum += num / i;
        }
        i += step;
    }
    if(i * i == num)
        sum += i;
    if(sum > num)
        return 1;
    return 0;
}


int main() {
    char number[28124];
    int buffer[28124];
    int length = 0;
    int i,j;

    memset(number, 1, sizeof(number));
    struct timeval start, end;

    gettimeofday(&start, NULL);

    for(i = 12;i < 28124;i ++)
        if(is_abundant_num(i))
            buffer[length ++] = i;

    int tmp;
    for(i = 0;i < length;i ++)
        for(j = i;j < length;j ++) {
            tmp = buffer[i] + buffer[j];
            if(tmp > 28123)
                continue;
            number[tmp] = 0;
        }
    int sum = 0;
    for(i = 1;i < 28124;i ++) {
        if(number[i] == 1)
            sum += i;
    }
    printf("%d \n", sum);
    gettimeofday(&end,NULL);
    printf("%d us\n",end.tv_usec - start.tv_usec);
    return 0;
}



