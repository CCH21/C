#include <stdio.h>

int main(void)
{
	int year, month, day, s, flag;
	printf("�����������գ��м��ÿո�ָ���");
	scanf("%d %d %d", &year, &month, &day);
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		flag = 1;
	else
		flag = 0;
	switch(month)
	{
		case 1:
			s = 0;
			break;
		case 2:
			s = 31;
			break;
		case 3:
			s = 59;
			break;
		case 4:
			s = 90;
			break;
		case 5:
			s = 120;
			break;
		case 6:
			s = 151;
			break;
		case 7:
			s = 181;
			break;
		case 8:
			s = 212;
			break;
		case 9:
			s = 243;
			break;
		case 10:
			s = 273;
			break;
		case 11:
			s = 304;
			break;
		case 12:
			s = 334;
			break;
		default:
			printf("�������\n");
	}
	s += day;
	if (flag == 1 && month > 2)
		s++;
	printf("������һ��ĵ�%d��\n", s);
	return 0;
}
