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

typedef struct Pair {
	tree* nn;
	int index;
}pair;

typedef struct Queue {
	pair* *arr;
	int front;
	int rear;
}queue;

void initialize(queue* q) {
	q->arr = (pair**)malloc(sizeof(pair*)*100);
	q->front = -1;
	q->rear = -1;
}

void push(queue* q, pair* data) {
	if(q->front == -1) {
		q->front = 0;
	}
	(q->rear)++;
	q->arr[q->rear] = data;
}

void pop(queue* q) {
	if(q->front == -1) {
		return;
	}
	q->front++;
}

int isEmpty(queue* q) {
	if((q->rear-q->front+1) == 0) {
		return 1;
	}
	return 0;
}

pair* peek(queue* q) {
	if(isEmpty(q)) {
		return NULL;
	}
	return q->arr[q->front];
}

void TopView(tree* root) {
	int i;
	if(root == NULL) {
		return;
	}
	queue* q = (queue*)malloc(sizeof(queue));
	initialize(q);
	int arr[50] = {0};
	arr[25] = root->data;
	pair* p = (pair*)malloc(sizeof(pair));
	p->nn = root;
	p->index = 25;
	push(q, p);
	while(!isEmpty(q)) {
		//printf("fghjk ");
		pair* curr = peek(q);
		//printf("fghjk ");
		pop(q);
		//printf("dfghj ");
		if(curr->nn->left != NULL) {
			int index = curr->index;
			if(arr[index-1] == 0) {
				arr[index-1] = curr->nn->left->data;
			}
			pair* p1 = (pair*)malloc(sizeof(pair));
			p1->index = index-1;
			p1->nn = curr->nn->left;
			push(q, p1);
		}
		
		if(curr->nn->right != NULL) {
			int index = curr->index;
			if(arr[index+1] == 0) {
				arr[index+1] = curr->nn->right->data;
			}
			pair* p1 = (pair*)malloc(sizeof(pair));
			p1->index = index+1;
			p1->nn = curr->nn->right;
			push(q, p1);
		}
	}
	for(i=0; i<50; i++) {
		if(arr[i] != 0) {
			printf("%d ",arr[i]);
		}
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
	TopView(root);
}
