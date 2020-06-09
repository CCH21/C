#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node* next;
} Node;

struct node* reverse(struct node* pHead);

int main(void) {
    Node* head = NULL, *tail = NULL, *p;
    int n;
    while (scanf("%d", &n) == 1 && n != -1) {
        p = (Node*)malloc(sizeof(Node));
        if (head == NULL) {
            head = p;
        } else {
            tail->next = p;
        }
        p->num = n;
        p->next = NULL;
        tail = p;
    }
    p = head;
    while (p != NULL) {
        printf("--%d", p->num);
        p = p->next;
    }
    printf("\n");
    p = reverse(head);
    while (p != NULL) {
        printf("--%d", p->num);
        p = p->next;
    }
    printf("\n");
    return 0;
}

struct node* reverse(struct node* pHead) {
    struct node* p, *q, *t;
    q = pHead;
    p = q->next;
    q->next = NULL;
    while (t != NULL) {
        t = p->next;
        p->next = q;
        q = p;
        if (t != NULL)
            p = t;
    }
    return p;
}