#include <stdio.h>
#define M 30

void MagicsquareInit(int MS[M][M], int m);
void Magicsquare(int MS[M][M], int m);
void MagicsquarePrint(int MS[M][M], int m);

int main(void) {
	int MS[M][M];
	int m;
	printf("������ħ�������m��mΪ������С��%d����", M);
	scanf("%d", &m);
	MagicsquareInit(MS, m);
	Magicsquare(MS, m);
	MagicsquarePrint(MS, m);
	return 0;
}

void MagicsquareInit(int MS[M][M], int m) {
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			MS[i][j] = 0;
}

void Magicsquare(int MS[M][M], int m) {
	int x = 0, y = m / 2, i;
	MS[x][y] = 1;                                /* ��0�е��м�λ����1 */
	for (i = 2; i <= m * m; i++) {
		x = (x - 1 + m) % m;                     /* ���Ͻǵ��к�ֵ */
		y = (y - 1 + m) % m;                     /* ���Ͻǵ��к�ֵ */
		if (MS[x][y] != 0) {                     /* �����λ���������������뵱ǰ�е���һ�� */
			x = (x + 2) % m;
			y = (y + 1) % m;
		}
		MS[x][y] = i;
	}
}

void MagicsquarePrint(int MS[M][M], int m) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++)
			printf("%4d", MS[i][j]);
		printf("\n");
	}
}