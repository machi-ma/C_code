#include<stdio.h>
#pragma warning(disable:4996)
#if 0
//дһ������������������
void Swap(int* a, int* b)//��������ֻ�Ƕ�ʵ�ε���ʱ����
                        //ֻ�д�ַ���ܽ������ı�a��b�Ĵ�С
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	//��ַ���ܸı�a��b�Ĵ�С��
	printf("a=%d \n b=%d", a, b);
	Swap(&a, &b);
	printf("a=%d \n b=%d", a, b);
	return 0;
}
#endif


#if 0
int Judge(int i)
{
	int j = 0;
	for ( j = 2; j <= i / 2; j++)
	{
		if (i % j == 0)
		{
			break;
		}
	}
	if (j == i)
	{
		printf("%d������\n",i);
	}

}

//�ж�һ��������������ӡ
int main()
{
	int i = 0;
	scanf("%d", &i);
	Judge(i);
	/*for (i = 1; i < 100; i++)
	{
		int j = 0;
		for (j = 2; j < sqrt(i); j++)
		{
			if (i % j == 0)
			{
				break;
			}
		}
		if (j == i)
		{
			printf("%d������", i);
		}
	}*/
	return 0;
}
#endif

#if 0
//��ӡ����
int Judge(int n)
{
	if ((n % 400 == 0) || (n % 4 == 0) && (n % 100 != 0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int ret = 0;
	int i = 0;
	for (i = 0; i <= 2020; i++)
	{
		ret =Judge(i);
		if (ret == 1)
		{
			printf("%d������\n", i);
		}
	}
	
	return 0;
}
#endif


#if 0
//дһ��������ʵ�ֶ��ֲ���,���ȶ�������������������۰����

void Revesre(int arr[], int num, int left, int right, int k)
{
	int mid = 0;
	while (left <= right)
	{
		mid = right - (right - left) / 2;
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else  if(arr[mid]<k)
		{
			left = mid + 1;
		}
		else
		{
			break;
		}
	}
	if (left <= right)
	{
		printf("�ҵ����±���%d\n", mid);
	}
	else
	{
		printf("�Ҳ���������\n");
	}

}


int IntCmp(const void *p,const void *q)
//�ص�������1���ظ�qsort,��ִ��Intcmp
{
	int *s1 = (int*)p;
	int *s2 = (int*)q;
	int temp = *s1;
	*s1 = *s2;
	*s2 = temp;
	if (*s1 > * s2)
	{
		return 1;
	}
	else if (*s2 < *s1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int arr[] = { 54,69,32,55,98,123,520,44,38,1314 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int k = 38;
	printf("��������Ҫ���ҵ���\n");
	scanf("%d", &k);
	int begin = 0;
	int end = num - 1;
	qsort(arr, num, sizeof(int), IntCmp);//�����������������
	/*for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}*/
	
	Revesre(arr, num,begin,end ,k);
	return 0;
}
#endif

#if 0
//дһ��������ÿ����һ�����������num+1
int  text(int *i)
{
	(*i)++;
	return i;
	
}

int main()
{

	int num = 0;
	
	text(&num);
	text(&num);
	text(&num);
	
	printf("%d", num);
}
#endif


#if 0
//����ʵ�ֽ׳˺ͽ׳˺�
#define BEGIN 1
#define LAST 5
int fact(int i)
{
	int sum=1;
	for (int j = 1; j <=i; j++)
	{
		sum *= j;
	}
	return sum;
}
int SumFact(int x, int y)
{
	int ret = 0;
	for (int i = x; i <= y; i++)
	{
		ret += fact(i);
	}
	return ret;
}
int main()
{
	int begin = BEGIN;
	int last = LAST;
	int ret = SumFact(begin, last);
	printf("%d", ret);
}
#endif


