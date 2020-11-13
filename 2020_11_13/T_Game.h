#pragma once//防止头文件被重复包含
#include<stdio.h>
#include<string.h>
#include<time.h>

#pragma warning(disable:4996)
#define ROW 3//棋盘宽为3；
#define COL 3//棋盘长为3；
#define P_COLOR 'X'//人执“x”
#define C_COLOR 'O'//电脑执“o”
#define NEXT 'N'//表示继续
#define DRAW 'P'//表示和棋
//以下为函数声明
void menu();
void T_Game();
void ShowBoard(char board[][COL], int row, int col);
void PlayMove(char board[][COL], int row, int col);
char Judge(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);