#include <stdio.h>
#include <stdlib.h>

typedef struct data{
	int num;
	struct data *next;
}Data;

int main(void)
{
	Data *head = NULL, *tail = NULL, *p;
	int n;
	while (scanf("%d", &n) == 1)
	{
		p = (Data *)malloc(sizeof(Data));
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		p->num = n;
		p->next = NULL;
		tail = p;
	}
	p = head;
	while (p != NULL)
	{
		printf("%-3d", p->num);
		p = p->next;
	}
	printf("\n");
	return 0;
}
