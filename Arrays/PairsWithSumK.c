#include<stdio.h>
#include<stdlib.h>

int findNum(int* arr, int l, int r, int diff, int n) {
	int count = 0, mid = 0;
	while(l<r) {
		mid = (l+r)/2;
		if(diff > arr[mid]) {
			l = mid+1;
		}
		else {
			r = mid;
		}
	}
	while(l<n && arr[l] == diff) {
		count++;
		l++;
	}
	return count;
}

void FindSum(int* arr, int n, int sum) {
	int i, c = 0;
	for(i=0; i<n; i++) {
		int diff = sum - arr[i];
		c = c+findNum(arr, i+1, n, diff, n);
	}
	printf("%d ",c);
}

int main() {
	int n = 10;
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int sum = 11;
	FindSum(arr, n, sum);
}
