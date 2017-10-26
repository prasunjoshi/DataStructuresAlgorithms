//A^n

#include<bits/stdc++.h>
using namespace std;

void multiply(int a[2][2], int b[2][2]){
    int w = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    int x = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    int y = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    int z = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    
  //  int c[2][2];
    b[0][0] = w;
    b[0][1] = x;
    b[1][0] = y;
    b[1][1] = z;
}

void power(int a[2][2], int n){
    int y[2][2] = {{1,0},{0,1}};
    while(n){
        if(n&1) multiply(a,y);
        multiply(a,a);
        n/=2;
    }
     for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            a[i][j] = y[i][j];
        }
    }
    
}

int main()
{
    int a[2][2] = {{1,2},{1,2}};
    int n = 2;
    //int b[2][2];
    power(a,n);
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
