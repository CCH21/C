#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node* next;
} Node;

Node* reverse(Node* L);

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

Node* reverse(Node* L) {
    Node* p1=NULL,*p2=NULL;
  while (L)
  {
    p2=L->next;
    L->next=p1;
    p1=L;
    L=p2;
  }
  return p1;
}