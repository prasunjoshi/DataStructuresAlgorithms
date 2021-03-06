#include<bits/stdc++.h>
using namespace std;
void printArr(int a[],int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

void bottomUpHeapify(int a[],int i)
{
    int p = (i-1)/2;
    while(p>=0 && a[i]<a[p])
    {
        swap(a[i],a[p]);
        i=p;
        p = (i-1)/2;
    }
}
void topDownHeapify(int a[],int n,int i)
{
    int min;
    while(i <= n)
    {
        min=i;
        if(2*i+1<=n && a[i] > a[2*i+1])
            min = 2*i+1;
        if(2*i+2 <=n && a[min] > a[2*i+2])
            min = 2*i+2;
        if(min!=i)
        {
            swap(a[i],a[min]);
            i = min;
        }
        else if(min == i) break;
   }
}
void buildHeap(int a[], int n)
{
    int i=n/2;
    while(i>=0)
    {
        topDownHeapify(a,n,i);
        i--;
    }
}
void changePriority(int a[],int n,int i,int x)
{
    int p = a[i];
    a[i] = x;
    if(p<x)
    {
        topDownHeapify(a,n-1,i);
    }
    else
    {
        bottomUpHeapify(a,i);
    }
}
int deleteMin(int a[],int n)
{
    if(n>0)
    {
        swap(a[0],a[n-1]);
        n--;
        topDownHeapify(a,n-1,0);
    }
    return n;
}
int addElement(int a[], int n,int i)
{
    a[n++] = i;
    bottomUpHeapify(a,n-1);
    return n;
}
int deleteE(int a[],int n,int i)
{
    changePriority(a,n,i,a[0]-1);
    return deleteMin(a,n);
}
int main()
{
    int a[] = {5,4,2,1,3,7,0,8,9,6};
    int k = 5;
    int n = sizeof(a)/sizeof(a[0]);
    buildHeap(a,k-1);
    cout<<"Heap Before\n";
    printArr(a,k);
    for(int i=k;i<n;i++)
    {
        if(a[i] > a[0])
        {
            swap(a[i],a[0]);
            topDownHeapify(a,k-1,0);
        }
    }
    cout<<"After: \n";
    printArr(a,k);

    return 0;
}
