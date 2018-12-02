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

void delete(Node** head, int data) {
    Node* curr = *head;
    Node* prev = NULL;
    if(curr != NULL && curr->data == data) {
    	*head = curr->next;
    	free(curr);
    	return;
	}
	
	while(curr != NULL && curr->data != data) {
		prev = curr;
		curr = curr->next;
	}
	
	if(curr == NULL) return;
	
	prev->next = curr->next;
	free(curr);
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
	delete(&head, 1);
	display(head);
}
