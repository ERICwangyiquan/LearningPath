#include "FindMines.h"


void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	//1~9
	int i = 0;
	int j = 0;

	//print the colomn number
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//print the row number

		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;

	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

static int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + 
		mine[x - 1][y - 1] + 
		mine[x][y - 1] + 
		mine[x + 1][y - 1] + 
		mine[x + 1][y] + 
		mine[x + 1][y + 1] + 
		mine[x][y + 1] + 
		mine[x - 1][y + 1] - 8*'0';
}


void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < row*col- EASY_COUNT)
	{
		printf("please enter the coordinate you want to check:>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("Sorry you are died\n");
				DisplayBoard(mine, row, col);
				break;
			}
			else
			{
				//to calculate there's how many bombs arround this coordinate
				int n = get_mine_count(mine, x, y);
				show[x][y] = n+'0';
				DisplayBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("Illegal coordinate, please choose a defferent one\n");
		}
	}
	if (win == row * col - EASY_COUNT)
	{
		printf("Congratulations! You are succeed!\n");
		DisplayBoard(mine, row, col);
	}

}