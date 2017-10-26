//F(N) = F(N-1) + F(N-3) in (logn)^3 where n is large

#include<bits/stdc++.h>
int MOD;
using namespace std;

void printmat(int a[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j =0 ; j<3;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void multiply(int a[3][3], int b[3][3]){
    
    int c[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c[i][j] = ((a[i][0]*b[0][j])%MOD + (a[i][1]*b[1][j])%MOD + (a[i][2]*b[2][j])%MOD);
        }
    }
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j] = c[i][j];
        }
    }
}
void copy(int a[3][3],int b[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j] = b[i][j];
        }
    }
}

void powerex(int a[3][3], int n)
{
    int y[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    while(n>0){
        if(n&1)
        {
            multiply(y,a);
        }
        multiply(a,a);
        n/=2;
    }
    copy(a,y);
}
void power(int a[3][3], int n[], int k){
    int y[3][3] = {{1,0,0},{0,1,0},{0,0,1}};
    int i = k - 1;
    while(i >= 0){
        if(n[i] > 0) 
        {
            //y  = y * a^n[i]
            int temp[3][3];
            copy(temp,a);

 //           cout<<"Temp: \n";
 //           printmat(temp);
            
            powerex(temp,n[i]);
            multiply(y,temp);

//            cout<<"Y: \n";
//            printmat(y);
        }
        //a = a^10;
        powerex(a,10);

//        cout<<"a: \n";
//        printmat(a);
        i--;
    }
//    cout<<"Y before copy(a,y):\n";
//    printmat(y);

    copy(a,y);
}

int main()
{
    srand(time(NULL));
    MOD = (rand()%100)+1;

    printf("m: %d\n",MOD);
    int a[3][3] = {{1,0,1},{1,0,0},{0,1,0}};
    int temp[3][3];
    copy(temp,a);
    int n[1];
    //  cout<<"Enter term number : ";
   // cin>>n;
    //int b[2][2];
    for(int i=1;i<=9;i++){
        n[0] = i;
        power(temp,n,(sizeof(n)/sizeof(int)));
        printmat(temp);
        printf("%dterm of series: %d\n",n[0],temp[1][0]);
        copy(temp,a);
    }
        return 0;
}
