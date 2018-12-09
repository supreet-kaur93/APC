// Rotation Count

#include<stdio.h>
#include<stdlib.h>

int FindPivot(int* arr, int l, int r) {
	if(l>r) {
		return -1;
	}
	int mid = (l+r)/2;
	if(mid < r && arr[mid] > arr[mid+1]) {
		return mid;
	}
	if(mid > l && arr[mid] < arr[mid-1]) {
		return mid-1;
	}
	if(arr[mid] > arr[l]) {
		return FindPivot(arr, l, mid-1);
	}
	else return FindPivot(arr, mid+1, r);
}

void SortedRotatedSearch(int* arr, int n) {
	int pivot = FindPivot(arr, 0, n-1);
	if(pivot == -1) {
		printf("-1");
	}
	else {
		printf("%d", pivot+1);
	}
}

int main() {
	int n = 6;
	//int arr[] = {1, 2, 3, 4, 5, 6};
	int arr[] = {15, 18, 2, 3, 6, 12};
	SortedRotatedSearch(arr, n);
}
