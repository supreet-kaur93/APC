#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
	int data;
	struct Queue* next;
}queue;

queue* createNode(int data) {
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

void push(queue** q, int data) {
	queue* nn = createNode(data);
	if((*q) == NULL) {
		(*q) = nn;
		(*q)->next = (*q);
		return;
	}
	queue* curr = *q;
	while(curr->next != (*q)) {
		curr = curr->next;
	}
	curr->next = nn;
	nn->next = (*q);
}

void pop(queue** q) {
	if((*q) == NULL) {
		return;
	}
	if((*q)->next == (*q)) {
		(*q) = NULL;
		return;
	}
	queue* curr = *q;
	while(curr->next != (*q)) {
		curr = curr->next;
	}
	(*q) = (*q)->next;
	curr->next = *q;
}

int peek(queue* q) {
	if(q == NULL) {
		return -1;
	}
	return q->data;
}

int main() {
	queue* q = NULL;
	int i;
	for(i=0; i<5; i++) {
		push(&q, i+1);
	}
	while(!isEmpty(q)) {
		printf("%d ",peek(q));
		pop(&q);
	}
}
