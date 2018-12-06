#include<stdio.h>
#include<stdlib.h>

typedef struct Tree {
	char data;
	struct Tree* left;
	struct Tree* right;
}tree;

tree* createNode(char data) {
	tree* nn = (tree*)malloc(sizeof(tree));
	nn->data = data;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

tree* ConstructTreeUtil(char* in, char* pre, int* index, int l, int r) {
	if(l>r) {
		return NULL;
	}
	int i;
	tree* nn = createNode(pre[*index]);
	for(i=l; i<=r; i++) {
		if(in[i] == pre[*index]) {
			break;
		}
	}
	(*index)++;
	nn->left = ConstructTreeUtil(in, pre, index, l, i-1);
	nn->right = ConstructTreeUtil(in, pre, index, i+1, r);
	return nn;
}

void display(tree* root) {
	if(root == NULL) {
		return;
	}
	display(root->left);
	printf("%c ",root->data);
	display(root->right);
}

void ConstructTree(char* in, char* pre, int n) {
	int index = 0;
	tree* root = ConstructTreeUtil(in, pre, &index, 0, n-1);
	display(root);
}

void main() {
	//dbeafc
	//abdecf
	char in[] = "dbeafc";
	char pre[] = "abdecf";
	ConstructTree(in, pre, 6);
}
