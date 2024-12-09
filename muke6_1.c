#include <stdio.h>
#define SIZE 15

int main(void)
{
    int year, month, day;
    int array[SIZE] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d-%d-%d", &year, &month, &day);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        array[2] += 1;
    }
    for (int i = month - 1; i >= 0; i--)
    {
        day += array[i];
    }
    printf("%d", day);
}