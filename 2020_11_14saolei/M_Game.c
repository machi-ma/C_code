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
	int count = NUMS;//�׵ĸ���
	while (count)
	{
		int x = rand() % 10 + 1;//���������1~10
		int y = rand() % 10 + 1;
		if (mine_board[x][y] == '0')
		{
			mine_board[x][y] = '1';//����1��ʾ
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
	//���ɨ�ĵ���Χ���׵ĸ�������ת�������͡�
}
void ShowBoard(char show_board[][COL], int row, int col)
{
	printf(" ");
	for (int i = 1; i < row - 1; i++)
	{
		printf("   %d",i);
	}
	printf("\n������������������������������������������\n");
	for (int i = 1; i < row - 1; i++)
	{
		printf("%2d|", i);
		for (int j = 1; j < col - 1; j++)
		{
			printf(" %c |", show_board[i][j]);
		}
		printf("  \n������������������������������������������\n");
	}
}//��ʾ����ҵ����̡�
void M_Game()
{
	char show_board[ROW][COL];
	char mine_board[ROW][COL];
	memset(show_board, '*', sizeof(show_board));//��ʼ��
	memset(mine_board, '0', sizeof(mine_board));
	srand((unsigned long)time(NULL));//�������������
	SetMine(mine_board,ROW,COL);
	int count = (ROW - 2) * (COL - 2) - NUMS; //�����׵ĸ���
	int x = 0;
	int y = 0;
	do
	{
		ShowBoard(show_board, ROW, COL);
		printf("��ѡ����ɨ��λ�ã�\n");
		scanf("%d %d",&x,&y);
		if (x < 1 || x>10 || y < 1 || y>10)
		{
			printf("�������λ��Խ����,�����䣡����\n");
			continue;
		}
		else if (show_board[x][y] != '*')
		{
			printf("���λ���Ѿ����ų������������룡����\n");
			continue;
		}
		else if (mine_board[x][y] == '1')
		{
			break;
		}
		else
		{
			int ret = GetMines(mine_board,ROW,COL,x,y);//�õ���Χ�׵ĸ���
			show_board[x][y] = ret+'0';//��retת�����ַ���
			count--;
		}
	} while (count > 0);
	if (count > 0)
	{
		printf("�㱻ը���ˣ���\n");
	}
	else
	{
		printf("��Ӯ�ˣ�\n");
	}
	ShowBoard(show_board,ROW,COL);
	ShowBoard(mine_board, ROW, COL);
}