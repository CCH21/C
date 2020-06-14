#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node* next;
} LinkNode;

LinkNode* Create(void);
void Print(LinkNode* Head);
void Bubblesort(LinkNode *head);

int main(void) {
    LinkNode* Head, *p, *q, *temp;
    Head = Create();
    Print(Head);
    Bubblesort(Head);
    Print(Head);
    return 0;
}

LinkNode* Create(void) {
    LinkNode* Head = (LinkNode*)malloc(sizeof(LinkNode)), *p, *r;
    int n;
    Head->next = NULL;
    r = Head;
    while (scanf("%d", &n) == 1) {
		p = (LinkNode*)malloc(sizeof(LinkNode));
        p->num = n;
        r->next = p;
        r = p;
        if (r != NULL)
            r->next = NULL;
    }
    return Head;
}

void Print(LinkNode* Head) {
    LinkNode* p = Head->next;
    while (p != NULL) {
		printf("%-3d", p->num);
		p = p->next;
	}
    printf("\n");
}

void Bubblesort(LinkNode *head) {
    LinkNode* cur = head, *tail = head, *p = head, *curNext = NULL;
    int node = 0;
    int flag = 0;
    while (tail != NULL)
        tail = tail->next;
    while (p->next != tail) {
        flag = 0;
        cur = head;
        while (cur->next != tail) {
            curNext = cur->next;
            if (cur->num > curNext->num) {
                node = cur->num;
                cur->num = curNext->num;
                curNext->num = node;
                flag = 1;
            }
            cur = cur->next;
        }
        tail = cur;
        if (flag == 0)
            return;
    }
}