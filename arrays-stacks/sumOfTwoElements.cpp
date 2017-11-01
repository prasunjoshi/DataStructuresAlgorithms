//O(n)

#include<bits/stdc++.h>
using namespace std;

bool sum(int a[],int n,int x)
{
    int l=0,r=n-1;
    while(l<r)
    {
        if(a[l]+a[r] < x)   l++;
        if(a[l]+a[r] > x)   r--;
        if(a[l]+a[r] == x)  return true;
    }
    return false;
}
int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};//sorted array
    int n = sizeof(a)/sizeof(a[0]);
    int x = 50;
    if(sum(a,n,x))
        cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
