#include <stdio.h>
#define SIZE 10

int main(void) {
    int array[SIZE];
    double sum = 0.0;

    // 输入数组元素
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &array[i]);
    }

    // 初始化 max 和 min
    int max = array[0];
    int min = array[0];

    // 计算总和、最大值和最小值
    for (int j = 0; j < SIZE; j++) {
        sum += array[j];
        if (array[j] > max) {
            max = array[j]; // 更新最大值
        }
        if (array[j] < min) {
            min = array[j]; // 更新最小值
        }
    }

    // 计算去掉最大值和最小值后的平均值
    double average = (sum - min - max) / (SIZE - 2); // 去掉最大值和最小值

    // 输出结果，保留六位小数
    printf("%.6lf\n", average);
    return 0;
}
