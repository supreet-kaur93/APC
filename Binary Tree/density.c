#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	int data;
	struct Tree* left;
	struct Tree* right;
}tree;

tree* createNode(int data) {
	tree* nn = (tree*)malloc(sizeof(tree));
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

int max(int a, int b) {
	return (a>b?a:b);
}

int height(tree* root) {
	if(root == NULL) {
		return 0;
	}
	return 1+max(height(root->left), height(root->right));
}

int CountNodes(tree* root) {
	if(root == NULL) {
		return;
	}
	return 1+CountNodes(root->left)+CountNodes(root->right);
}

void Density(tree* root) {
	int ht = height(root);
	int nodes = CountNodes(root);
	printf("%d",nodes/ht);
}

void main() {
	tree* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(7);
	root->left->right = createNode(6);
	root->right->left = createNode(5);
	root->right->right = createNode(4);
	Density(root);
}
