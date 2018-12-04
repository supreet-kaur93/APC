#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack {
	char* data;
	struct Stack* next;
}stack;

stack* createNode(char* data) {
	stack* nn = (stack*)malloc(sizeof(stack));
	nn->data = (char*)malloc(sizeof(char)*(strlen(data)));
	strcpy(nn->data, data);
	nn->next = NULL;
	return nn;
}

void push(stack** s, char* data) {
	stack* nn = createNode(data);
	nn->next = *s;
	*s = nn;
}

void pop(stack** s) {
	stack* curr = *s;
	if((*s) != NULL)
	*s = (*s)->next;
	free(curr);
}

char* peek(stack* s) {
	return s->data;
}

int isEmpty(stack* s) {
	if(s == NULL) {
		return 1;
	}
	return 0;
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

int isOperator(char x) {
	if((x == '+') || (x == '-') || (x == '*') || (x == '/' )|| (x == '(' )|| (x == ')' )|| (x == '^')) {
		return 1;
	}
	return 0;
}

void PrefixToInfix(char* str) {
	int i;
	stack* s = NULL;
	for(i=strlen(str)-1; i>=0; i--) {
		if(!isOperator(str[i])) {
			char ch[2];
			ch[0] = str[i];
			ch[1] = '\0';
			push(&s, ch);
		}
		else {
			char* s1 = peek(s);
			pop(&s);
			char* s2 = peek(s);
			pop(&s);
		    char* res = (char*)malloc(sizeof(char)*100);
		    int y = 0, j;
			res[y++] = '(';
			for(j=0; j<strlen(s1); j++) {
				res[y++] = s1[j];
			}
			res[y++] = str[i];
			for(j=0; j<strlen(s2); j++) {
				res[y++] = s2[j];
			}
			res[y++] = ')';
			res[y++] = '\0';
			push(&s, res);
		}
	}
	printf("%s ",peek(s));
}

int main() {
	char str[] = "*-A/BC-/AKL";
	int i;
	PrefixToInfix(str);
}
