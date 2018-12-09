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

node* Merge(node* head1, node* head2) {
	node* curr1 = head1;
	node* curr2 = head2;
	node* NewList = NULL;
	node* nn = NewList;
	while(curr1 != NULL && curr2 != NULL) {
		if(curr1->data < curr2->data) {
			if(NewList == NULL) {
				NewList = curr1;
				nn = NewList;
			}
			else {
				nn->next = curr1;
				nn = nn->next;
			}
			curr1 = curr1->next;
		}
		else {
			if(NewList == NULL) {
				NewList = curr2;
				nn = NewList;
			}
			else {
				nn->next = curr2;
				nn = nn->next;
			}
			curr2 = curr2->next;
		}
	}
	while(curr1 != NULL) {
		if(NewList == NULL) {
			NewList = curr1;
			nn = NewList;
		}
		else {
			nn->next = curr1;
			nn = nn->next;
		}
		curr1 = curr1->next;
	}
	
	while(curr2 != NULL) {
		if(NewList == NULL) {
			NewList = curr2;
			nn = NewList;
		}
		else {
			nn->next = curr2;
			nn = nn->next;
		}
		curr2 = curr2->next;
	}
	
	nn->next = NULL;
	return NewList;
}

void Display(node* head) {
	node* curr = head;
	while(curr != NULL) {
		printf("%d ",curr->data);
		curr = curr->next;
	}
}

int main() {
	node* head1 = CreateNode(5);
	head1->next = CreateNode(8);
	head1->next->next = CreateNode(20);
	node* head2 = CreateNode(4);
	head2->next = CreateNode(11);
	head2->next->next = CreateNode(15);
	node* nn = Merge(head1, head2);
	Display(nn);
}
