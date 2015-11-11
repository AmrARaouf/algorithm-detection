//Language: GNU C++


/*
online judge :
author       : rafsan
algorithm    :
*/
//#pragma comment(linker,"/STACK:102400000,102400000")
#include<iostream>
#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<climits>
#include<functional>
#include<fstream>
#include<istream>
#include<iterator>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>


using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b-1);i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)

#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define PCC pair<char,char>
#define PIC pair<int,char>
#define PCI pair<char,int>
#define FST first
#define SEC second
#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define PI acos(-1.0)
#define RADIANS(x) (((1.0 * x * PI) / 180.0))
#define DEGREES(x) (((x * 180.0) / (1.0 * pi)))
#define SINE(x) (sin(RADIANS(x)))
#define COSINE(x) (cos(RADIANS(x)))
#define SETBIT(x, i) (x |= (1 << i))
#define TANGENT(x) (tan(RADIANS(x)))
#define ARCSINE(x) (DEGREES((asin(x))))
#define RESETBIT(x, i) (x &= (~(1 << i)))
#define ARCCOSINE(x) (DEGREES((acos(x))))
#define ARCTANGENT(x) (DEGREES((atan(x))))
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define FASTIO ios_base::sync_with_stdio(0);cin.tie();
#define IN scanf
#define OUT printf
#define SI(a) scanf("%d",&a)
#define SL(a) scanf("%lld",&a)
#define SD(a) scanf("%lf",&a)
#define OI(a) printf("%d",a)
#define OL(a) printf("%lld",a)
#define OD(a) printf("%lf",a)
#define LL long long
#define ULL unsigned long long
#define EPS 1e-9
#define MOD 1000000007
#define MX  200005

int arr[MX];
struct Edge{int adj,next;}edge[2*MX];
int first[MX],edg=0,level[MX];
int strt[MX],timer=0,lim;
PII hold[MX];
void addEdge(int from,int to){++edg;edge[edg].adj=to;edge[edg].next=first[from];first[from]=edg;}
void dfs(int u,int lev)
{
    strt[u]=++timer;
    level[u]=lev;
    for(int e=first[u];e;e=edge[e].next)
    if(strt[edge[e].adj]==0)dfs(edge[e].adj,lev+1);
    hold[u]=MP(strt[u],++timer);
}
struct BIT
{
    LL tree[2*MX];
    void init(){CLR(tree);}
    void update(int idx,int val){for(;idx<=lim;idx+=idx&-idx)tree[idx]+=val;}
    LL query(int idx){LL res=0;for(;idx>0;idx-=idx&-idx)res+=tree[idx];return res;}
}odd,even;
int main()
{
    int n,q,s,d;
    scanf("%d%d",&n,&q);
    FOR(i,1,n+1)
    {
        scanf("%d",&arr[i]);
    }
    FOR(i,1,n)
    {
        scanf("%d%d",&s,&d);
        addEdge(s,d);
        addEdge(d,s);
    }
    dfs(1,1);
    lim=timer;
    //DEBUG(lim);
    //BIT odd,even;
    odd.init();
    even.init();
    //FOR(i,0,lim+1)cout<<odd.tree[i]<<" "<<even.tree[i]<<endl;
    FOR(i,0,q)
    {
        scanf("%d",&s);
        if(s==2)
        {
            scanf("%d",&s);
            if(level[s]&1)
            {
                printf("%I64d\n",arr[s]+odd.query(hold[s].FST)-even.query(hold[s].FST));
                //cout<<arr[s]+odd.query(hold[s].FST)-even.query(hold[s].FST)<<endl;
            }
            else
            {
                printf("%I64d\n",arr[s]-odd.query(hold[s].FST)+even.query(hold[s].FST));
            }
        }
        else
        {
            scanf("%d%d",&s,&d);
            if(level[s]&1)
            {
                 odd.update(hold[s].FST,d);
                 odd.update(hold[s].SEC+1,-d);
                //even.update(hold[s].FST,-d);
               // even.update(hold[s].SEC+1,+d);
            }
            else
            {
              //   odd.update(hold[s].FST,-d);
              //   odd.update(hold[s].SEC+1,+d);
                even.update(hold[s].FST,d);
                even.update(hold[s].SEC+1,-d);
            }
        }
    }

return 0;
}
/*

*/
