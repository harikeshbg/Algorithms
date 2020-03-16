#include<iostream>
using namespace std;
void displaysub(int subset[],int subsize)
{
    for(int i=0;i<subsize;i++)
        cout<<subset[i]<<" ";
    cout<<endl;
}
void subsetcheck(int mainset[],int mainsize,int subset[],int subsize,int subsum,int mainsum,int count)
{
    if(subsum==mainsum)
    {
        displaysub(subset,subsize);
        subsetcheck(mainset,mainsize,subset,subsize-1,subsum-mainset[count],mainsum,count+1);
    }
    for(int i=count;i<mainsize;i++)
    {
        subset[subsize]=mainset[i];
        subsetcheck(mainset,mainsize,subset,subsize+1,subsum+mainset[i],mainsum,i+1);
    }
}
void findsub(int mainset[],int mainsize,int mainsum)
{
    int *subset=new int [mainsize];
    subsetcheck(mainset,mainsize,subset,0,0,mainsum,0);
}
int main()
{
    int mainsize;
    cout<<"Enter the number of elements:";
    cin>>mainsize;
    int *mainset=new int[mainsize];
    cout<<"Enter the elements:"<<endl;
    for(int i=0;i<mainsize;i++)
        cin>>mainset[i];
    int mainsum;
    cout<<"Enter the total sum:";
    cin>>mainsum;
    findsub(mainset,mainsize,mainsum);
}
