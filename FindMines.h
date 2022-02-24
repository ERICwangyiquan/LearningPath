#pragma once

//include .h file
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

//definations of symbols
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10



//Initialize board
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//Print board
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//settle the bombs
void SetMine(char mine[ROWS][COLS], int row, int col);

//Find mine
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);