//Language: GNU C++11


#include<iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iomanip>
#include<fstream>
#include<time.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<map>
#include<stdio.h>
#include<cstdlib>
#include<string.h>
#define i(a) for(int i=0;i<a;i++)
#define j(a) for(int j=0;j<a;j++)
#define debug cout<<"here"<<endl
#include<complex>
#include<algorithm>
#include<queue>
#include<climits>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<string>
#include<setjmp.h>
#include <functional>
#include<list>
#include<set>
#define k(a) for(int k=0;k<a;k++)
#define x first
#define y second
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
using namespace std;
using namespace __gnu_pbds;
typedef complex<double> Point;
//#define X real()
//#define Y imag()
//#define PtoC(r,t) ((r)*exp(Point(0,t)))
//#define angle(v) (atan2((v).Y,(v).X))
//#define length(v) (hypot((v).Y,(v).X))
//#define dot(a,b) ((conj(a)*(b)).X)
//#define cross(a,b) ((conj(a)*(b)).Y)
//#define Vec(a,b) ((b)-(a))
//#define lengthsq(a) dot(a,a)
//#define rotate(v,t) PtoC(v,t)
//#define rotate_about(v,t,a) ((rotate(vec(a,v),t))+(a))
//#include<bits/stdc++.h>
//#ifdef ASD
//    #define fin cin
//    #define fout cout
//#else
//    ifstream fin("ditch.in");
//    ofstream fout("ditch.out");
//#endif // ASD
// fabs(a-b)<=1e-8  1LL<<60
//std::ios_base::sync_with_stdio(false);
//cin.tie(0);
//cout.tie(0);
typedef long long ll;
typedef long double ld;
string to_string(ll num){string str;while(num){str+=num%10+'0';num/=10;}reverse(str.begin(),str.end());
return (str.empty())?"0":str;}
ll strtoll(string str){ll num=0;for(int i=0;str[i];i++)num=num*10+str[i]-'0';return num;}
class compare : public std::binary_function<double,double,bool>
{public:compare( double arg = 1e-7 ) : e(arg) {}bool operator()( const double &left, const double &right  ) const
{return (abs(left - right) > e) && (left < right);}double e;};
inline long long myabs(long long a){return (a<0)?-a:a;}
inline int d_compare(double x,double y){return (fabs(x-y)<=1e-3)?0:(x>y)?1:-1;}
inline long long mod(long long x,long long y){if(y==0)return x;if(x<0)x=-x;if(x>=y)x%=y;return x;}
inline int cmod(int x,int y){if(y==0)return x;if(x<0)x+=(abs(x)/y+1)*y;if(x>=y)x=x%y;return x;}
int Bcount(int mask){int n=0;while(mask)n+=((mask&-mask)!=0),mask&=~(mask&-mask);return n;}
inline bool Bstate(int mask,int idx){return (mask&(1<<idx));}
inline int B1(int mask,int idx){return mask|(1<<idx);}
inline int B0(int mask,int idx){return mask&~(1<<idx);}
inline int drift(int mask,int n){return mask&((1<<n)-1);}
void debugmask(int mask,int n){i(n)cout<<Bstate(mask,i);}
int tdr[8]={0,0,-1,1,-1,1,-1,1},tdc[8]={-1,1,0,0,1,-1,-1,1};
int dr[4]={0,0,-1,1},dc[4]={-1,1,0,0};
template<typename Ty>void clear(Ty&q){Ty empty;swap(q,empty);}
typedef
tree< int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update > o_tree;
tree< ll,ll,less<ll>,rb_tree_tag,tree_order_statistics_node_update > llo_tree;
typedef pair<int,int> point;
typedef pair<ll,ll> llpoint;
typedef pair<ld,ld> ldpoint;
const ld PI=3.14159265;
const ll MOD=1000000993;
#define oo 10000000000000LL
#define sz 500000
int n,m,s,t;
int head[2][100100],nxt[2][100100],from[2][100100],to[2][100100],cost[100100],cnt;
void addEdge(int a,int b,int c,bool f)
{
    nxt[f][cnt]=head[f][a];
    head[f][a]=cnt;
    from[f][cnt]=a;
    to[f][cnt]=b;
    cost[cnt]=c;
    cnt+=f;
}
void addBiEdge(int a,int b,int c)
{
    addEdge(a,b,c,0);
    addEdge(b,a,c,1);
}
void initialSet()
{
    cnt=0;
    memset(head,-1,sizeof head);
}
vector<llpoint> dijkstra(int src,bool f)
{
    vector<llpoint> dis(n+1,llpoint(oo,0));
    dis[src]=make_pair(0,1);
    priority_queue<pair<ll,int> ,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
    q.push(pair<ll,int> (0,src));
    while(!q.empty())
    {
        pair<ll,int>  c=q.top();
        q.pop();
        if(dis[c.y].x==c.x)
            for(int i=head[f][c.y];i!=-1;i=nxt[f][i])
            {
                if(c.x+cost[i]<dis[to[f][i]].x)
                {
                    dis[to[f][i]].x=c.x+cost[i];
                    dis[to[f][i]].y=dis[c.y].y;
                    q.push(pair<ll,int> (c.x+cost[i],to[f][i]));
                }
                else if(c.x+cost[i]==dis[to[f][i]].x)
                        dis[to[f][i]].y=(dis[to[f][i]].y+dis[c.y].y)%MOD;
            }
    }
    return dis;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s>>t;
    initialSet();
    i(m)
    {
        int a,b,c;
        cin>>a>>b>>c;
        addBiEdge(a,b,c);
    }
    vector<llpoint> fromS=dijkstra(s,0);
//    cout<<"7amada"<<endl;
    vector<llpoint> fromT=dijkstra(t,1);
    ll shPath=fromS[t].x;
    for(int i=0;i<cnt;i++)
    {
        ll dis=fromS[from[0][i]].x+fromT[to[0][i]].x;
        ll ways=(fromS[from[0][i]].y*fromT[to[0][i]].y)%MOD;
        if(dis+cost[i]==shPath && ways==fromS[t].y) cout<<"YES"<<endl;
        else if(dis+1<shPath)  cout<<"CAN "<<cost[i]-(shPath-dis)+1<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
