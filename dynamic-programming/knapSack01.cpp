#include<bits/stdc++.h>
using namespace std;
int solveKnap(int w[],int val[],int n, int weight)
{
    int sack[n+1][weight+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=weight;j++)
        {
            if(!i || !j)
            {
                sack[i][j] = 0;
                continue;
            }
            sack[i][j] = sack[i-1][j];
            if(j>=w[i] && sack[i-1][j] < sack[i][j-w[i]]+val[i])
                sack[i][j] = sack[i-1][j-w[i]] + val[i];
        }
    }

    //backtracking
    int i=n,j=weight;
    while(i && j)
    {
        if(j>=w[i] && sack[i-1][j] < sack[i][j-w[i]]+val[i])
        {
            cout<<w[i]<<" "<<val[i]<<endl;
            j = j - w[i];
            i--;
        }
        else
        {
            i--;
        }
    }

    return sack[n][weight];
}
int main()
{
    int n,weight;
    n = 3,weight = 50;
//    cin>>n>>weight;
//    int w[n+1],val[n+1];
    int w[] = {0,10,20,30};
    int val[] = {0,60,100,120};
//    for(int i=1;i<=n;i++)
//    {
//        cin>>w[i]>>val[i];
//    }
    w[0] = 0;
    val[0] = 0;
    cout<<solveKnap(w,val,n,weight);
    return 0;
}
