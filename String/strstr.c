#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strstrImp(char* ch, char* substr) {
	//char* res = (char*)malloc(sizeof(char)* (strlen(ch)+ strlen(substr) + 1));
	char* res = (char*)malloc(sizeof(char)*100);
	int i;
	int* z = (int*)malloc(sizeof(int)*20);
	for(i=0; i<strlen(substr); i++) {
		res[i] = substr[i];
	}
	res[i] = '$';
	int y = i+1;
	for(i=0; i<strlen(ch); i++) {
		res[y++] = ch[i];
	}
	res[y++] = '\0';
	int start = 0;
	int end = 0;
	z[0] = 0;
	int n = strlen(res);
	for(i=1; i<strlen(res); i++) {
		if(end < i) {
			end = i;
			start = i;
			while(end<n && (res[end-start] == res[end])) {
				end++;
			}
			z[i] = end - start;
			end--;
		}
		else {
			int t = i-start;
			if(z[t] < (end-i+1)) {
				z[i] = z[t];
			}
			else {
				start = i;
				while(end<n && (res[end-start] == res[end])) {
					end++;
				}
				z[i] = end-start;
				end--;
			}
		}
	}
	for(i=0; i<n; i++) {
		if(z[i] == strlen(substr)) {
			printf("%d ",i-strlen(substr)-1);
			break;
		}
	}
}

int main() {
	char* ch = "abbbcaba";
	char* substr = "aba";
	strstrImp(ch, substr);
}
