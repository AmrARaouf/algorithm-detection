//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;

#define s(n)            scanf("%d",&n)
#define sl(n)           scanf("%lld",&n)
#define sf(n)           scanf("%lf",&n)
#define ss(n)           scanf("%s",n)
#define pls(x)          cout << x << " "
#define pln(x)          cout << x << "\n"
#define pis(x)          printf("%d ", x)
#define pin(x)          printf("%d\n", x)
#define pnl             printf("\n")
#define dbn             cout << "\n"
#define dbg(x)          cout << #x << " : " << x << " "
#define dbs(x)          cout << x << " "
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define rep(i,n)        FOR(i,0,n-1)
#define foreach(c,v)    for(__typeof((c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define mp              make_pair
#define FF              first
#define SS              second
#define pb              push_back
#define fill(a,v)       memset(a,v,sizeof(a))
#define all(x)          x.begin(),x.end()
#define sz(v)           ((int)(v.size()))
#define INF             (int)1e9
#define LINF            (long long)1e18
#define EPS             1e-9

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pair<lli,lli> > vlii;
const int MAXN = 200040;
const int MOD  =  (int)(1e9 + 7);

/*Main code begins now */
int T[MAXN][2];
void update(int p,int ind,int val){
    while(ind<MAXN){
        T[ind][p]+=val;
        ind += (ind & -ind);
    }
}
void updateRange(int p, int a,int b,int val){
    update(p,a,val);
    update(p,b+1,-val);
}
int get(int p, int ind){
    int ret = 0;
    while(ind>0){
        ret += T[ind][p];
        ind -= (ind & -ind);
    }
    return ret;
}
int lev[MAXN];
vi adl[MAXN];
int a[MAXN];
int tim;
int s[MAXN],e[MAXN];
bool visit[MAXN];
void dfs(int u){
    visit[u] = true;
    s[u] = ++tim;
    for(auto v:adl[u]){
        if(!visit[v]) {
            lev[v] = lev[u]+1;
            dfs(v);
        }
    }
    e[u] = tim;
}
int main(){
    int n,m;
    int x,y;
    s(n),s(m);
    tim = 0;
    fill(lev,0);
    fill(visit,0);
    fill(T,0);
    rep(i,n) s(a[i+1]);
    rep(i,n-1){
        s(x),s(y);
        adl[x].pb(y);
        adl[y].pb(x);
    }
    dfs(1);
    int ch;
    rep(i,m){
        s(ch);
        if(ch == 1){
            s(x),s(y);
            bool oddLev = lev[x]%2;
            updateRange(oddLev,s[x],e[x],y);
            updateRange(!oddLev,s[x],e[x],-y);
        }else{
            s(x);
            int ans = a[x] + get(lev[x]%2,s[x]);
            printf("%d\n",ans);         
        }
    }
    return 0;
}