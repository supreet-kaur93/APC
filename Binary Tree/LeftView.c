#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	int val;
	struct node* left;
	struct node* right;
};

typedef struct node Node;

Node* createNode(int data, int val) {
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->data = data;
	nn->val = val;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

Node* create(int data, Node* root, int val) {
	if(root == NULL) {
		root = createNode(data, val);
		return root;
	}
	if(root->data > data) {
		root->left = create(data, root->left, val-1);
	}
	else root->right = create(data, root->right, val+1);
	return root;
}

int max(int a, int b) {
	return (a>b? a:b);
}

void LeftView(Node* root, int level, int* maxLevel) {
	if(root == NULL) {
		return;
	}
	if(level > *maxLevel) {
		printf("%d ", root->data);
		*maxLevel = level;
	}
	LeftView(root->left, level+1, maxLevel);
	LeftView(root->right, level+1, maxLevel);
}

int main() {
	Node* root = NULL;
	root = create(5, root, 0);
	root = create(3, root, 0);
	root = create(2, root, 0);
	root = create(4, root, 0);
	root = create(7, root, 0);
	root = create(6, root, 0);
	root = create(8, root, 0);
	int maxLevel = 0;
	LeftView(root, 1, &maxLevel);
}
