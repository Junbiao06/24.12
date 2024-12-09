#include <stdio.h>

#define SIZE 15  // 棋盘大小

char board[SIZE][SIZE];  // 棋盘

// 初始化棋盘
void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '.';  // 空位用 '.' 表示
        }
    }
}

// 打印棋盘
void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// 判断是否胜利
int checkWin(int row, int col, char player) {
    // 水平检查
    int count = 1;
    for (int i = col + 1; i < SIZE && board[row][i] == player; i++) count++;
    for (int i = col - 1; i >= 0 && board[row][i] == player; i--) count++;
    if (count >= 5) return 1;

    // 垂直检查
    count = 1;
    for (int i = row + 1; i < SIZE && board[i][col] == player; i++) count++;
    for (int i = row - 1; i >= 0 && board[i][col] == player; i--) count++;
    if (count >= 5) return 1;

    // 主对角线检查
    count = 1;
    for (int i = 1; row + i < SIZE && col + i < SIZE && board[row + i][col + i] == player; i++) count++;
    for (int i = 1; row - i >= 0 && col - i >= 0 && board[row - i][col - i] == player; i++) count++;
    if (count >= 5) return 1;

    // 副对角线检查
    count = 1;
    for (int i = 1; row + i < SIZE && col - i >= 0 && board[row + i][col - i] == player; i++) count++;
    for (int i = 1; row - i >= 0 && col + i < SIZE && board[row - i][col + i] == player; i++) count++;
    if (count >= 5) return 1;

    return 0;  // 没有获胜
}

int main() {
    int row, col;
    int turn = 0;  // 轮次，0 为玩家 X，1 为玩家 O
    char currentPlayer;

    initBoard();

    while (1) {
        printBoard();
        currentPlayer = (turn % 2 == 0) ? 'X' : 'O';  // 玩家轮流下棋

        printf("玩家 %c，请输入您的落子位置 (行 列): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // 检查输入合法性
        if (row < 1 || row > SIZE || col < 1 || col > SIZE || board[row - 1][col - 1] != '.') {
            printf("无效位置，请重新输入！\n");
            continue;
        }

        // 玩家落子
        board[row - 1][col - 1] = currentPlayer;

        // 检查是否有玩家获胜
        if (checkWin(row - 1, col - 1, currentPlayer)) {
            printBoard();
            printf("玩家 %c 获胜！\n", currentPlayer);
            break;
        }

        turn++;  // 切换玩家
    }

    return 0;
}