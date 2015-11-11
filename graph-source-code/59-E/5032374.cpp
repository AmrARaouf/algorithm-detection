//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <cctype>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>
#include <map>

#define FOREACH(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)

#define ALL(c) (c).begin(), (c).end()
#define fi first
#define se second
#define ins insert
#define mp make_pair
#define pb push_back
#define LL long long
#define ULL unsigned long long

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,pii> ppi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef vector<int, int> vipi;
typedef pair<pii,double> pid;
typedef pair<pii,int> piii;
typedef pair<double,double> pdd;
typedef pair<pdd,pdd> pddpdd;
typedef pair<pdd,double> pddd;
typedef pair<pddpdd,double> ppddpddd;
typedef pair<pii, pdd > ppid;

template <class T> inline T MAX(T a, T b) { if (a > b) return a; return b; }
template <class T> inline T MIN(T a, T b) { if (a < b) return a; return b; }
template <class T> inline T ABS(T x) { if (x < 0) return -x; return x; }

inline void OPEN(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

const static int INF = 1000000000;

#define MAXN 3005

int n,m,k,a,b,c;
vvi ver(MAXN);

set<piii>gak;
typedef pair<pii,vi> pvi;
int dis[MAXN]={};
set<piii>visited;
set<pii>dua;
vi cal(int s,int t){
    REPN(i,t) dis[i] = INF;
    vvi path(MAXN);
    priority_queue<pvi,vector<pvi>,greater<pvi> >q;
    vi temp;
    temp.pb(s);
    path[s].pb(s);
    q.push(mp(mp(0,s),temp));
    dis[s] = 0;
    pvi now;
    while(!q.empty()){
        now = q.top();
        q.pop();
        int w = now.fi.se;
        vi tempPath = now.se;
        REP(i,ver[w].size()){
            int v = ver[w][i];
        //  printf("%d -> %d\n",w,v);
            piii cek;
            cek.fi.fi = cek.fi.se = cek.se = 0;
            int len = tempPath.size();
            int awal;
            if(len >= 2) awal = len-2;
            else awal = 0;
            for(int k = awal,j=0; k < tempPath.size(); k++,j++){
                if(j == 0) cek.fi.fi = tempPath[k];
                else cek.fi.se = tempPath[k];
            }
            if(len >= 2)
            cek.se = v;
            else if(len ==1)cek.fi.se = v;
            else cek.fi.fi=v;
            if(gak.find(cek) == gak.end()){
                //printf("%d->%d\n",cek.fi.se,cek.se);
                if(dua.find(mp(cek.fi.se,cek.se)) != dua.end()) continue;
                dua.insert(mp(cek.fi.se,cek.se));
                if(visited.find(cek) == visited.end()){
                    visited.insert(cek);
                    if(v != t || (v == t && dis[v] > now.fi.fi+1)){
                    dis[v] = now.fi.fi+1;
                    path[v] = tempPath;
                    path[v].pb(v);
                    /*
                    printf("dis[%d] = %d | %d %d %d\n",v,dis[v],cek.fi.fi,cek.fi.se,cek.se);
                    REP(k,path.size()) printf("%d ",path[k]);
                    printf("\n");*/
                //  printf("%d -> %d -> %d\n",cek.fi.fi,cek.fi.se,cek.se);
                    q.push(mp(mp(dis[v],v),path[v]));
                    }
                }
            }
        }
    }
    return path[t];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    REP(i,m){
        scanf("%d%d",&a,&b);
        ver[a].pb(b);ver[b].pb(a);
    }
    REP(i,k){
        scanf("%d%d%d",&a,&b,&c);
        gak.insert(mp(mp(a,b),c));
    }
    vi path = cal(1,n);
    if(dis[n] == INF) printf("-1\n");
    else{
        printf("%d\n",path.size()-1);
        REP(i,path.size()){
            if(i != 0) printf(" ");
            printf("%d",path[i]);
        }
        printf("\n");
    }
    return 0;
}