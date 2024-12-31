#include <stdio.h>
#include <string.h> //调用数据库使用strlen函数
#define N 100

int main(void)
{
    char array[N];
    int j = 0;
    printf("Please input the string: ");
    fgets(array, N, stdin);//用fgets减少考虑范围，变量用定义好的N，方便后续修改
    for (int i = 0; i < strlen(array); i++)
    {
        if (array[i] != ' ')
        {
            array[j] = array[i];
            j++;
        }
    }
    array[j] = '\0'; // 数组结束，在i和j之间的数也无需理会
    printf("String: %s\n", array);
    return 0; //养成良好习惯
}
