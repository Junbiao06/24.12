#include <stdio.h>
#include <math.h>
#define SIZE 13

int calculate(int year, int month, int day, int array[]);

int main(void)
{
    int year, month, day;
    int array[SIZE] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("Please input the date(YYYY-M-D 2024-12-4): ");
    scanf("%d-%d-%d", &year, &month, &day);
    int x = calculate(year, month, day, array);
    printf("Please input another date(YYYY-M-D 2024-12-4): ");
    scanf("%d-%d-%d", &year, &month, &day);
    int y = calculate(year, month, day, array);
    printf("There's between %d days.", abs(y - x));
    return 0;
}

int calculate(int year, int month, int day, int array[])
{
    int sum = 0;
    array[2] = 28;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        array[2] += 1;
    }
    for (int i = month - 1; i > 0; i--)
    {
        sum += array[i];
    }
    sum += day;
    return sum;
}