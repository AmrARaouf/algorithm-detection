//Language: GNU C++


#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;
const double eps=1e-8;
const int maxn=500005;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=~0u>>1;
int n,L;
int head[maxn],to[maxn],w[maxn],ne[maxn],idx[maxn],cnt;
void addedge(int u,int v,int k,int id=0) {
    to[cnt]=v;
    w[cnt]=k;
    idx[cnt]=id;
    ne[cnt]=head[u];
    head[u]=cnt++;
}
map<int,int>  m;
int tot;
int find_id(int x) {
    if(!m[x]) m[x]=++tot;
    return m[x];
}

struct p {
    int u;
    int d;
    p() {}
    p(int u,int d):u(u),d(d) {}
    bool operator < (const p& rhs) const {
        return d>rhs.d;
    }
};

int pre[maxn],pre_e[maxn];
bool done[maxn];
ll d[maxn];
void solve() {
    for(int i=1;i<=tot;i++) d[i]=INF;
    d[m[0]]=0;
    priority_queue<p> q;
    q.push(p(m[0],0));
    while(!q.empty())   {
        p tmp=q.top();
        q.pop();
        int u=tmp.u;
        if(done[u]) continue;
        done[u]=1;
        for(int i=head[u];i!=-1;i=ne[i]) {
            int v=to[i];
            if(d[v]>d[u]+w[i]) {
                d[v]=d[u]+w[i];
                pre[v]=u;
                pre_e[v]=i;
                q.push(p(v,d[v]));
            }
        }
    }
}
int main() {
    scanf("%d %d",&n,&L);
    int x,d,t,p;
    memset(head,-1,sizeof(head));
    vector<int> pos;
    pos.push_back(0),pos.push_back(L);
    for(int i=1;i<=n;i++) {
        scanf("%d%d%d%d",&x,&d,&t,&p);
        
        if(x-p>=0) {
            addedge(find_id(x-p),find_id(x+d),p+t,i);
            pos.push_back(x-p),pos.push_back(x+d);
        }
        
    }
    sort(pos.begin(),pos.end());
    pos.resize(unique(pos.begin(),pos.end())-pos.begin());
    int sz=pos.size();
    for(int i=0;i<sz-1;i++) {
        addedge(find_id(pos[i]),find_id(pos[i+1]),pos[i+1]-pos[i]);
        addedge(find_id(pos[i+1]),find_id(pos[i]),pos[i+1]-pos[i]);
    }
    solve();
    vector<int> ans;
    int cur=m[L];
    int k=0;
    while(pre[cur]) {
        if(pre_e[cur]!=-1&&idx[pre_e[cur]]) ans.push_back(idx[pre_e[cur]]),k++;
        cur=pre[cur];
    }
    printf("%I64d\n",::d[m[L]]);
    reverse(ans.begin(),ans.end());
    printf("%d\n",k);
    for(int i=0;i<k;i++) printf("%d\n",ans[i]);
    return 0;
}