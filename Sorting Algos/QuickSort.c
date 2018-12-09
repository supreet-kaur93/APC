#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* arr, int l, int r) {
	int pivot = arr[r];
	int i = l-1, j;
	for(j=l; j<=r-1; j++) {
		if(arr[j] <=pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}

void QuickSort(int* arr, int l, int r) {
	int i;
	if(l>r) {
		return;
	}
	int pi = Partition(arr, l, r);
	QuickSort(arr, l, pi-1);
	QuickSort(arr, pi+1, r);
}

void Display(int* arr, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
}

int main() {
	int n = 5;
	int arr[] = {2, 3, 5, 4, 1};
	QuickSort(arr, 0, n-1);
	Display(arr, n);
}
