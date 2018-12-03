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

int queueSortable(queue** q, int n) {
	int expected = 1;
	stack* s = NULL;
	while(expected != n) {
		int val = peek(*q);
		pop(q);
		if(expected == val) {
			expected++;
		}
		else {
			if(!isEmptyS(s)) {
				if(expected == peekS(s)) {
					expected++;
					popS(&s);
				}
				else {
					if(peekS(s) < val) {
						return 0;
					}
					else {
						pushS(&s, val);
					}
				}
			}
			else {
				pushS(&s, val);
			}
		}
	}
	while(!isEmptyS(s) && peekS(s) == expected) {
		popS(&s);
		expected++;
	}
	if(expected-1 == n && isEmptyS(s)) {
		return 1;
	}
	return 0;
}

int main() {
	queue* q = NULL;
	int i;
	push(&q, 5);
	push(&q, 1);
	push(&q, 2);
	//push(&q, 6);
	push(&q, 3);
	push(&q, 4);
	printf("%d " ,queueSortable(&q, 5));
}
