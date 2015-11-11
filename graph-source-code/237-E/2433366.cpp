//Language: MS C++


#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment(linker, "/STACK:200000000")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;


int n;
int lch;

struct edge{
    int from,to,cap,flow;
};

int c[210][210];
int f[210][210];
int cost[210][210];
int flow = 0;

void add_edge(int from, int to, int cap, int tcost){
    c[from][to] += cap;
    cost[from][to] += tcost;
    cost[to][from]-=tcost;
}

bool read(){
    string s;
    if (!(cin >> s)) return false;
    cin >> n;
    lch = sz(s);
    memset(c,0,sizeof(c));
    memset(f,0,sizeof(f));
    memset(cost,0,sizeof(cost));
    map <char,int> cnt;
    forn(i,sz(s))
        cnt[s[i]]++;
    for (char i='a'; i<='z'; i++)
        add_edge(0,i-'a'+1,cnt[i],0);
    forn(i,n){
        string tword; int tcap;
        cin >> tword >> tcap;
        cnt.clear();
        forn(j,sz(tword))
            cnt[tword[j]]++;
        for (int j='a'; j<='z'; j++)
            add_edge(j-'a'+1,30+i,cnt[j],i+1);
        add_edge(30+i,200,tcap,0);
    }   
    return true;
}

int ans = 0;

int push(int s, int t){
    int d[210];
    int p[210];
    int fl[210];
    memset(p,-1,sizeof(p));
    forn(i,210) d[i] = fl[i] = INF;
    set <pair <int,int> > q;
    d[0] = 0;
    q.insert(mp(d[0],0));
    while (!q.empty()){
        pair <int,int> fr = *q.begin();
        q.erase(q.begin());
        int v = fr.second;
        int dist = fr.first;
        forn(i,210){
            if (f[v][i]<c[v][i] && d[v]+cost[v][i]<d[i]){
                d[i] = d[v]+cost[v][i];
                p[i] = v;
                fl[i] = min(fl[v],c[v][i]-f[v][i]);
                q.insert(mp(d[i],i));
            }
        }
    }
    if (p[t] == -1) return 0;
    int flr = fl[t];
    int res = d[t]*flr;
    while (p[t]!=-1){
        f[p[t]][t] += flr;
        f[t][p[t]] -= flr;
        t = p[t];
    }
    flow += flr;
    return res;
}

int mincost_maxflow(int s, int t){
    int res = 0;
    int tpush = 0;
    while (tpush = push(s,t))
        res += tpush;
    return res;
}

void solve(){
    int s = 0;
    int t = 200;
    flow = 0;
    int ans = mincost_maxflow(s,t);
    if (flow != lch)
        ans = -1;
    cout << ans << endl;
}


int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    while (read())
        solve();
    return 0;
}