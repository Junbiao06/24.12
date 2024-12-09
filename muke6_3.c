#include <stdio.h>
#define SIZE 10

int main(void)
{
    int array[SIZE];
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &array[i]);
    }
    int max = array[0];
    int min = array[0];
    int a = 0;
    int b = 0;
    for (int j = 0; j < SIZE; j++)
    {
        if (max < array[j])
            max = array[j];
        if (min > array[j])
            min = array[j];
        sum += array[j];
    }
    for (int k = 0; k < SIZE; k++)
    {
        if (array[k] == max)
            a++;
        if (array[k] == min)
            b++;
    }
    printf("%lf\n", (sum - a * max - b * min) / (10 - a - b));
}