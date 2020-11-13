#include"T_Game.h"
int main()
{
	int flag = 0;
	int input = 0;
	while (!flag)
	{
		menu();
		printf("请选择<1or0>:\n");
		scanf("%d", &input);
		switch (input)
		{case 1:
			T_Game();
			printf("要不要再来一局？？？\n");
			break;
		case 0:
			flag = 1;
			break;
		default:
			printf("输入错误，请重输！！！\n");
			break;
		}
	}
	return 0;
}