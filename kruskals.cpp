#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class edge
{
    public:int source,dest,weight;
};
bool compare(edge e1,edge e2)
{
    return (e1.weight<e2.weight);
}
int findparent(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    return(findparent(parent[v],parent));
}
void kruskals(edge *input,int n,int e)
{
    sort(input,input+e,compare);//sort the array of edges based on weights using built-in sort function.
    edge *output=new edge[n-1];//the number of edges in the minimum spanning tree of the tree having 'n' edges will be 'n-1'.
    int *parent=new int[n];
    for(int i=0;i<n;i++)
        parent[i]=i;
    int count=0,i=0;
    while(count!=n-1)
    {
        edge currentedge=input[i];
        //check if the parents of source and destination are same.
        int sourceparent=findparent(currentedge.source,parent);
        int destparent=findparent(currentedge.dest,parent);
        if(sourceparent!=destparent)
        {
            output[count]=currentedge;
            count++;
            parent[sourceparent]=destparent;
        }
        i++;
    }
    cout<<endl<<"Minimum spanning tree:"<<endl;
    cout<<"-----"<<endl;
    cout<<"s d w"<<endl<<"-----"<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(output[i].source<output[i].dest)
            cout<<output[i].source<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        else
            cout<<output[i].dest<<" "<<output[i].source<<" "<<output[i].weight<<endl;
    }
}
int main()
{
    int e,n;
    cout<<"Enter the number of edges:";
    cin>>e;
    cout<<"Enter the number of vertices:";
    cin>>n;
    edge *input=new edge[e];
    for(int i=0;i<e;i++)
    {
        cout<<endl<<"Edge "<<i+1<<":\n";
        int s,d,w;
        cout<<"src:";
        cin>>s;
        cout<<"dest:";
        cin>>d;
        cout<<"wght:";
        cin>>w;
        input[i].source=s;
        input[i].dest=d;
        input[i].weight=w;
    }
    kruskals(input,n,e);
}
