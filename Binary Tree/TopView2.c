#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	int val;
	struct node* left;
	struct node* right;
};

typedef struct node Node;

typedef struct Pair_c {
	int index;
	Node* nn;
}Pair;

typedef struct Queue {
	struct Queue* next;
	Node* data;
}queue;

queue* newNode(Node* data) {
	queue* nn = (queue*)malloc(sizeof(queue));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

int isEmpty(queue* q) {
	if(q == NULL) {
		return 1;
	}
	return 0;
}

Node* peek(queue* q) {
	if(q == NULL) {
		return NULL;
	}
	return q->data;
}

void push(queue** q, Node* data) {
	queue* nn = newNode(data);
	if((*q) == NULL) {
		*q = nn;
		return;
	}
	queue* curr = *q;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = nn;
}

void pop(queue** q) {
	if(isEmpty(*q)) {
		return;
	}
	queue* curr = *q;
	*q = (*q)->next;
	free(curr);
}

int size(queue* q) {
	if(q == NULL) {
		return 0;
	}
	queue* curr = q;
	int count = 0;
	while(curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

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

void TopView(Node* root) {
	int arr[50] = {0};
	int index = 0;
	queue* q = NULL;
	push(&q, root);
	arr[25] = root->data;
	while(!isEmpty(q)) {
		Node* curr = peek(q);
		pop(&q);
		if(curr->left) {
			if(arr[25+curr->left->val] == 0)
			arr[25 + curr->left->val] = curr->left->data;
			push(&q, curr->left);
		}
		if(curr->right) {
			if(arr[25+ curr->right->val] == 0) {
				arr[25+curr->right->val] = curr->right->data;
			}
			push(&q, curr->right);
		}
	}
	int i;
	for(i=0; i<50; i++) {
		if(arr[i] != 0) {
			printf("%d ",arr[i]);
		}
	}
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
	TopView(root);
}
