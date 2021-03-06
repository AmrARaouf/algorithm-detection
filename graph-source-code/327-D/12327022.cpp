//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef int ll;
typedef set<int> si;
typedef long long Long;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<Long>vl;
typedef pair<int,int>pii;
typedef pair<Long,Long>pll;
typedef pair<string,int>psi;
typedef pair<double,double>pdd;
//#define get getchar_unlocked
//#define put putchar_unlocked
#define get getchar
#define put(c) printf("%c",c)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define repstl(i, s) for (__typeof((s).end())i=(s).begin();i!=(s).end();++i)
#define PI 3.1415926535897932384626433832795
#define FO freopen ("out.txt", "w", stdout)
#define FI freopen ("in.txt", "r", stdin)
#define ref(i,a,n) for(int i=a;i<=n;i++)
#define reb(i,n,a) for(int i=n;i>=a;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define pc(c) printf("%c",c)
#define ps printf(" ")
#define pn printf("\n")
#define l(a) 2*a+1
#define r(a) 2*a+2
#define left(a,b) a,(a+b)/2
#define right(a,b) (a+b)/2+1,b
#define mid(a,b) (a+b)/2

inline char skipwhitespace() { 
    char ch = get();
    while(ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') 
        ch = get();
    return ch;
}

void gi(ll &x) {
    register ll c = get(); x = 0;
    ll sn=1;
    for(;(c<48 || c>57);c = get()) 
    if(c=='-') sn=-1;
    for(;c>47 && c<58;c = get()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    x*=sn;
}

void gii(LL &x) {
    register LL c = get(); x = 0;
    LL sn=1;
    for(;(c<48 || c>57);c = get()) 
    if(c=='-') sn=-1;
    for(;c>47 && c<58;c = get()) {
        x = (x<<1) + (x<<3) + c - 48;
    }
    x*=sn;
}

void wi(ll n) {
    ll sign = n >= 0 ? 1 : -1;
    n = n>0 ? n : -n;
    char buf[10];
    ll i = 9;
    if(!n) buf[i--] = 48;
    while(n) {
        buf[i--] = n % 10 + 48;
        n /= 10;
    }
    if(sign < 0) put('-');
    while(++i < 10) put(buf[i]);
}
 
void wii(LL n)
{
    LL sign = n >= 0 ? 1 : -1;
    n = n>0 ? n : -n;
    char buf[25];
    LL i = 24;
    if(!n) buf[i--] = 48;
    while(n) {
        buf[i--] = n % 10 + 48;
        n /= 10;
    }
    if(sign < 0) put('-');
    while(++i < 25) put(buf[i]);
}

ll gs(char *s)
{
    char ch=skipwhitespace();
    ll n=0;
    while( (ch != '\n' && ch != ' ' && ch != '\t') )
    {
        s[n++] = ch;
        ch = get();
    }
    s[n] = 0;
    return n;
}

void ws(char *s)
{
    char *p = s;
    while(*p) {
        put(*p);
        p++;
    }
}

int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

#define N 505
char str[N][N];
ll n,m,x,y,visit[N][N]={0};
vector< pair<char,pii> > ans;
bool check(ll i,ll j) { return (i>=0 && j>=0 && i<n && j<m && str[i][j]=='.' && !visit[i][j]); }

void dfs(ll i,ll j) {
    if(visit[i][j]) return ;
    visit[i][j]=1;
    ll cnt=0;
    vector<pii> vec; vec.clear();
    rep(k,4) if(check(i+dx[k],j+dy[k])) vec.pb(mp(i+dx[k],j+dy[k]));
    if(vec.sz) {
        ans.pb(mp('B',mp(i+1,j+1)));
        repstl(k,vec) dfs(k->ff,k->ss);
        if(x!=i || y!=j) {
            ans.pb(mp('D',mp(i+1,j+1)));
            ans.pb(mp('R',mp(i+1,j+1)));
        }
    } else {
        if(x!=i || y!=j) ans.pb(mp('R',mp(i+1,j+1)));
        else         ans.pb(mp('B',mp(i+1,j+1)));
    }
}

int main() {
    gi(n); gi(m);
    rep(i,n) gs(str[i]);
    rep(i,n) rep(j,m) if(str[i][j]=='#') visit[i][j]=1;
    rep(i,n) rep(j,m) if(!visit[i][j]) { x=i; y=j; dfs(i,j); }
    cout << ans.sz << endl;
    repstl(i,ans) put(i->ff),ps,wi(i->ss.ff),ps,wi(i->ss.ss),pn;
//  if(n>=10) rep(i,n) cout << str[i] << endl;
    return 0;
}
