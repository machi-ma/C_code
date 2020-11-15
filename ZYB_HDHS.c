#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//void Print(int arr[], int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//int  ComInt(const void* _x, const void* _y)
//{
//	int* x = (int*)_x;
//	int* y = (int*)_y;
//	if (*x > * y)
//	{
//		return 1;//1代表升序，-1代表降序
//	}
//	else if (*x < *y)
//	{
//		return -1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int char_cmp(const void *x,const void *y)//x是地址的地址，二级指针
//{
//	char *_x = *(char**)x;
//	char *_y = *(char**)y;
//	return strcmp(_x,_y);//1,0,-1
//}
//int main()
//{
//	int arr[] = { 45,5,48,63,14,788,46,358,999,472,64,98,72,11,20 };
//	char *arr[] = { "ab124","ad4564","41564","b12482" };
//	int num = sizeof(arr) / sizeof(arr[0]);
//	//arr[]是指针数组，存放的是地址
//	Print(arr, num);
//	qsort(arr, num, sizeof(int), ComInt);
//	Print(arr, num);
//	qsort(arr,num,sizeof(char*),char_cmp);
//	return 0;
//}
//void menu()
//{
//	printf("*******************************\n");
//	printf("**** 1.Add           2.Sub ****\n");
//	printf("**** 3.Mul           4.Div ****\n");
//	printf("**********  5.exit ************\n");
//}
//int MyAdd(int x, int y)
//{
//	return x + y;
//}
//int MySub(int x, int y)
//{
//	return x - y;
//}
//int MyMul(int x, int y)
//{
//	return x * y;
//}
//int MyDiv(int x, int y)
//{
//	if (y == 0)
//	{
//		printf("除零了，请重输");
//	}
//	else
//	{
//		return x / y;
//	}
//}
////链接表编写计算器
//int main()
//{
//	int x;
//	int y;
//	int input = 1;
//	int ret = 0;
//	int(*arr[6])(int x, int y) = { 0,MyAdd,MySub,MyMul,MyDiv };
//	//(*arr[6])(int x, int y)是函数指针数组
//	while (input)
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		if (input < 5 && input >= 1)
//		{
//			printf("请输入两个数：\n");
//			scanf("%d %d", &x, &y);
//			ret = (*arr[input])(x, y);//通过函数返回值得到数组的值
//		}
//		else if (input == 5)
//		{
//			break;
//		}
//		else
//		{
//			printf("输入有误！\n");
//		}
//		printf("%d\n", ret);
//	}
//	return 0;
//}
