#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUEUESIZE 100

typedef struct person {
	char name[20];                               /* 姓名 */
	char sex[20];                                    /* 性别，M为男性，F为女性 */
} Person;

typedef struct queue{
	int front;
	int rear;
	int count;
	Person dancers[QUEUESIZE];
} CirQueue;

void InitQueue(CirQueue* q);                     /* 建立空队列 */
int isEmpty(CirQueue* q);                        /* 判断队列是否为空 */
void EnQueue(CirQueue* q, Person p);             /* 入队列 */
Person DeQueue(CirQueue* q);                     /* 出队列 */
Person QueueFront(CirQueue* q);                  /* 访问队列头元素 */
void Dance(Person dancers[], int num);           /* 舞伴配对 */

int main(void) {
	Person dancers[QUEUESIZE];
	int i, num;
	printf("请输入男女舞者的总人数：");
	scanf("%d", &num);
	printf("请输入姓名和性别：\n");
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
	printf("配对情况如下：\n");
	while (!isEmpty(&FDancers) && !isEmpty(&MDancers)) {
		p = DeQueue(&MDancers);
		printf("男：%s  ", p.name);
		p = DeQueue(&FDancers);
		printf("女：%s\n", p.name);
	}
	if (!isEmpty(&FDancers)) {
		printf("女队还有%d人在等待配对\n", FDancers.count);
		p = QueueFront(&FDancers);
		printf("女队第一个等待配对的是：%s\n", p.name);
	}
	else if (!isEmpty(&MDancers)) {
		printf("男队还有%d人在等待配对\n", MDancers.count);
		p = QueueFront(&MDancers);
		printf("男队第一个等待配对的是：%s\n", p.name);
	}
	else
		printf("两队均无人在等待配对\n");
}