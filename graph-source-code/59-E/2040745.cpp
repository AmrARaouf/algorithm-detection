//Language: GNU C++


#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define MP make_pair
typedef pair<int,int> pii;
typedef long long LL;

const int MN=3000+10;
vector<int> G[MN];
LL dis[MN][MN];
LL INF=(LL)1e15;
vector<int> bad[MN][MN];
int n;
queue<pii> Q;
vector<int> path;

void make_path(int b,int c)
{
     if(c==1)
     {
        path.push_back(1);
        return;
     }
     if(b==1)
     {
        path.push_back(1);
        path.push_back(c);
        return;
     }
     for(int i=0;i<(int)G[b].size();i++)
     {
        int a=G[b][i];
        if(dis[b][c]==dis[a][b]+1)
        {
           make_path(a,b);
           path.push_back(c);
           return;
        }
     }
}

inline bool valid(int &a,int &b,int &c)
{
       for(int i=0;i<(int)bad[a][b].size();i++)
       {
          if(bad[a][b][i]>c)
             return 1;
          if(bad[a][b][i]==c)
             return 0;
       }
       return 1;
}

void bfs(int st)
{
     for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           dis[i][j]=INF;
     for(int i=0;i<=n;i++)
        dis[i][st]=0;
     while(!Q.empty())
        Q.pop();
     Q.push(MP(0,st));
     while(!Q.empty())
     {
        int a=Q.front().first;
        int b=Q.front().second;
        Q.pop();
        for(int i=0;i<(int)G[b].size();i++)
        {
           int c=G[b][i];
           if(valid(a,b,c) && dis[a][b]+1<dis[b][c])
           {
              dis[b][c]=dis[a][b]+1;
              Q.push(MP(b,c));
           }
        }
     }
}

int main()
{
    int k,m;
    cin>>n>>m>>k;
    while(m--)
    {
       int a,b;
       cin>>a>>b;
       G[a].push_back(b);
       G[b].push_back(a);
    }
    while(k--)
    {
       int a,b,c;
       cin>>a>>b>>c;
       bad[a][b].push_back(c);
    }
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
          sort(bad[i][j].begin(),bad[i][j].end());
    bfs(1);
    LL ans=INF;
    int par=0;
    for(int i=1;i<=n;i++)
    {
       if(dis[i][n]<ans)
       {
          ans=dis[i][n];
          par=i;
       }
    }
    if(ans>=INF)
       cout<<-1<<endl;
    else
    {
       make_path(par,n);
       
       cout<<ans<<endl;
       //if(ans+1!=(int)path.size())
          //while(1);
       
       for(int i=0;i<(int)path.size();i++)
          cout<<path[i]<<' ';
       cout<<endl;
    }
    return 0;
}
