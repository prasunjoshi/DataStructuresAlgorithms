//O(n)
//max |ai - aj| j>i
#include<bits/stdc++.h>
using namespace std;

int maxDiff(int a[],int n)
{
    int i=0;//index of min element seen so far
    int j=1;
    int max = a[j]-a[i];
    while(j<n)
    {
        if(a[i]>a[j-1]) i=j-1;
        if(a[j]-a[i]>max) max = a[j]-a[i];
        j++;
    }
    return max;
}
int main()
{
    int a[] = {1,21,21,3,4,5,6,7,8,9,10};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<maxDiff(a,n)<<endl;
    return 0;
}
