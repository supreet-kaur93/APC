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

tree* ConstructTreeUtil(int* in, int* post, int* index, int l, int r) {
	if(l>r) {
		return NULL;
	}
	int i;
	tree* nn = createNode(post[*index]);
	for(i=l; i<=r; i++) {
		if(in[i] == post[*index]) {
			break;
		}
	}
	(*index)--;
	nn->right = ConstructTreeUtil(in, post, index, i+1, r);
	nn->left = ConstructTreeUtil(in, post, index, l, i-1);
	return nn;
}

void display(tree* root) {
	if(root == NULL) {
		return;
	}
	display(root->left);
	printf("%d ",root->data);
	display(root->right);
}

void ConstructTree(int* in, int* post, int n) {
	int index = n-1;
	tree* root = ConstructTreeUtil(in, post, &index, 0, n-1);
	display(root);
}

void main() {
	int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
	int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
	ConstructTree(in, post, 8);
}
