#include<bits/stdc++.h>
using namespace std;

void printarray(int a[], int p, int b) {
    for(int i = p; i <= b; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int rPivot(int p,int q)
{
    return (rand() % (q-p+1)) + p;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[],int p, int q)
{
    int l=p,r=q-1;
    while(l<=r)
    {
        while(l<=r && a[l]<a[q]){
            l++;
        }
        while(l<=r && a[r]>a[q]){
            r--;
        }
        if(l<=r) {
            swap(&a[l],&a[r]);
            l++;
            r--;
        }
    }
    swap(&a[l],&a[q]);
    return l;
}

void quickSort(int a[],int p, int q)
{
//    cout<<"Qsort";
    if(p<q)
    {
        int r = rPivot(p,q);
//        cout<<"pivot = "<<a[r]<<" array is:\n";
        printarray(a,p,q);
        swap(&a[r],&a[q]);
        printarray(a,p,q);
        int s = partition(a,p,q);
//        cout<<"array after partition:\n";
        printarray(a,p,q);
        
        quickSort(a,p,s-1);
        quickSort(a,s+1,q);
    }
}

int main()
{
    int a[] = {2,8,7,0,3,17,9,4,1,6};
    int n = sizeof(a)/sizeof(a[0]);
  cout<<"Initial array\n";
    printarray(a,0,n-1);
        
    quickSort(a,0,n-1);
    for(int i=0;i<n;i++)    cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
