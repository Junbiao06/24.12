#include <stdio.h>
#include <string.h>
#define N 50

typedef struct string // 建立数据结构，逻辑更加清晰
{
    char user[N];
    char index_user[N];
    char password[N];
    char index_password[N];
} STR;
int main(void)
{
    STR inputs;
    printf("Please input your username(End with '#'): "); // 参照课本171
    int k = 0;
    while ((inputs.user[k] = getchar()) != '#')
    {
        k++;
    }
    inputs.user[k] = '\0';
    printf("Please input your passwords(End with '#'): ");
    k = 0;
    while ((inputs.password[k] = getchar()) != '#')
    {
        k++;
    }
    inputs.password[k] = '\0';
    // 读取完毕，开始破译密码
    int count = 0; // 根据题意的奇偶性来定
    int j = 0;     // 初始值，j自增
    for (int i = 0; inputs.user[i] != '\0'; i++)
    {
        if ((inputs.user[i] >= 65 && inputs.user[i] <= 90) || (inputs.user[i] >= 97 && inputs.user[i] <= 122))
        {
            if (count % 2 == 0)
            {
                inputs.index_user[j] = inputs.user[i];
                j++;
            }
            count++;
        }
    }
    inputs.index_user[j]='\0';
    count = 1; // 根据题意的奇偶性来定
    j = 0;     // 初始值，j自增
    for (int i = 0; inputs.password[i] != '\0'; i++)
    {
        if(inputs.password[i] >= 48 && inputs.password[i] <= 57)
        {
            if (count % 2 == 0)
            {
                inputs.index_password[j] = inputs.password[i];
                j++;
            }
            count++;
        }
    }
    inputs.index_password[j]='\0';
    printf("Username:%s \nPasswords:%s", inputs.index_user, inputs.index_password);
}
