// Traversals without using extra space(stack) and recurssion

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

void InOrder(tree* root) {
	tree* curr = root;
	while(curr != NULL) {
		if(curr->left == NULL) {
			printf("%d ",curr->data);
			curr = curr->right;
		}
		else {
			pre = curr->left;
			while(pre->right != NULL && pre->right != curr) {
				pre = pre->right;
			}
			if(pre->right == NULL) {
				pre->right = curr;
				curr = curr->left;
			}
			else {
				pre->right = NULL;
				printf("%d ",curr->data);
				curr = curr->right;
			}
		}
	}
}

void Traversals(tree* root) {
    printf("Inorder Traversal\n");
	InOrder(root);
	printf("\nPreOrder Traversal\n");
	PreOrder(root);
	printf("\nPostOrder Traversal\n");
	PostOrder(root);
}

void main() {
	tree* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(2);
	root->left->left = createNode(3);
	root->left->right = createNode(4);
	root->right->left = createNode(4);
	root->right->right = createNode(3);
	Traversals(root);
}
