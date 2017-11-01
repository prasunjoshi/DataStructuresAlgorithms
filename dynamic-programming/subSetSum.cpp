#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int a[],int n, int x)
{
    bool dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
    {
        dp[i][0] = true;
    }
    for(int i=1;i<=x;i++)
    {
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {

            if(j-a[i-1] >= 0)
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            else
            {
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][x];
}

int main()
{
    int x = 6;
    int a[] = {9,5,3,7,4,10};
    int n = (sizeof(a)/sizeof(a[0]));
    cout<<"Is it possible that subset of array is equal to a number X? \n"<<(subsetSum(a,n,x)?"Yes":"No");
    return 0;
}
