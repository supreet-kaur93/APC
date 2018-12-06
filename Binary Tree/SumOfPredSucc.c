// sum of predecessor and successor

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

void StoreInOrder(tree* root, int* arr, int* index) {
	if(root == NULL) {
		return;
	}
	StoreInOrder(root->right, arr, index);
	arr[*index] = root->data;
	(*index)++;
	StoreInOrder(root->left, arr,index);
}

void SetValue(tree* root, int* arr, int* index) {
	if(root == NULL) {
		return;
	}
	SetValue(root->left, arr, index);
	root->data = arr[*index -1] + arr[*index +1];
	(*index)++;
	SetValue(root->right, arr, index);
}

void SumOfPredSucc(tree* root) {
	int index = 0, i;
	int arr[10] = {0};
	arr[0] = 0;
	StoreInOrder(root, arr, &index);
	arr[index] = 0;
	index = 1;
	SetValue(root, arr, &index);
}

void display(tree* root) {
	if(root == NULL) {
		return;
	}
	display(root->left);
	printf("%d ", root->data);
	display(root->right);
}

void main() {
	tree* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(4);
	root->right->left = createNode(4);
	root->right->right = createNode(3);
    printf("Inorder Before Change\n");
    display(root);
	SumOfPredSucc(root);
	printf("\nInorder After Change\n");
	display(root);
}
