#include<stdio.h>
#pragma warning(disable:4996)
#define BeGin 1
#define Last  4
#if 0
int Fact(int n)
{
	int result = 1;
	for (int i = n; i >= 1; i--)
	{
		result *= i;
	}
	return result;
}
int SumFact(int x, int y)
{
	int sum = 0;
	for (int i = x; i <= y; i++)
	{
		sum += Fact(i); 
	}
	return sum;
}

int main()
{
	int begin = BeGin;
	int last = Last;
	int num = SumFact(begin, last);
	printf("%d\n", num);

	return 0;
}
#endif


#if 0
int Printfnum(int n)
{
	if (n > 9)
	{
		Printfnum(n / 10);
	}
	printf("%d ", n % 10);

}
int main()
{
	int a = 1234;
	Printfnum(a);
	return 0;
}
#endif

#if 0
int Factorial(int i)
{
	if (i <= 1)
	{
		return 1;
	}
	return i * Factorial(i - 1);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Factorial(n);
	printf("%d\n", ret);
	return 0;
}
#endif


#if 0
//int MyStrlen(char* str)
//{
if (*str == '\0')
{
	return 0;
}
return 1 + MyStrlen(str + 1£©£»

}
int main()
{
	char* str = "abcdefg1234";
	int j = MyStrlen(str);
	printf("%d\n", j);
	printf("%s\n", str);
	return 0;
}
#endif


#if 0
void reverse_string(char* string)
{
	if (*string != '\0')
	{
		reverse_string(string + 1);
	}
	printf("%c", *string);
}
int main()
{
	char* str = "abcdmnk";
	reverse_string(str);
	return 0;
}
#endif



#if 0
int Sum(i)
{
	int sum = 0;
	int k = 0;
	if (i > 0)
	{
		return i % 10 + Sum(i / 10);
	}
	return 0;

}

int main()
{
	int a = 4559;
	int ret = Sum(a);
	printf("%d\n", ret);
	return 0;
}
#endif