#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 16

typedef struct stack {                            /* 定义顺序栈 */
	int data[MAXSIZE];
	int top;
	int base;
} Seqstack;

Seqstack StackR, StackD;                         /* 定义两个栈分别存放运算符和操作数 */

void InitStack(Seqstack* s);                     /* 初始化栈 */
int isEmpty(Seqstack* s);                        /* 判断栈是否为空 */
void Push(Seqstack* s, int x);                   /* 入栈 */
int Pop(Seqstack* s);                            /* 出栈 */
int GetTop(Seqstack* s);                         /* 取栈顶元素 */
int Operate(int a, char R, int b);               /* 返回aRb的运算值 */
int In(char c);                                  /* 判断c是否为运算符 */
char Proceed(char op, char c);                   /* 比较运算符优先级 */
int EvalExpres(void);                            /* 求解表达式 */

int main(void) {
	int v;
	v = EvalExpres();
	printf("结果为%d\n", v);
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
		if (op == '+' || op == '-')              /* 栈顶元素为 + 或 - 的时候 */
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
			if (op == '*' || op == '/')          /* 栈顶元素为 * 或 / 的时候 */
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
				if (op == '(')                   /* 栈顶元素为 ( 的时候 */
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
					if (op == ')')               /* 栈顶元素为 ) 的时候 */
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
						if (op == '#')           /* 栈顶元素为 # 的时候 */
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
	printf("请输入表达式并以 # 结束：\n");
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
			case '<':                            /* 栈顶的元素优先级高 */
				Push(&StackR, c[i]);
				i++;
				break;
			case '=':                            /* 遇到匹配的小括号时则去掉 */
				Pop(&StackR);
				i++;
				break;
			case '>':                            /* 栈顶的优先级低则出栈并将结果写入栈内 */
				r = Pop(&StackR);
				a = Pop(&StackD) - '0';
				b = Pop(&StackD) - '0';
				Push(&StackD, Operate(a, r, b));
				break;
			}
	}
	return GetTop(&StackD) - '0';
}