//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

const int MOD = 1000000007;
const int MAXN = 100000;
const int MAXE = 100000;
const int MAXC = MAXN;
const int MAXLOG = 17;

typedef int* IntPointer;

class Edge
{
    public:
        int from,to;
    Edge(){}
    Edge(int from,int to): from(from) , to(to) {}
};


int cycle_id[MAXN+5]; // take node


int ansToRoot[MAXC+5]; // take cycle
int parent[MAXLOG+2][MAXC+5]; // take log and cycle
int depth[MAXC+5]; // take cycle
int Csz[MAXC+5]; // take cycle
vector<Edge> Gc[MAXC+5]; // take cycle
int nc;

int track[MAXN+5];
bool vis[MAXN+5];
bool intrack[MAXN+5];

vector<Edge> G[MAXN+5];
int n,m;

void add_cycle(int root,int cnt)
{
    cycle_id[root] = nc;
    Csz[nc]++;
    while (track[--cnt]!=root){
        cycle_id[track[cnt]]=nc;
        Csz[nc]++;
    }
    nc++;
    return ;
    
}

void getcycle(int ind,int cnt)
{
    if (intrack[ind]){
        add_cycle(ind,cnt);
        return;
    }
    if (vis[ind])return ;
    vis[ind] = 1;
    intrack[ind] = 1;
    track[cnt] = ind;
    int c,c2;
    for (c=0;c<G[ind].size();c++){
        if (cnt>0 && track[cnt-1] == G[ind][c].to)continue;
        getcycle(G[ind][c].to,cnt+1);
    }
    if (cycle_id[ind]==-1)
        add_cycle(ind,cnt+1);
    intrack[ind] = 0;
    return ;
}

void cactusTree()
{
    memset(cycle_id,-1,sizeof(cycle_id));
    memset(vis,0,sizeof(vis));
    memset(intrack,0,sizeof(intrack));
    int c,c2;
    nc=0;
    for (c=0;c<n;c++){
        if (vis[c])continue;
        getcycle(c,0);
    }
    for (c=0;c<n;c++)
        for (c2=0;c2<G[c].size();c2++){
            int i1 = cycle_id[c];
            int i2 = cycle_id[G[c][c2].to];
            if (i1 == i2)continue;
            Gc[i1].push_back(Edge(i1,i2));
        }
    return ;
    
}


int lca(int i1,int i2)
{
    if (depth[i1]<depth[i2])
        swap(i1,i2);
        
    // i1 is deeper
    for (int log=MAXLOG;log>=0;log--){
        if (depth[i1] == depth[i2])break;
        if (parent[log][i1]==-1)continue;
        if (depth[parent[log][i1]] < depth[i2])continue;
        i1 = parent[log][i1];
    }
    if (i1 == i2)return i1;
    
    for (int log=MAXLOG;log>=0;log--){
        if (parent[log][i1]==-1)continue;
        if (parent[log][i1]==parent[log][i2])continue;
        i1 = parent[log][i1];
        i2 = parent[log][i2];
    }
    return parent[0][i1];
}
void flood(int ind,int p,int dep)
{
    parent[0][ind] = p;
    depth[ind] = dep;
    ansToRoot[ind] = (Csz[ind]>1);
    if (p!=-1)
        ansToRoot[ind]+=ansToRoot[p];

    for (int c=0;c<Gc[ind].size();c++){
        if (Gc[ind][c].to == p)continue;
        flood(Gc[ind][c].to,ind,dep+1);
    }
    return ;
}
void preCalculateAncestors()
{
    flood(0,-1,0);
    bool khalas;
    int log;
    for (log=1;log<=MAXLOG;log++){
        khalas=1;
        for (int c=0;c<nc;c++){
            parent[log][c]=-1;
            if (parent[log-1][c]==-1)continue;
            parent[log][c] = parent[log-1][parent[log-1][c]];
            khalas&= (parent[log][c]==-1);
        }
    }
    return ;
}

int powMod(int base,int power)
{
    if (power == 0)return 1;
    int ret = powMod(base,power>>1);
    ret = (ret * (long long)ret)%MOD;
    if (power&1)
        ret = (ret * (long long)base)%MOD;
    return ret;
}


int main()
{
//    freopen("cactus.in","r",stdin);
    int c,c2;
    scanf("%d%d",&n,&m);
    for (c=0;c<m;c++){
        int from,to;
        scanf("%d%d",&from,&to);from--;to--;
        G[from].push_back(Edge(from,to));
        G[to].push_back(Edge(to,from));
    }
    cactusTree();
    preCalculateAncestors();
    int qs;
    scanf("%d",&qs);
    for (c=0;c<qs;c++){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        t1--;t2--;
        int i1 = cycle_id[t1];
        int i2 = cycle_id[t2];
        int mid = lca(i1,i2);
        int ans = ansToRoot[i1] + ansToRoot[i2] - 2*ansToRoot[mid] + (Csz[mid]>1);
        printf("%d\n",powMod(2,ans));
    }
    
    
    
    
//    printf("End\n");while(1);
    return 0;
}
