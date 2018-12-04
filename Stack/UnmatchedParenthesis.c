// set values for matched parenthesis and unmatched parenthesis

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
	int data;
	struct Stack* next;
}stack;

stack* NewNode(int data) {
	stack* nn = (stack*)malloc(sizeof(stack));
	nn->data = data;
	nn->next = NULL;
	return nn;
}

void push(stack** s, int data) {
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

int peek(stack* s) {
	if(!isEmpty(s))
	return (s)->data;
	return -1;
}

void UnmatchedParenthesis(char* str) {
	int i;
	stack* s = NULL;
	for(i=0; i<strlen(str); i++) {
		if(str[i] == '(') {
			push(&s, i);
		}
		else if(str[i] == ')') {
			if(isEmpty(s) || str[peek(s)] != '(') {
				push(&s, i);
			}
			else if(!isEmpty(s)){
				str[i] = '1';
				str[peek(s)] = '0';
				pop(&s);
		    }
		}
	}
	while(!isEmpty(s)) {
		str[peek(s)] = '/';
		pop(&s);
	}
	printf("%s\n", str);
}

int main() {
	int i;
	char str[] = {"(((abc))((d)))))"};
	UnmatchedParenthesis(str);
}
