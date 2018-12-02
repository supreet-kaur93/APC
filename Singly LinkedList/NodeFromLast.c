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

void NodeFromLast(Node* head, int pos) {
 	Node* fast = head;
 	Node* slow = head;
 	int cnt = 0;
 	while(fast != NULL && cnt != pos) {
 		fast = fast->next;
 		cnt++;
	 }
	 if(fast == NULL) {
	 	return;
	 }
	 while(fast != NULL) {
	 	fast = fast->next;
	 	slow = slow->next;
	 }
	 printf("%d ",slow->data);
}

int main() {
	Node* head = NULL;
	// insert at beginning
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 4);
	int pos = 2;
	NodeFromLast(head, pos);
}
