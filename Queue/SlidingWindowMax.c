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
		return ;
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
}

void deleteFront(deque** q) {
	if(isEmpty(*q)) {
		return ;
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

void WindowMaximum(int* arr, int n, int k) {
	int i;
	deque* q = (deque*)malloc(sizeof(deque));
	initialize(q, k);
	for(i=0; i<k; i++) {
		while(!isEmpty(q) && arr[getRear(q)] <= arr[i]) {
			deleteRear(&q);
		}
		insertRear(&q, i);
	}
	printf("%d ",arr[getFront(q)]);
	for(i=k; i<n; i++) {
		while(!isEmpty(q) && getRear(q) <= (i-k)) {
			deleteFront(&q);
		}
		while(!isEmpty(q) && arr[getRear(q)] <= arr[i]) {
			deleteRear(&q);
		}
		insertRear(&q, i);
		printf("%d ",arr[getFront(q)]);
	}
}

int main() {
	int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
	WindowMaximum(arr, 10, 4);
}
