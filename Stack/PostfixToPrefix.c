#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
	char* data;
	struct Stack* next;
}stack;

stack* NewNode(char* data) {
	stack* nn = (stack*)malloc(sizeof(stack));
	nn->data = (char*)malloc(sizeof(char)*strlen(data));
	strcpy(nn->data, data);
	nn->next = NULL;
	return nn;
}

void push(stack** s, char* data) {
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

char* peek(stack* s) {
	if(!isEmpty(s))
	return (s)->data;
	return "";
}

int isOperator(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')') {
		return 1;
	}
	return 0;
}

void PostfixToPrefix(char* str) {
	int i;
	stack* s = NULL;
	for(i=0; i<strlen(str); i++) {
		if(isOperator(str[i])) {
			char* s1 = peek(s);
			pop(&s);
			char* s2 = peek(s);
			pop(&s);
			int y=0, j;
			char* res = (char*)malloc(sizeof(char)*(strlen(s1)+strlen(s2)+3));
			res[y++] = str[i];
			for(j=0; j<strlen(s2); j++) {
				res[y++] = s2[j];
			}
			for(j=0; j<strlen(s1); j++) {
				res[y++] = s1[j];
			}
			res[y++] = '\0';
			push(&s, res);
		}
		else {
			char ch[2];
			ch[0] = str[i];
			ch[1] = '\0';
			push(&s, ch);
		}
	}
	printf("%s\n",peek(s));
}

int main() {
	PostfixToPrefix("ABC/-AK/L-*");
}
