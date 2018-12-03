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
	if(q == NULL) {
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

int GiveChange(int* arr, int n) {
	int i;
	queue* q1 = NULL;
	queue* q2 = NULL;
	queue* q3 = NULL;
	for(i=0; i<n; i++) {
		if(arr[i] == 5) {
			push(&q1, 5);
		}
		else if(arr[i] == 10) {
			push(&q2, 10);
			if(size(q1) <1) {
				return -1;
			}
			pop(&q1);
		}
		else if(arr[i] == 20) {
			push(&q3, 20);
			if(size(q2) > 0 && size(q1) > 0) {
				pop(&q2);
				pop(&q1);
			}
			else if(size(q1) > 2) {
				pop(&q1);
				pop(&q1);
				pop(&q1);
			}
			else return -1;
		}
	}
	return 1;
}

int main() {
	int arr[] = {5, 5, 5 ,10, 20};
	printf("%d ",GiveChange(arr, 5));
}
