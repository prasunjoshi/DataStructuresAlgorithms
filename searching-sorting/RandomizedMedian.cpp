//algo to find kth smallest element in an array
//same as finding element with a given rank
//running time = O(n)
//Randomized Algorithm
/****Also known as RANDOMIZED QUICKSELECT****/

#include<iostream>
#include<cstdlib>
#include<climits>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int a[], int l, int r) {
	int x = a[r], i = l;
	for(int j = l; j <= r-1; j++) {
		if(a[j] <=x) {
			swap(&a[i], &a[j]);
			i++;
		}
	}
	swap(&a[i], &a[r]);
	return i;
}

int randomPartition(int a[], int l, int r) {
	int n = r-l+1;
	int pivot = rand() % n;
	swap(&a[l + pivot], &a[r]);
	return partition(a, l, r);
}

int kthsmallest(int a[], int l, int r, int k) {
	if(k > 0 && k <= r - l + 1) {
		int pos = randomPartition(a, l, r);
		if(pos-l == k-1)
			return a[pos];
		if(pos-l > k-1)
			return kthsmallest(a, l, pos-l, k);
		return kthsmallest(a, pos+1, r, k-pos+l-1);
	}
	return INT_MAX;
}

int main() {
	int a[] = {12,3,5,7,4,19,26};
	int n = sizeof(a)/sizeof(a[0]), k = 3;

	cout<<kthsmallest(a, 0, n-1, k);
	cout<<endl;
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	return 0;
}

