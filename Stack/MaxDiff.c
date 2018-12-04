// Max difference between first min on left and first min on right

#include<stdio.h>
#include<stdlib.h>

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

void LeftMin(int* arr, int* left, int n) {
	int i;
	stack* s = NULL;
	for(i=n-1; i>=0; i--) {
		if(isEmpty(s) || arr[peek(s)] <= arr[i]) {
			push(&s, i);
		}
		else {
			while(!isEmpty(s) && arr[peek(s)] > arr[i]) {
				left[peek(s)] = arr[i];
				pop(&s);
			}
		}
	}
	while(!isEmpty(s)) {
		left[peek(s)] = 0;
		pop(&s);
	}
}

void RightMin(int* arr, int* right, int n) {
	stack* s = NULL;
	int i;
	for(i=0; i<n; i++) {
		if(isEmpty(s) || arr[i] > arr[peek(s)]) {
			push(&s, i);
		}
		else {
			while(!isEmpty(s) && arr[peek(s)] > arr[i]) {
				right[peek(s)] = arr[i];
				pop(&s);
			}
		}
	}
	while(!isEmpty(s)) {
		right[peek(s)] = 0;
		pop(&s);
	}
}

void MaxDiff(arr, n) {
	int left[n], right[n];
	int i, max = 0;
	LeftMin(arr, left, n);
	RightMin(arr, right, n);
	for(i=0; i<n; i++) {
		if((left[i] - right[i]) > max) {
			max = left[i] - right[i];
		}
	}
	printf("%d\n",max);
}

int main() {
	int i;
	int arr[] = {2, 4, 8, 7, 7, 9, 3};
	MaxDiff(arr, 7);
}
