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

int calLength(Node* temp) {
	Node* curr = temp;
	int cnt = 1;
	while(curr->next != temp) {
		curr = curr->next;
		cnt++;
	}
	return cnt;
}

int LoopLength(Node* head) {
	Node* slow = head;
	Node* fast = head;
	while(slow && fast && fast->next) {
		slow = slow->next;
		fast->next->next;
		if(slow == fast) {
			return calLength(slow);
		}
	}
	return 0;
}

int main() {
	Node* head = NULL;
	// insert at beginning
	push(&head, 6);
	push(&head, 7);
	push(&head, 1);
	push(&head, 4);
	// creating loop
	head->next->next->next = head;
	int res = LoopLength(head);
	printf("%d", res);
}
