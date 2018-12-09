// the count of a given number in the array.

#include<stdio.h>
#include<stdlib.h>

int LowerBound(int* arr, int l, int r, int k) {
	while(l<r) {
		int mid = (l+r)/2;
		if(arr[mid] < k) {
			l = mid+1;
		}
		else {
			r = mid;
		}
	}
	return l;
}

int UpperBound(int* arr, int l, int r, int k) {
	while(l<r) {
		int mid = (l+r)/2;
		if(arr[mid] <= k) {
			l = mid+1;
		}
		else r = mid;
	}
	return l;
}

void FindCount(int* arr, int n, int k) {
	int lb = LowerBound(arr, 0, n-1, k);
	int rb = UpperBound(arr, 0, n-1, k);
	printf("%d", rb-lb);
}

int main() {
	int n = 10;
	int arr[] = {1, 2, 2, 5, 5, 5, 7, 7, 7, 8};
	int k = 5;
	FindCount(arr, n, k);
}
