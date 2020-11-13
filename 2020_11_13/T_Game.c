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
	printf("����������������\n");
	for (int i = 0; i < row; i++)
	{
		printf("| %d |", i + 1);
		for (int j = 0; j < col; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n����������������\n");
	}
}
void PlayMove(char board[][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	do 
	{
		printf("���������µ�λ��#��\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 3 && y <= 3 && y >= 1)
		{
			if (board[x - 1][y - 1] != ' ')
			{
				printf("�������λ���Ѿ��������ˣ������䣡����\n");
				continue;
			}
			else
			{
				board[x - 1][y - 1] = P_COLOR;//�궨�塰X��
				break;
			}
		}
		else
		{
			printf("������󣬳����ˣ������䣺\n");
			continue;
		}
	} while (1);
	//ShowBoard(board, ROW, COL);
}
char Judge(char board[][COL], int row, int col)
{//��ٷ����������������Ӯ��Ŀ��������£�
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && \
			board[i][1] == board[i][2] && \
			board[i][0] != ' ')
		{
			return board[i][0];
		}
	}//�������е������
	for (int j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && \
			board[1][j] == board[2][j] && \
			board[0][j] != ' ')
		{
			return board[0][j];
		}
	}//�������е������
	if (board[0][0] == board[1][1] && \
			board[1][1] == board[2][2] && \
			board[0][0] != ' ')
		{
			return board[0][0];
		}//�������Խ������
	if (board[0][2] == board[1][1] && \
		board[1][1] == board[2][0] && \
		board[0][2] != ' ')
	{
		return board[0][2];
	}//�����Խ������
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ');
			return NEXT;
			//��ʾ���̻�û���꣬������
		}
	}
	return DRAW;//���϶������㣬���Ǻ��壻
}
void ComputerMove(char board[][COL], int row, int col)
{
	while (1)  
	{
		int x = rand() % row;//�����漴����
		int y = rand() % col;//��3ȡģ����������0-2�������
		if (board[x][y] == ' ')
		{
			board[x][y] = C_COLOR;//�궨�塰O��
			break;
		}
	}
}
void T_Game()
{
	srand((unsigned long)time(NULL));//������������ӣ�timeΪʱ�����
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
		}//�����������Ѿ��н��������ѭ����
		ComputerMove(board, ROW, COL);
		ret=Judge(board, ROW, COL);
		if (ret != NEXT)
		{
			break;
		}//�����������Ѿ��н��������ѭ����
	} while (1);
	//��ѭ���ض��н��
	if (ret == P_COLOR)
	{
		ShowBoard(board, ROW, COL);
		printf("��Ӯ�ˣ�����\n");
	}
	else if ("ret==C_CPLOR")
	{
		ShowBoard(board, ROW, COL);
		printf("�����ˣ�����\n");
	}
	else
	{
		ShowBoard(board, ROW, COL);
		printf("���壡����\n");
	}
}