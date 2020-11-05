#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100005

/* 二叉链表结点 */
typedef struct Node {
    char data;              /* 二叉链表的结点信息 */
    struct Node* LChild;    /* 结点的左子树 */
    struct Node* RChild;    /* 结点的右子树 */
} BiTNode, * BiTree;

/* 栈结构 */
typedef struct elem {
    BiTNode node;    /* 栈中元素的结点信息 */
    int flag;        /* 标记位，进左子树为0，进右子树为1 */
} ElemType;

typedef struct stack {
    ElemType elem[MAXSIZE];    /* 顺序栈数组 */
    int top;                   /* 栈顶指针 */
} SeqStack;

/* 自定义函数声明 */
BiTNode* CreateBiTree(BiTNode* root);    /* 扩展先序序列建立二叉树 */
void PreOrder(BiTree root);              /* 递归先序遍历二叉树 */
void InOrder(BiTree root);               /* 递归中序遍历二叉树 */
void PostOrder(BiTree root);             /* 非递归后序遍历二叉树 */
SeqStack* InitStack(void);               /* 初始化栈 */
int Empty(SeqStack* s);                  /* 判空栈 */
int Push(SeqStack* s, ElemType x);       /* 入栈 */
int Pop(SeqStack* s);                    /* 出栈 */
ElemType* GetTop(SeqStack* s);           /* 取栈顶元素 */
int NonLeafNode(BiTree root);            /* 统计二叉树中非叶子结点的个数 */
int BiTreeDeepth(BiTree root);           /* 计算二叉树的高度 */

/* 主函数 */
int main(void) {
    BiTNode* root = CreateBiTree(root);
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("\n");
    PostOrder(root);
    printf("\n");
    printf("%d\n", NonLeafNode(root));
    printf("%d\n", BiTreeDeepth(root));
    return 0;
}

/* 自定义函数 */
BiTNode* CreateBiTree(BiTNode* root) {
    char ch;
    ch = getchar();
    if (ch == '#') {
        return NULL;
    } else {
        root = (BiTNode*)malloc(sizeof(BiTNode));
        root->data = ch;
        root->LChild = CreateBiTree(root->LChild);
        root->RChild = CreateBiTree(root->RChild);
    }
    return root;
}

void PreOrder(BiTree root) {
    if (root) {
        printf("%c", root->data);
        PreOrder(root->LChild);
        PreOrder(root->RChild);
    }
}

void InOrder(BiTree root) {
    if (root) {
        InOrder(root->LChild);
        printf("%c", root->data);
        InOrder(root->RChild);
    }
}

void PostOrder(BiTree root) {
    SeqStack* s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    while (root || !Empty(s)) {
        while (root) {
            ElemType temp;
            temp.node = * root;
            temp.flag = 0;
            Push(s, temp);
            root = root->LChild;
        }
        while(!Empty(s) && GetTop(s)->flag == 1) {
            printf("%c", GetTop(s)->node.data);
            Pop(s);
        }
        if (!Empty(s)) {
            root = GetTop(s)->node.RChild;
            GetTop(s)->flag = 1;
        }
    }
}

SeqStack* InitStack(void) {
    SeqStack* s;
    s = (SeqStack*)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int Empty(SeqStack* s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

int Push(SeqStack* s, ElemType x) {
    if (s->top == MAXSIZE - 1) {
        return 0;    /* 栈满不能入栈 */
    } else {
        s->top++;
        s->elem[s->top] = x;
        return 1;
    }
}

int Pop(SeqStack* s) {
    if (Empty(s)) {
        return 0;    /* 栈空不能出栈 */
    } else {
        s->top--;
        return 1;
    }
}

ElemType* GetTop(SeqStack* s) {
    if (Empty(s)) {
        return NULL;    /* 栈空 */
    } else {
        return &(s->elem[s->top]);
    }
}

int NonLeafNode(BiTree root) {
    if (!root) {
        return 0;
    } else if (!root->LChild && !root->RChild) {
        return 0;
    } else {
        return NonLeafNode(root->LChild) + NonLeafNode(root->RChild) + 1;
    }
}

int BiTreeDeepth(BiTree root) {
    if (!root) {
        return 0;
    } else {
        if (BiTreeDeepth(root->LChild) > BiTreeDeepth(root->RChild)) {
            return 1 + BiTreeDeepth(root->LChild);
        } else {
            return 1 + BiTreeDeepth(root->RChild);
        }
    }
}