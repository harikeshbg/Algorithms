#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int count;
int G[10][10],A[10];

void dfs(int i,int n)
{
    count=count+1;
    A[i]=count;
    for(int j=0;j<n;j++)
    {
        cout<<"i:"<<i<<" j:"<<j<<endl;
        if(A[j]==0&&G[i][j]==1)
            dfs(j,n);
    }
}

void DFS(int n,int sv)
{
    for(int i=0;i<n;i++)
        A[i]=0;
    count=0;
    dfs(sv,n);
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
            dfs(i,n);
    }

}

int main()
{
    cout<<"C++ Program to implement Depth First Search Algorithm."<<endl;
    cout<<"Enter the number of vertices:";
    int n;
    cin>>n;
    cout<<"Enter Adjacency relation of the graph in the form of matrix (row-wise)."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>G[i][j];
    }
    int sv;
    cout<<"Enter the starting vertex:";
    cin>>sv;
    DFS(n,sv);
    cout<<"The graph in the order DFS algorithm visited is "<<endl;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
    return (0);
}

