#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue {
	struct Queue* next;
	char data;
}queue;

queue* newNode(char data) {
	queue* nn = (queue*)malloc(sizeof(queue));
	nn->data = data;
	nn->next = NULL;
}

int isEmpty(queue* q) {
	if(q == NULL) {
		return 1;
	}
	return 0;
}

char peek(queue* q) {
	if(q == NULL) {
		return -1;
	}
	return q->data;
}

void push(queue** q, int data) {
	queue* nn = newNode(data);
	if((*q) == NULL) {
		*q = nn;
		return;
	}
	queue* curr = *q;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = nn;
}

void pop(queue** q) {
	if(isEmpty(*q)) {
		return;
	}
	queue* curr = *q;
	*q = (*q)->next;
	free(curr);
}

void NonRepeatingChar(char* str) {
	int i;
	queue* q = NULL;
	int count[26] = {0};
	for(i=0; i<strlen(str); i++) {
		char curr = str[i];
		count[str[i] - 'a']++;
		push(&q, curr);
		while(!isEmpty(q)) {
			char x = peek(q);
			if(count[x-'a'] > 1) {
				pop(&q);
			}
			else {
				printf("%c ",x);
				break;
			}
		}
		if(isEmpty(q)) {
			printf("-1 ");
		}
	}
}

int main() {
	NonRepeatingChar("aabc");
}
