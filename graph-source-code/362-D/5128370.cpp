//Language: GNU C++


// http://codeforces.com/problemset/problem/362/D

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
#define rF(a,b,c) for( int a = c-1 ; a >= b ; --a )
#define CL(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pair<int,int> > vpii;
typedef map<int,int> mii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL
#define y1 Y1

#define N 100100
int n,m,p,q,t1,t2,t3;
int rep[N], ind=0;
pii par[N], resp[N];
ll tot[N];
priority_queue<pll, vector<pll>, greater<pll> > heap;
int findset(int a){ return a==rep[a]?a:rep[a]=findset(rep[a]); }


int main() {
//  cin.sync_with_stdio(false);
    scanf("%d%d%d%d",&n,&m,&p,&q);
//  if(m==0 && p && q==n){ puts("NO"); return 0; }
    n++;
    Fr(i,1,n) rep[i]=i, tot[i]=0, par[i]=MP(-1,-1);
    Fr(i,0,m){
        scanf("%d%d%d",&t1,&t2,&t3);
        t1=findset(t1), t2=findset(t2);
        if(t1!=t2) rep[t1]=t2, tot[t2]+=tot[t1], par[t2] = MP(t1,t2);;
        tot[t2]+=ll(t3);
    //  printf("OXE %d %d\n",t1,t2);
    }
    
    Fr(i,1,n){
        t1=findset(i);
        if(~tot[t1]) heap.push(MP(tot[t1], t1)), tot[t1]=-1;
    }
    
/*  if(n==1001){
        printf("tam %d\n",heap.size());
        Fr(i,0,10){
            printf(" eh %I64d %I64d\n",heap.top().F, heap.top().S);
            heap.pop();
        }
    }//*/
    
    while(int(heap.size())>q){
        if(!p) {
            puts("NO");
            return 0;
        }
        pll a = heap.top(); heap.pop();
        pll b = heap.top(); heap.pop();
        resp[ind++] = MP(a.S,b.S); //printf("%I64d %I64d\n",a.S, b.S);
        pll novo = MP((a.F+b.F) + min((a.F+b.F)+1LL, 1000000000LL), a.S);
    //  if(n==1001) printf("Tira (%I64d %I64d) e (%I64d %I64d), insere (%I64d %I64d)\n",a.F,a.S, b.F,b.S, novo.F,novo.S);
        heap.push(novo);
        par[a.S] = MP(a.S, b.S);
        p--;
    }
    
    if(int(heap.size()) != q){puts("NO"); return 0;}
    
    if(p){
//      printf("hum %d\n",p);
        Fr(i,1,n) if(~par[i].F){
//          puts("...");
            while(p) resp[ind++] = MP(par[i].F,par[i].S), p--; //printf("%d %d\n",par[i].F, par[i].S);
            break;
        }
//      printf("AF%d\n",p);
        if(p) {puts("NO"); return 0;}
    }
    
    puts("YES");
    Fr(i,0,ind) printf("%d %d\n",resp[i].F,resp[i].S);
    
    return 0;
}
