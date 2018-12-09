//Given an array, lengths, of N stick lengths (where each length is a positive integer), a cut operation 
//reduces the length of each stick in the array by the length of the array's shortest stick.
//A stick can only be cut if it has a length = 1.

#include<stdio.h>
#include<stdlib.h>

int comparator(const void* x, const void* y) {
	return *(int*)x - *(int*)y;
}

void CutSticks(int* arr, int n) {
	int i, length = 0, y =0;
	qsort(arr, n, sizeof(int), comparator);
	int* res = (int*)malloc(sizeof(int)*n);
	for(i=0; i<n; i++) {
		res[y++] = n-i;
		while(i<n-1 && arr[i] == arr[i+1]) {
			i++;                                                          
		}
	}
	for(i=0; i<y; i++) {
		printf("%d ",res[i]);
	}
}

int main() {
	int n = 8; 
	int arr[] = {1, 2, 3, 4, 3, 3, 2, 1};
	CutSticks(arr, n);
}
