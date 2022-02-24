#include "Chess.h"
#include "Chess.c"



void menu()
{
	printf("************************\n");
	printf("*****   1. play   ******\n");
	printf("*****   0. exit   ******\n");
	printf("************************\n");
}

void game()
{
	//The data will be stored in to a char-type 2D array, player's move is '*',computer's move is '#',
	char board[ROW][COL] = {0};//the content of the array should be all space
	InitBoard(board, ROW, COL);//Initialize the chessboard
	//print it
	DisplayBoard(board, ROW, COL);
	//play it
	char ret = 0;
	while (1)
	{
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("player won!\n");
	}
	else if (ret == '#')
	{
		printf("computer won!\n");
	}
	else
	{
		printf("tied game\n");
	}
}


void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}

	} while (input);
}

int main()
{
	test();

	return 0;
}