//Language: GNU C++


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <windows.h>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define LL long long
#define FOR0(a,b) for(int a=0; a<b; a++)
#define FOR1(a,b) for(int a=1; a<=b;a++)
#define sortV(A) sort(A.begin(), A.end())
#define file freopen("input.txt","r",stdin)
int g[4000000];
int used[4000000];
int d[4000000];
int u=3;

bool dfs(int v)
{

    used[v]=1;
    if(g[v]==-1){used[v]=2; return true;}
    if(used[g[v]]==1)return false;
    if(used[g[v]]==0)
         if(!dfs(g[v]))return false;


    d[v]=max(d[v],d[g[v]]+1);
    used[v]=2;
    return true;
}

void dfs2(int v)
{
    used[v]=1;

    if(g[v]!=-1){
        dfs2(g[v]);}
    else used[v]=0;
}

int used2[4000000];

bool dfs3(int v)
{
    used2[v]=u;
    if(g[v]!=-1)
        if(used[g[v]]){// cout<<g[v]<<endl;
            return false;}
        else
            return dfs3(g[v]);
    return true;
}

int main()
{
   // file;
    memset(g,-1,sizeof(g));

    int n,m;
    cin>>n>>m;
    FOR0(i,n)
        FOR0(j,m)
        {
            char x;
            cin>>x;
            if(x=='<')g[(i)*m+j]=((i)*m+j-1);
            if(x=='>')g[(i)*m+j]=((i)*m+j+1);
            if(x=='v')g[(i)*m+j]=((i+1)*m+j);
            if(x=='^')g[(i)*m+j]=((i-1)*m+j);
        }

    int k=0;
    int nom=0;
    FOR0(i,n*m)
        if(!used[i])
        {
            if(!dfs(i)){cout<<-1; return 0;}
            if(k<d[i]){ nom=i; k=d[i]; }
        }

    if(k==0){cout<<0; return 0;}

    FOR0(i,n*m)
        used[i]=0;

    dfs2(nom);

   // FOR0(i,n*m)
  //      if(used[i]) cout<<i<<endl;
    for(int i=nom+1; i<n*m; i++)
    {
        u++;
        if(d[i]==k)
            if(dfs3(i)){cout<<2*k; return 0;}
    }
    cout<<2*k-1;

}

