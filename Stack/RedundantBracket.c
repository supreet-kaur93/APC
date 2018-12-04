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

void RedundantBracket(char* str) {
	int i;
	stack* s = NULL;
	for(i=0; i<strlen(str); i++) {
		if(str[i] != ')') {
			push(&s, str[i]);
		}
		else {
			char tp = peek(s);
			pop(&s);
			int flag = 1;
			while(tp != '(') {
				if(tp == '+' || tp == '-' || tp == '*' || tp == '/') {
					flag = 0;
				}
				tp = peek(s);
				pop(&s);
			}
			if(flag == 1) {
				printf("Redundant bracket\n");
			}
		}
	}
}

int main() {
	int i;
	char str[] = {"(a+(b)/c)"};
	RedundantBracket(str);
}
