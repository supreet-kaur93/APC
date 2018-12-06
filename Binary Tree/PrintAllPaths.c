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

void RootToLeafPathUtil(tree* root, int* arr, int index) {
	if(root == NULL) {
		return;
	}
	arr[index] = root->data;
	if(root->left == NULL && root->right == NULL) {
		int i;
		for(i=0; i<=(index); i++) {
			printf("%d ",arr[i]);
		}
		printf("\n");
	}
	index++;
	RootToLeafPathUtil(root->left, arr, index);
	RootToLeafPathUtil(root->right, arr, index);
}

void RootToLeafPath(tree* root) {
	if(root == NULL) {
		return;
	}
	int arr[10]={0};
	int index = 0;
	RootToLeafPathUtil(root, arr, index);
}

void main() {
	tree* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(7);
	root->left->right = createNode(6);
	root->right->left = createNode(5);
	root->right->right = createNode(4);
	RootToLeafPath(root);
}
