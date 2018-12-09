#include<stdio.h>
#include<stdlib.h>

int CountPeople(int* arr, int mid, int n) {
	int sum = 0, c = 1, i;
	for(i=0; i<n; i++) {
		if(sum+arr[i] > mid) {
			sum = arr[i];
			c++;
		}
		else {
			sum = sum+arr[i];
		}
	}
	return c;
}

void PaintersPartition(int* arr, int time, int k, int n) {
	int min = 100;
	int max = 0, sum = 0, i;
	for(i=0; i<n; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
		sum = sum + arr[i];
	}
	min = max; 
	max = sum;
	while(min<max) {
		int mid = (min+max)/2;
		if(CountPeople(arr, mid, n) <= k) {
			max = mid;
		}
		else {
			min = mid+1;
		}
	}
	printf("%d ", max*time);
}

int main() {
	int k = 2;
	 int time = 5; 
	 int arr[] = {1, 10};
	 PaintersPartition(arr, time, k, 2);
}
