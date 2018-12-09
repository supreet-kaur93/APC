//delete all nodes that have duplicate numbers,
//leaving only distinct numbers from the original list.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

node* CreateNode(int data) {
	node* nn = (node*)malloc(sizeof(node));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void RemoveDuplicates(node** head) {
	node* curr = *head;
	node* dummy = (node*)malloc(sizeof(node));
	dummy->next = *head;
	node* prev = dummy;
	while(curr) {
		while(curr->next && prev->next->data == curr->next->data) {
			curr = curr->next;
		}
		if(prev->next == curr) {
			prev = curr;
		}
		else {
			prev->next = curr->next;
		}
		curr = curr->next;
	}
	prev->next = NULL;
	*head = dummy->next;
}

void Display(node* head) {
	node* curr = head;
	while(curr != NULL) {
		printf("%d ",curr->data);
		curr = curr->next;
	}
}

int main() {
	node* head = CreateNode(1);
	head->next = CreateNode(2);
	head->next->next = CreateNode(3);
	head->next->next->next = CreateNode(3);
	head->next->next->next->next = CreateNode(4);
	head->next->next->next->next->next = CreateNode(4);
	head->next->next->next->next->next->next = CreateNode(5);
	RemoveDuplicates(&head);
	Display(head);
}
