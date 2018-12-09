// Search Element in rotated sorted array

#include<stdio.h>
#include<stdlib.h>

void BinarySearch(int* arr, int l, int r, int no) {
	int flag = 0;
	while(l<=r) {
		int mid = (l+r)/2;
		if(arr[mid] == no) {
			printf("%d ",mid);
			flag = 1;
			break;
		}
		else if(arr[mid] > no) {
			r = mid-1;
		}
		else l = mid+1;
	}
	if(flag == 0) {
		printf("-1");
	}
}

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

void SortedRotatedSearch(int* arr, int n, int k) {
	int pivot = FindPivot(arr, 0, n-1);
	if(pivot == -1) {
		BinarySearch(arr, 0, n-1, k);
	}
	else if(arr[pivot] == k) {
		printf("%d ", pivot);
		return;
	}
	else if(arr[0] < k) {
		BinarySearch(arr, 0, pivot-1, k);
	}
	else {
		BinarySearch(arr, pivot+1, n-1, k);
	}
}

int main() {
	int n = 6;
	int arr[] = {15, 18, 2, 3, 6, 12};
	int k = 3;
	SortedRotatedSearch(arr, n, k);
}
