#include"T_Game.h"
int main()
{
	int flag = 0;
	int input = 0;
	while (!flag)
	{
		menu();
		printf("��ѡ��<1or0>:\n");
		scanf("%d", &input);
		switch (input)
		{case 1:
			T_Game();
			printf("Ҫ��Ҫ����һ�֣�����\n");
			break;
		case 0:
			flag = 1;
			break;
		default:
			printf("������������䣡����\n");
			break;
		}
	}
	return 0;
}