#include<stdio.h>
#include<stdlib.h>

void SquareRoot(int no) {
	int l = 1;
	int r = no;
	int mid = 0, res = 0;
	while(l<=r) {
		mid = (l+r)/2;
		if((mid*mid) == no) {
			printf("%d ",mid);
			return;
		}
		else if((mid*mid) > no) {
			r = mid-1;
		}
		else {
			res = mid;
			l = mid+1;
		}
	}
	printf("%d ",res);
}

int main() {
	int no = 11;
	SquareRoot(no);
}
