#include <stdio.h>
#include <stdlib.h> // malloc ����� ���� ��� �߰�

typedef struct TreeNode {
    int key;
    struct TreeNode* left, * right;
} TreeNode;
TreeNode* new_node(int item)
{
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
// ��ȯ�� Ž�� �Լ�
TreeNode* recursive_search(TreeNode* node, int key) {
    if (node == NULL) return NULL;
    if (key == node->key) return node;
    else if (key < node->key)
        return recursive_search(node->left, key);
    else
        return recursive_search(node->right, key);
}
// �ݺ��� Ž�� �Լ�
TreeNode* iterative_search(TreeNode* node, int key) {
    while (node != NULL) {
        if (key == node->key) return node;
        else if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}
TreeNode* insert_node(TreeNode* node, int key)
{
    // Ʈ���������̸���ο��带��ȯ�Ѵ�. 
    if (node == NULL) return new_node(key);
    // �׷����������ȯ������Ʈ������������. 
    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    // ����ȷ�Ʈ�����͸���ȯ�Ѵ�. 
    return node;
}

// ���� ��ȸ (Ʈ�� ���� Ȯ�ο�)
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

// ���� ���� ���� ������ ��� ã��
TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// ���� �Լ�
TreeNode* delete_node(TreeNode* root, int key) {
    if (root == NULL) return root;
    if (key < root->key)
        root->left = delete_node(root->left, key);
    else if (key > root->key)
        root->right = delete_node(root->right, key);
    else {
        // �ڽ��� �ϳ� �Ǵ� ���� ���
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        // �ڽ��� �� �� �ִ� ���
        TreeNode* temp = min_value_node(root->right);
        root->key = temp->key;
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

// ���� �Լ�
int main(void) {
    TreeNode* root = NULL;
    TreeNode* tmp = NULL;

    // ����
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("minimum node key = %d\n", min_value_node(root)->key);  // Test: find minimum key
    printf("\n\n");

    // Inorder traversal
    printf("BST(inorder):\n");
    inorder(root);
    printf("\n\n");

    // Recursive search
    if (recursive_search(root, 30) != NULL)
        printf("Recursive search: found - 30\n");
    else
        printf("Recursive search: not found - 60\n");

    // Iterative search
    if (iterative_search(root, 60) != NULL)
        printf("Iterative search: found - 60\n");
    else
        printf("Iterative search: not found - 60\n");

    // Deletion
    root = delete_node(root, 30);
    printf("\nDelete 30:\n");
    inorder(root);
    printf("\n");

    return 0;

}