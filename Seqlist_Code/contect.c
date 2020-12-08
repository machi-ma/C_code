#include"Contect.h"
void menu()
{
	printf("################################\n");
	printf("##    1.Add         2.Div     ##\n");
	printf("##    3.Search      4.modify  ##\n");
	printf("##    5.Print       6.Sort    ##\n");
	printf("##    7.Save        0.Exit    ##\n");
	printf("################################\n");
}
void SaveContact(struct Contact* ps)
{
	FILE* fpwrite = fopen("mycontact.date", "wb");
	if (fpwrite == NULL)
	{
		printf("SaveContact::%s", strerror(errno));
		return;
	}
	else//将通讯录文件保存在文件中
	{
		for (int i = 0; i < ps->size; i++)
		{
			fwrite(&(ps->date[i]), sizeof(PerInfo), 1, fpwrite);
		}
	}
	fclose(fpwrite);
	fpwrite = NULL;
}
void LoadContact(struct Contact* ps)
{
	PerInfo temp = { 0 };
	FILE* fpread = fopen("mycontact.date", "rb");
	
	if (fpread == NULL)
	{
		printf("LoadContact::%s", strerror(errno));
		return;
	}
	else
	{
		//初始化时将文件里的内容读进通讯录里
		while (fread(&temp, sizeof(PerInfo), 1, fpread))
		{
			CheckCapacity(ps);
			ps->date[ps->size] = temp;
			ps->size++;
		}
	}
	fclose(fpread);
	fpread = NULL;
}
void InitContact(struct Contact *ps)
{
	ps->date = (PerInfo*)malloc(CAPACITY_SZ * (sizeof(PerInfo)));
	if (ps->date == NULL)
	{
		return;
	}
	else
	{
		ps->size = 0;//已存数目
		ps->capacity = CAPACITY_SZ;//初始容量
	}
	LoadContact(ps);//加载文件中的内容
	
	/*memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;*/
}
//判断是否需要增容
 void CheckCapacity(struct Contact* ps)
{
	if ((ps->size) == (ps->capacity))//判断是否需要增容
	{
		//增容
		PerInfo* pos = (PerInfo*)realloc(ps->date, (CAPACITY_SZ * 2)*sizeof(PerInfo));
		if (pos != NULL)
		{
			printf("增容成功\n");
			ps->date = pos;
			ps->capacity = CAPACITY_SZ * 2;
		}
		else
		{
			printf("扩容失败\n");
		}
		
	}
}
void AddContact(struct Contact* ps)//增加函数
{
	CheckCapacity(ps);//判断是否需要增容
	printf("请输入名字：");
	scanf(" %s", ps->date[ps->size].name);
	printf("请输入年龄：");
	scanf(" %d", &ps->date[ps->size].age);
	printf("请输入性别：");
	scanf(" %s", ps->date[ps->size].sex);
	printf("请输入电话：");
	scanf("%s", ps->date[ps->size].tele);
	printf("请输入住址：");
	scanf("%s", ps->date[ps->size].addr);
	printf("添加成功\n");
	ps->size++;

	/*if (ps->size == MAX)
	{
		printf("空间已满,添加失败\n");
	}
	else
	{
		printf("请输入名字：" );
		scanf(" %s", ps->date[ps->size].name);
		printf("请输入年龄：");
		scanf(" %d",& ps->date[ps->size].age);
		printf("请输入性别：");
		scanf(" %s", ps->date[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入住址：");
		scanf("%s", ps->date[ps->size].addr);
		printf("添加成功\n");
		ps->size++;
	}
	*/
	
}
void PrintContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%sd\t%-5s\t%-12s\t%-30s\n",
			"姓名", "年龄", "性别", "电话号码", "住址");
		for (int i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%4d\t%-5s\t%-12s\t%-30s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].addr);
		}
	}
	
	
}
//寻找名字对应下标的函数
static int FindContact(const struct Contact* ps,char name[MAX_NAME])
{
	int pos = 0;
	for (pos = 0; pos < ps->size; pos++)
	{
		if (strcmp(ps->date[pos].name, name) == 0)
		{
			break;
		}
	}
	if (pos == ps->size)
	{
		return -1;
	}
	else
	{
		return pos;
	}
}
void DelContact(struct Contact*ps)
{
	char name[MAX_NAME];
	printf("请输入你要删的名字：>");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("你要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入你要查找的人名字:>");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("你要查找的人不存在\n");
	}
	else
	{
		printf("查找成功\n");
		printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\n",
			"名字", "年龄", "性别", "电话号码", "住址");
		printf("%-20s\t%-5d\t%-4s\t%-12s\t%-30s\n",
			ps->date[pos].name, ps->date[pos].age,
			ps->date[pos].sex, ps->date[pos].tele,
			ps->date[pos].addr);
	}
}
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入你要修改人的名字\n");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("你要修改的人信息不存在\n");
	}
	else
	{
		printf("请输入要修改的名字：");
		scanf(" %s", ps->date[pos].name);
		printf("请输入要修改的年龄：");
		scanf(" %d", &ps->date[pos].age);
		printf("请输入要修改的性别：");
		scanf(" %s", ps->date[pos].sex);
		printf("请输入要修改的电话：");
		scanf("%s", ps->date[pos].tele);
		printf("请输入要修改的住址：");
		scanf("%s", ps->date[pos].addr);
		printf("修改成功\n");
	}
}
void FreeContact(struct Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}
