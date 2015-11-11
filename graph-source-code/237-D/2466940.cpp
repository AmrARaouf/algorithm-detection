//Language: GNU C++


#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<sstream>
#include<string>
#include<climits>
#include<stack>
#include<set>
#include<bitset>
#include<cmath>
#include<deque>
#include<map>
#include<queue>
#define iinf 0x7f7f7f7f
#define linf 1000000000000000000LL
#define dinf 1e200
#define eps 1e-11
#define all(v) (v).begin(),(v).end()
#define sz(x)  x.size()
#define pb push_back
#define mp make_pair
#define lng long long
#define sqr(a) ((a)*(a))
#define pii pair<int,int>
#define pll pair<lng,lng>
#define pss pair<string,string>
#define pdd pair<double,double>
#define X first
#define Y second
#define pi 3.14159265359
#define ff(i,xi,n) for(int i=xi;i<=(int)(n);++i)
#define ffd(i,xi,n) for(int i=xi;i>=(int)(n);--i)
#define ffl(i,r) for(int i=head[r];i!=-1;i=edge[i].next)
#define ffe(i,r) for(_edge *i=head[r];i;i=i->next)
#define cc(i,j) memset(i,j,sizeof(i))
#define two(x)          ((lng)1<<(x))
#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
#define mod  1073741824
#define pmod(x,y) (x%y+y)%y
using namespace std;
typedef vector<int>  vi;
typedef vector<string>  vs;
template<class T> inline void checkmax(T &x,T y)
{
    if(x<y) x=y;
}
template<class T> inline void checkmin(T &x,T y)
{
    if(x>y) x=y;
}
template<class T> inline T Min(T x,T y)
{
    return (x>y?y:x);
}
template<class T> inline T Max(T x,T y)
{
    return (x<y?y:x);
}
template<class T> T Abs(T a)
{
    return a>0?a:(-a);
}
template<class T> inline T lowbit(T n)
{
    return (n^(n-1))&n;
}
template<class T> inline int countbit(T n)
{
    return (n==0)?0:(1+countbit(n&(n-1)));
}
int n;
int y;
vi a[111111];
int main()
{
    while(scanf("%d",&n)==1)
    {
        ff(i,1,n) a[i].clear();   printf("%d\n",n-1);
        ff(i,1,n-1)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d %d %d\n",2,u,v);
           a[u].pb(i); a[v].pb(i);
           }
        ff(i,1,n)
        ff(j,0,a[i].size()-2)
        printf("%d %d\n",a[i][j],a[i][j+1]);
    }
    return 0;
}
