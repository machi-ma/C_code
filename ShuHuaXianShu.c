#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma warning(disable:4996)
int main()
{
	for (int i = 0; i < 100000; i++)
	{
		int count = 0;
		int temp = i;
		while (temp)
		{
			count++;
			temp /= 10;
		}
		int sum = 0;
		temp = i;
		while (temp)
		{
			sum += pow(temp % 10, count);
			temp /= 10;
		}
		if (i == sum)
		{
			printf("%d\n", sum);
		}
	}
	return 0;
}