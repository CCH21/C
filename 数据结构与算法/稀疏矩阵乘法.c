#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000

/* clear语句用于清空缓冲区 */
int ch;
#define clear while ((ch = getchar()) != EOF && ch != '\n');

/* 定义三元组 */
typedef struct {
    int i;        /* 行下标 */
    int j;        /* 列下标 */
    int val;      /* 矩阵元素的值 */
} Triple;

/* 定义稀疏矩阵的三元组表 */
typedef struct {
    Triple data[MAXSIZE + 1];
    int m;        /* 元素总行数 */
    int n;        /* 元素总列数 */
    int num;      /* 矩阵中非零元个数 */
} TSMatrix;

/* 函数声明区 */
int dotTSMatrix(TSMatrix* A, TSMatrix* B, int** ret);

/* 主函数 */
int main(void) {
    TSMatrix A, B;
    int k;
    scanf("%d%d%d", &A.m, &A.n, &A.num);
    clear;
    for (k = 1; k <= A.num; k++) {
        scanf("(%d,%d,%d)", &A.data[k].i, &A.data[k].j, &A.data[k].val);
    }
    clear;
    scanf("%d%d%d", &B.m, &B.n, &B.num);
    clear;
    for (k = 1; k <= B.num; k++) {
        scanf("(%d,%d,%d)", &B.data[k].i, &B.data[k].j, &B.data[k].val);
    }
    clear;
    /* 矩阵乘法 */
    int** res = (int**)calloc(A.m, sizeof(int));
    for (int i = 0; i < A.m; i++) {
        res[i] = (int*)calloc(B.n, sizeof(int));
    }
    int flag = dotTSMatrix(&A, &B, res);
    printf("------------------------------------------------------------\n");
    if (flag) {
        printf("The result is:\n");
        for (int i = 0; i < A.m; i++) {
            for (int j = 0; j < B.n; j++) {
                printf("%-4d", res[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Error: Matrix multiplication is not possible.\n");
    }
    return 0;
}

/* 自定义函数 */
int dotTSMatrix(TSMatrix* A, TSMatrix* B, int** ret) {
    /**
     * dotTSMatrix()函数用于将稀疏矩阵A和B相乘
     * 将AB的结果保存在二维数组ret中
     */
    /* 判断A和B是否满足矩阵乘法条件 */
    if (A->n != B->m) {
        return 0;
    }
    /* 动态分配数组A_arr, B_arr */
    int** A_arr = (int**)calloc(A->m, sizeof(int));
    for (int i = 0; i < A->m; i++) {
        A_arr[i] = (int*)calloc(A->n, sizeof(int));
    }
    int** B_arr = (int**)calloc(B->m, sizeof(int));
    for (int i = 0; i < B->m; i++) {
        B_arr[i] = (int*)calloc(B->n, sizeof(int));
    }
    /* 将稀疏矩阵的元素信息保存在二维数组中 */
    for (int i = 1; i <= A->num; i++) {
        A_arr[A->data[i].i - 1][A->data[i].j - 1] = A->data[i].val;
    }
    for (int i = 1; i <= B->num; i++) {
        B_arr[B->data[i].i - 1][B->data[i].j - 1] = B->data[i].val;
    }
    /* 利用矩阵乘法的运算法则进行计算，将结果存入ret中 */
    for (int i = 0; i < A->m; i++) {
        for (int j = 0; j < B->n; j++) {
            int s = 0;
            for (int k = 0; k < A->n; k++) {
                s += A_arr[i][k] * B_arr[k][j];
            }
            ret[i][j] = s;
        }
    }
    return 1;
}