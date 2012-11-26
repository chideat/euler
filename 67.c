#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define SIZE 100

void mread(int a[][SIZE][2]) {
    FILE *fp = fopen("67_data", "r");
    if(fp == NULL) {
        printf("Open Error");
        exit(1);
    }
    char tmp[330];
    int i,j,v;
    for(i = 0;i < SIZE;i ++) {
        fgets(tmp, 330, fp);
        for(j = 0;j < strlen(tmp);j += 3) {
            v = tmp[j] - 48;
            v = v * 10 + tmp[j+1] - 48;
            a[i][j/3][0] = v;
        }
    }
    fclose(fp);
}

int main(int argc,char **argv) {
	struct timeval start;
	struct timezone tz;
	struct timeval end;
	gettimeofday(&start,&tz);
    int a[SIZE][SIZE][2] = {0};
    //read file
    mread(a);
    int i,j,tmp;

    for(i = 0;i < SIZE - 1;i ++)
        for(j = 0;j <= i;j ++) {
            if(j == 0 || a[i][j][0] > a[i][j-1][0]) {
                a[i+1][j][0] += a[i][j][0];
                a[i+1][j][1] = j;
            }
            if(j == i || a[i][j][0] >= a[i][j + 1][0]) {
                a[i+1][j+1][0] += a[i][j][0];
                a[i+1][j+1][1] = j;
            }
        }

    for(tmp = 0,i = 0;i < SIZE;i ++) {
        if(a[SIZE - 1][i][0] > tmp) 
            tmp = a[SIZE - 1][i][0], j = i;
    }
    printf("the route is \n");
    for(i = 99;i >=0;i --) {
        printf("(%d,%d)\n",i+1, j+1);
        j = a[i][j][1];
    }
    printf("%d \n",tmp);
	gettimeofday(&end,&tz);
	printf("%d \n", end.tv_usec - start.tv_usec);
	return 0;
}
