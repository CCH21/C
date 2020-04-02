/* 线性表应用实例——约瑟夫环问题
 * 编号为1,2,…,n的n个人按顺时针方向围坐在一张圆桌周围，每人持有一个密码（正整数）。
 * 一开始任选一个正整数作为报数上限值m，从第一个人开始按顺时针方向自1开始报数。
 * 报到m时停止报数，报m的那个人出列，将他的密码作为新的m值，
 * 从他顺时针方向的下一个人开始重新从1报数，数到m的那个人又出列；
 * 如此下去，直至圆桌周围的人全部出列为止。*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct NodeType {
	int id;                                                               /* 编号 */
	int password;                                                         /* 密码 */
	struct NodeType* next;                                                /* 用于指向下一个结点的指针 */
} NodeType;

void CreaList(NodeType** ppHead, int n);                                  /* 创建单向循环链表 */
NodeType* GetNode(int iId, int iPassword);                                /* 得到一个结点 */
void PrntList(NodeType* pHead);                                           /* 打印循环链表 */
int IsEmptyList(NodeType* pHead);                                         /* 测试链表是否为空 */
void JosephusOperate(NodeType** ppHead, int iPassword);                   /* 运行约瑟夫环问题 */

int main(void) {
	int n = 0, m = 0;
	NodeType* pHead = NULL;
	do {
		if (n > MAX)                                                      /* 人数n超过最大人数需重新输入 */
			printf("人数过多，请重新输入！\n");
		printf("请输入人数n（最多%d个）：", MAX);
		scanf("%d", &n);
	} while (n > MAX);
	printf("请输入初始密码m：");
	scanf("%d", &m);
	CreaList(&pHead, n);
	printf("\n------------打印循环链表------------\n");
	PrntList(pHead);
	printf("\n------------打印出队情况------------\n");
	JosephusOperate(&pHead, m);
	return 1;
}

void CreaList(NodeType** ppHead, int n) {                                 /* 创建有n个结点的循环链表ppHead */
	int i = 0;
	int iPassword = 0;
	NodeType* pNew = NULL;
	NodeType* pCur = NULL;
	for (i = 1; i <= n; i++) {
		printf("输入第%d个人的密码：", i);
		scanf("%d", &iPassword);
		pNew = GetNode(i, iPassword);
		if (*ppHead == NULL) {
			*ppHead = pCur = pNew;
			pCur->next = *ppHead;
		}
		else {
			pNew->next = pCur->next;
			pCur->next = pNew;
			pCur = pNew;
		}
	}
	printf("完成单向循环链表的创建！\n");
}

NodeType* GetNode(int iId, int iPassword) {                               /* 向结点中传送编号和密码 */
	NodeType* pNew = NULL;
	pNew = (NodeType*)malloc(sizeof(NodeType));
	if (!pNew) {
		printf("Error, the memory is not enough!\n");
		exit(-1);
	}
	pNew->id = iId;
	pNew->password = iPassword;
	pNew->next = NULL;                                                    /* pNew的next指向NULL，置空表尾 */
	return pNew;
}

void PrntList(NodeType* pHead) {                                          /* 依次输出至n个人且输出密码 */
	NodeType* pCur = pHead;
	if (!IsEmptyList(pHead)) {                                            /* 若pHead不为NULL则执行 */
		printf("--ID-- --PASSWORD--\n");
		do {
			printf("%3d %9d\n", pCur->id, pCur->password);
			pCur = pCur->next;                                            /* 让指针变量pCur改为指向后继结点 */
		} while (pCur != pHead);
	}
}

int IsEmptyList(NodeType* pHead) {
	if (!pHead) {                                                         /* 若pHead为NULL返回1 */
		printf("The list is empty!\n");
		return 1;
	}
	return 0;                                                             /* 否则返回0 */
}

void JosephusOperate(NodeType** ppHead, int iPassword) {
	int iCounter = 0;
	int iFlag = 1;
	NodeType* pPrv = NULL;
	NodeType* pCur = NULL;
	NodeType* pDel = NULL;
	pPrv = pCur = *ppHead;
	while (pPrv->next != *ppHead)                                         /* 将pPrv初始为指向尾结点，为删除做准备 */
		pPrv = pPrv->next;
	while (iFlag) {
		for (iCounter = 1; iCounter < iPassword; iCounter++) {
			pPrv = pCur;
			pCur = pCur->next;
		}
		if (pPrv == pCur)
			iFlag = 0;
		pDel = pCur;                                                      /* 删除pCur指向的结点，即有人出列 */
		pPrv->next = pCur->next;                                          /* 使pPrv指向结点与下下一个结点相连 */
		pCur = pCur->next;                                                /* 指针pCur指向后继结点，后移一个结点 */
		iPassword = pDel->password;                                       /* 记录出列人的密码 */
		printf("第%d个人出列（密码：%d）\n", pDel->id, pDel->password);
		free(pDel);                                                       /* 释放结点空间 */
	}
	*ppHead = NULL;
	getchar();
}