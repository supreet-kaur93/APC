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

typedef struct Stack {
	tree* data;
	struct Stack* next;
}stack;

stack* createStack(tree* data) {
	stack* nn = (stack*)malloc(sizeof(stack));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void push(stack** s, tree* data) {
	stack* nn = createStack(data);
	nn->next = *s;
	*s = nn;
}

void pop(stack** s) {
	stack* curr = *s;
	*s = (*s)->next;
	free(curr);
}

tree* peek(stack* s) {
	if(s == NULL) {
		return NULL;
	}
	return s->data;
}

int isEmpty(stack* s) {
	if(s == NULL) {
		return 1;
	}
	return 0;
}

void LevelOrderInSpiral(tree* root) {
	if(root == NULL) {
		return;
	}
	stack* s1 = NULL;
	stack* s2 = NULL;
	push(&s1, root);
	while(!isEmpty(s1) || !isEmpty(s2)) {
		while(!isEmpty(s1)) {
			tree* curr = peek(s1);
			pop(&s1);
			printf("%d ",curr->data);
			if(curr->right != NULL) {
				push(&s2, curr->right);
			}
			if(curr->left != NULL) {
				push(&s2, curr->left);
			}
		}
		printf("\n");
		while(!isEmpty(s2)) {
			tree* curr = peek(s2);
			pop(&s2);
			printf("%d ",curr->data);
			if(curr->left != NULL) {
				push(&s1, curr->left);
			}
			if(curr->right != NULL) {
				push(&s1, curr->right);
			}
		}
		printf("\n");
	}
}

void main() {
	tree* root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(7);
	root->left->right = createNode(6);
	root->right->left = createNode(5);
	root->right->right = createNode(4);
	LevelOrderInSpiral(root);
}
