// Deque using circular array
// operations supported
//  - insertFront() - deleteFront()
//  - insertRear() - deleteRear()
//  - getFront()  - getRear()
//  - isEmpty()  - isFull()

#include<stdio.h>
#include<stdlib.h>

typedef struct Deque {
	int* arr;
	int front;
	int back;
	int size;
}deque;

void initialize(deque* q, int size) {
	q->arr = (int*)malloc(sizeof(int)*size);
	q->size = size;
	q->front = -1;
	q->back = -1;
}

int isEmpty(deque* q) {
	if(q->front == -1) {
		return 1;
	}
	return 0;
}

int isFull(deque* q) {
	if((q->front == 0 && q->back == q->size-1) || (q->front == q->back+1)) {
		return 1;
	}
	return 0;
}

void insertFront(deque** q, int data) {
	if(isFull(*q)) {
		printf("Deque full\n");
		return;
	}

	if((*q)->front == -1) {
		(*q)->front = 0;
		(*q)->back = 0;
		(*q)->arr[(*q)->front] = data;
		return;
	}

	if((*q)->front == 0) {
		(*q)->front = (*q)->size-1;
		(*q)->arr[(*q)->front] = data;
		return;
   }

	(*q)->front--;
	(*q)->arr[(*q)->front] = data;
}

void insertRear(deque** q, int data) {
	if(isFull(*q)) {
		printf("Deque full\n");
		return;
	}

	if((*q)->front == -1) {
		(*q)->front = 0;
		(*q)->back = 0;
		(*q)->arr[(*q)->back] = data;
		return;
	}

	if((*q)->back == (*q)->size-1) {
		(*q)->back = 0;
		(*q)->arr[(*q)->back] = data;
		return;
	}

	(*q)->back++;
	(*q)->arr[(*q)->back] = data;
}

void deleteRear(deque** q) {
	if(isEmpty(*q)) {
		return -1;
	}

	int x = (*q)->arr[(*q)->back];
	if((*q)->front == (*q)->back) {
		(*q)->front = -1;
		(*q)->back = -1;
		return;
	}

	if((*q)->back == 0) {
		(*q)->back = (*q)->size-1;
		return;
	}

	(*q)->back--;
	return x;
}

void deleteFront(deque** q) {
	if(isEmpty(*q)) {
		return -1;
	}

	int x = (*q)->arr[(*q)->front];
	if((*q)->front == (*q)->back) {
		(*q)->front = -1;
		(*q)->back = -1;
		return;
	}

	if((*q)->front == (*q)->size-1) {
		(*q)->front = 0;
		return;
	}

	(*q)->front++;
	return x;
}

int getFront(deque* q) {
	if(isEmpty(q)) {
		printf("Underflow\n");
		return;
	}
	return q->arr[q->front];
}

int getRear(deque* q) {
	if(isEmpty(q)) {
		printf("Underflow");
		return;
	}
	return q->arr[q->back];
}

int main() {
	deque* q = (deque*)malloc(sizeof(deque));
	initialize(q, 5);
	insertRear(&q, 5);
	insertRear(&q, 10);
	printf("Rear Element\n");
	printf("%d\n", getRear(q));
	deleteRear(&q);
	printf("Rear Element\n");
	printf("%d\n", getRear(q));
	insertFront(&q, 15);
	printf("Front Element\n");
	printf("%d\n", getFront(q));
	deleteFront(&q);
	printf("Front Element\n");
	printf("%d\n", getFront(q));
}
