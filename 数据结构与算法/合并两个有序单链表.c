#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;

ListNode* Create(void);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
void Print(ListNode* head);

int main(void) {
    ListNode* Head1 = Create();
    ListNode* Head2 = Create();
    ListNode* Head = mergeTwoLists(Head1, Head2);
    Print(Head);
	return 0;
}

ListNode* Create(void) {
    ListNode* Head = (ListNode*)malloc(sizeof(ListNode)), * p, * r;
    int n;
    Head->next = NULL;
    r = Head;
    while (scanf("%d", &n) == 1 && n != -1) {
        p = (ListNode*)malloc(sizeof(ListNode));
        p->val = n;
        r->next = p;
        r = p;
        if (r != NULL)
            r->next = NULL;
    }
    return Head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* p1, * p2, * p, * head;
    p1 = l1;
    p2 = l2;
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    if (p1->val < p2->val) {
        head = p1;
        p1 = p1->next;
    }
    else {
        head = p2;
        p2 = p2->next;
    }
    p = head;
    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            p->next = p1;
            p = p1;
            p1 = p1->next;
        }
        else {
            p->next = p2;
            p = p2;
            p2 = p2->next;
        }
    }
    if (p1 != NULL)
        p->next = p1;
    else
        p->next = p2;
    head = head->next;
    return head;
}

void Print(ListNode* head) {
    ListNode* p = head->next;
    while (p != NULL) {
        printf("--%d", p->val);
        p = p->next;
    }
    printf("\n");
}