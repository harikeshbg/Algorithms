#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
void hpsrt(int *H,int n)
{
    for(int i=(ceil(n/2)-1);i>=0;i--)
    {
        int k=i;
        int v=H[k];
        bool heap=false;
        while(!(heap)&&((2*k+1)<=n-1))
        {
            int j=(2*k)+1;
            if(j<n-1)
            {
                if(H[j+1]>H[j])
                    j=j+1;
            }
            if(v>H[j])
                heap=true;
            else
            {
                H[k]=H[j];
                k=j;
            }
        }
        H[k]=v;
    }
}
void swapfn(int *H,int i)
{
    int t=H[0];
    H[0]=H[i];
    H[i]=t;
}
int main()
{
    int *arr,n;
    cout<<"Enter the number of elements :";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
        arr[i]=((rand()%(80000-0+1))+0);
    cout<<"Before heapify:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    int i=n-1;
    while(i>=2)
    {
        hpsrt(arr,i);
        swapfn(arr,i);
        i--;
    }
    cout<<endl<<"After heapify"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

}


