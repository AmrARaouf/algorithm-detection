//Language: GNU C++0x


//created by Yash Sadhwani
//sadhwaniyash6
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000009
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
    ll y=((((tp*)a)->w)-(((tp*)b)->w));
    if(y>0)return 1;
    else if(y==0)return 0;
    else return -1;
}*/

#define MAXN 100010
#define ii pair<int,int>

ii d[MAXN];
int N,K;
int edges[MAXN];
vector<ii> ans;
int len[MAXN];

inline void ReadInput(void){
    si(N); si(K);
    for(int i=1;i<=N;i++){
        int x; si(x);
        d[i]=ii(x,i);
        len[i]=x;
    }
}

inline void solve(void){
    if(N==1 && K==0){
        if(d[1].first==0){
            cout<<"0\n";
            return;
        }else{
            cout<<"-1\n";
            return;
        }
    }
    else if(N==1){
        cout<<"-1\n";
        return;
    }
    else if(K==0){
        cout<<"-1\n";
        return;
    }
    sort(d+1,d+N+1);
    queue<int> pp;
    pp.push(d[1].second);
    if(d[1].first!=0){
        cout<<"-1\n";
        return;
    }
    for(int i=2;i<=N;i++){
        
        while(!pp.empty()  && (edges[pp.front()]==K || len[pp.front()]<len[d[i].second]-1))pp.pop();
        if(pp.empty()){
            cout<<"-1\n";
            return;
        }
        int u=pp.front();
        //cout<<u<<" "<<d[i].second<<endl;
        if(len[u]==len[d[i].second]){
            cout<<"-1\n";
            return;
        }
        //cout<<"hello\n";
        if(edges[u]<K && len[u]+1==len[d[i].second]){
            edges[u]++;
            edges[d[i].second]++;
            pp.push(d[i].second);
            ans.pb(ii(u,d[i].second));
            if(edges[u]==K)pp.pop();
            //cout<<u<<" "<<d[i].second<<endl;
        }
    }   
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

inline void Refresh(void){
    fill(edges,edges+MAXN,0);
}

int main()
{
    ReadInput();
    Refresh();
    solve();    
    return 0;
}