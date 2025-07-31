#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int get_node_count(TreeNode* node)
{
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) +
		get_node_count(node->right);
	return count;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

int get_height(TreeNode* node)
{
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_leaf_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) +
			get_leaf_count(node->right);
	}
	return count;
}

int main(void)
{
	printf("노드의 개수: %d\n", get_node_count(root));
	printf("트리의 높이: %d\n", get_height(root));
	printf("단말 노드의 수: %d\n", get_leaf_count(root));

	return 0;
}