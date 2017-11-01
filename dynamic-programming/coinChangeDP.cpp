 //number of ways to have change of n cents given coin
//denominations available in infinite quantity

#include <bits/stdc++.h>

using namespace std;

long getMin(int n, vector < int > c){
    int m = c.size();
    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=m;i++)    dp[i][0] = 0;
   for(int i=0;i<=n;i++)   dp[0][i] = 0;
    for(int i=1;i<=n;i++)   dp[1][i] = i;
    for(int i=2;i<=m;i++)
    {
        for(int j=c[0];j<=n;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= c[i-1] && ((dp[i][j-c[i-1]] + 1) < dp[i][j]))
            {
                dp[i][j] = dp[i][j-c[i-1]] + 1;
            }
        }
    }

    //backtracking
    int i = m,j=n;
 //   stack<int> coins;
    while(i && j)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else
        {
            cout<<c[i-1]<<" ";
//            coins.push(c[i]);
            j = j - c[i-1];
        }
    }
    cout<<endl;
    return dp[m][n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    int mn = getMin(n, c);
    cout<<mn;
    return 0;
}
