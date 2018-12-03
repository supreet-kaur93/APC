#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
	int* arr;
	int front;
	int back;
}queue;

void initialize(queue* q, int size) {
	q->arr = (int*)malloc(sizeof(int)*size);
	q->front = -1;
	q->back = -1;
}

void push(queue** q, int data) {
	if((*q)->front == -1) {
		(*q)->front = 0;
	}
	(*q)->back++;
	(*q)->arr[(*q)->back] = data;
}

void pop(queue** q) {
	(*q)->front++;
}

int isEmpty(queue* q) {
	if((q->back - q->front +1) == 0) {
		return 1;
	}
	return 0;
}

int size(queue* q) {
	return (q->back - q->front + 1);
}

int peek(queue *q) {
	if(isEmpty(q) || q->front == -1) {
		return -1;
	}
	return q->arr[q->front];
}

void reverse(queue** q) {
	if(isEmpty(*q)) {
		return;
	}
	int val = peek(*q);
	pop(q);
	reverse(q);
	push(q, val);
}

int main() {
	int i=0;
	queue* q = (queue*)malloc(sizeof(queue));
	initialize(q, 5);
	queue* dummy = (queue*)malloc(sizeof(queue));
	initialize(dummy, 5);
	for(i=0; i<5; i++) {
		push(&q, i+1);
		push(&dummy, i+1);
	}
	printf("Before reverse\n");
	while(!isEmpty(dummy)) {
		printf("%d ",peek(dummy));
		pop(&dummy);
	}
	reverse(&q);
	printf("\nAfter reverse\n");
	while(!isEmpty(q)) {
		printf("%d ",peek(q));
		pop(&q);
	}
}
