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

void intersectionPt(Node* head, Node* head2) {
	Node* curr = head;
	Node* curr2 = head2;
	int cnt1 = 0;
	int diff = 0;
	while(curr != NULL) {
		curr = curr->next;
		cnt1++;
	}
	int cnt2 = 0;
	while(curr2 != NULL) {
		curr2 = curr2->next;
		cnt2++;
	}
	if(cnt1 > cnt2) {
		diff = cnt1 - cnt2;
		curr = head;
		while(curr != NULL && diff > 0) {
			curr = curr->next;
			diff--;
		}
	}
	else {
		diff = cnt2 - cnt1;
		curr2 = head2;
		while(curr2 != NULL && diff > 0) {
			curr2 = curr2->next;
			diff--;
		}
	}
	while(curr != NULL && curr2 != NULL) {
		if(curr == curr2) {
			break;
		}
		curr = curr->next;
		curr2 = curr2->next;
    }
    if(curr != NULL) {
    	printf("%d", curr->data);
	}
	else printf("-1");
}

int main() {
	Node* head = NULL;
	// insert at beginning
	push(&head, 3);
	push(&head, 6);
	push(&head, 9);
	push(&head, 15);
	push(&head, 30);
	
	Node* head2 = NULL;
	push(&head2, 10);
	head2->next = head->next->next->next;
	head2->next->next = NULL;
	push(&head2, 30);
	intersectionPt(head, head2);
}
