#include<stdio.h>
#include<stdlib.h>

void Reverse(int* arr, int l, int r) {
	while(l<r) {
		int temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
		l++;
		r--;
	}
}

void Display(int* arr, int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%d ",arr[i]);
	}
}

void RotateList(int* arr, int n, int rotate) {
	int i;
	rotate = rotate%n;
	Reverse(arr, 0, rotate-1);
	Reverse(arr, rotate, n-1);
	Reverse(arr, 0, n-1);
	Display(arr, n);
}

int main() {
	int n = 9;
	int arr[] = {3, 5, 2, 1, 7, 5, 9, 15, 11};
	int rotate = 10;
	RotateList(arr, n, rotate);
}
