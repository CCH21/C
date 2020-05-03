/* 数据结构与算法 —— 迷宫问题 —— 栈 */

#include <stdio.h>

int map[10][10] = {                              /* 地图，1为障碍物，0为通道 */
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
int M = 8, N = 8;                                /* 行数和列数 */

typedef struct box {
    int i;                                       /* 当前行 */
    int j;                                       /* 当前列 */
    int di;                                      /* 下一个可走的位置的方位号 */
} Box;

typedef struct stack {
    Box data[100];
    int top;
} Stack;

int Path(int xi, int yi, int xe, int ye);        /* 求解从(xi,yi)到(xe,ye)的路径 */

int main(void) {
    printf("迷宫如下：\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            printf("%-2d", map[i][j]);
        printf("\n");
    }
    printf("\n");
    if (!Path(1, 1, M, N))
        printf("迷宫无解\n");
    return 0;
}

int Path(int xi, int yi, int xe, int ye) {
    int i, j, k, di, find;
    Stack st;
    st.top = -1;                                 /* 初始化栈 */
    st.top++;                                    /* 初始方块入栈 */
    st.data[st.top].i = xi;
    st.data[st.top].j = yi;
    st.data[st.top].di = -1;
    while (st.top > -1) {
        i = st.data[st.top].i;
        j = st.data[st.top].j;
        di = st.data[st.top].di;                 /* 取栈顶方块 */
        if (i == xe && j == ye) {
            printf("找到出口，路径如下：\n");
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
            st.data[st.top].di = di;             /* 修改原栈顶元素的di值 */
            st.top++;                            /* 下一个可走方块进栈 */
            st.data[st.top].i = i;
            st.data[st.top].j = j;
            st.data[st.top].di = -1;
            map[i][j] = 1;                       /* 避免重复走到该方块 */
        }
        else {
            map[st.data[st.top].i][st.data[st.top].j] = 0;
            st.top--;                            /* 将该方块退栈 */
        }
    }
    return 0;
}