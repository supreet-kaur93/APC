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

void append(Node** head, int data) {
	Node* nn = createNode(data);
	Node* curr = *head;
	if(*head == NULL) {
		*head = nn;
		return;
	}
	while(curr != NULL && curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = nn;
}

void insertAt(Node** head, int pos, int data) {
	Node* nn = createNode(data);
	if(pos == 1) {
		nn->next = *head;
		*head = nn;
		return;
	}
	int cnt = 1;
	Node* curr = *head;
	Node* prev = *head;
	while((curr != NULL) && (cnt != pos)) {
		prev = curr;
		curr = curr->next;
		cnt++;
	}
	nn->next = curr;
	prev->next = nn;
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
	
	// insert at end
	append(&head, 2);
	append(&head, 3);
	
	// insert after position
	int pos = 2;
	insertAt(&head, pos, 8);
	display(head);
}
