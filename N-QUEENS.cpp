#include<iostream>
#include<stdlib.h>
using namespace std;
int n;
int place(int k,int i,int cols[])
{
    for(int j=0;j<k;j++)
    {
        if(cols[j]==i)
            return 0;
        if(abs(k-j)==abs(i-cols[j]))
            return 0;
    }
    return 1;
}
void printsol(int cols[],int n)
{
    char arr[n][n];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j]='X';
    cout<<endl<<"Solution:"<<endl;
    for(int m=0;m<n;m++)
       arr[m][cols[m]]='O';
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

}
void nqueens(int k,int n,int cols[])
{
    for(int i=0;i<n;i++)
    {
        if(place(k,i,cols))
        {
            cols[k]=i;
            if(k==n-1)
                printsol(cols,n);
            else
                nqueens(k+1,n,cols);
        }
    }
}
int main()
{
    cout<<"Enter the number of queens:";
    cin>>n;
    char arr[n][n];
    int cols[n];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            arr[i][j]='0';
    nqueens(0,n,cols);
}
