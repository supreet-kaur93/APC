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

int isOperator(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')') {
		return 1;
	}
	return 0;
}

int BalancedParenthesis(char* str) {
	int i;
	stack* s = NULL;
	for(i=0; i<strlen(str); i++) {
		if(str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(&s, str[i]);
		}
		else {
			if(str[i] == ')') {
				if(isEmpty(s) || peek(s) != '(') {
					return 0;
				}
				pop(&s);
			}
			else if(str[i] == '}') {
				if(isEmpty(s) || peek(s) != '{') {
					return 0;
				}
				pop(&s);
			}
			else if(str[i] == ']') {
				if(isEmpty(s) || peek(s) != '[') {
					return 0;
				}
				pop(&s);
			}
		}
	}
	if(isEmpty(s)) {
		return 1;
	}
	return 0;
}

int main() {
	char str[] = "{()}[]";
	int res = BalancedParenthesis(str);
	if(res == 1) {
		printf("Balanced\n");
	}
	else {
		printf("Not Balanced\n");
	}
}
