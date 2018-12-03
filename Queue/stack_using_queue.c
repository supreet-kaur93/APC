#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int* arr;
	int front;
	int back;
}node;

typedef struct Queue {
	node* new_node;
	
}queue;

void initialize(queue *q, int size) {
	q->new_node = (node*)malloc(sizeof(node));
	q->new_node->arr = (int*)malloc(sizeof(int)*size);
	q->new_node->front = -1;
	q->new_node->back = -1;
}

void push(queue** q, int data) {
	if((*q)->new_node->front == -1) {
		(*q)->new_node->front = 0;
	}
	((*q)->new_node->back)++;
	(*q)->new_node->arr[(*q)->new_node->back] = data;
	//printf( "%d ", (*q)->new_node->arr[(*q)->new_node->back]);
}

int isEmpty(queue* q) {
	return (q->new_node->back - q->new_node->front +1 == 0)?1:0;
}

int peek(queue *q) {
	if(isEmpty(q) || q->new_node->front == -1) {
		return -1;
	}
	return q->new_node->arr[q->new_node->front];
}

void pop(queue** q) {
	((*q)->new_node->front)++;
}

int size(queue* q) {
	return (q->new_node->back - q->new_node->front + 1);
}

int removeLast(queue **q) {
	if(isEmpty(*q)) {
		return -1;
	}
	int sz = size(*q);
	//printf("%d ",sz);
	while(sz>1) {
		int x = peek(*q);
		pop(q);
		if(x != -1)
		push(q, x);
		sz--;
	}
	int x = peek(*q);
	pop(q);
	return x;
}


int main() {
	queue* q = (queue*)malloc(sizeof(queue));
	initialize(q, 6);
	push(&q, 1);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	push(&q, 5);
	push(&q, 6);
	int i;
	while(!isEmpty(q)) {
		printf("%d ",removeLast(&q));
	}
}
