#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* Create(void);                             /* ���������� */
void PreOrderTree(struct TreeNode* root);                  /* ǰ����������� */
void InOrderTree(struct TreeNode* root);                   /* ������������� */
void PostOrderTree(struct TreeNode* root);                 /* ������������� */
void FreeTree(struct TreeNode* root);                      /* �������ٶ����� */

int main(void) {
	printf("���������㣺");
	struct TreeNode* root = Create();
	printf("��������Ϊ��");
	PreOrderTree(root);
	printf("\n��������Ϊ��");
	InOrderTree(root);
	printf("\n��������Ϊ��");
	PostOrderTree(root);
	FreeTree(root);
	return 0;
}

struct TreeNode* Create(void) {                            /* ���������� */
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

void PreOrderTree(struct TreeNode* root) {                 /* ǰ����������� */
	if (root == NULL)
		return;
	printf("%d ", root->val);
	PreOrderTree(root->left);
	PreOrderTree(root->right);
}

void InOrderTree(struct TreeNode* root) {                  /* ������������� */
	if (root == NULL)
		return;
	InOrderTree(root->left);
	printf("%d ", root->val);
	InOrderTree(root->right);
}

void PostOrderTree(struct TreeNode* root) {                /* ������������� */
	if (root == NULL)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	printf("%d ", root->val);
}

void FreeTree(struct TreeNode* root) {                     /* �������ٶ����� */
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