#include <iostream>
#include <stdio.h>
#define IS_LEAP_YEAR(x) ((x%100!=0 && x%4==0) || x%400==0) ? 1 : 0
#include <string.h>

using namespace std;

// 从1000年到3000年，支持重复输入， 输入格式为 19 October 2001 这样的

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

struct Date{
    int year;
    int month;
    int day;
    void next_day(){
        if (day == dayOfMonth[month][IS_LEAP_YEAR(year)]){
            if (month == 12) {
                year++;
                month = 1;
                day = 1;
            }
            else {
                month++;
                day = 1;
            }
        }
        else {
            day++;
        }
    };
};

int buf[3001][13][32];
char monthName[13][20] = {
    "",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
char dayName[8][20] = {
    "",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

int main() {
    Date temp;
    int cnt = 0;
    temp.year = 1000; // 实际上是从1000年开始的
    temp.month = 1;
    temp.day = 1;

    while (temp.year != 3001) {
        buf[temp.year][temp.month][temp.day] = cnt;
        cnt++;
        temp.next_day();
    }
    int d, m, y;
    char s[20];
    while (scanf("%d%s%d", &d, s, &y) != EOF) {
        for (m = 1; m <= 12; m++) {
            if (strcmp(s, monthName[m]) == 0)
                break;
        }
        int diff = buf[y][m][d] - buf[2020][5][19];
        diff = 1 + (diff%7 + 7 + 1) % 7;
        puts(dayName[diff]);
    }
    return 0;
}

