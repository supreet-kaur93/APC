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

void NextGreaterElement(int* arr, int n) {
	int i;
	stack* s = 	NULL;
	int res[n];
	for(i=0; i<n; i++) {
		if(isEmpty(s) || arr[i] <= arr[peek(s)]) {
			push(&s, i);
		}
		else {
			while(!isEmpty(s) && arr[i] > arr[peek(s)]) {
				res[peek(s)] = arr[i];
				pop(&s);
			}
			push(&s, i);
		}
	}
	while(!isEmpty(s)) {
		res[peek(s)] = -1;
		pop(&s);
	}
	for(i=0; i<n; i++) {
		printf("%d ",res[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {4, 5, 2, 25};
	NextGreaterElement(arr, 4);
	int arr1[] = {13, 7, 6, 12};
	NextGreaterElement(arr1, 4);
}
