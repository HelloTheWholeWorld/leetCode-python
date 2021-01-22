#include <stdio.h>
#include <algorithm>
#define is_leap_year(x) (x%100!=0&&x%4==0)||(x%400==0) ? 1 : 0
int dayOfMonth[13][2] = {
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};

int main() {
    int year, month, day;
    while (scanf("%d%d", &year, &day) != EOF) {
        month = 1;
        while (day > dayOfMonth[month][is_leap_year(year)]) {
            day -= dayOfMonth[month][is_leap_year(year)];
            month += 1;
        }
        printf("%d-%02d-%02d\n", year, month, day);
    }
    return 0;
}
