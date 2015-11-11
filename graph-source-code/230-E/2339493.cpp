//Language: MS C++


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ull unsigned __int64
#define ll __int64
//#define ll long long
#define ls rt<<1
#define rs ls|1
#define lson l,mid,ls
#define rson mid+1,r,rs
#define middle l+r>>1
#define INF 0x3F3F3F3F
#define esp (1e-10)
#define MOD 1000000007
#define type ll
typedef pair<int,int> pii;
typedef multiset<int> mset;
typedef multiset<int>::iterator mst_it;
//const double pi=acos(-1.0);
const int M=1000000 +5;
#define clr_all(x,c) memset(x,c,sizeof(x))
#define clr(x,c,n) memset(x,c,sizeof(x[0])*n+1)
type min(type x,type y){return x<y? x:y;}
type max(type x,type y){return x>y? x:y;}
void swap(type& x,type& y){type t=x;x=y;y=t;}
int T,cas=0;

ll n,m;
ll cnt[M];

void preSof(){
    return;
}

void run(){
    int i,j;
    ll ret=n*(n-1)*(n-2)/6-m*(n-2);
    clr(cnt,0,n);
    for(i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        cnt[a]++,cnt[b]++;
    }
    if(n<3){puts("0");return;}
    for(i=1;i<=n;i++) if(cnt[i])
        ret+=cnt[i]*(cnt[i]-1)/2;
    printf("%I64d\n",ret);
}

int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    preSof();
    //run();
    while(~scanf("%I64d%I64d",&n,&m)) run();
    //for(scanf("%d",&T),cas=1;cas<=T;cas++) run();
    //system("pause");
    return 0;
}