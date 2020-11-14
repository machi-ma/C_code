#pragma once
#include<stdio.h>
#include<string.h>
#include<time.h>

#pragma warning(disable:4996)

#define NUMS 20//雷的个数
#define ROW 12//棋盘长为10
#define COL 12//棋盘宽为10
void menu();
int GetMines(char mine_board[][COL], int row, int col, int x, int  y);
void ShowBoard(char mine_board[][COL], int row, int col);
void SetMine(char mine_board[][COL], int row, int col);