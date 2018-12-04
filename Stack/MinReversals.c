// Min number of bracket reversals to balance expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
	char data;
	struct Stack* next;
}stack;

stack* NewNode(char data) {
	stack* nn = (stack*)malloc(sizeof(stack));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void push(stack** s, char data) {
	stack* nn =  NewNode(data);
	nn->next = *s;
	*s = nn;
}

void pop(stack** s) {
	stack* curr = *s;
	*s = (*s)->next;
	free(curr);
}

int isEmpty(stack* s) {
	if(s == NULL) {
		return 1;
	}
	return 0;
}

char peek(stack* s) {
	if(!isEmpty(s))
	return (s)->data;
	return -1;
}

int size(stack* s) {
	stack* curr = s;
	int count = 0;
	while(curr != NULL) {
		count++;
		curr = curr->next;
	}
	return count;
}

void MinReversals(char* str) {
	int i;
	stack* s = NULL;
	for(i=0; i<strlen(str); i++) {
		if(str[i] == '}') {
			if(isEmpty(s) || peek(s) != '{') {
				push(&s, str[i]);
			}
			else {
				pop(&s);
			}
		}
		else {
			push(&s, str[i]);
		}
	}
	int n = size(s);
	int c = 0;
	while(!isEmpty(s) && peek(s) == '{') {
		c++;
		pop(&s);
	}
	printf("%d ",n/2 + c%2);
}

int main() {
	int i;
	char str[] = {"}{{}}{{{"};
	MinReversals(str);
}
