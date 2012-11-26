#include <stdio.h>

typedef enum{false = 0, true = 1}boolean;

boolean is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? true : false;
}

int main(int argc,char **argv) {
    int days_of_month[] = {365, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int which_day = (365 + 0) % 7;
    int sum = 0;

    int i,j;
    for(i = 1901;i <= 2000;i ++) {
        if(is_leap_year(i)) {
            days_of_month[0] = 366;
            days_of_month[2] = 29;
        }
        else {
            days_of_month[0] = 365;
            days_of_month[2] = 28;
        }
        for(j = 1;j <= 12;j ++) {
            which_day = (which_day + days_of_month[j]) % 7;
            if(which_day == 6)
                sum ++;
        }
    }
    printf("%d \n", sum);
    return 0;
}
