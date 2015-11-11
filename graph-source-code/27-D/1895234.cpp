//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>

using namespace std;
const int Maxv=110;
int n,m;
int head[Maxv];
int org[Maxv][2];
int etot;
bool vis[Maxv];
int blg[Maxv];
bool flag;
struct Edge
{
    int to,next;
}edge[Maxv*Maxv*2];

void init_edge()
{
    etot=0;
    memset(head,-1,sizeof(head));
}

void add_edge(int u,int v)
{
    edge[etot].to=v;
    edge[etot].next=head[u];
    head[u]=etot++;
}

bool judge(int e1,int e2)
{
    int x1=org[e1][0];int y1=org[e1][1];
    int x2=org[e2][0];int y2=org[e2][1];
    if(x1==x2||x1==y2||y1==x2||y1==y2)
    return false;
    int cnt=0;
    x1=(x1==n?1:x1+1);y1=(y1==1?n:y1-1);
    //cout<<x1<<" "<<y1<<endl;
    for(int i=x1;;i=(i==n?1:i+1))
    {
        if(i==x2||i==y2)
        cnt++;
        if(i==y1)
        break;
    }
    if(cnt==1)
    return true;
    return false;
}


void dfs(int x)
{
    vis[x]=true;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(!vis[v])
        {
            blg[v]=blg[x]^1;
            dfs(v);
        }
        else if(blg[v]!=(blg[x]^1))
        flag=false;
    }
}

int main()
{
    int i,j;
    init_edge();
    flag=true;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&org[i][0],&org[i][1]);
    }
    //judge(0,3);

    for(i=0;i<m;i++)
    for(j=1;j<m;j++)
    if(judge(i,j))
    {
        add_edge(i,j);
        add_edge(j,i);
       // cout<<i<<" "<<j<<endl;
    }
    for(i=0;i<m&&flag;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    if(flag)
    {
        for(i=0;i<m;i++)
        if(blg[i])
        cout<<"i";
        else
        cout<<"o";
    }
    else
        puts("Impossible");
    return 0;

}
/*
5 5
1 5
2 3
3 4
2 5
4 3
*/

