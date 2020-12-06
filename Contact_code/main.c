#include"Contect.h"
int main()
{//‘ˆº”£¨…æ≥˝£¨≤È’“£¨–ﬁ∏ƒ£¨≈≈–Ú£¨¥Ú”°
	struct Contact con;
	InitContact(&con);
	int input = 0;
	do
	{
		menu();
		printf("«Î—°‘Ò:>\n");
		scanf("%d", &input);
		int pos = 0;
		switch (input)
		{case ADDCONTACT:
			AddContact(&con);
			break;
		case DELCONTACT:
			DelContact(&con);
			break;
		case SEARCHCONTACT:
			SearchContact(&con);
			break;
		case MODIFYCONTACT:
			ModifyContact(&con);
			break;
		case PRINTCONTACT:
			PrintContact(&con);
			break;
		case SORTCONTACT:
			break;
		case EXITCONTACT:
			SaveContact(&con);
			FreeContact(&con);
			break;
		case SAVECONTACT:
			SaveContact(&con);
			break;
		default:
			printf(" ‰»Î¥ÌŒÛ\n");
			break;
		}
	} while (input);

	return 0;
}