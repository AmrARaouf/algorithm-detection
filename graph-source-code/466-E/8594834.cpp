//Language: MS C++


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int inf =100009;
int in [inf],out[inf];
vi adj[inf];
int owner[inf];
vii ques[inf];
int tree[inf];
int sz[inf];
int com[inf];
int info1[inf];
int info2[inf];
int numofduc=1,n;
bool par[inf];
bool sol[inf];
int cp=0,ans=0;
int root(int a)
{
    while (a!=tree[a])
    {
        tree[a]=tree[tree[a]];
        a=tree[a];
    }
    return a;
}
int t=0;
void dfs(int x,int p)
{
    par[x]=false;
    in[x]=t++;
    for (int i=0; i<adj[x].size(); ++i)
        if (adj[x][i]!=p)
            dfs(adj[x][i],x);
    out[x]=t++;
}

int main()
{
    int m,a,b,c;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
        par[i]=true;
    for (int i=0; i<m; ++i)
    {
        scanf("%d",&c);
        if (c==1)
        {
            com[cp]=1;
            scanf("%d%d",&info1[cp],&info2[cp]);
            adj[info2[cp]].push_back(info1[cp]);
            par[info1[cp]]=false;
            cp++;
        }
        else if (c==2)
            {
                scanf("%d",&owner[numofduc]);
                com[cp]=2;
                info1[cp++]=numofduc++;
            }
        else
            {
                scanf("%d%d",&a,&b);
                ques[b].push_back(make_pair(a,ans++));
            }
    }

    int idx=-1;
    for (int i=1; i<=n; ++i)
      {

        if (par[i])
        {
            idx=i;
            dfs(idx,-1);
        }
        sz[i]=1;
        tree[i]=i;
      }
    for (int i=0; i<cp; ++i)
    {
        if (com[i]==1)
        {
            a=info1[i],b=info2[i];
            if (sz[a]<sz[b])
            swap(a,b);
            a=root(a),b=root(b);
            sz[a]+=sz[b];
            tree[b]=a;
        }
        else if (com[i]==2)
        {
            int k=info1[i];
            a=owner[k];

            for (int j=0;j<ques[k].size();++j)
            {
            b=ques[k][j].first;
            if (root(a)==root(b) && in[b]<=in[a] && out[b]>=out[a])
               sol[ques[k][j].second]=1;
            else
                sol[ques[k][j].second]=0;

            }
        }
    }
    for (int i=0;i<ans;++i)
        printf(sol[i]?"YES\n":"NO\n");
    return 0;
}
