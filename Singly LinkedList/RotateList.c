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

void RotateList(node** head, int k) {
	node* curr = *head;
	int c = 0;
	while(curr->next != NULL) {
		curr = curr->next;
		c++;
	}
	node* temp = *head;
	k = c-k;
	node* SecHead = *head;
	while(k>0 && temp) {
		temp = temp->next;
		k--;
	}
	*head = temp->next;
	temp->next = NULL;
	curr->next = SecHead;
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
	head->next->next->next = CreateNode(4);
	head->next->next->next->next = CreateNode(5);
	head->next->next->next->next->next = CreateNode(6);
	head->next->next->next->next->next->next = CreateNode(7);
	RotateList(&head, 2);
	Display(head);
}
