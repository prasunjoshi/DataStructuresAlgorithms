#include<bits/stdc++.h>
using namespace std;

long long int pow(long long int x, long long int n)
{
    if(n==0) return 1;
    else if(n==1) return x;
    else if(n&1)    return x*pow(x*x,n/2);
    return pow(x*x,n/2);
}

int main()
{
    long long int x,n;
    cin>>x>>n;
    cout<<pow(x,n)<<endl;
    return 0;
}
