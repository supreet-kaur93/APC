#include<stdio.h>
#include<stdlib.h>

void MatrixSearch(int n1, int n2, int arr[][n2], int no) {
	if(no < arr[0][0]) {
		return;
	}
	if(no > arr[n1-1][n2-1]) {
		return;
	}
	int i;
	for(i=0; i<n1; i++) {
		if(arr[i][n2-1] > no) {
			break;
		}
	}
	int l = 0;
	int r = n2 - 1;
	while(l<=r) {
		int mid = (l+r)/2;
		if(arr[i][mid] == no) {
			printf("1\n");
			return;
		}
		else if(arr[i][mid] > no) {
			r = mid-1;
		}
		else {
			l = mid+1;
		}
	}
	printf("0");
}

int main() {
	int arr[][4] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	int n1 = 3;
	int n2 = 4;
	int no = 4;
	MatrixSearch(n1, n2, arr, no);
}
