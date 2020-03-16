#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int cnt=0;
using namespace std;
void mergealgorithm(int B[],int p,int C[],int q,int A[])
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        if(B[i]<=C[j])
        {
            cnt++;
            A[k]=B[i];
            i++;
        }
        else
        {
            cnt++;
            A[k]=C[j];
            j++;
        }
        k++;
    }
    if(i==p)
    {
        for(int l=j;l<q;l++)
        {
            A[k]=C[l];
            k++;
        }
    }
     if(j==q)
    {
        for(int m=i;m<p;m++)
        {
            A[k]=B[m];
            k++;
        }
    }
}
void mergesort(int A[],int n)
{
    if(n>1)
    {
        int bs,cs;
        if(n%2!=0)
        {
            bs=floor(n/2);
            cs=floor(n/2+1);
        }
        if(n%2==0)
        {
            bs=n/2;
            cs=n/2;
        }
        int B[bs];
        int C[cs];
        int i;
        for(i=0;i<bs;i++)
            B[i]=A[i];
        for(int j=0;j<cs;j++)
        {
            C[j]=A[i];
            i++;
        }
        mergesort(B,bs);
        mergesort(C,cs);
        mergealgorithm(B,bs,C,cs,A);
    }
}
int main()
{
    srand(time(0));
    int n,*arr;
    cout<<"Enter the number of elements :";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
        arr[i]=((rand()%(80000-0+1))+0);
    cout<<"ARRAY:"<<endl<<endl;
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    mergesort(arr,n);
     cout<<endl<<endl<<endl<<"SORTED ARRAY:"<<endl<<endl;
    for(int k=0;k<n;k++)
        cout<<arr[k]<<" ";
    cout<<endl<<endl<<"number of comparisions:"<<cnt<<endl;
    return 0;
}
