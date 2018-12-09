//shift all the negative elements to the right side
//of the array while maintaining the original order
//of the positive and negative elements.

#include<stdio.h>
#include<stdlib.h>

void moveElements(int* arr, int n) {
	int i;
	for(i=0; i<n; i++) {
		if(arr[i] < 0) {
			continue;
		}
		int prev = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] <0) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = prev;
	}
	for(i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
}

int main() {
	int n = 10;
	int arr[] = {-6, 7, 13, 10, -8, 15, -9, 2, -1};
	moveElements(arr, n);
}
