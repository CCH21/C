/* ���ݽṹ���㷨 ���� �Թ����� ���� ջ */

#include <stdio.h>

int map[10][10] = {                              /* ��ͼ��1Ϊ�ϰ��0Ϊͨ�� */
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int M = 8, N = 8;                                /* ���������� */

typedef struct box {
    int i;                                       /* ��ǰ�� */
    int j;                                       /* ��ǰ�� */
    int di;                                      /* ��һ�����ߵ�λ�õķ�λ�� */
} Box;

typedef struct stack {
    Box data[100];
    int top;
} Stack;

int Path(int xi, int yi, int xe, int ye);        /* ����(xi,yi)��(xe,ye)��·�� */

int main(void) {
    printf("�Թ����£�\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%-2d", map[i][j]);
        printf("\n");
    }
    printf("\n");
    if (!Path(1, 1, M, N))
        printf("�Թ��޽�\n");
    return 0;
}

int Path(int xi, int yi, int xe, int ye) {
    int i, j, k, di, find;
    Stack st;
    st.top = -1;                                 /* ��ʼ��ջ */
    st.top++;                                    /* ��ʼ������ջ */
    st.data[st.top].i = xi;
    st.data[st.top].j = yi;
    st.data[st.top].di = -1;
    while (st.top > -1) {
        i = st.data[st.top].i;
        j = st.data[st.top].j;
        di = st.data[st.top].di;                 /* ȡջ������ */
        if (i == xe && j == ye) {
            printf("�ҵ����ڣ�·�����£�\n");
            for (k = 0; k <= st.top; k++) {
                printf("(%d,%d)\t", st.data[k].i, st.data[k].j);
                if ((k + 1) % 5 == 0)
                    printf("\n");
            }
            printf("\n");
            return 1;
        }
        find = 0;
        map[1][1] = 1;
        while (di < 4 && find == 0) {
            di++;
            switch (di) {
            case 0:
                i = st.data[st.top].i - 1;
                j = st.data[st.top].j;
                break;
            case 1:
                i = st.data[st.top].i;
                j = st.data[st.top].j + 1;
                break;
            case 2:
                i = st.data[st.top].i + 1;
                j = st.data[st.top].j;
                break;
            case 3:
                i = st.data[st.top].i;
                j = st.data[st.top].j - 1;
                break;
            }
            if (map[i][j] == 0)
                find = 1;
        }
        if (find == 1) {
            st.data[st.top].di = di;             /* �޸�ԭջ��Ԫ�ص�diֵ */
            st.top++;                            /* ��һ�����߷����ջ */
            st.data[st.top].i = i;
            st.data[st.top].j = j;
            st.data[st.top].di = -1;
            map[i][j] = 1;                       /* �����ظ��ߵ��÷��� */
        }
        else {
            map[st.data[st.top].i][st.data[st.top].j] = 0;
            st.top--;                            /* ���÷�����ջ */
        }
    }
    return 0;
}