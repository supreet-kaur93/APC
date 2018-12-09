#include<stdio.h>
#include<stdlib.h>

int CountPages(int* arr, int n, int no) {
	int i, sum = 0, c = 1;
	for(i=0; i<n; i++) {
		if(sum+arr[i] > no) {
			sum = arr[i];
			c++;
		}
		else {
			sum = sum + arr[i];
		}
	}
	return c;
}

void AllocateBooks(int* arr, int n, int stud) {
	int sum = 0;
	int max = 0, min, i;
	for(i=0; i<n; i++) {
		sum = sum+arr[i];
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	min = max;
	max = sum;
	int res = -1;
	while(min<=max) {
		int mid = (min+max)/2;
		if(CountPages(arr, n, mid) <= stud) {
			max = mid-1;
			res = mid;
		}
		else {
			min = mid+1;
		}
	}
	printf("%d ",res);
}

int main() {
	int arr[] = {12,34, 67, 90};
	int n = 2;
	AllocateBooks(arr, 4, n);
}
