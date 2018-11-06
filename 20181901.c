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

	printf("--그대로 출력--\n");
	printf("이름		생년월일		성별		주소					전화번호\n");
	for (int i = 0; i<10; i++)
		Print_Data(&person[i]);

	printf("\n");

	printf("--이름순--\n");
	printf("이름		생년월일		성별		주소					전화번호\n");
	for (int i = 0; i<10; i++)
		Print_Data(&person[i]);

	for (int i = 0; i < 9; i++)
		for (int j = i; j >= 0; j--)
			Sort_by_age(person + j, person + (j + 1));

	printf("\n");

	printf("--나이순--\n");
	printf("이름		생년월일		성별		주소					전화번호\n");
	for (int i = 0; i<10; i++)
		Print_Data(&person[i]);

	return 0;
}

void Input_Data(Report * person, int i)
{

	printf("		--%d번째 사람의 개인명세서 입력--		\n", i + 1);
	printf("이름: ");				scanf("%s", &(person->name));
	printf("생년월일(연도): ");		scanf("%d", &(person->year));
	printf("생년월일(달): ");		scanf("%d", &(person->month));
	printf("생년월일(날짜): ");		scanf("%d", &(person->day));
	printf("성별(남/여): ");		scanf("%s", &(person->sex));
	printf("주소: ");				scanf("%s", &(person->address));
	printf("전화번호: ");			scanf("%s", &(person->phonenum));
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