//Given an array, find next smaller element for all the elements in the array
//Store in an array B[].

#include<iostream>
using namespace std;

void printarray(int a[], int n) {
	for(int i = 0; i < n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

//O(n^2) method
void nextSmallerElement(int a[], int n) {
	int b[n],j;
	for(int i = 0; i < n; i++) {
		for(j = i + 1; j < n; j++) {
//			cout<<"a[i] = "<<a[i]<<" a[j] = "<<a[j]<<endl;
			if(a[j] < a[i]) {
				b[i] = j;
				break;
			}
		}
		if(j == n)
			b[i] = 0;
//		cout<<"b[i] = "<<b[i]<<endl;
	}
	
	
	cout<<"Array of next smaller element: \n";
	printarray(b, n);

}
	
//O(n) method
//traverse through array
//push into stack if element is greater
//while element is smaller than top of stack, pop the stack and update b[i] = index of element
//push smaller element index onto stack
//at last simply pop everything from stack and update b[i] = 0
void nextSmallerElement1(int a[], int n) {
	int i, j, s[n], b[n];

	i = 0; s[i] = 0;
	for(j = 1; j < n; j++) {
		if(a[j] > a[s[i]])
			s[++i] = j;
		else {
			while(a[j] < a[s[i]] && i >= 0){
				b[s[i]] = j;
				i--;
			}
			s[++i] = j;	
		}
	}
	while(i >= 0)
		b[s[i--]] = 0;

	cout<<"\nArray of next smaller element:\n";
	printarray(b, n);

}

int main() {
	int a[] = {3,6,8,7,5,2,9,10};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout<<"Original array:\n";
	printarray(a, n);

	nextSmallerElement(a, n);
	nextSmallerElement1(a, n);
	return 0;
}
