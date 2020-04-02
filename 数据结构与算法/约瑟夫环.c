/* ���Ա�Ӧ��ʵ������Լɪ������
 * ���Ϊ1,2,��,n��n���˰�˳ʱ�뷽��Χ����һ��Բ����Χ��ÿ�˳���һ�����루����������
 * һ��ʼ��ѡһ����������Ϊ��������ֵm���ӵ�һ���˿�ʼ��˳ʱ�뷽����1��ʼ������
 * ����mʱֹͣ��������m���Ǹ��˳��У�������������Ϊ�µ�mֵ��
 * ����˳ʱ�뷽�����һ���˿�ʼ���´�1����������m���Ǹ����ֳ��У�
 * �����ȥ��ֱ��Բ����Χ����ȫ������Ϊֹ��*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct NodeType {
	int id;                                                               /* ��� */
	int password;                                                         /* ���� */
	struct NodeType* next;                                                /* ����ָ����һ������ָ�� */
} NodeType;

void CreaList(NodeType** ppHead, int n);                                  /* ��������ѭ������ */
NodeType* GetNode(int iId, int iPassword);                                /* �õ�һ����� */
void PrntList(NodeType* pHead);                                           /* ��ӡѭ������ */
int IsEmptyList(NodeType* pHead);                                         /* ���������Ƿ�Ϊ�� */
void JosephusOperate(NodeType** ppHead, int iPassword);                   /* ����Լɪ������ */

int main(void) {
	int n = 0, m = 0;
	NodeType* pHead = NULL;
	do {
		if (n > MAX)                                                      /* ����n��������������������� */
			printf("�������࣬���������룡\n");
		printf("����������n�����%d������", MAX);
		scanf("%d", &n);
	} while (n > MAX);
	printf("�������ʼ����m��");
	scanf("%d", &m);
	CreaList(&pHead, n);
	printf("\n------------��ӡѭ������------------\n");
	PrntList(pHead);
	printf("\n------------��ӡ�������------------\n");
	JosephusOperate(&pHead, m);
	return 1;
}

void CreaList(NodeType** ppHead, int n) {                                 /* ������n������ѭ������ppHead */
	int i = 0;
	int iPassword = 0;
	NodeType* pNew = NULL;
	NodeType* pCur = NULL;
	for (i = 1; i <= n; i++) {
		printf("�����%d���˵����룺", i);
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
	printf("��ɵ���ѭ������Ĵ�����\n");
}

NodeType* GetNode(int iId, int iPassword) {                               /* �����д��ͱ�ź����� */
	NodeType* pNew = NULL;
	pNew = (NodeType*)malloc(sizeof(NodeType));
	if (!pNew) {
		printf("Error, the memory is not enough!\n");
		exit(-1);
	}
	pNew->id = iId;
	pNew->password = iPassword;
	pNew->next = NULL;                                                    /* pNew��nextָ��NULL���ÿձ�β */
	return pNew;
}

void PrntList(NodeType* pHead) {                                          /* ���������n������������� */
	NodeType* pCur = pHead;
	if (!IsEmptyList(pHead)) {                                            /* ��pHead��ΪNULL��ִ�� */
		printf("--ID-- --PASSWORD--\n");
		do {
			printf("%3d %9d\n", pCur->id, pCur->password);
			pCur = pCur->next;                                            /* ��ָ�����pCur��Ϊָ���̽�� */
		} while (pCur != pHead);
	}
}

int IsEmptyList(NodeType* pHead) {
	if (!pHead) {                                                         /* ��pHeadΪNULL����1 */
		printf("The list is empty!\n");
		return 1;
	}
	return 0;                                                             /* ���򷵻�0 */
}

void JosephusOperate(NodeType** ppHead, int iPassword) {
	int iCounter = 0;
	int iFlag = 1;
	NodeType* pPrv = NULL;
	NodeType* pCur = NULL;
	NodeType* pDel = NULL;
	pPrv = pCur = *ppHead;
	while (pPrv->next != *ppHead)                                         /* ��pPrv��ʼΪָ��β��㣬Ϊɾ����׼�� */
		pPrv = pPrv->next;
	while (iFlag) {
		for (iCounter = 1; iCounter < iPassword; iCounter++) {
			pPrv = pCur;
			pCur = pCur->next;
		}
		if (pPrv == pCur)
			iFlag = 0;
		pDel = pCur;                                                      /* ɾ��pCurָ��Ľ�㣬�����˳��� */
		pPrv->next = pCur->next;                                          /* ʹpPrvָ����������һ��������� */
		pCur = pCur->next;                                                /* ָ��pCurָ���̽�㣬����һ����� */
		iPassword = pDel->password;                                       /* ��¼�����˵����� */
		printf("��%d���˳��У����룺%d��\n", pDel->id, pDel->password);
		free(pDel);                                                       /* �ͷŽ��ռ� */
	}
	*ppHead = NULL;
	getchar();
}