//O(n)
//max |ai - aj| j = i+l
#include<bits/stdc++.h>
using namespace std;

int maxDiff(int a[],int n,int l)
{
    int j;
    int max = INT_MIN;
    for(int i=0;i<n-l;i++)
    {
        j = i+l;
        if(a[j]-a[i] > max) max = a[j]-a[i];
    }
    return max;
}
int main()
{
    int a[] = {10,21,21,3,4,12,5,6,7,8,9,50};
    int n = sizeof(a)/sizeof(a[0]);
    int l = 3;
    cout<<maxDiff(a,n,l)<<endl;
    return 0;
}
