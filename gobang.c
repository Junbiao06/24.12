#include <stdio.h>
#define N 50

void initboard(int n);
void printboard(int n);
int wincheck(int row, int col, int player, int n);

int board[N][N];

int main(void)
{
    int n;
    int row, col;
    int gameover = 0;
    int player = 1;
    printf("***************************Welcome to Gobang!********************************\n");
    printf("Player 1: O    Player 2: X\n");
    do
    {
        printf("Size: ");
        scanf("%i", &n);
        n++;
    } while (n > N || n < 5);
    initboard(n);
    while (!gameover)
    {
        do
        {
            printf("Player %i's turn.\n", player);
            printf("Please input the location: ");
            scanf("%i%i", &row, &col);
        } while (row > n || row < 1 || col > n || col < 1 || board[row][col] != 0);
        board[row][col] = player;
        printboard(n);
        gameover = wincheck(row, col, player, n);
        player = (player == 1) ? 2 : 1;
    }
    printf("******************************GAMEOVER!*************************************\n");
    printf("Winner is player %i!", player = (player == 1) ? 2 : 1);
}

void initboard(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    printf("****************************************************************************\n");
    printf("  ");
    for (int i = 1; i < n; i++)
    {
        printf("%2d ", i);
        if (i == 9)
            printf(" ");
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        printf("%2d", i);
        for (int j = 1; j < n; j++)
        {
            printf(" . ");
        }
        printf("\n");
    }
}

int wincheck(int row, int col, int player, int n)
{
    int count = 1;
    for (int i = 1; row + i < n && board[row + i][col] == player; i++)
        count++;
    for (int i = 1; row - i >= 1 && board[row - i][col] == player; i++)
        count++;
    if (count >= 5)
        return 1;

    count = 1;
    for (int i = 1; col + i < n && board[row][col + i] == player; i++)
        count++;
    for (int i = 1; col - i >= 1 && board[row][col - i] == player; i++)
        count++;
    if (count >= 5)
        return 1;

    count = 1;
    for (int i = 1; row + i < n && col - i >= 1 && board[row + i][col - i] == player; i++)
        count++;
    for (int i = 1; row - i >= 1 && col + i < n && board[row - i][col + i] == player; i++)
        count++;
    if (count >= 5)
        return 1;

    count = 1;
    for (int i = 1; row + i < n && col + i < n && board[row + i][col + i] == player; i++)
        count++;
    for (int i = 1; row - i >= 1 && col - i >= 1 && board[row - i][col - i] == player; i++)
        count++;
    if (count >= 5)
        return 1;

    return 0;
}

void printboard(int n)
{
    printf("**********************************************************************\n");
    printf("  ");
    for (int i = 1; i < n; i++)
    {
        printf("%2d ", i);
        if (i == 9)
            printf(" ");
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        printf("%2d", i);
        for (int j = 1; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                printf(" . ");
            }
            else if (board[i][j] == 1)
            {
                printf(" O ");
            }
            else if (board[i][j] == 2)
            {
                printf(" X ");
            }
        }
        printf("\n");
    }
}
