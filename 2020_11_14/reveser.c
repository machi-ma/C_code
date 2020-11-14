#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
void Reverse(char* begin, char* end)
{
	char temp;
	while (begin <= end)
	{
		temp = *begin;
		*begin = *end;
		*end = temp;
		begin++;
		end--;
	}
}
int main()
{
	char str[100] = { 0 };
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';
	char* begin = str;
	char* end = str;
	while (*end != '\0')
	{
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		Reverse(begin, end-1);
		if (*end != '\0')
		{
			end++;
		}
		begin = end;
	}
	Reverse(str, str+strlen(str)-1);
	printf("%s", str);
	return 0;
}