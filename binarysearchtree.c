#include <stdio.h>
#include <stdlib.h>

struct BinaryTreeNode {
	int key;
	struct BinaryTreeNode *left, *right;
};

struct BinaryTreeNode* newNodeCreate(int value)
{
	struct BinaryTreeNode* temp
		= (struct BinaryTreeNode*)malloc(
			sizeof(struct BinaryTreeNode));
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}



struct BinaryTreeNode*
insertNode(struct BinaryTreeNode* node, int value)
{
	if (node == NULL) {
		return newNodeCreate(value);
	}
	if (value < node->key) {
		node->left = insertNode(node->left, value);
	}
	else if (value > node->key) {
		node->right = insertNode(node->right, value);
	}
	return node;
}

void postOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		postOrder(root->left);
		postOrder(root->right);
		printf(" %d ", root->key);
	}
}

void inOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		inOrder(root->left);
		printf(" %d ", root->key);
		inOrder(root->right);
	}
}

void preOrder(struct BinaryTreeNode* root)
{
	if (root != NULL) {
		printf(" %d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	struct BinaryTreeNode* root = NULL;

	root = insertNode(root, 50);
	insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 40);
	insertNode(root, 70);
	insertNode(root, 60);
	insertNode(root, 80);

	postOrder(root);
	printf("\n");

	preOrder(root);
	printf("\n");

	inOrder(root);
	printf("\n");


	return 0;
}
