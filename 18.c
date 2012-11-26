#include <stdio.h>

int main(int argc,char **argv) {
    int a[][15] = {
		{75},
		{95, 64},
		{17, 47, 82},
		{18, 35, 87, 10},
		{99,  4, 82, 47, 65},
		{99,  1, 23, 75,  3, 34},
		{88,  2, 77, 73,  7, 63, 67},
		{99, 65,  4, 28,  6, 16, 70, 92},
		{41, 41, 26, 56, 83, 40, 80, 70, 33},
		{99, 48, 72, 33, 47, 32, 37, 16, 94, 29},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
		{63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
		{ 99, 62, 98, 27, 23 , 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
    };
    int i,j,tmp;
    for(i = 0;i < 14;i ++)
        for(j = 0;j <= i;j ++) {
            if(j == 0 || a[i][j] > a[i][j-1])
                a[i+1][j] += a[i][j];
            if(j == i || a[i][j] > a[i][j + 1])
                a[i+1][j+1] += a[i][j];
        }
    for(i = 0;i < 15;i ++) {
    	for(j = 0;j <= i;j ++)
    		printf("%6d",a[i][j]);
    	putchar('\n');
    } 
    for(tmp = 0,i = 0;i < 15;i ++) {
        if(a[14][i] > tmp)
            tmp = a[14][i];
    }
    printf("%d \n",tmp);
	return 0;
}