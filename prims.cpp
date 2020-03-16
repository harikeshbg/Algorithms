#include<iostream>
#include<stdlib.h>
#include<math.h>
int **graph;
using namespace std;
int findminvertex(int *distance,bool *visited,int n)
{
    int minvertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!(visited[i])&&(minvertex==-1||distance[i]<distance[minvertex]))
            minvertex=i;
    }
    return minvertex;
}
void prims(int n)
{
    bool *visited=new bool[n];
    int *distance=new int[n];
    int *parent=new int[n];

    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    for(int i=0;i<n;i++)
    {
        int minvertex=findminvertex(distance,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++)
        {
            if(!(visited[j])&&graph[minvertex][j]>0&&graph[minvertex][j]<distance[j])
            {
                distance[j]=graph[minvertex][j];
                parent[j]=minvertex;
            }
        }
    }
    cout<<"MST:"<<endl;
        cout<<"v p w"<<endl;
    for(int i=0;i<n;i++)
        cout<<i<<" "<<parent[i]<<" "<<distance[i]<<endl;
}
int main()
{
    int n,e;
    cout<<"Enter the number of vertices:";
    cin>>n;
    cout<<"Enter the number of edges:";
    cin>>e;
    graph=new int *[n];
    for(int i=0;i<n;i++)
        graph[i]=new int[n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=0;
    for(int i=0;i<e;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        graph[s][d]=w;
        graph[d][s]=w;
    }
    prims(n);

}

