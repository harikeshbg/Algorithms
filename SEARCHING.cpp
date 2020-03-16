#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>
using namespace std;
int linsearch(int arr[],int s,int pos,int key)
{
    int kpos
    if(pos<size)
    {
        if(arr[pos]==key)
            return pos;
        kpos=linsearch(arr,s,pos+1,key);
        return kpos;
    }
    return -1;
}
int binsearch(int arr[],int low,int high,int k)
{
    int mid,kpos;
    if(low<=high)
    {
        mid=(low+high)/2;
        if(k==arr[mid])
            return mid;
        if(k<arr[mid])
            kpos=binsearch(arr,low,mid-1,k);
        if(k>arr[mid])
            kpos=binsearch(arr,mid+1,high,k);
        return kpos;
    }
    return -1;
}
void bsort(int arr[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++)
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
}
int main()
{
    srand(time(0));
    int *arr,key,n,res,choice;
    cout<<"Enter the number of elements:";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;i++)
        arr[i]=((rand()%(20000-0+1))+0);
    cout<<"Array elements:"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    bsort(arr,n);
    cout<<endl<<endl<<endl<<"Sorted array:";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl<<"Enter the key element between 0 and 20000:";
    cin>>key;

    res=binsearch(arr,0,n-1,key);
    if(res==-1)
        cout<<"Key not found"<<endl;
    else
        cout<<"Key found at position:"<<res+1<<endl;
    return 0;

}

