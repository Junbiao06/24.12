#include<stdio.h>
#include<string.h>
#define N 50

int main(void)
{
    char array[N];
    char *p=array;
    char *q=array;
    printf("Please input the string: ");
    fgets(array, N, stdin);//用fgets减少考虑范围，变量用定义好的N，方便后续修改
    for(;*p!='\0';p++)
    {
        if(*p!=' ')
        {
            *q=*p;
            q++;
        }
    }
    *q='\0';
    printf("String: %s\n",array);
    return 0;
}