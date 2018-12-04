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

int* NextGreater(int* arr, int n) {
	int i;
	int* Greater = (int*)malloc(sizeof(int)*n);
	stack* s = NULL;
	for(i=0; i<n; i++) {
		if(isEmpty(s) || (arr[i] <= arr[peek(s)])){
			push(&s, i);
		}
		else {
			while(!isEmpty(s) && (arr[i] > arr[peek(s)])) {
				Greater[peek(s)] = i;
				pop(&s);
			}
			push(&s, i);
		}
	}
	while(!isEmpty(s)) {
		Greater[peek(s)] = -1;
		pop(&s);
	}
	return Greater;
}

int* NextSmaller(int* arr, int n) {
	int i;
	int* Smaller = (int*)malloc(sizeof(int)*n);
	stack* s = NULL;
	for(i=0; i<n; i++) {
		if(isEmpty(s) || arr[i] >= arr[peek(s)]) {
			push(&s, i);
		}
		else {
			while(!isEmpty(s) && arr[i] < arr[peek(s)]) {
				Smaller[peek(s)] = arr[i];
				pop(&s);
			}
			push(&s, i);
		}
	}
	while(!isEmpty(s)) {
		Smaller[peek(s)] = -1;
		pop(&s);
	}
	return Smaller;
}

void Next_Smaller_Of_Next_Greater(int *arr, int n) {
	int i;
	int* Greater = NextGreater(arr, n);
	int* Smaller = NextSmaller(arr, n);
	for(i=0; i<n; i++) {
		if(Greater[i] != -1) {
			printf("%d ", Smaller[Greater[i]]);
		}
		else {
			printf("-1 ");
		}
	}
}

int main() {
	int i;
	int arr[] = {5, 1, 9, 2, 5, 1, 7};
	Next_Smaller_Of_Next_Greater(arr, 7);
}
