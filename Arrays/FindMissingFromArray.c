#include<stdio.h>
#include<stdlib.h>

int FindMissingUtil(int* arr, int l, int r, int no) {
	while(l<=r) {
		int mid = (l+r)/2;
		if(arr[mid] == no) {
			return 1;
		}
		else if(arr[mid] > no) {
			r = mid-1;
		}
		else l = mid+1;
	}
	return 0;
}

int comparator(const void* x, const void* y) {
	return *(int*)x - *(int*)y;
}

void FindMissing(int* arr1, int n1, int* arr2, int n2) {
	int i;
	qsort(arr2, n2, sizeof(int), comparator);
	for(i=0; i<n1; i++) {
		if(!FindMissingUtil(arr2, 0, n2-1, arr1[i])) {
			printf("%d ",arr1[i]);
			break;
		}
	}
}

int main() {
	int n1 = 5;
	int arr1[] = {1, 2, 3, 4, 5};
	int n2 = 4;
	int arr2[] = {3, 4, 1, 2};
	FindMissing(arr1, n1, arr2, n2);
}
