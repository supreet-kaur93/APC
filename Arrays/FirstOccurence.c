#include<stdio.h>
#include<stdlib.h>

int LowerBound(int* arr, int l, int r, int k) {
	while(l<r) {
		int mid = (l+r)/2;
		if(arr[mid] >= k) {
			r = mid;
		}
		else l = mid+1;
	}
	return l;
}

void FirstOccurence(int* arr, int n, int k) {
	int lb = LowerBound(arr, 0, n-1, k);
	if(arr[lb] == k) {
		printf("%d", lb);
	}
	else {
		printf("-1");
	}
}

int main() {
	int n = 10;
	int arr[] = {1, 2, 2, 5, 5, 5, 7, 7, 7, 8};
	int k = 9;
	FirstOccurence(arr, n, k);
}
