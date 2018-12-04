#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
	int data;
	struct Stack* next;
}stack;

stack* NewNode(int data) {
	stack* nn = (stack*)malloc(sizeof(stack));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void push(stack** s, int data) {
	stack* nn =  NewNode(data);
	nn->next = *s;
	*s = nn;
}

void pop(stack** s) {
	stack* curr = *s;
	*s = (*s)->next;
	free(curr);
}

int isEmpty(stack* s) {
	if(s == NULL) {
		return 1;
	}
	return 0;
}

int peek(stack* s) {
	if(!isEmpty(s))
	return (s)->data;
	return -1;
}

int isOperator(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')') {
		return 1;
	}
	return 0;
}

void ReverseUtil(stack** s, int val) {
	if(isEmpty(*s)) {
		push(s, val);
		return;
	}
	int val1 = peek(*s);
	pop(s);
	ReverseUtil(s, val);
	push(s, val1);
}

void ReverseStack(stack** s) {
	if(isEmpty(*s)) {
		return;
	}
	int val = peek(*s);
	pop(s);
	ReverseStack(s);
	ReverseUtil(s, val);
}

void display(stack* s) {
	while(!isEmpty(s)) {
		printf("%d ",peek(s));
		pop(&s);
	}
}

int main() {
	int i;
	stack* s = NULL;
	for(i=0; i<5; i++) {
		push(&s, i+1);
	}
	ReverseStack(&s);
	display(s);
}
