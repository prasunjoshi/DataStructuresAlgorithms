//Given an array, find next smaller element for all the elements in the array
//Store in an array B[].

#include<iostream>
using namespace std;

void printarray(int a[], int n) {
	for(int i = 0; i < n; i++) 
		cout<<a[i]<<" ";
	cout<<endl;
}

void nextGreateElement(int a[], int n) {
	int i = 0, s[n], b[n], j;
	s[0] = 0;

	for(j = 1; j < n; j++) {
		while(i >= 0 && a[s[i]] < a[j]) {
			b[s[i]] = j;
			i--;
		}
		s[++i] = j;
	}

	while(i >= 0) {
		b[s[i--]] = -1;
	}

	cout<<"Final array:\n";
	printarray(b, n);
}

int main() {
	int a[] = {3,6,8,7,5,2,9,10};
	int n = sizeof(a)/sizeof(a[0]);

	cout<<"Initial array:\n";
	printarray(a, n);

	nextGreateElement(a, n);
	
	return 0;
}
