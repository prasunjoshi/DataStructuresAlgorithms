//Given a sequence a0,a1,...,an-1, Find the maximum sum from all subsequence of contigous elements in the array

#include<iostream>
using namespace std;

//O(n)
int maxSum(int a[], int n) {
	int s = a[0], m = 0;
	for(int j = 1; j < n; j++) {
		if(s < 0)
			s = 0;
		s = s + a[j];
		if(m < s)
			m = s;
	}
	return m;
}

int main() {
	int a[] = {-2,-3,4,-1,-2,1,5,-3};
	int n = sizeof(a)/sizeof(a[0]);
	//O(n)
	cout<<"\nMaximum sum subsequence = "<<maxSum(a, n)<<endl;
	return 0;
}
