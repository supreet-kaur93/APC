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

int size(queue *q) {
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

void display(queue* q) {
	while(!isEmpty(q)) {
		printf("%d ", peek(q));
		pop(&q);
	}
}

void interLeave(queue **q) {
	int sz = size(*q);
	int k = sz/2;
	stack* s = NULL;
	while(k > 0) {
		int val = peek(*q);
		pop(q);
		pushS(&s, val);
		k--;
	}
	while(!isEmptyS(s)) {
		push(q, peekS(s));
		popS(&s);
	}
	k = sz/2;
	while(k>0) {
		int val = peek(*q);
		pop(q);
		push(q, val);
		k--;
	}
	k = sz/2;
	while(k>0) {
		pushS(&s, peek(*q));
		pop(q);
		k--;
	}
	queue* res = NULL;
	while(!isEmptyS(s)) {
		push(&res, peekS(s));
		popS(&s);
		push(&res, peek(*q));
		pop(q);
	}
	display(res);
}

int main() {
	queue* q = NULL;
	int i;
	push(&q, 1);
	push(&q, 2);
	push(&q, 3);
	push(&q, 4);
	interLeave(&q);
}
