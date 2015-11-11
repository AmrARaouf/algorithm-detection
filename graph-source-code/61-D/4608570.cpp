//Language: GNU C++


#include <bits/stdc++.h>

using namespace std;
 
#define SZ(a) int((a).size())
#define PB push_back
#define ALL(c) (c).begin(),(c).end()
#define LLA(A) A.rbegin(), A.rend()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define BSC(A, x) (lower_bound(ALL(A), x) - A.begin())
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(all(c),x) != (c).end()) // present in a container or not.
#define MP make_pair
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define REP1(i,n) for(int _n=n, i=1;i<=_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<_b;++i)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define FF first
#define SS second
#define INPUT(a) freopen (a, "r", stdin)
#define OUTPUT(a) freopen (a, "w", stdout)
#define FORD(i, b, a) for (int i=int(b-1);i>=int(a);--i)
#define FILL(a, v) memset(a, v, sizeof(a));
#define DREP(a)                 sort(ALL(a)); a.erase(unique(ALL(a)),a.end()) // will make the vector unique and sorted order
#define DEBUG(args...)          {dbg,args; cerr<<endl;}
#define INF                     (int)1e9
#define LINF                    (long long)1e18

typedef long long LL;
typedef long double LD;
typedef vector <int> VI;
typedef vector <LL> VLL;
typedef vector <double> VD;
typedef vector<string> VS;
typedef vector <VI> VVI;
typedef pair <int,int> PII;
typedef pair <LL,LL> PLL;
typedef vector <PII > VPII;
typedef pair <double, double> PDD;
typedef vector <PDD> VPDD;

struct debugger { template<typename T> debugger& operator , (const T& v) {  cerr<<v<<" ";    return *this;  } } dbg;

template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS rv; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) rv.PB(s.substr(p, np - p)); p = np + 1;} if (p < SZ(s)) rv.PB(s.substr(p)); return rv;}

void print(VI v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "["; if (sz) cerr << v[0]; FOR (i, 1, sz) cerr << ", " << v[i]; cerr << "]" << endl; }
void print(VD v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "["; if (sz) cerr << v[0]; FOR (i, 1, sz) cerr << ", " << v[i]; cerr << "]" << endl; }
void print(VS v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "["; if (sz) cerr << v[0]; FOR (i, 1, sz) cerr << ", " << v[i]; cerr << "]" << endl; }
void print (PII v) { cerr << "{ " << v.FF << ", " << v.SS << " }"; }
void print (VPII v, int sz = -1) { if (sz == -1) sz = SZ(v); cerr << "[ "; if (sz) print (v[0]); FOR (i, 1, sz) { cerr << ", "; print (v[i]);} cerr << "]" << endl;}
void print(VVI v, int sz1 = -1, int sz2 = -1) { if (sz1 == -1) sz1 = SZ(v); if (sz2 == -1) sz2 = SZ(v[0]); cerr << "[ ---" << endl;if (sz1) cerr << " ", print(v[0], sz2);FOR(i, 1, sz1) cerr << " ", print(v[i], sz2);    cerr << "--- ]\n";}

const double EPS = 1e-9;
const int MOD = int(1e9) + 7;
const double PI = acos(-1.0); //M_PI;

////////////
const int N=100005;
LL memo[N],memo1[N];
int vis[N],vis1[N];
vector<pair<int,int> >g[N];
LL cycle(int u){
    if(memo[u]!=-1)return memo[u];
    vis[u]=true;
    LL ans=0;
    REP(i,SZ(g[u])){
        int v=g[u][i].first;
        if(!vis[v]){
            ans+=cycle(v);
            ans+=2*g[u][i].second;
        }
    }
    memo[u]=ans;
    return ans;
}

LL traverse(int u){
    if(memo1[u]!=-1)return memo1[u];
    vis1[u]=true;
    LL cc=0,ans=LINF;
    int neigh=0;
    REP(i,SZ(g[u])){
        int v=g[u][i].first;
        if(!vis1[v]){
            cc+=cycle(v);
            cc+=2*g[u][i].second;
            neigh++;
        }   
    }
    REP(i,SZ(g[u])){
        int v=g[u][i].first;
        if(!vis1[v]){
            LL tc=traverse(v);
            tc+=g[u][i].second;
            LL total=cc-cycle(v)-2*g[u][i].second+tc;
            //cout<<total<<endl;
            ans=min(ans,total);
        }   
    }
    if(neigh==0)ans=0;
    memo1[u]=ans;
    return ans;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i+1<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--,y--;
        g[x].PB(MP(y,z));
        g[y].PB(MP(x,z));
    }
    FILL(memo,-1);
    FILL(memo1,-1);
    REP(i,n)cycle(i);
    cout<<traverse(0)<<endl;
    return 0;
}