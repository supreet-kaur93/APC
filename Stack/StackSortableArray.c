// check if 1-n numbers can be sorted using stack
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

void StackSortable(int* arr, int n) {
	stack* s = NULL;
	int i, expected = 1;
	int flag = 0;
	for(i=0; i<n; i++) {
		if(expected == arr[i]) {
			expected++;
		}
		else {
			if(!isEmpty(s) && peek(s) == expected) {
				expected++;
				pop(&s);
			}
			else if(!isEmpty(s) && peek(s) < arr[i]) {
				flag = 1;
				break;
			}
			else {
				push(&s, arr[i]);
			}
		}
	}

	while(!isEmpty(s)) {
		if(expected == peek(s)) {
			expected++;
			pop(&s);
		}
		else {
			flag = 1;
			break;
		}
	}
	if(flag == 0) {
		printf("Yes\n");
	}
	else printf("No\n");
}

int main() {
	int i;
	int arr[] = {4, 1, 2 , 3};
	StackSortable(arr, 4);
	int arr1[] = {2, 3, 1};
	StackSortable(arr, 3);
}
