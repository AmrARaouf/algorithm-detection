//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
 
#define gc getchar
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define MOD 1000000007
#define inf 2000000000
#define oo (ll)1e18
#define TRACE
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
 
#ifdef TRACE
 #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
 
#else
 
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
 
#endif
  
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

void scan(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
const int M=4005;
bool g[M][M];
pair<int,int>x[M];
int r[M];
int main(){
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&x[i].ff,&x[i].ss);
        g[x[i].ff][x[i].ss]=1;
        g[x[i].ss][x[i].ff]=1;
        if(x[i].ff>x[i].ss)
        swap(x[i].ff,x[i].ss);
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            r[i]+=g[i][j];
        }
    }
    sort(x,x+m);
    
    int ans=inf;
    for(int i=0;i<m;i++){
        int a=x[i].ff,b=x[i].ss;
        for(int j=i+1;j<m;j++){
            int c=x[j].ff,d=x[j].ss;
            if(c==a&&g[b][d]==1){
                ans=min(ans,r[a]+r[b]+r[d]-6);
                //trace4(a,b,c,d);
                //trace3(r[a],r[b],r[d]);
            }
        }
    }
    if(ans==inf)ans=-1;
    printf("%d\n",ans); 
    return 0;
}
