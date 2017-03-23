//
// Created by Administrator on 2017/3/22.
//
#include <stdio.h>
#include <stdbool.h>

int MonthDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int leapMonthDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool leapYear(int);
int main(){
    int Year=2017;
    int Month=3;
    int Day=23;
    int YearSum=0;
    int MonthSum=0;
    int DaySum=0;
    int sum=0;

    //scanf("%d,%d,%d",&Year,&Month,Day);
    for(int i=2000;i<Year;i++){
        if(leapYear(i)){
            YearSum+=366;
        } else {
            YearSum+=365;
        }
    }
    if(leapYear(Year)){
        for(int i=1;i<Month;i++){
            MonthSum+=leapMonthDay[i];
        }
    } else {
        for(int i=1;i<Month;i++){
            MonthSum+=MonthDay[i];
        }
    }
    printf("%d,%d,%d",YearSum,MonthSum,Day);
    printf("%d",(YearSum+MonthSum+Day-1+6)%7);


}
bool leapYear(int Year){
    if((Year%4==0)&&(Year%100!=0||Year%400==0)){
        return true;

    } else {
        return false;
    }
}
