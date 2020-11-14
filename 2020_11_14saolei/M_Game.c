#include"M_Game.h"
void menu()
{
	printf("*****************************\n");
	printf("***********1.play************\n");
	printf("***********0.exit************\n");
	printf("*****************************\n");
}
void SetMine(char mine_board[][COL], int row, int col)
{
	int count = NUMS;//雷的个数
	while (count)
	{
		int x = rand() % 10 + 1;//生成随机数1~10
		int y = rand() % 10 + 1;
		if (mine_board[x][y] == '0')
		{
			mine_board[x][y] = '1';//雷用1表示
			count--;
		}
	}
}
int GetMines(char mine_board[][COL], int row, int col, int x, int  y)
{
	return mine_board[x - 1][y - 1] + mine_board[x - 1][y]\
		+ mine_board[x - 1][y + 1] + mine_board[x][y - 1]\
		+ mine_board[x][y + 1]+ mine_board[x + 1][y - 1] \
		+ mine_board[x + 1][y] + mine_board[x + 1][y + 1]-8*'0';
	//获得扫的点周围的雷的个数，并转换成整型。
}
void ShowBoard(char show_board[][COL], int row, int col)
{
	printf(" ");
	for (int i = 1; i < row - 1; i++)
	{
		printf("   %d",i);
	}
	printf("\n—————————————————————\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf("%2d|", i);
		for (int j = 1; j < col - 1; j++)
		{
			printf(" %c |", show_board[i][j]);
		}
		printf("  \n—————————————————————\n");
	}
}//显示给玩家的棋盘。
void M_Game()
{
	char show_board[ROW][COL];
	char mine_board[ROW][COL];
	memset(show_board, '*', sizeof(show_board));//初始化
	memset(mine_board, '0', sizeof(mine_board));
	srand((unsigned long)time(NULL));//种下随机数种子
	SetMine(mine_board,ROW,COL);
	int count = (ROW - 2) * (COL - 2) - NUMS; //不是雷的个数
	int x = 0;
	int y = 0;
	do
	{
		ShowBoard(show_board, ROW, COL);
		printf("请选择你扫的位置：\n");
		scanf("%d %d",&x,&y);
		if (x < 1 || x>10 || y < 1 || y>10)
		{
			printf("你输入的位置越界了,请重输！！！\n");
			continue;
		}
		else if (show_board[x][y] != '*')
		{
			printf("这个位置已经被排除，请重新输入！！！\n");
			continue;
		}
		else if (mine_board[x][y] == '1')
		{
			break;
		}
		else
		{
			int ret = GetMines(mine_board,ROW,COL,x,y);//得到周围雷的个数
			show_board[x][y] = ret+'0';//将ret转换成字符型
			count--;
		}
	} while (count > 0);
	if (count > 0)
	{
		printf("你被炸死了！！\n");
	}
	else
	{
		printf("你赢了！\n");
	}
	ShowBoard(show_board,ROW,COL);
	ShowBoard(mine_board, ROW, COL);
}