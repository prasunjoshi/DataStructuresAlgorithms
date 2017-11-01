//O(n)
//max |ai - aj| j>i+l
#include<bits/stdc++.h>
using namespace std;

int maxDiff(int a[],int n,int l)
{
    int i=0;//index of min element seen so far
    int j=l;
    int max = a[j]-a[i];
    while(j<n)
    {
        if(a[i]>a[j-l]) i=j-l;
        if(a[j]-a[i]>max) max = a[j]-a[i];
        j++;
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
