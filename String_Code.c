#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#pragma warning(disable:4996)

#if 0
//ʵ��strcat
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
	//str ����ֵ��1234��һ�γ��ֵ��׵�ַ,������������
	//�ڵ�һ����������ĵ�ַ������ҵڶ���(�ַ���)��
	strncpy(str, "2245", 4);
	puts(str);
	return 0;
}
#endif


#if 0
//ʵ��strstr

char* MyStrstr(const char* s1, const char* s2)
{
	char* p = (char *)s1;
	char* q = (char *)s2;
	char* x = NULL;//xָ��s1
	if (*s2 == '\0')
	{
		return NULL;//s2��s1���Ҳ���������NULL
	}
	while (*p)//��s1���ң�
	{
		x = p;
		q = s2;
		while (*x && *q && (*x == *q))
//��s1�����ݺ�s2�ĵ�һ��������ȣ��������ң�ֱ��s2Ϊ'\0'
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
//strtok:�ַ����ָ����
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
//strerror ���������ش����룬����Ӧ�Ĵ�����Ϣ��
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
//tolower�������ַ�ת������������д���Сд��
//toupper�������ַ�ת����������Сд��ɴ�д��
//isupper�������ж��ַ��Ƿ��Ǵ�д��
//islower�������ж��ַ��Ƿ��Ǵ�д��
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


