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
void dijkstras(int n,int sv)
{
    bool *visited=new bool[n];
    int *distance=new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
        distance[i]=INT_MAX;
    }
    distance[sv]=0;
    for(int i=0;i<n-1;i++)
    {
        int minvertex=findminvertex(distance,visited,n);
        visited[minvertex]=true;
        for(int j=0;j<n;j++)
        {
            if(graph[minvertex][j]>0&&!(visited[j]))
            {
                int newdist=distance[minvertex]+graph[minvertex][j];
                if(newdist<distance[j])
                    distance[j]=newdist;
            }
        }
    }
    cout<<"Shortest distances:"<<endl;
    for(int i=0;i<n;i++)
        cout<<distance[i]<<" ";
}
int main()
{
    int n,e;
    cout<<"Enter the number of vertices:";
    cin>>n;
    cout<<"Enter the number of edges:";
    cin>>e;
    int sv;
    cout<<"Enter the starting vertex:";
    cin>>sv;
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
    dijkstras(n,sv);

}
