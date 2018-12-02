#include<stdio.h>
#include<stdlib.h>

typedef struct List {
	int data;
	struct List *next;
}Node;

Node* createNode(int data) {
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void push(Node** head, int data) {
	Node* nn = createNode(data);
	nn->next = *head;
	*head = nn;
}

void SwapNodes(Node** head, int x, int y) {
	Node* prevX = NULL;
	Node* prevY = NULL;
	Node* currX = *head;
	Node* currY = *head;
	while(currX != NULL && currX->data != x) {
		prevX = currX;
		currX = currX->next;
	}
	while(currY != NULL && currY->data != y) {
		prevY = currY;
		currY = currY->next;
	}
	if(prevX == NULL) {
		*head = currY;
	}
	else {
		prevX->next = currY;
	}
	if(prevY == NULL) {
		*head = currX;
	}
	else {
		prevY->next = currX;
	}
	Node* temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
}

void display(Node* head) {
	Node* curr = head;
	while(curr != NULL) {
		printf("%d ",curr->data);
		curr = curr->next;
	}
}

int main() {
	Node* head = NULL;
	// insert at beginning
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	printf("Before swapping\n");
	display(head);
	SwapNodes(&head, 7, 4);
	printf("\nAfter swapping\n");
	display(head);
}
