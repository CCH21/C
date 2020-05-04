/* �Թ��������
 * ��һ��m��n�ľ����ʾ�Թ���0��1�ֱ��ʾ�Թ��е�ͨ·���ϰ���
 * ���һ�����򣬶Ը������Թ�������ҵ��ĵ�һ������ڵ����ڵ�ͨ·����õ�û��ͨ·�Ľ��ۡ�
 * ����ָ����
 * �Թ������Ϊ��������Ͻ�(1,1)���Թ��ĳ���Ϊ���½�(m,n);
 * ·����̽��˳������Ϊ�������������������������ϣ���
 * ���룺
 * ��һ�����������������ո������ֱ��ʾ���������m������n��
 * ������������m�У������Թ��������Ϣ��
 * �����
 * ��õ�ͨ·����Ԫ��(i,j,d)����ʽ�����
 */

#include <stdio.h>
#include <stdlib.h>
#define N 16

typedef struct box {
    int i;                                                           /* ������ */
    int j;                                                           /* ������ */
    int di;                                                          /* ���� */
} Box;

typedef struct stack {
    Box data[256];
    int top;
} Stack;

int m, n;
int map[N][N] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
Stack st;

int Path(int xi, int yi, int xe, int ye);                            /* ����(xi,yi)��(xe,ye)��·�� */

int main(void) {
    int a, b;
    scanf("%d %d", &m, &n);
    char* row = (char*)malloc((n + 1) * sizeof(char));
    for (a = 1; a <= m; a++) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        scanf("%s", row);
        for (b = 1; b <= n; b++)
            map[a][b] = row[b - 1] - '0';
    }
    Path(1, 1, m, n);
    return 0;
}

int Path(int xi, int yi, int xe, int ye) {
    int i, j, k, di, find;
    Stack st;
    st.top = -1;                                                     /* ��ʼ��ջ */
    st.top++;                                                        /* ��ʼ������ջ */
    st.data[st.top].i = xi;
    st.data[st.top].j = yi;
    st.data[st.top].di = -1;
    while (st.top > -1) {
        i = st.data[st.top].i;
        j = st.data[st.top].j;
        di = st.data[st.top].di;                                     /* ȡջ������ */
        if (i == xe && j == ye) {
            for (k = 0; k <= st.top; k++) {
                printf("(%d,%d,%d)", st.data[k].i, st.data[k].j, st.data[k].di + 1);
            }
            printf("\n");
            return 1;
        }
        find = 0;
        while (di < 4 && find == 0) {
            di++;
            switch (di) {
            case 0:
                i = st.data[st.top].i;
                j = st.data[st.top].j + 1;
                break;
            case 1:
                i = st.data[st.top].i + 1;
                j = st.data[st.top].j;
                break;
            case 2:
                i = st.data[st.top].i;
                j = st.data[st.top].j - 1;
                break;
            case 3:
                i = st.data[st.top].i - 1;
                j = st.data[st.top].j;
                break;
            }
            if (map[i][j] == 0)
                find = 1;
        }
        if (find == 1) {
            st.data[st.top].di = di;                                 /* �޸�ԭջ��Ԫ�ص�diֵ */
            st.top++;                                                /* ��һ�����߷����ջ */
            st.data[st.top].i = i;
            st.data[st.top].j = j;
            st.data[st.top].di = -1;
            map[i][j] = 1;                                           /* �����ظ��ߵ��÷��� */
        }
        else {
            map[st.data[st.top].i][st.data[st.top].j] = 0;
            st.top--;                                                /* ���÷�����ջ */
        }
    }
    return 0;
}