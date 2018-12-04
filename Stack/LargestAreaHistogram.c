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

void Histogram(int* arr, int n) {
	int i;
	stack*s = NULL;
	int max = 0;
	for(i=0; i<n;) {
		if(isEmpty(s) || arr[peek(s)] <= arr[i]) {
			push(&s, i++);
		}
		else {
			int tp = peek(s);
			pop(&s);
			int area = 0;
			if(isEmpty(s)) {
				area = arr[tp]* (i);
			}
			else {
				area = arr[tp]*(i-peek(s) -1);
			}
			if(area > max) {
				max = area;
			}
		}
	}
	while(!isEmpty(s)) {
		int tp = peek(s);
		pop(&s);
		int area = 0;
		if(isEmpty(s)) {
			area = arr[tp]* (i);
		}
		else {
			area = arr[tp]*(i-peek(s) -1);
		}
		if(area > max) {
			max = area;
		}
	}
	printf("%d ",max);
}

int main() {
	int i;
	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	Histogram(arr, 7);
}
