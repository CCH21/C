/* ��Ŀ����1Ԫֽ�Ҷһ���1�֡�2�֡�5�ֵ�Ӳ�ҹ�60ö�����г����жһ����� */
#include <stdio.h>
int main (void)
{
	int i = 0; 
	int one, two, five; 
	for (one = 0; one <= 60; one++)
	{
		for (two = 0; two <= 50; two++)
		{
			for (five = 0; five <= 20; five++)
			{
				if ((one * 1 + two * 2 + five * 5 == 100) && (one + two + five == 60))
				{
					i++; 
					printf ("�һ�����%2d��1��Ӳ��%2dö��2��Ӳ��%2dö��5��Ӳ��%2dö\n", i, one, two, five); 
				}
			}
		}
	}
	printf ("����%d�ֶһ�����\n", i); 
	return 0; 
}
