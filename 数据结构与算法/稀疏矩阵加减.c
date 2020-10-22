#include <stdio.h>
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
int cmp(Triple a, Triple b);
void addTSMatrix(TSMatrix* A, TSMatrix* B, TSMatrix* C);
void subTSMatrix(TSMatrix* A, TSMatrix* B, TSMatrix* C);

/* 主函数 */
int main(void) {
    TSMatrix A, B, C, D;
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
    addTSMatrix(&A, &B, &C);
    printf("%d %d %d\n", C.m, C.n, C.num);
    for (k = 1; k <= C.num; k++) {
        printf("(%d,%d,%d)", C.data[k].i, C.data[k].j, C.data[k].val);
    }
    printf("\n");
    subTSMatrix(&A, &B, &D);
    printf("%d %d %d\n", D.m, D.n, D.num);
    for (k = 1; k <= D.num; k++) {
        printf("(%d,%d,%d)", D.data[k].i, D.data[k].j, D.data[k].val);
    }
    printf("\n");
    return 0;
}

/* 自定义函数 */
int cmp(Triple a, Triple b) {
    /**
     * cmp()函数用于比较三元组a和b的相对位置
     * 若位置相同，则返回0
     * 若a在b的前面，则返回-1
     * 若b在a的前面，则返回1
     */
    if (a.i == b.i) {
        if (a.j == b.j) {
            return 0;
        } else if (a.j < b.j) {
            return -1;
        } else {
            return 1;
        }
    } else if (a.i < b.i) {
        return -1;
    } else {
        return 1;
    }
}

void addTSMatrix(TSMatrix* A, TSMatrix* B, TSMatrix* C) {
    /**
     * addTSMatrix()函数用于将稀疏矩阵A和B相加
     * 将A+B的结果保存在稀疏矩阵C中
     */
    int i, j;
    int p = 1, q = 1;
    C->num = 1;
    while (p <= A->num && q <= B->num) {
        if (cmp(A->data[p], B->data[q]) == -1) {
            C->data[C->num].i = A->data[p].i;
            C->data[C->num].j = A->data[p].j;
            C->data[C->num++].val = A->data[p].val;
            p++;
        }
        if (cmp(A->data[p], B->data[q]) == 1) {
            C->data[C->num].i = B->data[q].i;
            C->data[C->num].j = B->data[q].j;
            C->data[C->num++].val = B->data[q].val;
            q++;
        }
        if (cmp(A->data[p], B->data[q]) == 0) {
            if (A->data[p].val + B->data[q].val) {
                C->data[C->num].i = A->data[p].i;
                C->data[C->num].j = A->data[p].j;
                C->data[C->num++].val = A->data[p].val + B->data[q].val;
            }
            p++;
            q++;
        }
    }
    /* 合并剩余的三元组表 */
    C->m = A->m;
    C->n = A->n;
    while (p <= A->num) {
        C->data[C->num].i = A->data[p].i;
        C->data[C->num].j = A->data[p].j;
        C->data[C->num++].val = A->data[p].val;
        p++;
        C->m = A->m;
        C->n = A->n;
    }
    while (q <= B->num) {
        C->data[C->num].i = B->data[q].i;
        C->data[C->num].j = B->data[q].j;
        C->data[C->num++].val = B->data[q].val;
        q++;
        C->m = B->m;
        C->n = B->n;
    }
    C->num--;
}

void subTSMatrix(TSMatrix* A, TSMatrix* B, TSMatrix* C) {
    /**
     * subTSMatrix()函数用于将稀疏矩阵A和B相减
     * 将A-B的结果保存在稀疏矩阵C中
     * 主体思路为A-B=A+(-1)*B
     */
    int i;
    for (i = 1; i <= B->num; i++) {
        B->data[i].val *= -1;
    }
    /* 调用addTSMatrix()函数 */
    addTSMatrix(A, B, C);
}