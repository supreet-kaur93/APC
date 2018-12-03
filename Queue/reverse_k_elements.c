#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
	struct Queue* next;
	int data;
}queue;

queue* newNode(int data) {
	queue* nn = (queue*)malloc(sizeof(queue));
	nn->data = data;
	nn->next = NULL;
}

int isEmpty(queue* q) {
	if(q == NULL) {
		return 1;
	}
	return 0;
}

int peek(queue* q) {
	if(q == NULL) {
		return -1;
	}
	return q->data;
}

void push(queue** q, int data) {
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

typedef struct Stack {
	int data;
	struct Stack* next;
}stack;

stack* newNodeS(int data) {
	stack* nn = (stack*)malloc(sizeof(stack));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void* pushS(stack** s, int data) {
	stack* nn = newNodeS(data);
	nn->next = *s;
	*s = nn;
}

void* popS(stack** s) {
	stack* curr = *s;
	*s = (*s)->next;
	free(curr);
}

int peekS(stack* s) {
	if(s == NULL) {
		return -1;
	}
	return s->data;
}

int isEmptyS(stack* s) {
	return (s == NULL);
}

void reverseQueue(queue** q) {
	int sz = size(*q);
	stack* s = NULL;
	while(sz>0) {
		pushS(&s, peek(*q));
		pop(q);
		sz--;
	}
	while(!isEmptyS(s)) {
		push(q, peekS(s));
		popS(&s);
	}
}

void reverse(queue** q, int k) {
	if(isEmpty(*q) || k <= 0) {
		return;
	}
	stack* s = NULL;
	reverseQueue(q);
	while(k>0) {
		int val = peek(*q);
		pop(q);
		pushS(&s, val);
		k--;
	}
	while(!isEmptyS(s)) {
		push(q, peekS(s));
		popS(&s);
	}
}

void display(queue* q) {
	while(!isEmpty(q)) {
		printf("%d ",q->data);
		pop(&q);
	}
}

int main() {
	queue* q = NULL;
	int i;
	for(i=0; i<10; i++) {
		push(&q, i+1);
	}
	int k = 5;
	reverse(&q, k);
	display(q);
}
