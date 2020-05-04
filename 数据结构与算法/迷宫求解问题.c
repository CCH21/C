/* 迷宫求解问题
 * 用一个m×n的矩阵表示迷宫，0和1分别表示迷宫中的通路和障碍。
 * 设计一个程序，对给定的迷宫，求出找到的第一条从入口到出口的通路，或得到没有通路的结论。
 * 我们指定：
 * 迷宫的入口为矩阵的左上角(1,1)，迷宫的出口为右下角(m,n);
 * 路径的探索顺序依次为“东南西北”（即：右下左上）。
 * 输入：
 * 第一行输入两个整数，空格间隔，分别表示矩阵的行数m和列数n；
 * 接下来的连续m行，输入迷宫矩阵的信息。
 * 输出：
 * 求得的通路以三元组(i,j,d)的形式输出。
 */

#include <stdio.h>
#include <stdlib.h>
#define N 16

typedef struct box {
    int i;                                                           /* 横坐标 */
    int j;                                                           /* 纵坐标 */
    int di;                                                          /* 方向 */
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

int Path(int xi, int yi, int xe, int ye);                            /* 求解从(xi,yi)到(xe,ye)的路径 */

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
    st.top = -1;                                                     /* 初始化栈 */
    st.top++;                                                        /* 初始方块入栈 */
    st.data[st.top].i = xi;
    st.data[st.top].j = yi;
    st.data[st.top].di = -1;
    while (st.top > -1) {
        i = st.data[st.top].i;
        j = st.data[st.top].j;
        di = st.data[st.top].di;                                     /* 取栈顶方块 */
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
            st.data[st.top].di = di;                                 /* 修改原栈顶元素的di值 */
            st.top++;                                                /* 下一个可走方块进栈 */
            st.data[st.top].i = i;
            st.data[st.top].j = j;
            st.data[st.top].di = -1;
            map[i][j] = 1;                                           /* 避免重复走到该方块 */
        }
        else {
            map[st.data[st.top].i][st.data[st.top].j] = 0;
            st.top--;                                                /* 将该方块退栈 */
        }
    }
    return 0;
}