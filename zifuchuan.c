#include<stdio.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)

#if 0
size_t MyStrlen(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str ++;
	}
	return count;
}
int main()
{
	char* str = "abcd12534";
	size_t ret = MyStrlen(str);
	printf("%d\n", ret);
	printf("%d", strlen(str));
	return 0;
}

#endif


#if 0
char* MyStrcpy(char* s1, const char* s2)
{
	char* t = s1;
	int s = strlen(s2) + 1;
	while (s)
	{
		*s1 = *s2;
		s1++;
		s2++;
		s--;
	}
	return t;
}
int main()
{
	char str[] = "abjdfh";
	char dst[100];
	char* ret = MyStrcpy(dst,str);
	printf("str:%s\n", str);
	printf("dst:%s", dst);
	return 0;
}
#endif




#if 0
int MyStrcmp(const char* s1, const char* s2)
{
	assert(s2 != NULL);
	assert(s1 != NULL);
	int ret = 0;
	unsigned char* p = (unsigned char*)s1;
	unsigned char* x = (unsigned char*)s2;
	while (!(ret = (*p -*x)) & *p)
	{
		++p;
		++x;
	}
	if (ret < 0)
	{
		ret = -1;
	}
	else if (ret > 0)
	{
		ret = 1;
	}
	else
	{
		ret = 0;
	}
	return ret;
}
int main()
{
	char* str = "ans452";
	char* dst = "ansjdkcs";
	int ret = MyStrcmp(str, dst);
	return 0;
}
#endif



