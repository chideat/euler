#include <stdio.h>

int main(int argc, char **argv) {
    int i,j;
    unsigned sum = 1;
    unsigned current = 1;
    for(i = 3;i <= 1001;i += 2) {
        for(j = 0;j < 4;j ++) {
            current += i - 1;
                sum += current;
        }
    }
    printf("%d\n", sum);
}
