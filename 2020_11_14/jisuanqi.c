#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma warning (disable:4996)
int MyAdd(int x, int y)
{
	return x + y;
}
int MySub(int x, int y)
{
	return x - y;
}
int MyMul(int x, int y)
{
	return x * y;
}
int MyDiv(int x, int y)
{
	return x / y;
}
int main()
{
	
	int quit = 0;
	do
	{
		int a = 0;
		int b = 0;
		printf("请输入两个想运算的数：\n");
		scanf("%d %d", &a, &b);
		char c = 'x';
		printf("请选择<+ - * />:");
		scanf(" %c", &c);//???
		if (c == '+')
		{
			int sum = MyAdd(a, b);
			printf("%d+%d=%d\n", a, b, sum);
		}
		else if (c == '-')
		{
			int sub = MySub(a, b);
			printf("%d-%d=%d\n", a, b, sub);
		}
		else if (c == '*')
		{
			int mul = MyMul(a, b);
			printf("%d*%d=%d\n", a, b, mul);
		}
		else if (c == '/')
		{
			if (b == 0)
			{
				printf("分母不能为零!error\n");
			}
			else
			{
				int div = MyDiv(a, b);
				printf("%d/%d=%d\n", a, b, div);
			}
		}
		else
		{
			printf("error");
		}
	} while (!quit);

	return 0;
}