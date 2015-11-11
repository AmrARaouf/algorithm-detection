//Language: GNU C++


/*
***************************************************************************************************************

                            Author : Yash Sadhwani
                            
                            
                            # 100% Copied from Sundar

                        PATIENCE IS ABOVE PERFECTION !!!!

**************************************************************************************************************
*/
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
#include<stack>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)



//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
    ll y=((((tp*)a)->w)-(((tp*)b)->w));
    if(y>0)return 1;
    else if(y==0)return 0;
    else return -1;
}

//return true if in correct positions
bool way(ii x,ii y){
    return x.first<y.first or x.first==y.first and x.second<y.second;
}

//return false if in correct positions
struct OrderBy
{
    bool operator() (ii a, ii b) { return a.S < b.S; }
};
priority_queue<ii, std::vector<ii >, OrderBy> Q;


ll modpow(ll base, ll exponent,ll modulus){
    if(base==0&&exponent==0)return 0;
    ll result = 1;
    while (exponent > 0){
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

#define getchar_unlocked getchar
using namespace std;
inline int scan(){
    char c = getchar_unlocked();
    int x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}

*/


#define MAXN 100010
#define ls (node<<1)
#define rs ((node<<1)+1)
#define ii pair<int,int>
#define F first
#define S second
#define ins insert

multiset<int> AdjList[MAXN];

int path[5*MAXN+10];

int timers=0;

int N,M;



void EULER(int node){
    while(AdjList[node].size()){
        int from=node;
        int to=*(AdjList[node].begin());
        AdjList[from].erase(AdjList[from].find(to));
        AdjList[to].erase(AdjList[to].find(from));
        EULER(to);
    }
    path[timers++]=node;
}

inline void ReadInput(void){
    si(N); si(M);
    for(int i=1;i<=M;i++){
        int a,b;
        si(a); si(b);
        AdjList[a].insert(b);
        AdjList[b].insert(a);
    }
}

inline void solve(void){
    int prev=-1;
    for(int i=1;i<=N;i++){
        int sz=AdjList[i].size();
        if(sz&1){
            if(prev!=-1){
                AdjList[i].insert(prev);
                AdjList[prev].insert(i);
                prev=-1;
                M++;
            }else{
                prev=i;
            }
        }
    }
    if(M&1){
        AdjList[1].insert(1); 
        AdjList[1].insert(1);
        M++;
    }
    EULER(1);
    printf("%d\n",M );
    for(int i=0;i<M;i++){
        if(i&1){
            printf("%d %d\n",path[i],path[i+1] );
        }else{
            printf("%d %d\n",path[i+1],path[i] );
        }
    }
}

inline void Refresh(void){
    
}

int main()
{   
    ios_base::sync_with_stdio(false);
    ReadInput();
    solve();
    return 0;
}


//A man got to have a code

