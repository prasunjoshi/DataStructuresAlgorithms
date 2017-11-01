//O(n) max aj-ai where j<i+k

#include<bits/stdc++.h>
using namespace std;

int minWindow(int a[],int n,int k)
{
    int temp=0;
    int l=0,r=0,j=1;
    int s[n-k+1];
    s[l] = 0;
    int max = 0;
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
            temp = s[l];
            if(a[j]-a[temp]>max) 
                max = a[j]-a[temp];
           // cout<<a[s[l]]<<" ";
        }
        cout<<max<<" ";
        j++;
    }
    cout<<endl;
    return max;
}

int main()
{
    int a[] = {3,6,8,7,5,2,9,10};
    int n = sizeof(a)/sizeof(a[0]);
    int l = 3;
    cout<<minWindow(a,n,l)<<endl;
    return 0;
}
