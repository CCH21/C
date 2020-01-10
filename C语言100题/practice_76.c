#include <stdio.h>

int main(void)
{
	int num;
	for (num = 10; num < 100; num++)
		if (num * 809 == num * 800 + num * 9)
			if (8 * num < 100 && 8 * num >= 10)
				if (9 * num < 1000 && 9 * num >= 100)
					printf("%d\n%d\n", num, 809 * num);
	return 0;
}
