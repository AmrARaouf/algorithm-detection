//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <queue>
#include <cstring>

using namespace std;

#define sz size()
#define pb push_back
#define len length()
#define clr clear()
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FORR(i,n) for(i=0;i<n;i++)
#define is_digit(c) ('0'<=(c) && (c)<='9')

#define eps 0.0000001
#define PI  3.14159265359
#define inf 1999888777

struct grana {
    int x,d;
} gr;

class cmp {
public:
    bool operator() (const grana& a, const grana& b) const {
        return (a.d>b.d);
    }
};

int d[555555];
bool mark[555555];
vector<int> adj[555555], adjw[555555];
priority_queue<grana,vector<grana>,cmp> pq;

int main() {

    int n,m,s,i,l,j,u,v,w,t,px,py,pw,res,p1i,p1v,p2i,p2v;

    scanf("%d%d%d", &n, &m, &s);
    s--;

    for(i=0; i<m; i++) {
        scanf("%d%d%d", &px, &py, &pw);
        px--; py--;
        adj[px].pb(py);
        adj[py].pb(px);
        adjw[px].pb(pw);
        adjw[py].pb(pw);
    }

    scanf("%d", &l);

    for(i=0; i<n; i++) {
        d[i]=inf;
        mark[i]=false;
    }

    d[s]=0;
    gr.x=s; gr.d=0;
    pq.push(gr);

    for(i=0; i<n; i++) {

        while(!pq.empty() && mark[pq.top().x]) pq.pop();

        u=pq.top().x; pq.pop();
        mark[u]=true;
        t=adj[u].sz;
        for(j=0; j<t; j++) {
            v=adj[u][j]; w=adjw[u][j];
            if (d[v] > d[u]+w) {
                d[v]=d[u]+w;
                gr.x=v; gr.d=d[v];
                pq.push(gr);
            }
        }
    }

    res=0;
    for(i=0; i<n; i++) {
        t=adj[i].sz;
        if (d[i]==l) res+=2;
        for(j=0; j<t; j++) {
            v=adj[i][j]; w=adjw[i][j];

            if ( d[i]<l && w>l-d[i] && d[i]!=l && w-l+d[i]+d[v]>=l ) {
                p1i=l-d[i]; p1v=w-l+d[i];
            } else {
                p1i=-1; p1v=-1;
            }

            if ( d[v]<l && w>l-d[v] && d[v]!=l && w-l+d[i]+d[v]>=l ) {
                p2i=w-l+d[v]; p2v=l-d[v];
            } else {
                p2i=-2; p2v=-2;
            }

            //printf("%d %d   %d %d   %d %d\n", i, v, d[i], d[v], p1i, p2i);

            if (p1i>0) res++;
            if (p2i>0) res++;
            if (p1i==p2i) res--;
        }
    }

    printf("%d\n", res/2);

    return 0;
}
