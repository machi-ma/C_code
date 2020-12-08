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
	else//��ͨѶ¼�ļ��������ļ���
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
		//��ʼ��ʱ���ļ�������ݶ���ͨѶ¼��
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
		ps->size = 0;//�Ѵ���Ŀ
		ps->capacity = CAPACITY_SZ;//��ʼ����
	}
	LoadContact(ps);//�����ļ��е�����
	
	/*memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;*/
}
//�ж��Ƿ���Ҫ����
 void CheckCapacity(struct Contact* ps)
{
	if ((ps->size) == (ps->capacity))//�ж��Ƿ���Ҫ����
	{
		//����
		PerInfo* pos = (PerInfo*)realloc(ps->date, (CAPACITY_SZ * 2)*sizeof(PerInfo));
		if (pos != NULL)
		{
			printf("���ݳɹ�\n");
			ps->date = pos;
			ps->capacity = CAPACITY_SZ * 2;
		}
		else
		{
			printf("����ʧ��\n");
		}
		
	}
}
void AddContact(struct Contact* ps)//���Ӻ���
{
	CheckCapacity(ps);//�ж��Ƿ���Ҫ����
	printf("���������֣�");
	scanf(" %s", ps->date[ps->size].name);
	printf("���������䣺");
	scanf(" %d", &ps->date[ps->size].age);
	printf("�������Ա�");
	scanf(" %s", ps->date[ps->size].sex);
	printf("������绰��");
	scanf("%s", ps->date[ps->size].tele);
	printf("������סַ��");
	scanf("%s", ps->date[ps->size].addr);
	printf("��ӳɹ�\n");
	ps->size++;

	/*if (ps->size == MAX)
	{
		printf("�ռ�����,���ʧ��\n");
	}
	else
	{
		printf("���������֣�" );
		scanf(" %s", ps->date[ps->size].name);
		printf("���������䣺");
		scanf(" %d",& ps->date[ps->size].age);
		printf("�������Ա�");
		scanf(" %s", ps->date[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->date[ps->size].tele);
		printf("������סַ��");
		scanf("%s", ps->date[ps->size].addr);
		printf("��ӳɹ�\n");
		ps->size++;
	}
	*/
	
}
void PrintContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-20s\t%sd\t%-5s\t%-12s\t%-30s\n",
			"����", "����", "�Ա�", "�绰����", "סַ");
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
//Ѱ�����ֶ�Ӧ�±�ĺ���
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
	printf("��������Ҫɾ�����֣�>");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("��Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}
void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ���ҵ�������:>");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("��Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("���ҳɹ�\n");
		printf("%-20s\t%-5s\t%-4s\t%-12s\t%-30s\n",
			"����", "����", "�Ա�", "�绰����", "סַ");
		printf("%-20s\t%-5d\t%-4s\t%-12s\t%-30s\n",
			ps->date[pos].name, ps->date[pos].age,
			ps->date[pos].sex, ps->date[pos].tele,
			ps->date[pos].addr);
	}
}
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("��������Ҫ�޸��˵�����\n");
	scanf("%s", name);
	int pos = FindContact(ps, name);
	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ�����Ϣ������\n");
	}
	else
	{
		printf("������Ҫ�޸ĵ����֣�");
		scanf(" %s", ps->date[pos].name);
		printf("������Ҫ�޸ĵ����䣺");
		scanf(" %d", &ps->date[pos].age);
		printf("������Ҫ�޸ĵ��Ա�");
		scanf(" %s", ps->date[pos].sex);
		printf("������Ҫ�޸ĵĵ绰��");
		scanf("%s", ps->date[pos].tele);
		printf("������Ҫ�޸ĵ�סַ��");
		scanf("%s", ps->date[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}
void FreeContact(struct Contact* ps)
{
	free(ps->date);
	ps->date = NULL;
}
