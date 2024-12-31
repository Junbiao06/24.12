#include <stdio.h>

typedef struct Date
{
    int year;
    int month;
    int day;
} Date;

int checkDate(Date date);

int main(void)
{
    Date date;
    printf("Date (YYYY-MM-DD): ");
    scanf("%i-%i-%i", &date.year, &date.month, &date.day);
    if (checkDate(date))
        printf("Valid.");
    else
        printf("Error.");
}

int checkDate(Date date)
{
    if (date.year < 1900 || date.year > 2022) // 需要考虑能被400整除的年份
        return 0;
    else if (date.month < 1 || date.month > 12)
        return 0;
    else
    {
        int bigmonth[] = {1, 3, 5, 7, 8, 10, 12}; // 31天的月份
        int smallmonth[] = {4, 6, 9, 11};         // 30天的月份
        for (int i = 0; i < sizeof(bigmonth) / sizeof(bigmonth[0]); i++)
        {
            if (date.month == bigmonth)
            {
                if (date.day > 31 || date.day < 1)
                    return 0;
            }
        }
        for (int i = 0; i < sizeof(smallmonth) / sizeof(smallmonth[0]); i++)
        {
            if (date.month == smallmonth)
            {
                if (date.day > 30 || date.day < 1)
                    return 0;
            }
        }
        // 年份被4整除，被100整除，被400整除，即2000年，29天
        // 年份只被4整除，即2004年，29天
        // 年份被4整除，被100整除，不被400整除，即1900年，28天
        // 年份不被这些整除，28天
        if (date.year % 4 == 0 || (date.year % 4 == 0 && date.year % 100 == 0 && date.year % 400 == 0))
        {
            if (date.day > 29 || date.day < 1)
                return 0;
        }
        else
        {
            if (date.day > 28 || date.day < 1)
                return 0;
        }
        return 1;
    }
}