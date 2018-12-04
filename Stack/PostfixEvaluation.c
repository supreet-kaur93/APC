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

int isOperator(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
		return 1;
	}
	return 0;
}

void EvaluatePostfix(char* str) {
	int i;
	stack* s = NULL;
	for(i=0; i<strlen(str); i++) {
		//printf("ghjk ");
		if(str[i] == ' ') {
			continue;
		}
		if(isOperator(str[i])) {
			//printf("fghj ");
			int no1 = peek(s);
			pop(&s);
			int no2 = peek(s);
			pop(&s);
			if(str[i] == '+') {
				push(&s, no2+no1);
			}
			else if(str[i] == '-') {
				push(&s, no2-no1);
			}
			else if(str[i] == '*') {
				push(&s, no2*no1);
			}
			else if(str[i] == '/') {
				push(&s, no2/no1);
			}
			else if(str[i] == '^') {
				push(&s, no2^no1);
			}
		}
		else {
			int no = 0;
			while(str[i] >='0' && str[i]<='9') {
				no = no*10+(str[i] - '0');
				//printf("fghjk ");
				i++;
			}
			if(no != 0)
			push(&s, no);
		}
	}
	printf("%d\n", peek(s));
}

int main() {
	int i;
	char str[] = {"2 3 1 * + 9 -"};
	EvaluatePostfix(str);
}
