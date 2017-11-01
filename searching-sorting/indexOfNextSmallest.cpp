//O(n)
#include<bits/stdc++.h>
using namespace std;

void nextSmallest(int a[],int n)
{
    int s[100],b[100];
    int top = -1,j=0;
    s[++top] = j;
    for(j=1;j < n;j++)
    {
        if(a[j]>a[s[top]])
        {
            s[++top] = j;
        }
        else{
            while(top >= 0 && a[j]<a[s[top]])
            {
                b[s[top]] = j;
                top--;
            }
            s[++top] = j;
        }
    }
    while(top>-1)
    {
        b[s[top--]]=0;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";(b[i]>0?cout<<a[b[i]]:cout<<"Not Present");cout<<" \n";
    }
}
int main()
{
    int a[] = {3,6,8,7,5,2,9,10};
    int n = sizeof(a)/sizeof(a[0]);
    nextSmallest(a,n);
    return 0;
}
