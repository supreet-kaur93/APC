// RemoveDuplicates from sorted array

#include<stdio.h>
#include<stdlib.h>

void removeDuplicates(int* arr, int n) {
	int i, flag = 0, y = 0;
	int* res = (int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++) {
		res[y++] = arr[i];
		while(i+1<n && arr[i] == arr[i+1]) {
			i++;
			flag = 1;
		}
	}
	for(i=0; i<y; i++) {
		printf("%d ", res[i]);
	}
}

int main() {
	int n = 12;
	int arr[] = {7, 7, 18, 18, 18, 18, 21, 39, 39, 42, 42, 42};
	removeDuplicates(arr, n);
}
