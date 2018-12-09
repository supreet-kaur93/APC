#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    1 3 5
    2 6 9
    3 6 9
*/

int UpperBound(int l, int r, int i, int no,int a[][r]) {
	while(l<r) {
		int mid = l+(r-l)/2;
		if(a[i][mid] <= no) {
			l = mid+1;
		}
		else r = mid;
	}
	return l;
}

void FindMedian(int n, int arr[][n]) {
	int i, min = 100, max = 0;
	for(i=0; i<n; i++) {
		if(arr[i][n-1] > max) {
			max = arr[i][n-1];
		}
		if(arr[i][0] < min) {
			min = arr[i][0];
		}
	}
	int res = n*n;
	res = (n+1)/2;
	while(min<max) {
		int mid = min+(-min+max)/2;
		int lb = 0;
		for(i=0; i<n; i++) {
			lb = lb+ UpperBound(0 ,n ,i ,mid, arr);
		}
		if(res > lb) {
			min = mid+1;
		}
		else {
			max = mid;
		}
	}
	printf("%d\n", min);
}

int main() {
	int arr[][3] = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
	FindMedian(3, arr);
}
