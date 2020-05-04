#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUESIZE 100

typedef struct person {
	char name[20];                               /* ���� */
	char sex[20];                                    /* �Ա�MΪ���ԣ�FΪŮ�� */
} Person;

typedef struct queue{
	int front;
	int rear;
	int count;
	Person dancers[QUEUESIZE];
} CirQueue;

void InitQueue(CirQueue* q);                     /* �����ն��� */
int isEmpty(CirQueue* q);                        /* �ж϶����Ƿ�Ϊ�� */
void EnQueue(CirQueue* q, Person p);             /* ����� */
Person DeQueue(CirQueue* q);                     /* ������ */
Person QueueFront(CirQueue* q);                  /* ���ʶ���ͷԪ�� */
void Dance(Person dancers[], int num);           /* ������ */

int main(void) {
	Person dancers[QUEUESIZE];
	int i, num;
	printf("��������Ů���ߵ���������");
	scanf("%d", &num);
	printf("�������������Ա�\n");
	for (i = 0; i < num; i++) {
		scanf("%s", dancers[i].name);
		scanf("%s", dancers[i].sex);
	}
	Dance(dancers, num);
	return 0;
}

void InitQueue(CirQueue* q) {
	q->front = q->rear = 0;
	q->count = 0;
}

int isEmpty(CirQueue* q) {
	return q->count == 0;
}

void EnQueue(CirQueue* q, Person p) {
	q->count++;
	q->dancers[q->rear] = p;
	q->rear = q->rear + 1;
}

Person DeQueue(CirQueue* q) {
	Person p;
	if (!isEmpty(q)) {
		p = QueueFront(q);
		q->count--;
		q->front = q->front++;
		return p;
	}
	exit(1);
}

Person QueueFront(CirQueue* q) {
	return q->dancers[q->front];
}

void Dance(Person dancers[], int num) {
	int i;
	Person p;
	CirQueue MDancers, FDancers;
	InitQueue(&MDancers);
	InitQueue(&FDancers);
	for (i = 0; i < num; i++) {
		p = dancers[i];
		if (!strcmp(p.sex, "F"))
			EnQueue(&FDancers, p);
		else if (!strcmp(p.sex, "M"))
			EnQueue(&MDancers, p);
	}
	printf("���������£�\n");
	while (!isEmpty(&FDancers) && !isEmpty(&MDancers)) {
		p = DeQueue(&MDancers);
		printf("�У�%s  ", p.name);
		p = DeQueue(&FDancers);
		printf("Ů��%s\n", p.name);
	}
	if (!isEmpty(&FDancers)) {
		printf("Ů�ӻ���%d���ڵȴ����\n", FDancers.count);
		p = QueueFront(&FDancers);
		printf("Ů�ӵ�һ���ȴ���Ե��ǣ�%s\n", p.name);
	}
	else if (!isEmpty(&MDancers)) {
		printf("�жӻ���%d���ڵȴ����\n", MDancers.count);
		p = QueueFront(&MDancers);
		printf("�жӵ�һ���ȴ���Ե��ǣ�%s\n", p.name);
	}
	else
		printf("���Ӿ������ڵȴ����\n");
}