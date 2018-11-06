#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct report
{
	char name[20];
	struct birth
	{
		int year;
		int month;
		int day;
	};
	char sex[3];
	char address[30];
	char phonenum[11];
}Report;

void Input_Data(Report * person, int i);
void Sort_by_name(Report*person1, Report * person2);
void Sort_by_age(Report*person1, Report*person2);
void Print_Data(Report * person);

int main()
{
	Report person[10];

	for (int i = 0; i<10; i++)
		Input_Data(person + i, i);

	for (int i = 0; i < 9; i++)
		for (int j = i; j >= 0; j--)
			Sort_by_name(person + j, person + (j + 1));

	printf("\n");

	printf("--�״�� ���--\n");
	printf("�̸�		�������		����		�ּ�					��ȭ��ȣ\n");
	for (int i = 0; i<10; i++)
		Print_Data(&person[i]);

	printf("\n");

	printf("--�̸���--\n");
	printf("�̸�		�������		����		�ּ�					��ȭ��ȣ\n");
	for (int i = 0; i<10; i++)
		Print_Data(&person[i]);

	for (int i = 0; i < 9; i++)
		for (int j = i; j >= 0; j--)
			Sort_by_age(person + j, person + (j + 1));

	printf("\n");

	printf("--���̼�--\n");
	printf("�̸�		�������		����		�ּ�					��ȭ��ȣ\n");
	for (int i = 0; i<10; i++)
		Print_Data(&person[i]);

	return 0;
}

void Input_Data(Report * person, int i)
{

	printf("		--%d��° ����� ���θ��� �Է�--		\n", i + 1);
	printf("�̸�: ");				scanf("%s", &(person->name));
	printf("�������(����): ");		scanf("%d", &(person->year));
	printf("�������(��): ");		scanf("%d", &(person->month));
	printf("�������(��¥): ");		scanf("%d", &(person->day));
	printf("����(��/��): ");		scanf("%s", &(person->sex));
	printf("�ּ�: ");				scanf("%s", &(person->address));
	printf("��ȭ��ȣ: ");			scanf("%s", &(person->phonenum));
}

void Sort_by_name(Report*person1, Report*person2)
{
	int cmp = strcmp(person1->name, person2->name);

	Report temp;

	if (cmp > 0)
	{
		temp = *person1;
		*person1 = *person2;
		*person2 = temp;
	}
}

void Sort_by_age(Report*person1, Report*person2)
{
	Report temp;

	if (person1->year > person2->year)
	{
		temp = *person1;
		*person1 = *person2;
		*person2 = temp;
	}
	if (person1->year == person2->year)
	{
		if (person1->month > person2->month)
		{
			temp = *person1;
			*person1 = *person2;
			*person2 = temp;
		}

	}
	if ((person1->year == person2->year) && (person1->month == person2->month))
	{
		if (person1->day > person2->day)
		{
			temp = *person1;
			*person1 = *person2;
			*person2 = temp;
		}
	}

}

void Print_Data(Report * person)
{

	printf("%s		", person->name);
	printf("%d-%d-%d		", person->year, person->month, person->day);
	printf("%s		", person->sex);
	printf("%s					", person->address);
	printf("%s", person->phonenum);

	printf("\n");
}