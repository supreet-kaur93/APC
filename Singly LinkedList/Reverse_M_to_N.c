//Reverse a linked list from position m to n

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

node* reverse(node* head, int n) {
	node* curr = head;
	node* prev = NULL;
	while(curr != NULL && n>0) {
		node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
		n--;
	}
	head->next = curr;
	return prev;
}

void ReverseList(node** head, int n, int m) {
	node* curr = *head;
	node* prev = NULL;
	m = m-n;
	while(curr != NULL && n>1) {
		prev = curr;
	    curr = curr->next;
	    n--;
	}
	if(prev == NULL) {
		*head = reverse(curr, m+1);
	}
	else {
		prev->next = reverse(curr, m+1);
	}
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
	//head->next->next->next->next->next = CreateNode(6);
	//head->next->next->next->next->next->next = CreateNode(7);
	ReverseList(&head, 2, 4);
	Display(head);
}
