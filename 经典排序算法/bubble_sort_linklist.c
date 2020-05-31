#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct nums* next;
} LinkNode, *pLinkNode;

int main(void) {
    LinkNode* Head = NULL, *Tail = NULL, *p, *q;
    int n, temp;
    while (scanf("%d", &n) == 1) {
		p = (LinkNode*)malloc(sizeof(LinkNode));
		if (Head == NULL)
			Head = p;
		else
			Tail->next = p;
		p->num = n;
		p->next = NULL;
		Tail = p;
    }
    p = Head;
    while (p != NULL) {
		printf("%-3d", p->num);
		p = p->next;
	}
	printf("\n");
    for (p = Head; p->next != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->num > q->num) {
                temp = p->num;
                p->num = q->num;
                q->num = temp;
            }
        }
    }
    p = Head;
    while (p != NULL) {
		printf("%-3d", p->num);
		p = p->next;
	}
	printf("\n");
    return 0;
}