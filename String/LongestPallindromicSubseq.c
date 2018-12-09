#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Pallindrom(char* str) {
	int i, j, k, start = 0;
	int n =strlen(str);
	int maxLength = 1;
	int table[n][n];
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			table[i][j] = 0;
		}
	}
	for(i=0; i<strlen(str); i++) {
		table[i][i] = 1;
	}
	// length 2
	for(i=0; i<n-1; i++) {
		if(str[i] == str[i+1]) {
			table[i][i+1] = 1;
			start = i;
			maxLength = 2;
		}
	}
	
	// for length more than 2
	for(i=3; i<=n; i++) {
		for(j=0; j<n-i+1; j++) {
			int k = j+i-1;
			if(table[j+1][k-1] && str[j] == str[k]) {
				table[j][k] = 1;
				if(i>maxLength) {
					maxLength = i;
					start = j;
				}
			}
		}
	}
	for(i=start; i<maxLength; i++) {
		printf("%c", str[i]);
	}
}

int main() {
	char* ch = "abaabacdb";
	Pallindrom(ch);
}
