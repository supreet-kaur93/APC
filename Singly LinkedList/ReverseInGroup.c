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

Node* reverse(Node* head, int k) {
	if(head == NULL) {
		return;
	}
	Node* curr = head;
	Node* prev = NULL;
	int cnt = k;
	Node* temp = NULL;
	while(curr != NULL && k>0) {
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		k--;
	}
	if(temp != NULL) {
		head->next = reverse(temp, cnt);
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
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	head = reverse(head, 2);
	display(head);
}
