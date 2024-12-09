#include <stdio.h>
#include <string.h>
#define N 30

void initboard(int n);
void printboard(int n);
int wincheck(int row, int col, int player, int n);

char board[N][N];

int main(void)
{
    int n;
    int gameover = 0;
    int player = 1;
    printf("Size: ");
    scanf("%i", &n);
    printf("**********WELCOME TO GOBANG!**********\n");
    printf("Player 1:O.  Player 2:X\n");
    initboard(n);
    printboard(n);
    while (!gameover)
    {
        int row, col;
        int turnsjudge = 1;
        if (turnsjudge % 2 != 0)
            player = 1;
        else
            player = 2;
        do
        {
            printf("**********Player %i's turn.**********\n", player);
            printf("Please input the location: ");
            scanf("%i%i", &row, &col);
        } while (row < n && row >= 1 && col < n && col >= 1);
        if (player == 1)
        {
            board[row][col] = 'O';
            printboard(n);
            gameover = wincheck(row, col, player, n);
        }
        else
        {
            board[row][col] = 'X';
            printboard(n);
            gameover = wincheck(row, col, player, n);
        }
        turnsjudge++;
    }
    printf("**********GAMEOVER!!!**********");
    printf("Winner is player %i!", player);
}

void initboard(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }
    }
    for (int i = 1; i < n; i++)
    {
        board[i][0] = '@' + i;
        board[0][i] = '`' + i;
    }
}

int wincheck(int row, int col, int player, int n)
{
    char array[n][n];
    int count = 1;
    for (int i = row + 1; i < n && array[i][col] == player; i++)
        count++;
    for (int i = row + 1; i < n && array[i][col] == player; i++)
        count++;
    if (count == 5)
        return 1;

    for (int i = col + 1; i < n && array[row][i] == player; i++)
        count++;
    for (int i = col - 1; i < n && array[row][i] == player; i++)
        count++;
    if (count == 5)
        return 1;

    for (int i = 1; row - i >= 1 && col - i >= 1 && array[row - i][col - i] == player; i++)
        count++;
    for (int i = 1; row + i < n && col + i < n && array[row + i][col + i] == player; i++)
        count++;
    if (count == 5)
        return 1;

    for (int i = 1; row - i >= 1 && col + i < n && array[row - i][col + i] == player; i++)
        count++;
    for (int i = 1; row + i < n && col + i >= 1 && array[row + i][col - i] == player; i++)
        count++;
    if (count == 5)
        return 1;
    return 0;
}

void printboard(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}