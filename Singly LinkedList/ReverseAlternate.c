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

Node* reverseAlternate(Node* head, int k) {
	Node* curr = head;
	Node* prev = NULL;
	Node* temp = NULL;
	int cnt = k;
	while(curr != NULL && cnt>0) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		cnt--;
	}
	cnt = k;
	if(head != NULL) {
		head->next = curr;
	}
	while(curr != NULL && cnt>1) {
		cnt--;
		curr = curr->next;
	}
	if(curr != NULL) {
		curr->next = reverseAlternate(curr->next, k);
	}
	return prev;
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
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	head = reverseAlternate(head, 3);
	display(head);
}
