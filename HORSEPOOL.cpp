#include<iostream>
#include<string.h>
using namespace std;
int cnt=0;
void shifttable(char pat[],int table[])
{
    int m=strlen(pat);
    //cout<<"s="<<s<<endl;
    cout<<"Inside shift table\n";
    int flag[128];
    for(int h=0;h<128;h++)
        flag[h]=0;
    for(int j=m-2;j>=0;j--)
    {
        //cout<<"Inside for\n";
        //k=int(pat[i]);
        //cout<<"k="<<k<<endl;
        //cout<<"s-1-j="<<s-1-j<<endl;
        if(flag[pat[j]]==0)
        {
            //cout<<"inside if"<<endl;
            table[pat[j]]=m-1-j;
            flag[pat[j]]=1;
            cout<<pat[j]<<"="<<table[pat[j]]<<endl;
        }
    }
}
int horsepool(char txt[],char pat[])
{
   int m,n;
   m=strlen(pat);
   n=strlen(txt);
   int table[128];
   for(int i=0;i<=127;i++)
       table[i]=m;
   shifttable(pat,table);
    for(int i=0;i<=127;i++)
        cout<<"tab="<<table[i+1]<<endl;
   int i=m-1,k;
   while(i<=n-1)
   {
       k=0;
       while(k<=m-1&&pat[m-1-k]==txt[i-k])
        {
            k=k+1;
            cnt++;
        }
       if(k==m)
        return (i-(m-1));
       else
        {
            i=i+table[txt[i]];
            cnt++;
        }
   }
   return -1;
}
int main()
{
    char text[50],pattern[50];
    int res;
    cout<<"Enter the text:";
    cin>>text;
    cout<<"Enter the pattern:";
    cin>>pattern;
    res=horsepool(text,pattern);
    if(res==-1)
        cout<<"Pattern not found\n";
    else
        cout<<"string found at position:"<<res<<endl;
    cout<<"comps="<<cnt;
    return 0;

}

