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

void RemoveDuplicates(Node** head) {
	Node* curr = *head;
	while(curr != NULL && curr->next != NULL && curr->data == curr->next->data) {
		curr = curr->next;
	}
	*head = curr;
	curr = *head;
	while(curr != NULL && curr->next != NULL) {
		Node* temp = curr->next;
		if(curr->data == temp->data) {
			Node* del = temp;
			curr->next = temp->next;
			free(del);
		}
		else curr = curr->next;
	}
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
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);
	push(&head, 4);
	push(&head, 4);
	push(&head, 4);
	RemoveDuplicates(&head);
	display(head);
}
