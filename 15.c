#include <stdio.h>

#define SIZE 20

int main(int argc, char **argv) {
    unsigned long long grid[SIZE][SIZE] = {0};

    int i,j;
    //init the last line
    for(i = SIZE - 1,j = 2;i >=0;i --) 
        grid[SIZE - 1][i] = j ++;

    //generate other data
    for(i = SIZE - 2;i >=0;i --) {
        grid[i][i] = 2 * grid[i + 1][i];
        for(j = i - 1;j >=0;j --) {
            grid[i][j] = grid[i][j + 1] + grid[i + 1][j];
        }
    }

    printf("%lld\n",grid[0][0]);
    return 0;
}
