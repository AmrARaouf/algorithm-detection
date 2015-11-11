//Language: GNU C++


//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;
vector<long long>adj[100009],revadj[100009],vec;
long long visited[100009],dis[100009],ar[100009],t,inf,mi,num;
void dfs1(long long a)
{
    long long s,d,f,g,h,j,k,l;
    visited[a]=1;
    for(s=0;s<adj[a].size();s++)
    {
        if(visited[adj[a][s]]==0) dfs1(adj[a][s]);
    }
    vec.push_back(a);
}
void dfs2(long long a)
{
    long long s,d,f,g,h,j,k,l;
    visited[a]=0;
    dis[a]=t;
    //cout<<a<<" "<<ar[a]<<" "<<mi<<" bvxnv\n";
    if(mi>ar[a])
    {
        //cout<<a<<' '<<ar[a]<<endl;
        mi=ar[a];
        num=1;
    }
    else if(mi==ar[a]) num++;
    for(s=0;s<revadj[a].size();s++)
    {
        if(visited[revadj[a][s]]) dfs2(revadj[a][s]);
    }
}
int main()
{
    long long a,s,d,f,g,h,j,k,l,ans,ans1,no;
    inf=1;
    for(a=1;a<=40;a++) inf=inf*2;
    //scanf("%d",&a);
    cin>>a;
    for(s=1;s<=a;s++)
    {
        int temp;
        scanf("%d",&temp);
        ar[s]=temp;
    }
    cin>>no;
    for(s=1;s<=no;s++)
    {
        int temp1,temp2;
        scanf("%d%d",&temp1,&temp2);
        h=temp1;
        j=temp2;
        adj[h].push_back(j);
        revadj[j].push_back(h);
    }
    for(g=1;g<=a;g++)
    {
        if(visited[g]==0) dfs1(g);
    }
    t=0;
    ans=1;
    ans1=0;
    for(g=vec.size()-1;g>=0;g--)
    {
        //cout<<vec[g]<<" \n\n";
        num=0;
        mi=inf;
        if(visited[vec[g]]==1)
        {
            t++;
            dfs2(vec[g]);
            ans=ans*num;
            ans1=ans1+mi;
            //cout<<mi<<' ';
            ans=ans%1000000007;
            //cout<<ans<<" "<<ans1<<endl;
        }
    }
    cout<<ans1<<" "<<ans<<endl;
    return 0;
}
