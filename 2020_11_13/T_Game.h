#pragma once//��ֹͷ�ļ����ظ�����
#include<stdio.h>
#include<string.h>
#include<time.h>

#pragma warning(disable:4996)
#define ROW 3//���̿�Ϊ3��
#define COL 3//���̳�Ϊ3��
#define P_COLOR 'X'//��ִ��x��
#define C_COLOR 'O'//����ִ��o��
#define NEXT 'N'//��ʾ����
#define DRAW 'P'//��ʾ����
//����Ϊ��������
void menu();
void T_Game();
void ShowBoard(char board[][COL], int row, int col);
void PlayMove(char board[][COL], int row, int col);
char Judge(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);