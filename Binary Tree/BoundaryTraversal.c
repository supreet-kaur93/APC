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

void printLeft(tree* root) {
	if(root == NULL) {
		return;
	}
	if(root->left != NULL) {
		printf("%d ",root->data);
		printLeft(root->left);
	}
	else if(root->right != NULL) {
		printf("%d ",root->data);
		printLeft(root->right);
	}
}

void printRight(tree* root) {
	if(root ==NULL) {
		return;
	}
	if(root->right != NULL) {
		printRight(root->right);
		printf("%d ",root->data);
	}
	else if(root->left != NULL) {
		printRight(root->left);
		printf("%d ",root->data);
	}
}

void printLeaves(tree* root) {
	if(root == NULL) {
		return;
	}
	printLeaves(root->left);
	if(!root->left && !root->right) {
		printf("%d ",root->data);
	}
	printLeaves(root->right);
}

void BoundaryTraversal(tree* root) {
	if(root == 	NULL) {
		return;
	}
	printf("%d ",root->data);
	printLeft(root->left);
	printLeaves(root->left);
	printLeaves(root->right);
	printRight(root->right);
}

void main() {
	tree* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(7);
	root->left->right = createNode(6);
	root->right->left = createNode(5);
	root->right->right = createNode(4);
	BoundaryTraversal(root);
}
