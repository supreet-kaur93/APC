#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue {
	struct Queue* next;
	char data;
}queue;

queue* newNode(char data) {
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

char peek(queue* q) {
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

int size(queue* q) {
	if(isEmpty(q)) {
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

int comparator(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int comp2(const void* a, const void* b) {
	return -1*(*(int*)a - *(int*)b);
}

void LargestMultipleThree(int* arr, int n) {
	int i, sum = 0;
	qsort(arr, n, sizeof(int), comparator);
	for(i=0; i<n; i++) {
		sum = sum+arr[i];
	}
	queue* q1 = NULL; // elements which give remainder 0 when divided by 3
	queue* q2 = NULL; // elements which give remainder 1 when divided by 3
	queue* q3 = NULL; // elements which give remainder 2 when divided by 3
	for(i=0; i<n; i++) {
		if(arr[i] % 3 == 0) {
			push(&q1, arr[i]);
		}
		else if(arr[i] %3 == 1) {
			push(&q2, arr[i]);
		}
		else if(arr[i] %3 == 2){
			push(&q3, arr[i]);
		}
	}
	int res[n];
	int j = 0;
	if(sum %3 == 0) {
		while(!isEmpty(q1)) {
			res[j++] = peek(q1);
			pop(&q1);
		}
		while(!isEmpty(q2)) {
			res[j++] = peek(q2);
			pop(&q2);
		}
		while(!isEmpty(q3)) {
			res[j++] = peek(q3);
			pop(&q3);
		}
	}
	else if(sum %3 == 1) {
		if(size(q2) > 0) {
			pop(&q2);
		}
		else if(size(q3) > 1) {
			pop(&q3);
			pop(&q3);
		}
		else return;
		while(!isEmpty(q1)) {
			res[j++] = peek(q1);
			pop(&q1);
		}
		while(!isEmpty(q2)) {
			res[j++] = peek(q2);
			pop(&q2);
		}
		while(!isEmpty(q3)) {
			res[j++] = peek(q3);
			pop(&q3);
		}
	}
	else if(sum %3 == 2) {
		if(size(q3) > 0) {
			pop(&q3);
		}
		else if(size(q2) > 1) {
			pop(&q2);
			pop(&q2);
		}
		else return;
		while(!isEmpty(q1)) {
			res[j++] = peek(q1);
			pop(&q1);
		}
		while(!isEmpty(q2)) {
			res[j++] = peek(q2);
			pop(&q2);
		}
		while(!isEmpty(q3)) {
			res[j++] = peek(q3);
			pop(&q3);
		}
	}
	if(j == 0) {
		printf("Not possible");
	}
	qsort(res, j, sizeof(int), comp2);
	for(i=0; i<j; i++) {
		printf("%d ",res[i]);
	}
}

int main() {
	int arr[] = {8, 1, 7, 6, 0};
	LargestMultipleThree(arr, 5);
}
