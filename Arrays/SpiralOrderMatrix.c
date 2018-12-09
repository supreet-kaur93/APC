#include<stdio.h>
#include<stdlib.h>

/*
    1 2 3
    8 9 4
	7 6	5    

*/
void PrintSpiral(int rows, int column, int arr[][column]) {
	int n = 0;
	int m = 0, i;
	while(n<rows && m<column) {
		for(i=m ;i<column; i++) {
			printf("%d ", arr[n][i]);
		}
		n++;
		for(i=n; i<rows; i++) {
			printf("%d ",arr[i][column-1]);
		}
		column--;
		if(n < rows) {
		    for(i=column-1; i>=m; i--) {
			    printf("%d ",arr[rows-1][i]);
		    }
	    }
		rows--;
		if(m < column) {
		    for(i=rows-1; i>=n; i--) {
			    printf("%d ",arr[i][m]);
		    }
	    }
		m++;
	}
}

int main() {
	int rows = 3;
	int column = 3;
	int arr[][3] = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
	PrintSpiral(rows, column, arr);
}
