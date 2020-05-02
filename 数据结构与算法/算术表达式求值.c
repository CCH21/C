#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 16

typedef struct stack {                            /* ����˳��ջ */
	int data[MAXSIZE];
	int top;
	int base;
} Seqstack;

Seqstack StackR, StackD;                         /* ��������ջ�ֱ���������Ͳ����� */

void InitStack(Seqstack* s);                     /* ��ʼ��ջ */
int isEmpty(Seqstack* s);                        /* �ж�ջ�Ƿ�Ϊ�� */
void Push(Seqstack* s, int x);                   /* ��ջ */
int Pop(Seqstack* s);                            /* ��ջ */
int GetTop(Seqstack* s);                         /* ȡջ��Ԫ�� */
int Operate(int a, char R, int b);               /* ����aRb������ֵ */
int In(char c);                                  /* �ж�c�Ƿ�Ϊ����� */
char Proceed(char op, char c);                   /* �Ƚ���������ȼ� */
int EvalExpres(void);                            /* �����ʽ */

int main(void) {
	int v;
	v = EvalExpres();
	printf("���Ϊ%d\n", v);
	return 0;
}

void InitStack(Seqstack* s) {
	s->top = 0;
	s->base = 0;
}

int isEmpty(Seqstack* s) {
	if (s->top == s->base)
		return 1;
	else
		return 0;
}

void Push(Seqstack* s, int x) {
	if (s->top == MAXSIZE) {
		printf("OVER FLOW!\n");
		exit(0);
	}
	else {
		s->data[s->top] = x;
		s->top++;
	}
}

int Pop(Seqstack* s) {
	int e;
	if (isEmpty(s)) {
		printf("UNDER FLOW!\n");
		return 0;
	}
	else {
		s->top--;
		e = s->data[s->top];
		return e;
	}
}

int GetTop(Seqstack* s) {
	if (isEmpty(s)) {
		printf("UNDER FLOW!\n");
		return 0;
	}
	else
		return s->data[s->top - 1];
}

int Operate(int a, char R, int b) {
	int s = 0, d1 = a, d2 = b;
	switch (R) {
	case '+':
		s = d1 + d2;
		break;
	case '-':
		s = d2 - d1;
		break;
	case '*':
		s = d1 * d2;
		break;
	case '/':
		if (d1 != 0)
			s = d2 / d1;
		else {
			printf("Error!\n");
			exit(0);
		}
	}
	return s + '0';
}

int In(char c) {
	char ch[7] = {'+', '-', '*', '/', '#', '(', ')'};
	int i;
	for (i = 0; i < 7; i++)
		if (c == ch[i])
			return 1;
	return 0;
}

char Proceed(char op, char c) {
	char ch = '0';
	if (op == '(' && c == ')' || op == '#' && c == '#')
		ch = '=';
	else
		if (op == '+' || op == '-')              /* ջ��Ԫ��Ϊ + �� - ��ʱ�� */
			switch (c) {
			case '+':
			case '-':
			case ')':
			case '#':
				ch = '>';
				break;
			case '*':
			case '/':
			case '(':
				ch = '<';
			}
		else
			if (op == '*' || op == '/')          /* ջ��Ԫ��Ϊ * �� / ��ʱ�� */
				switch (c) {
				case '+':
				case '-':
				case '*':
				case '/':
				case ')':
				case '#':
					ch = '>';
					break;
				case '(':
					ch = '<';
				}
			else
				if (op == '(')                   /* ջ��Ԫ��Ϊ ( ��ʱ�� */
					switch (c) {
					case '+':
					case '-':
					case '*':
					case '/':
					case '(':
						ch = '<';
						break;
					case '#':
						printf("Error!\n");
						exit(0);
					}
				else
					if (op == ')')               /* ջ��Ԫ��Ϊ ) ��ʱ�� */
						switch (c) {
						case '+':
						case '-':
						case '*':
						case '/':
						case '#':
							ch = '>';
							break;
						case '(':
							printf("Error!\n");
							exit(0);
						}
					else
						if (op == '#')           /* ջ��Ԫ��Ϊ # ��ʱ�� */
							switch (c) {
							case '+':
							case '-':
							case '*':
							case '/':
							case '(':
								ch = '<';
								break;
							case ')':
								printf("Error!\n");
								exit(0);
							}
	return ch;
}

int EvalExpres(void) {
	int a, b, i = 0, s = 0;
	char c[80] = {0}, r;
	InitStack(&StackR);
	Push(&StackR, '#');
	InitStack(&StackD);
	printf("��������ʽ���� # ������\n");
	gets(c);
	while (c[i] != '#' || GetTop(&StackR) != '#') {
		if (!In(c[i])) {
			if (c[i] >= '0' && c[i] <= '9') {
				s += c[i] - '0';
				while (!In(c[++i])) {
					s *= 10;
					s += c[i] - '0';
				}
				Push(&StackD, s + '0');
				s = 0;
			}
			else {
				printf("Error!\n");
				return 0;
			}
		}
		else
			switch (Proceed(GetTop(&StackR), c[i])) {
			case '<':                            /* ջ����Ԫ�����ȼ��� */
				Push(&StackR, c[i]);
				i++;
				break;
			case '=':                            /* ����ƥ���С����ʱ��ȥ�� */
				Pop(&StackR);
				i++;
				break;
			case '>':                            /* ջ�������ȼ������ջ�������д��ջ�� */
				r = Pop(&StackR);
				a = Pop(&StackD) - '0';
				b = Pop(&StackD) - '0';
				Push(&StackD, Operate(a, r, b));
				break;
			}
	}
	return GetTop(&StackD) - '0';
}