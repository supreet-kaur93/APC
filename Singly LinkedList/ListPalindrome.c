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

Node* reverse(Node* head) {
	Node* curr = head;
	Node* prev = NULL;
	while(curr != NULL) {
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}

int checkPalindrome(Node* head) {
	Node* slow_p = head;
	Node* fast_p = head;
	Node* prev = NULL;
	while(fast_p && fast_p->next) {
		prev = slow_p;
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
	}
	Node* secondHead = NULL;
	if(fast_p == NULL) {
		secondHead = slow_p;
		prev->next = NULL;
	}
	else {
		secondHead = slow_p->next;
		prev->next = NULL;
	}
	secondHead = reverse(secondHead);
	
	while(secondHead != NULL && head != NULL) {
		if(secondHead->data != head->data) {
			return 0;
		}
		secondHead = secondHead->next;
		head = head->next;
	}
	return 1;
}

int main() {
	Node* head = NULL;
	// insert at beginning
	push(&head, 6);
	push(&head, 7);
	push(&head, 7);
	push(&head, 6);
	int res = checkPalindrome(head);
	if(res == 1) {
		printf("List is palindrome\n");
	}
	else printf("List is not palindrome\n");
}
