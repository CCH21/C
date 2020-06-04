#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* Create(void);                                       /* 创建二叉树 */
void PreOrderTree(struct TreeNode* root);                            /* 前序遍历二叉树 */
void InOrderTree(struct TreeNode* root);                             /* 中序遍历二叉树 */
void PostOrderTree(struct TreeNode* root);                           /* 后序遍历二叉树 */
int MaxDepth(struct TreeNode* root);                                 /* 二叉树的最大深度 */
int IsMirror(struct TreeNode* root1, struct TreeNode* root2);        /* 是否为对称二叉树 */
void FreeTree(struct TreeNode* root);                                /* 后序销毁二叉树 */

int main(void) {
	printf("请输入二叉树的根结点：");
	struct TreeNode* root = Create();
	printf("先序排列为：");
	PreOrderTree(root);
	printf("\n中序排列为：");
	InOrderTree(root);
	printf("\n后序排列为：");
	PostOrderTree(root);
	printf("\n该二叉树的最大深度为：%d\n", MaxDepth(root));
	if (IsMirror(root, root))
		printf("该二叉树是对称二叉树\n");
	else
		printf("该二叉树不是对称二叉树\n");
	FreeTree(root);
	return 0;
}

struct TreeNode* Create(void) {                                      /* 创建二叉树 */
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

void PreOrderTree(struct TreeNode* root) {                           /* 前序遍历二叉树 */
	if (root == NULL)
		return;
	printf("%d ", root->val);
	PreOrderTree(root->left);
	PreOrderTree(root->right);
}

void InOrderTree(struct TreeNode* root) {                            /* 中序遍历二叉树 */
	if (root == NULL)
		return;
	InOrderTree(root->left);
	printf("%d ", root->val);
	InOrderTree(root->right);
}

void PostOrderTree(struct TreeNode* root) {                          /* 后序遍历二叉树 */
	if (root == NULL)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	printf("%d ", root->val);
}

int MaxDepth(struct TreeNode* root) {                                /* 二叉树的最大深度 */
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

int IsMirror(struct TreeNode* root1, struct TreeNode* root2) {       /* 是否为对称二叉树 */
	if (root1 == NULL && root2 == NULL)
		return 1;
	if (root1 == NULL || root2 == NULL)
		return 0;
	return (root1->val == root2->val) && IsMirror(root1->left, root2->right) && IsMirror(root1->right, root2->left);
}

void FreeTree(struct TreeNode* root) {                               /* 后序销毁二叉树 */
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