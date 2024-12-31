#include <stdio.h>
#define N 20 // 定义数组大小

int main(void)
{
    int n;
    int array[N];
    printf("Length: ");
    scanf("%i", &n);
    printf("Please input %i elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i < 0.5 * n) // 通过数学逻辑，避免数组元素是奇数还是偶数的讨论
        {
            int t = array[0 + i];
            array[0 + i] = array[n - 1 - i];
            array[n - 1 - i] = t;
        }
    }
    for (int i = 0; i < n; i++) // 打印
    {
        printf("%i ", array[i]);
    }
}