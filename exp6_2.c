#include <stdio.h>
#include <string.h>
#define N 50

typedef struct string {
    char user[N];
    char index_user[N];
    char password[N];
    char index_password[N];
} STR;

int main(void)
{
    STR inputs;
    
    // 输入用户名，直到遇到 '#'
    printf("Please input your username: ");
    int k = 0;
    while ((inputs.user[k] = getchar()) != '#') {
        k++;
    }
    inputs.user[k] = '\0';  // 确保字符串正确结束

    // 输入密码，直到遇到 '#'
    printf("Please input your password: ");
    k = 0;
    while ((inputs.password[k] = getchar()) != '#') {
        k++;
    }
    inputs.password[k] = '\0';  // 确保字符串正确结束

    // 提取用户名（只考虑字母，取奇数位置的字母）
    int count = 1;
    int j = 0;
    for (int i = 0; inputs.user[i] != '\0'; i++) {
        if ((inputs.user[i] >= 'A' && inputs.user[i] <= 'Z') || (inputs.user[i] >= 'a' && inputs.user[i] <= 'z')) {
            if (count % 2 == 1) {  // 只取奇数位置的字母
                inputs.index_user[j++] = inputs.user[i];
            }
            count++;
        }
    }
    inputs.index_user[j] = '\0';  // 字符串结束符

    // 提取密码（只考虑数字，取偶数位置的数字）
    count = 1;  // 重置计数器
    j = 0;      // 重置索引
    for (int i = 0; inputs.password[i] != '\0'; i++) {
        if (inputs.password[i] >= '0' && inputs.password[i] <= '9') {  // 判断是否为数字
            if (count % 2 == 0) {  // 只取偶数位置的数字
                inputs.index_password[j++] = inputs.password[i];
            }
            count++;
        }
    }
    inputs.index_password[j] = '\0';  // 字符串结束符

    // 输出提取的用户名和密码
    printf("Username: %s\n", inputs.index_user);
    printf("Password: %s\n", inputs.index_password);

    return 0;
}
