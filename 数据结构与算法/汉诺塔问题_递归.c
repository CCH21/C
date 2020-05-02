#include <stdio.h>

void hanoi(int n, char a, char b, char c);

int main(void) {
	int n;
	printf("请输入圆盘数量n：");
	scanf("%d", &n);
	printf("移动方法如下：\n");
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		printf("%c -> %c\n", a, c);
		return;
	}	
	else {
		hanoi(n - 1, a, c, b);
		printf("%c -> %c\n", a, c);
		hanoi(n - 1, b, a, c);
	}
}