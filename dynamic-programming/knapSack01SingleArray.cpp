///0/1 Knapsack Problem
///weights w1,w2,....,wn | values v1,v2,...,vn  |  capacity W
///Time O(nw)
///Space O(w)


#include<bits/stdc++.h>
using namespace std;
int solveKnap(int w[],int p[],int n, int W)
{
    int v[W+1];
    int u[W+1];

    for(int i = 0; i <= W; i++)
        v[i] = 0;
    for(int i = 0; i <= W; i++)
        u[i] = 0;


     for(int j = 1; j <= n; j++) {
       for(int i = 1; i <= W; i++) {
            v[i] = u[i-1];
            if(i >= w[j-1] && v[i] < p[j-1] + u[i-w[j-1]]) {

                    v[i] = p[j-1] + u[i-w[j-1]];
            }
        }
        for(int i = 0; i <= W; i++)
            u[i] = v[i];
    }
    return v[W];
}
int main()
{
    int w[] = {10,20,30};
    int n = sizeof(w)/sizeof(w[0]);
    int p[] = {60,100,120};
    int W = 50;

    cout<<solveKnap(w,p,n,W);
    return 0;
}
