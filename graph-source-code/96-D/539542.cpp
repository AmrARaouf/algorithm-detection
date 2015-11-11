//Language: GNU C++


#include<iostream>
#include<sstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cctype>
#include<set>
#include<bitset>
#include<algorithm>
#include<list>
#include<utility>
#include<functional>
#include <deque>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <ctime>


#include<cmath>
#include<math.h>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

using namespace std;

#define deb(a)      cout<<" -> "<<#a<<"  "<<a<<endl;
#define oo          (1<<30)
#define ERR         1e-5
#define PRE         1e-8
#define popcount(a) (__builtin_popcount(a))
#define SZ(a)       ((int)a.size())
#define X           first
#define Y           second
#define PB          push_back
#define LL          long long
#define MP          make_pair
#define ISS         istringstream
#define OSS         ostringstream
#define SS          stringstream
#define VS          vector<string>
#define VI          vector<int>
#define VD          vector<double>
#define VLL         vector<long long>
#define IT          ::iterator
#define SI          set<int>
#define mem(a,b)    memset(a,b,sizeof(a))
#define memc(a,b)   memcpy(a,b,sizeof(b))
#define accu(a,b,c) accumulate((a),(b),(c))
#define fi(i,a,b)   for(i=a;i<b;i++)
#define fd(i,a,b)   for(i=a;i>b;i--)
#define fii(a,b)    for(i=a;i<b;i++)
#define fdi(a,b)    for(i=a;i>b;i--)
#define fij(a,b)    for(j=a;j<b;j++)
#define fdj(a,b)    for(j=a;j>b;j--)
#define fik(a,b)    for(k=a;k<b;k++)
#define fdk(a,b)    for(k=a;k>b;k--)
#define fil(a,b)    for(l=a;l<b;l++)
#define fdl(a,b)    for(l=a;l>b;l--)
#define ri(i,a)     for(i=0;i<a;i++)
#define rd(i,a)     for(i=a;i>-1;i--)
#define rii(a)      for(i=0;i<a;i++)
#define rdi(a)      for(i=a;i>-1;i--)
#define rij(a)      for(j=0;j<a;j++)
#define rdj(a)      for(j=a;j>-1;j--)
#define rik(a)      for(k=0;k<a;k++)
#define rdk(a)      for(k=a;k>-1;k--)
#define ril(a)      for(l=0;l<a;l++)
#define rdl(a)      for(l=a;i>-1;l--)

#define fore(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

#define EQ(a,b)     (fabs(a-b)<ERR)
#define all(a)      (a).begin(),(a).end()
#define CROSS(a,b,c,d)  ((b.x-a.x)*(d.y-c.y)-(d.x-c.x)*(b.y-a.y))
#define sqr(a)      ((a)*(a))
#define p2(a)       (1LL<<a)
#define INC(a,b,c)   (b<=a&&a<=c)

//const double pi=2*acos(0.);

template<class TT>TT abs(TT a){if(a<0)  return -a;return a;}
template<class ZZ>ZZ max(ZZ a,ZZ b,ZZ c){return max(a,max(b,c));}
template<class ZZ>ZZ min(ZZ a,ZZ b,ZZ c){return min(a,min(b,c));}

//typedef pair< , > pi;
//typedef struct {int x,y;    void print(){printf("%d %d\n",x,y);}}P;
//bool operator < (const P &a,const P &b){    return (a.x!=b.x?a.x<b.x:a.y<b.y);}
//bool com(P a,P b){return(a.x!=b.x?a.x<b.x:a.y<b.y);}

struct pq{LL n,cs;
    bool operator<(const pq &b)const{
    if(cs!=b.cs)    return cs>b.cs;

}};

const int ww=1010;
int s,d;
LL mat[ww][ww],n;
VI adj[ww],w[ww];
LL c[ww],l[ww],dis[ww];
bool col[ww];

void dij(int su)
{
    priority_queue<pq>q;
    pq u;
    int i;

    mem(col,false);
    mat[su][su]=0;
    q.push((pq){su,0});

    while(!q.empty())
    {
        u = q.top();q.pop();

        if(col[u.n])    continue;
        col[u.n]=true;

        rii(SZ(adj[u.n]))
            if(mat[su][adj[u.n][i]]>u.cs+w[u.n][i])
            {
                mat[su][adj[u.n][i]]=u.cs+w[u.n][i];
                q.push((pq){adj[u.n][i],mat[su][adj[u.n][i]]});
            }
    }

}

void _dij()
{
    priority_queue<pq>q;
    int i;
    pq u,v;
    mem(col,false);
    dis[s]=0;
    q.push((pq){s,0});

    while(!q.empty())
    {
        u = q.top();q.pop();

        if(col[u.n])    continue;
        col[u.n]=true;

        for(i=1;i<=n;i++)
            if(l[u.n]>=mat[u.n][i] && u.cs+c[u.n] < dis[i])
            {
                dis[i] = u.cs+c[u.n];
                q.push((pq){i,dis[i]});
            }

    }

}

int main()
{
    //freopen("in.in","r",stdin);
    //freopen("ou.in","w",stdout);
    //ios_base::sync_with_stdio(false);

    int ks=1,tks;
    int i,j,k,m;
    LL u,v,cs;

    while(cin>>n>>m)
    {
        cin>>s>>d;
        rii(n+1)
        {
                dis[i] = p2(60);
                rij(n+1)    mat[i][j]=p2(60);
                mat[i][j]=0;
        }

        rii(m)
        {
            cin>>u>>v>>cs;

            adj[u].PB(v);
            adj[v].PB(u);
            w[u].PB(cs);
            w[v].PB(cs);
        }
        fii(1,n+1)
        {
            cin>>l[i]>>c[i];
        }
        if(s==d)    {cout<<0<<endl;continue;}

        for(i=1;i<=n;i++)   dij(i);

        _dij();
        if(dis[d]<p2(60))
            cout<<dis[d]<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}

