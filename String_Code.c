#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#pragma warning(disable:4996)

#if 0
//实现strcat
char* MyStrcat(char* s1, const char* s2)
{
	assert(s1);
	assert(s2);
	char* p = s1;
	while (*s1)
	{
		s1++;
	}
	while (*s2)
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	return p;
}
int main()
{
	char* str = " world!";
	char dst[64] = "hello";
	//strcat(dst, str);
	printf("befor dst:%s\n", dst);
	MyStrcat(dst, str);
	printf("after dst:%s", dst);


	return 0;
}
#endif


#if 0
int main()
{
	char str[] = "This thi 123 1234";
	char* p = strstr(str, "1234");
	//str 返回值是1234第一次出现的首地址,参数有两个，
	//在第一个（传数组的地址）里边找第二个(字符串)。
	strncpy(str, "2245", 4);
	puts(str);
	return 0;
}
#endif


#if 0
//实现strstr

char* MyStrstr(const char* s1, const char* s2)
{
	char* p = (char *)s1;
	char* q = (char *)s2;
	char* x = NULL;//x指向s1
	if (*s2 == '\0')
	{
		return NULL;//s2在s1中找不到，返回NULL
	}
	while (*p)//在s1中找，
	{
		x = p;
		q = s2;
		while (*x && *q && (*x == *q))
//当s1的内容和s2的第一个内容相等，在往后找，直到s2为'\0'
		{
			x++;
			q++;
		}
		if (*q == '\0')
		{
			return p;
		}
		else
		{
			p++;
		}

		
	}
}
int main()
{
	char str[] = "this is a simple";
	char* p = MyStrstr(str, "simple");

	return 0;
}
#endif


#if 0
//strtok:字符串分割函数；
int main()
{
	char* p = "zhangpengwei@bitedu.tech";
	char* sep = "@.";
	char arr[30];
	char* str = NULL;
	strcpy(arr, p);
	for (str = strtok(arr, sep); str != NULL; str = strtok(NULL, sep))
	{
		printf("%s\n", str);
	}
	/*char str[] = "-this is#pargam,sample/strring.";
	char* ph = NULL;
	ph = strtok(str, "-, ,#,,,/,.");
	while (ph != NULL)
	{
		printf("%s\n", ph);
		ph = strtok(NULL, "-, ,#,,,/,.");
	}*/

	return 0;
}
#endif

#if 0
//strerror 函数，返回错误码，所对应的错误信息。
int main()
{
	FILE* p = fopen("text.bin", "r");
	if (p == NULL)
	{
		printf("%s", strerror(errno));
	}
	return 0;
}
#endif


#if 0
//tolower函数：字符转换函数，将大写变成小写，
//toupper函数：字符转换函数，将小写变成大写，
//isupper函数：判断字符是否是大写，
//islower函数：判断字符是否是大写，
int main()
{
	int i = 0;
	char str[] = "This is A AuppEr MAn";
	char c;
	while (str[i])
	{
		c = str[i];
		if (isupper(c))
		{
			c = tolower(c);
		}
		putchar(c);
		i++;
	}
	return 0;
}
#endif


