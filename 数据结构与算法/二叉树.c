#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* Create(void);                             /* 创建二叉树 */
void PreOrderTree(struct TreeNode* root);                  /* 前序遍历二叉树 */
void InOrderTree(struct TreeNode* root);                   /* 中序遍历二叉树 */
void PostOrderTree(struct TreeNode* root);                 /* 后序遍历二叉树 */
void FreeTree(struct TreeNode* root);                      /* 后序销毁二叉树 */

int main(void) {
	printf("请输入根结点：");
	struct TreeNode* root = Create();
	printf("先序排列为：");
	PreOrderTree(root);
	printf("\n中序排列为：");
	InOrderTree(root);
	printf("\n后序排列为：");
	PostOrderTree(root);
	FreeTree(root);
	return 0;
}

struct TreeNode* Create(void) {                            /* 创建二叉树 */
	int val;
	scanf("%d", &val);
	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	if (!root) {
		printf("创建失败！\n");
		return NULL;
	}
	if (val <= 0)
		return NULL;
	root->val = val;
	printf("请输入%d的左结点：", val);
	root->left = Create();
	printf("请输入%d的右结点：", val);
	root->right = Create();
	return root;
}

void PreOrderTree(struct TreeNode* root) {                 /* 前序遍历二叉树 */
	if (root == NULL)
		return;
	printf("%d ", root->val);
	PreOrderTree(root->left);
	PreOrderTree(root->right);
}

void InOrderTree(struct TreeNode* root) {                  /* 中序遍历二叉树 */
	if (root == NULL)
		return;
	InOrderTree(root->left);
	printf("%d ", root->val);
	InOrderTree(root->right);
}

void PostOrderTree(struct TreeNode* root) {                /* 后序遍历二叉树 */
	if (root == NULL)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	printf("%d ", root->val);
}

void FreeTree(struct TreeNode* root) {                     /* 后序销毁二叉树 */
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