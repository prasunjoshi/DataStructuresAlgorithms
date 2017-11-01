#include<bits/stdc++.h>
using namespace std;

int max_sum(int a[], int n, int k)
{
    int result = INT_MIN,sum=0;
    for(int i=0;i<k;i++)
    {
        sum += a[i];
    }
    result = sum;
    for(int i=k;i<n;i++)
    {
        if(sum + a[i]-a[i-k]>result) result = sum + a[i] - a[i-k];
    }
    return result;
}

int main()
{
    int a[] = {1,4,2,10,20,-3,14,-24,30};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 3;
    cout<<max_sum(a,n,k)<<endl;
    return 0;
}
