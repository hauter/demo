#include <stdio.h>
#include <time.h>
#define X 6
#define Y 6
int chess[X][Y];
int nextxy (int *x, int *y, int dir)
{
    int nx = *x, ny = *y;
    switch (dir) {
    case 0:
        nx -= 2; ny -= 1;
        break;
    case 1:
        nx -= 2; ny += 1;
        break;
    case 2:
        nx -= 1; ny += 2;
        break;
    case 3:
        nx += 1; ny += 2;
        break;
    case 4:
        nx += 2; ny += 1;
        break;
    case 5:
        nx += 2; ny -= 1;
        break;
    case 6:
        nx += 1; ny -= 2;
        break;
    case 7:
        nx -= 1; ny -= 2;
        break;
    default:
        break;
    }
    if (nx >= 0 && nx < X &&
            ny >= 0 && ny < Y &&
            chess[nx][ny] == 0)
    {
        *x = nx;
        *y = ny;

        return 1;
    }
    else
        return 0;
}
void printChess(int chess[X][Y])
{
    printf("\n\n");
    int i, j;
    for (i = 0; i < X; ++i)
    {
        for (j = 0; j < Y; ++j)
            printf("%3d", chess[i][j]);
        printf("\n\n");
    }
}

int chessTravel(int x, int y, int count)
{
    int dir, nx = x, ny = y;
    chess[x][y] = count;
    if (count == X * Y)
        return 1;

    for (dir = 0; dir <= 7; ++dir)
    {
        nx = x;
        ny = y;
        if (nextxy(&nx, &ny, dir))
        {
            if ( chessTravel(nx, ny, count + 1))
                return 1;
            else
            {
                chess[nx][ny] = 0;
            }
        }

    }
    return 0;
}

int main1 (void)
{
    clock_t begin, end ;
    int i, j;
    //初始化棋盘
    begin = clock();
    for (i = 0; i < X; ++i)
    {
        for (j = 0; j < Y; ++j)
            chess[i][j] = 0;
    }

    if (chessTravel(0, 0, 1))
        printChess(chess);
    else
    {
        printf(" \n失败\n");
        printChess(chess);
    }
    end = clock();
    printf("用时:%ld ms", end - begin);

    return 0;
}
















