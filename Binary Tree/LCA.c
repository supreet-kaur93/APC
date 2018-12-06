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

int FindNode(tree* root, int data) {
	if(root == NULL) {
		return 0;
	}
	if(root->data == data) {
		return 1;
	}
	return (FindNode(root->left, data) || FindNode(root->right, data));
}

tree* LCAUtil(tree* root, int n1, int n2, int* v1, int* v2) {
	if(root == 	NULL) {
		return NULL;
	}
	if(root->data == n1) {
		*v1 =1;
		return root;
	}
	if(root->data == n2) {
		*v2 = 1;
		return root;
	}
	tree* ls = LCAUtil(root->left, n1, n2, v1, v2);
	tree* rs = LCAUtil(root->right, n1, n2, v1, v2);
	if(ls && rs) {
		return root;
	}
	if(!ls) {
		return rs;
	}
	else return ls;
}

void LCA(tree* root, int n1, int n2) {
	if(root == NULL) {
		return;
	}
	int v1 = 0;
	int v2 = 0;
	tree* lca = LCAUtil(root, n1, n2, &v1, &v2);
	if(v1 == 1 && v2 == 1) {
		printf("%d ",lca->data);
	}
	else if(v1 == 1 && FindNode(lca, n2) == 1) {
		printf("%d ",lca->data);
	}
	else if(v2 == 1 && FindNode(lca, n1) == 1) {
		printf("%d ",lca->data);
	}
	else printf("Node does not exist in the tree\n");
}

void main() {
	tree* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(7);
	root->left->right = createNode(6);
	root->right->left = createNode(5);
	root->right->right = createNode(4);
	LCA(root, 3, 5);
}
