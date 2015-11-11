//Language: GNU C++


#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<math.h>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<stack>
#include<functional>

using namespace std;

typedef long long ll;

//#define CODEForces

#ifndef CODEForces
    #define G getchar_unlocked
    #define P putchar_unlocked
#else
    #define G getchar
    #define P putchar
#endif

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(o) (o).begin(),(o).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
typedef vector <int> vi;typedef pair<int,int> pii;typedef vector<pii> vpi;typedef long long ll;
template <typename T,typename U> void _max(T &a,U b){if(a<b) a=b;}
template <typename T,typename U> void _min(T &a,U b){if(a>b) a=b;}
#define K 1000000007

ll gcd(ll a,ll b)
{
    if(b>a) a=a^b,b=a^b,a=a^b;
    ll x;
    while(b)
    x=a%b,a=b,b=x;
    
    return a;
}

int a[4005][4005],b[4005];
vector <int>    v[4005];

int main()
{
    int n,m,i,j,k,ans=-1,x,y;
    
    scanf("%d%d",&n,&m);
    
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        a[x][y]=a[y][x]=1;
        v[x].pb(y);
        v[y].pb(x);
        b[x]++;
        b[y]++;
    }
    
    for(i=1;i<=n;i++){
        for(j=0;j+1<v[i].size();j++){
            for(k=j+1;k<v[i].size();k++){
                if(a[v[i][j]][v[i][k]]){
                    if(ans==-1) ans=b[i]+b[v[i][j]]+b[v[i][k]]-6;
                    else ans=min(ans,b[i]+b[v[i][j]]+b[v[i][k]]-6);
                    //cout<<i<<' '<<v[i][j]<<' '<<v[i][k]<<' '<<ans<<endl;
                }   
            }
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}