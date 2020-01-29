#include <stdio.h>
#include <stdlib.h>

void fun(char *s);
int main(void)
{
	char s[10000];
	scanf("%s", &s);
	fun(s);
	return 0;
}

void fun(char *s)
{
	char *stack = (char *)malloc(sizeof(char) * 10000);
	int stack_size = 0;
	int index = 0;
	while (*(s + index) != '\0')
	{
		char c = *(s + index);
		if (c == '(' || c == '[' || c == '{')
			stack[stack_size++] = c;
		else if (c == ')' || c == ']' || c == '}')
		{
			if (stack_size > 0)
			{
				if ((c == ')' && stack[stack_size - 1] != '(') || (c == '}' && stack[stack_size - 1] != '{') || (c == ']' && stack[stack_size - 1] != '['))
				{
					printf("False\n");
					return;
				}
				else
					stack_size--;
			}
			else
			{
				printf("False\n");
				return;
			}
		}
		index++;
	}
	if (stack_size > 0)
	{
		printf("False\n");
		return;
	}
	printf("True\n");
}
