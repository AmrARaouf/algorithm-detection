//Language: GNU C++


#include<bits/stdc++.h>
#define in freopen("input.txt","r",stdin)
#define out freopen("output.txt","w",stdout)

#define inp freopen(".in","r",stdin)
#define outp freopen(".out","w",stdout)

using namespace std;

#define pb push_back
#define pf push_front
#define p_f pop_front
#define p_b pop_back
#define LL long long int
#define LD long double
#define MP make_pair
#define sqr(x) (x*x)
#define fi first
#define dist(x,y,xx,yy) sqrt( (x-xx)*(x-xx)+(y-yy)*(y-yy) )
#define lenint int intsi(int x){ int cnt=0; while(x>0){cnt++;x/=10;} return (cnt); }
#define se second
#define all(v) v.begin(),v.end()
#define sc scanf
#define DEBUG(a) cout<<#a<<" -> "<<a<<endl;
#define pr printf
#define si size()
#define str strlen
#define gcd LL GCD(LL a,LL b){ if(b==0)return a;else return GCD(b,a%b); }
const int INF=(-1u)/2;
const long long int INF2=(-1ull)/2;
int a,b,i,d[1011000],j,k,n,m,timer=0,l,r,x,y;
int c,cnt=0,fl=0,a2,a3=-1000000,ans=0;
vector<int>v[100101];
vector< pair<int,int> >g[100101];
priority_queue< pair<int,int> >q;
main()
{
    sc("%d%d",&n,&m);
    for( i=0;i<m;i++ )
    {
        sc("%d%d%d",&a,&b,&c);
        g[a].pb( MP(b,c) );
        g[b].pb( MP(a,c) );
    }
    for( i=1;i<=n;i++ )
    {
        d[i]=INF;
        sc("%d",&k);
        for( j=0;j<k;j++ )
        {
            sc("%d",&a);
            v[i].pb(a);
        }
    }
    q.push( MP( 0,1 ) );
    while( !q.empty() )
    {
        x=q.top().fi*-1;
        y=q.top().se;
        q.pop();
        if( d[y]<x )continue;
        d[y]=x;
        for( i=0;i<v[y].si;i++ )
        {
            if( v[y][i]==x )x++;
        }
        for( i=0;i<g[y].si;i++ )
        {
            int to=g[y][i].fi;
            if( d[to]>x+g[y][i].se )
            {
                d[to]=g[y][i].se+x;
                q.push( MP( -1*d[to],to ) );
            }
        }
    }
    if( d[n]==INF )pr("-1\n");
    else pr("%d\n",d[n]);
    return 0;
}
