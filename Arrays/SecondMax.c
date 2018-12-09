#include<stdio.h>
#include<stdlib.h>

void FindMax(int* arr, int n) {
	int i, Sec_Max = INT_MIN, max = INT_MIN, count = 0;
	for(i=0; i<n; i++) {
		if(arr[i] > max) {
			Sec_Max = max;
			max = arr[i];
		}
		else if(Sec_Max < arr[i] && arr[i] != max) {
			Sec_Max = arr[i];
		}
		else if(max == arr[i]) {
			count++;
		}
   }
   if(count == n-1) {
   	printf("%d ",arr[0]);
   }
   else
	printf("%d ",Sec_Max);
}

int main() {
	int arr[] = {2, 3, 5, 4, 5, 1};
	FindMax(arr, 6);
}
