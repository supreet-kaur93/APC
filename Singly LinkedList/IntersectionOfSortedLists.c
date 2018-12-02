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

Node* intersect(Node* head1, Node* head2) {
	Node* curr1 = head1;
	Node* curr2 = head2;
	Node* res = NULL;
	Node* temp = NULL;
	while(curr1 != NULL && curr2 != NULL) {
		if(curr1->data < curr2->data) {
			if(res == NULL) {
				temp = curr1;
				res = temp;
			}
			else {
				temp->next = curr1;
				temp = temp->next;
			}
			curr1 = curr1->next;
		}
		else {
			if(res == NULL) {
				temp = curr2;
				res = temp;
			}
			else {
				temp->next = curr2;
				temp = temp->next;
			}
			curr2 = curr2->next;
		}
	}

	while(curr1 != NULL) {
		if(res == NULL) {
			temp = curr1;
			res = temp;
		}
		else {
			temp->next = curr1;
			temp = temp->next;
		}
		curr1 = curr1->next;
	}
	
	while(curr2 != NULL) {
	    if(res == NULL) {
			temp = curr2;
			res = temp;
		}
		else {
			temp->next = curr2;
			temp = temp->next;
		}
		curr2 = curr2->next;	
	}
	return res;
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
	push(&head, 10);
	push(&head, 9);
	push(&head, 5);
	push(&head, 4);
	push(&head, 2);

	Node* head2 = NULL;
	push(&head2, 9);
	push(&head2, 8);
	push(&head2, 7);
	
	Node* res = intersect(head, head2);
	display(res);
}
