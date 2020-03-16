#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;
int part(int *A,int l,int r)
{
    int x=A[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(A[j]<=x)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
void qcksrt(int *A,int l,int r)
{
    if(l<r)
    {
        int s=part(A,l,r);
        qcksrt(A,0,s-1);
        qcksrt(A,s+1,r);
    }
}
int main()
{
    srand(time(0));
    int *arr,n;
    cout<<"Enter the number of elements:";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
        arr[i]=((rand()%(80000-0+1))+0);
    cout<<"Unsorted-array:"<<endl;
     for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    qcksrt(arr,0,n-1);
    cout<<endl<<endl<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}
