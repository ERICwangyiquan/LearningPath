
#include "Chess.h"



void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void GiveExample()
{
	printf("\n");
	printf("Example move:>2 3\n");
	printf("   |   |   \n");
	printf("---|---|---\n");
	printf("   |   | * \n");
	printf("---|---|---\n");
	printf("   |   |   \n");
	printf("\n");
	printf("Game Start: \n");
}
//version1
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		//data
//		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
//		//cutline
//		if(i<row-1)
//			printf("---|---|---\n");
//	}
//}


//version2
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//data
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		//cutline
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if(j<col-1)
					printf("|");
			}
		}
		printf("\n");
	}
}


//player move
void player1_move(char board[ROW][COL], int row, int col)
{
	printf("Player1 move:>");
	int x = 0;
	int y = 0;

	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("This coordinate has been taken, please choose again!\n");
			}
		}
		else
		{
			printf("Illegal coordinate, please choose again!\n");
		}
	}
}


void player2_move(char board[ROW][COL], int row, int col)
{
	printf("Player2 move:>");
	int x = 0;
	int y = 0;

	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("This coordinate has been taken, please choose again!\n");
			}
		}
		else
		{
			printf("Illegal coordinate, please choose again!\n");
		}
	}
}


void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("Computer's move:>\n");
	while (1)
	{
		x = rand() % ROW;//0~2
		y = rand() % COL;//0~2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//3 Rows
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//3 Colomns
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//Judge of the diagonal
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2] &&board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//Judge if tied
	if (1==is_full(board, row, col))
	{
		return 'Q';
	}
	//continue
	return 'C';
}