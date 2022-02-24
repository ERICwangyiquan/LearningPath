#include "FindMines.h"
#include "FindMines.c"

void menu()
{
	printf("***********************\n");
	printf("*****  1. play     ****\n");
	printf("*****  0. exit     ****\n");
	printf("***********************\n");
}


void game()
{
	//create array
	char mine[ROWS][COLS] = {0};//store the place of each mines
	char show[ROWS][COLS] = { 0 };//store the place of the mines already been found

	//initialize the board with 0
	InitBoard(mine, ROWS, COLS, '0');
	//initialize the board with *
	InitBoard(show, ROWS, COLS, '*');

	//Display board
	//DisplayBoard(mine, ROW, COL);
	
	//settle mines
	SetMine(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//DisplayBoard(mine, ROW, COL);
	//find mines
	FindMine(mine, show, ROW, COL);
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("Please choose:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			//Find Mine
			game();
			break;
		case 0:
			printf("Exit from game\n");
			break;
		default:
			printf("wrong choice\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}