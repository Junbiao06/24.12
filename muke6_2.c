#include <stdio.h>
#define SIZE 1000

int fun(int a, int b, int r[]);
void output(int n, int r[]);

int main(void)
{
    int a, b;
    int array[SIZE];
    scanf("%d%d", &a, &b);
    int n = fun(a, b, array);
    output(n, array);
    return 0;
}

int fun(int a, int b, int r[])
{
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }
    int i = 0;
    for (int j = a; j <= b; j++)
    {
        if ((j % 7 == 0 || j % 11 == 0) && !(j % 7 == 0 && j % 11 == 0))
        {
            r[i] = j;
            i++;
        }
    }
    return i;
}

void output(int n, int r[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", r[i]);
        if (i < n - 1)
            printf(" ");
    }
    printf("\n");
}