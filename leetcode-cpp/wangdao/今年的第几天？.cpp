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
    while (scanf("%d%d%d", &year, &month, &day) != EOF) {
        int cnt = day;
        month--;
        while (month >= 1) {
            cnt += dayOfMonth[month][is_leap_year(year)];
            month--;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
