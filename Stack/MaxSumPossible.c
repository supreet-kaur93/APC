// max equal sum from 3 arrays

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

void MaxPossibleSum(int* arr1, int* arr2, int* arr3, int n1, int n2, int n3) {
	stack* s1 = NULL, *s2 = NULL, *s3 = NULL;
	int i, sum1 = 0, sum2 = 0, sum3 = 0;
	for(i=n1-1; i>=0; i--) {
		push(&s1, arr1[i]);
		sum1 = sum1 + arr1[i];
	}
	for(i=n2-1; i>=0; i--) {
		push(&s2, arr2[i]);
		sum2 = sum2 + arr2[i];
	}
	for(i=n3-1; i>=0; i--) {
		push(&s3, arr3[i]);
		sum3 = sum3 + arr3[i];
	}
	while(sum1 != sum2 || sum2 != sum3) {
		if(sum1>=sum2 && sum1 >= sum3) {
			if(isEmpty(s1)) {
				break;
			}
			sum1 = sum1 - peek(s1);
			pop(&s1);
		}
		else if(sum2 >=sum1 && sum2 >= sum3) {
			if(isEmpty(s2)) {
				break;
			}
			sum2 = sum2 - peek(s2);
			pop(&s2);
		}
		else {
			if(isEmpty(s3)) {
				break;
			}
			sum3 = sum3 - peek(s3);
			pop(&s3);
		}
	}
	printf("%d %d %d",sum1,sum2, sum3);
	if((sum1 == sum2 && sum2 == sum3)) {
		printf("Possible sum - %d",sum1);
	}
	else printf("Not Possible");
}

int main() {
	int i;
	int arr1[] = {3, 2, 1, 1, 1};
	int arr2[] = {4, 3, 2};
	int arr3[] = {1, 1, 4, 1};
	MaxPossibleSum(arr1, arr2, arr3, 5, 3, 4);
}
