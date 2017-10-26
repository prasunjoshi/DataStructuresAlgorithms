#include<bits/stdc++.h>

using namespace std;

long long int power(long long int x, long long int n)
{
    long long int y =1;
    while(n)
    {
        if(n&1) y = y * x;
        x = x * x;
        n/=2;
    }
    return y;
}

int main()
{
    long long int x,n;
    cin>>x>>n;
    cout<<power(x,n)<<endl;
    return 0;
}
