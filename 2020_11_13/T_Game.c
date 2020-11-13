#include"T_Game.h"
void menu()
{
	printf("***************************\n");
	printf("********* 1.play **********\n");
	printf("********* 0.exit **********\n");
	printf("***************************\n");
}
void ShowBoard(char board[][COL], int row,int col)
{
	printf("|     %d | %d | %d |\n", 1, 2, 3);
	printf("————————\n");
	for (int i = 0; i < row; i++)
	{
		printf("| %d |", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n————————\n");
	}
}
void PlayMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	do 
	{
		printf("请输入你下的位置#：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y <= 3 && y >= 1)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("你输入的位置已经有棋子了，请重输！！！\n");
				continue;
			}
			else
			{
				board[x - 1][y - 1] = P_COLOR;//宏定义“X”
				break;
			}
		}
		else
		{
			printf("输入错误，出界了，请重输：\n");
			continue;
		}
	} while (1);
	//ShowBoard(board, ROW, COL);
}
char Judge(char board[][COL], int row, int col)
{//穷举法，下棋过程中所有赢棋的可能性如下：
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')
		{
			return board[i][0];
		}
	}//代表所有的行相等
	for (int j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && \
			board[1][j] == board[2][j] && \
			board[0][j] != ' ')
		{
			return board[0][j];
		}
	}//代表所有的列相等
	if (board[0][0] == board[1][1] && \
			board[1][1] == board[2][2] && \
			board[0][0] != ' ')
		{
			return board[0][0];
		}//代表主对角线相等
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[0][2] != ' ')
	{
		return board[0][2];
	}//代副对角线相等
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ');
			return NEXT;
			//表示棋盘还没下完，继续。
		}
	}
	return DRAW;//以上都不满足，即是和棋；
}
void ComputerMove(char board[][COL], int row, int col)
{
	while (1)  
	{
		int x = rand() % row;//产生随即数。
		int y = rand() % col;//对3取模，产生俩个0-2的随机数
		if (board[x][y] == ' ')
		{
			board[x][y] = C_COLOR;//宏定义“O”
			break;
		}
	}
}
void T_Game()
{
	srand((unsigned long)time(NULL));//种下随机数种子，time为时间戳。
	int ret = 0;
	char board[ROW][COL];
	memset(board, ' ', sizeof(board));
	do
	{
		ShowBoard(board,ROW,COL);
		PlayMove(board, ROW, COL);
		ret=Judge(board, ROW, COL);
		if (ret != NEXT)
		{
			break;
		}//棋盘下满，已经有结果，跳出循环。
		ComputerMove(board, ROW, COL);
		ret=Judge(board, ROW, COL);
		if (ret != NEXT)
		{
			break;
		}//棋盘下满，已经有结果，跳出循环。
	} while (1);
	//出循环必定有结果
	if (ret == P_COLOR)
	{
		ShowBoard(board, ROW, COL);
		printf("你赢了！！！\n");
	}
	else if ("ret==C_CPLOR")
	{
		ShowBoard(board, ROW, COL);
		printf("你输了！！！\n");
	}
	else
	{
		ShowBoard(board, ROW, COL);
		printf("和棋！！！\n");
	}
}