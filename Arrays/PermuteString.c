#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* ch, int l, int r) {
	int temp = ch[l];
	ch[l] = ch[r];
	ch[r] = temp;
}

void Permute(char* ch, int l, int r, char res[][100], int* y) {
	if(l==r) {
		strcpy(res[(*y)++], ch);
		return;
	}
	int i;
	for(i=l; i<=r; i++) {
		swap(ch, l, i);
		Permute(ch, l+1, r, res, y);
		swap(ch, l, i);
	}
}

void Display(char res[][100], int y) {
	int i, j;
	for(i=0; i<y-1; i++) {
		for(j=0; j < y-i-1; j++) {
			if(strcmp(res[j], res[j+1]) > 0) {
				char temp[100];
				strcpy(temp, res[j]);
				strcpy(res[j], res[j+1]);
				strcpy(res[j+1], temp);
			}
		}
	}
	for(i=0; i<y; i++) {
		printf("%s ",res[i]);
	}
}

int main() {
	char ch[] = "abc";
	char res[100][100];
	int y = 0;
	Permute(ch, 0, strlen(ch)-1, res, &y);
	Display(res, y);
}
