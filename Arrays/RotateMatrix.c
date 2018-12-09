// rotate matrix 90 degree

#include<stdio.h>
#include<stdlib.h>

void SwapColumns(int column, int row, int arr[][column]) {
	int i, j;
	for(i=0; i<row; i++) {
		int k = column-1;
		for(j=0; j<k; j++) {
			int temp = arr[i][j];
			arr[i][j] = arr[i][k];
			arr[i][k] = temp;
			k--;
		}
	}
}

void Transpose(int rows, int column, int arr[][column]) {
	int i, j;
	for(i=0; i<rows; i++) {
		for(j=i; j<column; j++) {
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}
	}
	SwapColumns(column, rows, arr);
	for(i=0; i<rows; i++) {
		for(j=0; j<column; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}

void RotateArray(int n, int arr[][n]) {
	Transpose(n, n, arr);
}

int main() {
	int n = 3; 
	int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	RotateArray(n, arr);
}
