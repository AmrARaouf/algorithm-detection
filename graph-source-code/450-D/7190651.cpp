//Language: GNU C++


#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

struct Node{
    int v;
    long long int w;
};

long long int dist[100050]; //1到i的最小距离
long long int dist2[100050];
bool flag[100050];
bool visit[100050];
vector<Node> adj[100050];
int ans;

queue<int> q;

void SPFA()
{
    int i,j,k;
    while(!q.empty())q.pop();
    q.push(1);
    memset(dist,0x3f,sizeof(dist));
    memset(visit,0,sizeof(visit));
    dist[1]=0;
    visit[1]=1;
    while(!q.empty())   //计算后dist为从起点到各个位置的长度 
    {
        int now=q.front();
        int l=adj[now].size();
        q.pop();
        visit[now]=0;           //**************
        for(j=0;j<l;j++)
        {
            int to=adj[now][j].v;
            long long int weight=adj[now][j].w;
            if(dist[to]>dist[now]+weight)
            {
                dist[to]=dist[now]+weight;
                if(!visit[to])
                {
                    visit[to]=1;
                    q.push(to);
                }
            }
        }
    }
}

void SPFA2()
{
    int i,j,k;
    while(!q.empty())q.pop();
    q.push(1);
    memset(dist2,0x3f,sizeof(dist));
    memset(visit,0,sizeof(visit));
    dist2[1]=0;
    visit[1]=1;
    while(!q.empty())   //计算后dist为从起点到各个位置的长度 
    {
        int now=q.front();
        int l=adj[now].size();
        q.pop();
        visit[now]=0;           //**************
        
        
        
        for(j=0;j<l;j++)
        {
            int to=adj[now][j].v;
            long long int weight=adj[now][j].w;
            if(dist2[to]>dist2[now]+weight)
            {
                dist2[to]=dist2[now]+weight;
                if(!visit[to])
                {
                    visit[to]=1;
                    q.push(to);
                }
                if(dist2[to]<dist[to]&&flag[to])
                {
                    flag[to]=0;
                    ans++;
                }
            }
            else if(dist2[to]==dist2[now]+weight&&now!=1&&dist2[to]<=dist[to]&&flag[to])
            {
                    flag[to]=0;
                    ans++;
            }
        }
    }
}


int main()
{
    int N,M,K;
    int i,j,k;
    long long int u,v,w;
    while(cin>>N>>M>>K)
    {
        
        for(i=0;i<=N;i++)adj[i].clear();
        
        for(i=0;i<M;i++)
        {
            Node x;
            cin>>u>>v>>w;
            x.v=v;x.w=w;
            adj[u].push_back(x);
            x.v=u;
            adj[v].push_back(x);
        }
        
        SPFA();
        memset(flag,0,sizeof(flag));//flag表保留 
        ans=0;
        for(i=0;i<K;i++)
        {
            Node x;
            cin>>x.v>>x.w;
            if(x.w<dist[x.v])
            {
                adj[1].push_back(x);
                dist[x.v]=x.w;
                
                if(flag[x.v])ans++; 
                flag[x.v]=1;
            }
            else ans++;
        }
        SPFA2();
        cout<<ans<<endl;
    }
    return 0;
}


