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
	while(curr != NULL && curr->next != NULL) {
		Node* temp = curr;
		while(temp->next != NULL) {
			if(curr->data == temp->next->data) {
				Node* del = temp->next;
				temp->next = temp->next->next;
				free(del);
			}
			else temp = temp->next;
		}
		curr = curr->next;
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
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 4);
	push(&head, 1);
	RemoveDuplicates(&head);
	display(head);
}
