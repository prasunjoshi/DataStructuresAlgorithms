//O(n)

#include<bits/stdc++.h>
using namespace std;

bool minDiff(int a[],int n)
{
    int min = INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]-a[i] < min)   min = a[i+1]-a[i];
    }
    return min;
}
int main()
{
    int a[] = {1,21,21,3,4,5,6,7,8,9,10};//sorted array
    int n = sizeof(a)/sizeof(a[0]);
    sort(a,a+n); //sort if array is not sorted O(nlogn)
    cout<<minDiff(a,n)<<endl;
    return 0;
}
