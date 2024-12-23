#include <stdio.h>

void sort(int *a, int n);

int main(void)
{
    int n;
    static int array[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &array[i]); // array+i
    sort(array, n);
    for (int i = 0; i < n; i++)
        printf("%d  ", array[i]);
    printf("\n");
}

void sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[minor] > a[j])
            {
                minor = j;
            }
        }
        if (minor != i)
        {
            int t = a[minor];
            a[minor] = a[i];
            a[i] = t;
        }
    }
}