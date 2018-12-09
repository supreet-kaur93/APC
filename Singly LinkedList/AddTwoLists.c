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

void Display(node* head) {
	node* curr = head;
	while(curr != NULL) {
		printf("%d ",curr->data);
		curr = curr->next;
	}
}

void AddList(node* list1, node* list2) {
	node* res = NULL;
	node* curr = res;
	int rem = 0;
	int sum = 0;
	while(list1 && list2) {
		sum = list1->data + list2->data +rem;
		rem = sum/10;
		if(res == NULL) {
			res = CreateNode(sum%10);
			curr = res;
		}
		else {
			curr->next = CreateNode(sum%10);
			curr = curr->next;
		}
		list1 = list1->next;
		list2 = list2->next;
	}
	while(list1 != NULL) {
		sum = list1->data + rem;
		rem = sum/10;
		if(res == NULL) {
			res = CreateNode(sum%10);
			curr = res;
		}
		else {
			curr->next = CreateNode(sum%10);
			curr = curr->next;
		}
		list1 = list1->next;
	}
	
	while(list2 != NULL) {
		sum = list2->data +rem;
		rem = sum/10;
		if(res == NULL) {
			res = CreateNode(sum%10);
			curr = res;
		}
		else {
			curr->next = CreateNode(sum%10);
			curr = curr->next;
		}
		list2 = list2->next;
	}
	
	if(rem != 0) {
		curr->next = CreateNode(rem);
		curr = curr->next;
	}
	curr->next = NULL;
	Display(res);
}

int main() {
	node* head1 = CreateNode(2);
	head1->next = CreateNode(4);
	head1->next->next = CreateNode(3);
	node* head2 = CreateNode(5);
	head2->next = CreateNode(6);
	head2->next->next = CreateNode(4);
	head2->next->next->next = CreateNode(10);
	AddList(head1, head2);
	//Display(nn);
}
