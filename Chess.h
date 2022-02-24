#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define ROW 3
#define COL 3




//initialize chessboard
 void InitBoard(char board[ROW][COL], int row, int col);

//print chessboard
void DisplayBoard(char board[ROW][COL], int row, int col);

//player move
void player_move(char board[ROW][COL], int row, int col);

//computer move
void computer_move(char board[ROW][COL], int row, int col);

//the code to judge win or lose
//player won - '*'
//computer won - '#'
//tied --- 'Q'
//continue ----'C'

char is_win(char board[ROW][COL], int row, int col);