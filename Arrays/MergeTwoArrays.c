#include<stdio.h>
#include<stdlib.h>

void merge(int* arr1, int n1, int* arr2, int n2) {
	int i=0, j=0, y=0;
	int* res = (int*)malloc(sizeof(int)*(n1+n2));
	while(i<n1 && j<n2) {
		if(arr1[i] < arr2[j]) {
			res[y++] = arr1[i++];
		}
		else {
			res[y++] = arr2[j++];
		}
	}
	while(i<n1) {
		res[y++] = arr1[i++];
	}
	while(j<n2) {
		res[y++] = arr2[j++];
	}
	for(i=0; i<y; i++) {
		printf("%d ",res[i]);
	}
}

int main() {
	int n1 = 4; 
	int arr1[] = {1, 2, 3, 6};
	int n2 = 3;
	int arr2[] = {4, 5, 7};
	merge(arr1, n1, arr2, n2);
}
