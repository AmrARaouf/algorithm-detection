//Language: GNU C++


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

using namespace std;


#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define inf (1<<30)
#define pb push_back
#define ins insert
#define mp make_pair
#define sz(x) ((i64)x.size())
#define read(x) freopen(x,"r",stdin);
#define rite(x) freopen(x,"w",stdout);
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<i64> vi;

template<class T> inline T __cin(){ T ret; cin>>ret; return ret; }
#define Q __cin<i64>()


#define mx 100020

vi edge[mx], cost[mx];
vi block[mx];
vi add[mx];

struct data{
    i64 u;
    i64 time;
    data(i64 _u,i64 _time){
        u=_u, time=_time;
    }
    bool operator < (const data &b) const{
        return time>b.time;
    }
};

i64 find(i64 v,vi &vec){
   i64 lo=0, hi=sz(vec)-1;
   //cout<<"lo="<<lo<<" "<<hi<<endl;
   while(lo<=hi){
       i64 mid=(lo+hi)/2;
       //cout<<mid<<" "<<vec[mid]<<endl;
       if(vec[mid]>v) hi=mid-1;
       else if(vec[mid]<v) lo=mid+1;
       else return mid;
   }
   return -1;
}

i64 dp[mx];
int main(){
    //read("in.txt");
    ios_base::sync_with_stdio(0);
    i64 n=Q, m=Q;
    rep(i,m){
        i64 u=Q-1, v=Q-1, w=Q;
        edge[u].pb(v);
        edge[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    rep(i,n){
        dp[i]=1LL<<58;
        i64 k=Q;
        //add[i].pb(0);
        //cout<<k<<endl;
        while(k--){
            i64 now=Q;
            i64 vvv;
            if(!sz(block[i]) || now!=block[i].back()+1) vvv=0;
            else vvv=1;
            block[i].pb(now);
            if(!sz(add[i])) add[i].pb(vvv);
            else add[i].pb( vvv+add[i].back() );
            //cout<<block[i].back()<<","<<add[i].back()<<endl;
        }
    }
    priority_queue<data> q;
    dp[0]=0;
    q.push(data(0,0));
    while(!q.empty()){
        data top=q.top();
        q.pop();
        if(top.u==n-1) { cout<<top.time<<endl; return 0; }
        rep(i,sz(edge[top.u])){
            i64 u=top.u;
            i64 v=edge[top.u][i];
            i64 w=cost[top.u][i];
            i64 temp=dp[top.u];
            i64 pos=find(temp,block[u]);
            if(pos!=-1){
                i64 ans=-1, lo=pos, hi=sz(block[u])-1;
                while(lo<=hi){
                    i64 mid=(lo+hi)/2;
                    //cout<<lo<<" "<<hi<<endl;
                    if(add[u][mid]-add[u][pos]==mid-pos) lo=mid+1, ans=mid;
                    else hi=mid-1;
                }
                //cout<<"--ans="<<ans<<endl;
                temp=block[u][ans]+1;
            }
            temp+=w;
            if(dp[v]>temp){
                //cout<<top.u+1<<" "<<v+1<<" time="<<temp<<endl;
                dp[v]=temp;
                q.push(data(v,dp[v]));
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}
