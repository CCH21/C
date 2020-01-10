#include <stdio.h>

int main(void)
{
	int i;
	int nOne, nTwo, nFive;
	for (nOne = 1; nOne <= 100; nOne++)
		for (nTwo = 1; nTwo <= 50; nTwo++)
			for (nFive = 1; nFive <= 20; nFive++)
				if (nOne + 2 * nTwo + 5 * nFive == 100)
				{
					i++;
					printf("·½·¨%-3d£º1*%d+2*%d+5*%d=100\n", i, nOne, nTwo, nFive);
				}
	return 0;
}
