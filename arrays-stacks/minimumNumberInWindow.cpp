//Given a array and a window size, find smallest element in each window in the array.
//input = [3,6,8,7,5,2,9,10]
//output = [3,6,5,2,2,2]
#include<bits/stdc++.h>
using namespace std;

void minWindow(int a[],int n,int k)
{
    int l=0,r=0,j=1;
    int s[n-k+1];
    s[l] = 0;
    while(j<n)
    {
        while(r>=l && a[j]<a[s[r]])
            r--;
        s[++r] = j;
        if(j>=k-1)
        {
            if(s[r]-s[l]>=k)
            {
                l++;
            }
            cout<<a[s[l]]<<" ";
        }
        j++;
    }
}

int main()
{
    int a[] = {3,6,8,7,5,2,9,10};
    int n = sizeof(a)/sizeof(a[0]);
    int l = 3;
    minWindow(a,n,l);
    return 0;
}
