//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<list>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
int dist[3030][3030];
int main()
{
    list<int>adj[3030];
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int n1,n2;scanf("%d%d",&n1,&n2);
        adj[n1].pb(n2);
        adj[n2].pb(n1);
    }
    for(int i=1;i<=n;i++)
    {
        bool vis[3001]={0};
        queue<pair<int,int> >bfs;
        bfs.push(mp(i,0));
        vis[i]=1;
        while(!bfs.empty())
        {
            pair<int,int> temp=bfs.front();
            bfs.pop();
            dist[i][temp.f]=temp.s;
            list<int>::iterator it1=adj[temp.f].begin();
            for(;it1!=adj[temp.f].end();it1++)
            {
                if(vis[*it1])
                    continue;
                bfs.push(mp(*it1,temp.s+1));
                vis[*it1]=1;
            }
        }
    }
    int s1,s2,t1,t2,l1,l2;scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    if(dist[s1][t1]>l1 || dist[s2][t2]>l2)
    {
        printf("-1\n");
        return 0;
    }
    int ansmin=10000;
    ansmin=min(m+1,dist[s1][t1]+dist[s2][t2]);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int v1=dist[s1][i]+dist[j][t1]+dist[i][j];
            int v2=dist[s2][i]+dist[j][t2]+dist[i][j];
            if(v1<=l1 && v2<=l2)
                ansmin=min(ansmin,v1+v2-dist[i][j]);
            v1=dist[s1][j]+dist[i][t1]+dist[i][j];
            v2=dist[s2][i]+dist[j][t2]+dist[i][j];
            if(v1<=l1 && v2<=l2)
                ansmin=min(ansmin,v1+v2-dist[i][j]);
            v1=dist[s1][j]+dist[i][t1]+dist[i][j];
            v2=dist[s2][j]+dist[i][t2]+dist[i][j];
            if(v1<=l1 && v2<=l2)
                ansmin=min(ansmin,v1+v2-dist[i][j]);
            v1=dist[s1][i]+dist[j][t1]+dist[i][j];
            v2=dist[s2][j]+dist[i][t2]+dist[i][j];
            if(v1<=l1 && v2<=l2)
                ansmin=min(ansmin,v1+v2-dist[i][j]);
        }
    }
    if(ansmin>m)
        printf("-1\n");
    else
        cout<<m-ansmin<<endl;
    return 0;
}




