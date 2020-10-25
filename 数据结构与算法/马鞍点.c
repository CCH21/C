/**
 * 求解马鞍点问题
 * 若矩阵A中某个元素A[i][j]是矩阵第i行中值最小的元素，
 * 同时又是第j列中值最大的元素，则称元素A[i][j]是矩阵中的一个马鞍点。
 * 设以二维数组存储矩阵，编写算法求矩阵A中的所有马鞍点。
 * 注意当最大值（最小值）并列相等时，会出现多鞍点的情况。
 * 第一行输入矩阵的总行数M和总列数N，以空格间隔。
 * 之后的M行，依次输入矩阵的各行数据，以空格间隔。
 * 若有马鞍点，则以行序为主序，依次输出各个马鞍点。
 * 每个马鞍点以(row,col,val)的形式输出，
 * 其中row代表马鞍点的行号，col代表马鞍点的列号，val代表马鞍点的值。
 * 若无马鞍点，则输出NONE。
 */
#include <stdio.h>
#include <stdlib.h>

/* 函数声明区 */
void SaddlePoint(int** matrix, int m, int n);

/* 主函数 */
int main(void) {
    int M, N;
    scanf("%d%d", &M, &N);
    int** A = (int**)calloc(M, sizeof(int));
    for (int i = 0; i < M; i++) {
        A[i] = (int*)calloc(N, sizeof(int));
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    SaddlePoint(A, M, N);
    return 0;
}

/* 自定义函数 */
void SaddlePoint(int** matrix, int m, int n) {
    /**
     * SaddlePoint()函数用于求解马鞍点问题
     * 得到的结果将以(row,col,val)的形式输出
     */
    int flag = 0;    /* 标志位，用于标记是否找到马鞍点，初始化为0 */
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int flag_row = 1, flag_col = 1;    /* 标志位，用于标记某元素是否为该行最小元素或该行最大元素，初始化为1 */
            for (int k = 0; k < n; k++) {
                if (matrix[i][j] > matrix[i][k]) {
                    /* 判断当前元素是否为该行最小元素，若不是则令flag_row = 0 */
                    flag_row = 0;
                }
            }
            for (int k = 0; k < m; k++) {
                if (matrix[i][j] < matrix[k][j]) {
                    /* 判断当前元素是否为该列最大元素，若不是则令flag_col = 0 */
                    flag_col = 0;
                }
            }
            if (flag_row && flag_col) {
                /* 元素同时满足该行最小且该列最大，该元素为马鞍点，输出马鞍点 */
                flag = 1;
                printf("(%d,%d,%d)", i + 1, j + 1, matrix[i][j]);
            }
        }
    }
    if (!flag) {
        /* 如果没有找到马鞍点，输出NONE */
        printf("NONE\n");
    } else {
        /* 如果找到马鞍点，此时已将所有马鞍点全部输出，再输出\n即可 */
        printf("\n");
    }
}