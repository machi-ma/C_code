#include"M_Game.h"
int main()
{
	int quit = 0;
	int input = 0;
	while (!quit) 
	{
		menu();
		printf("��ѡ��<1|0>:\n");
		scanf("%d", &input);
		switch (input)
		{case 1:
			M_Game();
			break;
		case 0:
			quit = 1;
			break;
		default:
			printf("������������䣡����\n");
			break;
		}
	}
}