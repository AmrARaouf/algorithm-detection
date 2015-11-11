//Language: GNU C++



using namespace std;

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define inf (1<<30)
#define eps 1e-9
#define pb push_back
#define ins insert
#define mp make_pair
#define sz(x) ((int)x.size())
#define clr clear()
#define all(x) x.begin(),x.end()
#define xx first
#define yy second
#define sqr(x) ((x)*(x))
#define mem(x,val) memset((x),(val),sizeof(x));
#define read(x) freopen(x,"r",stdin);
#define rite(x) freopen(x,"w",stdout);
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef map<int,st> mis;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define mx 1010
vi edge[mx];
bool v[mx];
void call(int u){
    if(v[u]) return ;
    v[u]=1;
    rep(i,sz(edge[u])) call(edge[u][i]);
}
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    while(cin>>n){
        vpii vec;
        rep(i,n){
            edge[i].clr;
            int x,y;
            cin>>x>>y;
            x--,y--;
            vec.pb(mp(x,y));
        }
        rep(i,n){
            rep(j,n) if(i!=j) {
                if(vec[i].xx==vec[j].xx || vec[i].yy==vec[j].yy) edge[i].pb(j);
            }
        }
        mem(v,0);
        int cnt=0;
        rep(i,n)if(!v[i]){
            call(i);
            cnt++;
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}
