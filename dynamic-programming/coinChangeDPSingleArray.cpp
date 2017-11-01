//minimum coins using denominations c array

#include <bits/stdc++.h>

using namespace std;

long getMin(int n, vector < int > c){
    int m = c.size();
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    for(int i=1;i<=n;i++)   dp[i] = i;
    for(int i=2;i<=m;i++)
    {
        for(int j=c[0];j<=n;j++)
        {
            if(j >= c[i-1] && ((dp[j-c[i-1]] + 1) < dp[j]))
            {
                dp[j] = dp[j-c[i-1]] + 1;
            }
        }
    }
    return dp[n];
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

