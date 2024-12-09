#include <stdio.h>

#define SIZE 15 // 棋盘大小
#define EMPTY 0
#define PLAYER1 1
#define PLAYER2 2

int board[SIZE][SIZE]; // 棋盘

void initializeBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard() {
    printf("   ");
    for (int i = 1; i < SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");

    for (int i = 1; i < SIZE; i++) {
        printf("%2d ", i);
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] == EMPTY) {
                printf(" . ");
            } else if (board[i][j] == PLAYER1) {
                printf(" X ");
            } else {
                printf(" O ");
            }
        }
        printf("\n");
    }
}

int checkWin(int player) {
    // 检查水平、垂直和两个对角线方向
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == player) {
                // 水平
                if (j + 4 < SIZE && board[i][j + 1] == player && board[i][j + 2] == player &&
                    board[i][j + 3] == player && board[i][j + 4] == player) {
                    return 1;
                }
                // 垂直
                if (i + 4 < SIZE && board[i + 1][j] == player && board[i + 2][j] == player &&
                    board[i + 3][j] == player && board[i + 4][j] == player) {
                    return 1;
                }
                // 主对角线
                if (i + 4 < SIZE && j + 4 < SIZE && board[i + 1][j + 1] == player &&
                    board[i + 2][j + 2] == player && board[i + 3][j + 3] == player &&
                    board[i + 4][j + 4] == player) {
                    return 1;
                }
                // 副对角线
                if (i + 4 < SIZE && j - 4 >= 0 && board[i + 1][j - 1] == player &&
                    board[i + 2][j - 2] == player && board[i + 3][j - 3] == player &&
                    board[i + 4][j - 4] == player) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int player = PLAYER1;
    int x, y;

    initializeBoard();

    while (1) {
        printBoard();
        printf("玩家 %d 的回合 (输入行 列): ", player);
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || board[x][y] != EMPTY) {
            printf("无效的输入，请重试。\n");
            continue;
        }

        board[x][y] = player;

        if (checkWin(player)) {
            printBoard();
            printf("玩家 %d 胜利！\n", player);
            break;
        }

        player = (player == PLAYER1) ? PLAYER2 : PLAYER1; // 切换玩家
    }

    return 0;
}
