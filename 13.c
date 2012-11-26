#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void add(char *a, char *b) {
    int i,j,c,tmp;
    i = strlen(b) - 1;
    if(b[i] == '\n')
        i --;
    for(j = 0,c = 0;i >= 0;i --,j ++) {
        tmp = c + a[j] + b[i] - 48;
        a[j] = tmp % 10;
        c = tmp / 10;
    }
    while(c != 0) {
        tmp = a[j] + c;
        a[j++] = tmp % 10;
        c = tmp / 10;
    }
}

void print(char *result) {
    int i,flag = 0;
    for(i = 99;i >= 0;i --){
        if(flag)
            printf("%d",result[i]);
        else 
            if(result[i] != 0)
                flag = 1,i++;
    }
    putchar('\n');
}

int main(int argc, char ** argv) {
    struct timeval start,end;
    gettimeofday(&start,NULL);

    char result[100] = {0};
    char a[55];
    int i;

    FILE *file = fopen("13_data","r");
    if(file == NULL)    exit(0);
    for(i = 0;i < 100;i ++) {
        fgets(a,55,file);
        add(result,a);

    }
    fclose(file);
    print(result);
    gettimeofday(&end,NULL);
    printf("%d \n", end.tv_usec - start.tv_usec);
    return 0;
}
