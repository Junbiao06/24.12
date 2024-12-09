#include <stdio.h>
#define SIZE 50

int main(void)
{
    int x, y;
    int n;
    int player;
    printf("SIZE: ");
    scanf("%i", &n - 1);
    int board[SIZE][SIZE];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    for (int i = 1; i < n; i++)
    {
        board[0][i] = i;
        board[i][0] = i;
    }
    while ()
    {
        printf("Row: ");
        scanf("%i", &x);
        printf("Column: ");
        scanf("%i", &y);
        int k = 1;
        if (k % 2 != 0)
        {
            board[x][y] = 1;
            k++;
        }
        else
        {
            board[x][y] = 2;
            k++;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i < n; j++)
            {
                printf("%i", board[i][j]);
            }
        }
    }
}

int wincheck(int n, int row, int col, int player)
{
    int borad[n][n];
    int count = 0;
    for (int i = 1; i < n - 4; i++)
    {
        if (col + count >= 0 && borad[row][col + count] == player)
        {
            count++;
            if (count == 4)
                return 0;
        }
        else
        {
            count = 0;
            break;
        }
    }

    for (int i = 1; i < n - 4; i++)
    {
        if (row + count >= 0 && borad[row + count][col] == player)
        {
            count++;
            if (count == 4)
                return 0;
        }
        else
        {
            count = 0;
            break;
        }
    }

    for(int i=1;i<n-4;i++)
    {
        
    }
}
