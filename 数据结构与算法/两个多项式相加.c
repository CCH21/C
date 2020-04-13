#include <stdio.h>
#include <stdlib.h>

typedef struct Polynomial {
	float coef;                                                      /* 系数 */
	int expn;                                                        /* 指数 */
	struct Polynomial* next;                                         /* 指向下一个结点的指针 */
} Polynomial;
typedef struct Polynomial* Polyn;

Polyn CreatePoly(void);                                              /* 建立多项式 */
void PrintPolyn(Polyn P);                                            /* 输出多项式 */
Polyn AddPolyn(Polyn pa, Polyn pb);                                  /* 两个多项式相加 */
Polyn SubtractPolyn(Polyn pa, Polyn pb);                             /* 两个多项式相减 */

int main(void) {
	printf("请输入第一个多项式：\n");
	Polyn A = CreatePoly();
	printf("请输入第二个多项式：\n");
	Polyn B = CreatePoly();
	Polyn Add = AddPolyn(A, B);
	printf("两个多项式相加的结果为：\n");
	PrintPolyn(Add);
	Polyn Sub = SubtractPolyn(A, B);
	printf("两个多项式相减的结果为：\n");
	PrintPolyn(Sub);
	return 0;
}

Polyn CreatePoly(void) {
	Polynomial* head, * rear, * s;
	int c, e;
	head = (Polynomial*)malloc(sizeof(Polynomial));
	rear = head;
	scanf("%d, %d", &c, &e);
	while (c != 0) {
		s = (Polynomial*)malloc(sizeof(Polynomial));
		s->coef = c;
		s->expn = e;
		rear->next = s;
		rear = s;
		scanf("%d, %d", &c, &e);
	}
	rear->next = NULL;
	return head;
}

void PrintPolyn(Polyn P) {
	Polyn q = P->next;
	int flag = 1;
	if (!q) {
		putchar('0');
		printf("\n");
		return;
	}
	while (q) {
		if (q->coef > 0 && flag != 1)
			putchar('+');
		if (q->coef != 1 && q->coef != -1) {
			printf("%g", q->coef);
			if (q->expn == 1)
				putchar('X');
			else if (q->expn)
				printf("X^%d", q->expn);
		}
		else {
			if (q->coef == 1) {
				if (!q->expn)
					putchar('1');
				else if (q->expn == 1)
					putchar('X');
				else
					printf("X^%d", q->expn);
			}
			if (q->coef == -1) {
				if (!q->expn)
					putchar('-1');
				else if (q->expn == 1)
					putchar('-X');
				else
					printf("-X^%d", q->expn);
			}
		}
		q = q->next;
		flag++;
	}
	printf("\n");
}

Polyn AddPolyn(Polyn pa, Polyn pb) {
	Polyn qa = pa->next;
	Polyn qb = pb->next;
	Polyn headc, pc, qc;
	pc = (Polyn)malloc(sizeof(struct Polynomial));
	pc->next = NULL;
	headc = pc;
	while (qa != NULL && qb != NULL) {
		qc = (Polyn)malloc(sizeof(struct Polynomial));
		if (qa->expn < qb->expn) {
			qc->coef = qa->coef;
			qc->expn = qa->expn;
			qa = qa->next;
		}
		else if (qa->expn == qb->expn) {
			qc->coef = qa->coef + qb->coef;
			qc->expn = qa->expn;
			qa = qa->next;
			qb = qb->next;
		}
		else {
			qc->coef = qb->coef;
			qc->expn = qb->expn;
			qb = qb->next;
		}
		if (qc->coef != 0) {
			qc->next = pc->next;
			pc->next = qc;
			pc = qc;
		}
		else
			free(qc);
	}
	while (qa != NULL) {
		qc = (Polyn)malloc(sizeof(struct Polynomial));
		qc->coef = qa->coef;
		qc->expn = qa->expn;
		qa = qa->next;
		qc->next = pc->next;
		pc->next = qc;
		pc = qc;
	}
	while (qb != NULL) {
		qc = (Polyn)malloc(sizeof(struct Polynomial));
		qc->coef = qb->coef;
		qc->expn = qb->expn;
		qb = qb->next;
		qc->next = pc->next;
		pc->next = qc;
		pc = qc;
	}
	return headc;
}

Polyn SubtractPolyn(Polyn pa, Polyn pb) {
	Polyn h = pb;
	Polyn p = pb->next;
	Polyn pd;
	while (p) {
		p->coef *= -1;
		p = p->next;
	}
	pd = AddPolyn(pa, h);
	for (p = h->next; p; p = p->next)
		p->coef *= -1;
	return pd;
}