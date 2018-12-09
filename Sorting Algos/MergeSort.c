#include<stdio.h>
#include<stdlib.h>

void Merge(int* arr, int l, int mid, int r) {
	int n1 = mid-l+1;
	int n2 = r-mid;
	int L[n1];
	int R[n2];
	int i;
	for(i=0; i<n1; i++) {
		L[i] = arr[l+i];
	}
	for(i=0; i<n2; i++) {
		R[i] = arr[mid+i+1];
	}
	i=0;
	int j = 0, y = l;
	while(i<n1 && j<n2) {
		if(L[i] <= R[j]) {
			arr[y++] = L[i++];
		}
		else {
			arr[y++] = R[j++];
		}
	}
	while(i<n1) {
		arr[y++] = L[i++];
	}
	while(j<n2) {
		arr[y++] = R[j++];
	}
}

void MergeSort(int* arr, int l, int r) {
	if(l<r) {
	    int mid = l+(r-l)/2;
	    MergeSort(arr, l, mid);
	    MergeSort(arr, mid+1, r);
	    Merge(arr, l, mid, r);
    }
}

void Display(int* arr, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
}

int main() {
	int n = 5;
	int arr[] = {3, 4, 2, 1, 5};
	MergeSort(arr, 0, 4);
	Display(arr, 5);
}
