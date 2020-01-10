#include<stdio.h>

int main()
{
	long long int n, s = 0, t = 1;
	for (n = 1; n <= 20; n++)
	{
	    t *= n;
	    s += t;
	}
	printf("1+2!+3!+...+20!=%lld\n", s);
	return 0;
}
