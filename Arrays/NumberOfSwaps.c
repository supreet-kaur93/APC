// no of swaps in different algorithms

#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int* arr, int n) {
	int i, j, c = 0;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-i-1; j++) {
			if(arr[j] > arr[j+1]) {
				c++;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("%d\n", c);
}

void SelectionSort(int* arr, int n) {
	int i, j, count = 0;
	for(i=0; i<n-1; i++) {
		int min = i;
		int flag = 0;
		for(j=i+1; j<n; j++) {
			if(arr[j] < arr[min]) {
				min = j;
			}
		}
		if(i != min) {
			count++;
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	printf("%d\n", count);
}

void InsertionSort(int* arr, int n) {
	int i, count = 0;
	for(i=1; i<n; i++) {
		int j = i-1;
		int flag = 0;
		int key = arr[i];
		while(j>=0 && arr[j]>key) {
			arr[j+1] = arr[j];
			flag = 1;
			count++;
			j--;
		}
		if(flag == 1) {
			count++;
			arr[j+1] = key;
		}
	}
	printf("%d\n", count);
}

int main() {
	int n = 10;
	int arr[] = {123, 21, 34, 45, 25, 675, 23, 44, 55, 900};
	BubbleSort(arr, n);
	// For Selection Sort
	int n2 = 5;
	int arr2[] = {10, 11, 8, 7, 1};
	SelectionSort(arr2, n2);
	// For Insertion Sort
	int n3 = 5; 
	int arr3[] = {2, 4, 1, 3, 5};
	InsertionSort(arr3, n3);
}
