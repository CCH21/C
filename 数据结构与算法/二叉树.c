#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* Create(void);                                       /* ���������� */
void PreOrderTree(struct TreeNode* root);                            /* ǰ����������� */
void InOrderTree(struct TreeNode* root);                             /* ������������� */
void PostOrderTree(struct TreeNode* root);                           /* ������������� */
int MaxDepth(struct TreeNode* root);                                 /* �������������� */
int IsMirror(struct TreeNode* root1, struct TreeNode* root2);        /* �Ƿ�Ϊ�Գƶ����� */
void FreeTree(struct TreeNode* root);                                /* �������ٶ����� */

int main(void) {
	printf("������������ĸ���㣺");
	struct TreeNode* root = Create();
	printf("��������Ϊ��");
	PreOrderTree(root);
	printf("\n��������Ϊ��");
	InOrderTree(root);
	printf("\n��������Ϊ��");
	PostOrderTree(root);
	printf("\n�ö�������������Ϊ��%d\n", MaxDepth(root));
	if (IsMirror(root, root))
		printf("�ö������ǶԳƶ�����\n");
	else
		printf("�ö��������ǶԳƶ�����\n");
	FreeTree(root);
	return 0;
}

struct TreeNode* Create(void) {                                      /* ���������� */
	int val;
	scanf("%d", &val);
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (!root) {
		printf("����ʧ�ܣ�\n");
		return NULL;
	}
	if (val <= 0)
		return NULL;
	root->val = val;
	printf("������%d�����㣺", val);
	root->left = Create();
	printf("������%d���ҽ�㣺", val);
	root->right = Create();
	return root;
}

void PreOrderTree(struct TreeNode* root) {                           /* ǰ����������� */
	if (root == NULL)
		return;
	printf("%d ", root->val);
	PreOrderTree(root->left);
	PreOrderTree(root->right);
}

void InOrderTree(struct TreeNode* root) {                            /* ������������� */
	if (root == NULL)
		return;
	InOrderTree(root->left);
	printf("%d ", root->val);
	InOrderTree(root->right);
}

void PostOrderTree(struct TreeNode* root) {                          /* ������������� */
	if (root == NULL)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	printf("%d ", root->val);
}

int MaxDepth(struct TreeNode* root) {                                /* �������������� */
	if (root == NULL)
		return 0;
	else {
		int maxLeft = MaxDepth(root->left), maxRight = MaxDepth(root->right);
		if (maxLeft > maxRight)
			return 1 + maxLeft;
		else
			return 1 + maxRight;
	}
}

int IsMirror(struct TreeNode* root1, struct TreeNode* root2) {       /* �Ƿ�Ϊ�Գƶ����� */
	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 == NULL || root2 == NULL)
		return 0;
	return (root1->val == root2->val) && IsMirror(root1->left, root2->right) && IsMirror(root1->right, root2->left);
}

void FreeTree(struct TreeNode* root) {                               /* �������ٶ����� */
	if (!root)
		return;
	if (root->left) {
		FreeTree(root->left);
		root->left = NULL;
	}
	if (root->right) {
		FreeTree(root->right);
		root->right = NULL;
	}
	if (root) {
		free(root);
		root = NULL;
	}
}