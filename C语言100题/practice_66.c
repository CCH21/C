#include <stdio.h>

typedef struct student{
	char name[40];
	char sex[6];
	int age;
}Stu;

void input(Stu *stu);
void output(Stu *stu);
int main(void)
{
	Stu stu[5];
	printf("请输入5个学生的信息：\n");
	input(stu);
	printf("\n学生信息如下：\n");
	printf("姓名  性别  年龄\n");
	output(stu);
	return 0;
}

void input(Stu *stu)
{
	for (int i = 0; i < 5; i++)
		scanf("%s %s %d", stu[i].name, stu[i].sex, &stu[i].age);
}

void output(Stu *stu)
{
	for (int i = 0; i < 5; i++)
		printf("%s  %s  %d\n", stu[i].name, stu[i].sex, stu[i].age);
}
