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
//		return 1;//1��������-1������
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
//int char_cmp(const void *x,const void *y)//x�ǵ�ַ�ĵ�ַ������ָ��
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
//	//arr[]��ָ�����飬��ŵ��ǵ�ַ
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
//		printf("�����ˣ�������");
//	}
//	else
//	{
//		return x / y;
//	}
//}
////���ӱ��д������
//int main()
//{
//	int x;
//	int y;
//	int input = 1;
//	int ret = 0;
//	int(*arr[6])(int x, int y) = { 0,MyAdd,MySub,MyMul,MyDiv };
//	//(*arr[6])(int x, int y)�Ǻ���ָ������
//	while (input)
//	{
//		menu();
//		printf("��ѡ��\n");
//		scanf("%d", &input);
//		if (input < 5 && input >= 1)
//		{
//			printf("��������������\n");
//			scanf("%d %d", &x, &y);
//			ret = (*arr[input])(x, y);//ͨ����������ֵ�õ������ֵ
//		}
//		else if (input == 5)
//		{
//			break;
//		}
//		else
//		{
//			printf("��������\n");
//		}
//		printf("%d\n", ret);
//	}
//	return 0;
//}
