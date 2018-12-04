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

void StockSpan(int* arr, int n) {
	stack* s = NULL;
	int i;
	int res[n];
	for(i=0; i<n; i++) {
		if(isEmpty(s) || arr[peek(s)] > arr[i]) {
			push(&s, i);
			res[i] = 1;
		}
		else {
			while(!isEmpty(s) && arr[peek(s)] <= arr[i]) {
				pop(&s);
			}
			if(!isEmpty(s))
		    res[i] = i-peek(s);
		    else res[i]= i+1 ;
		    push(&s, i);
		}
	}
	for(i=0; i<n; i++) {
		printf("%d ",res[i]);
	}
}

int main() {
	int arr[] = {100, 80, 60, 70, 60, 75, 85};
	StockSpan(arr, 7);
}
