//Language: GNU C++


/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
  ------ Faculty of Computer Engineering Chulalongkorn University ------
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<utility>
using namespace std;
#define REP(i,FN) for(int i=0;i<FN;i++)
#define FOR(i,ST,FN) for(int i=ST;i<=FN;i++)
#define FORD(i,FN,ST) for(int i=FN;i>=ST;i--)
#define FORX(i,c) for(typeof(c.begin())i=c.begin();i!=c.end();i++)
#define pause system("pause")
#define S scanf
#define P printf
#define X first
#define Y second
#define pb push_back
#define PII pair<int,int>
#define sz size()

const int MOD(1000000007);
const int INF((1<<30)-1);
const int MAXN(505);

int a[MAXN][MAXN],x[MAXN],b[MAXN][MAXN],d[MAXN],p[MAXN][MAXN];

int main(){

    int n;
    S("%d",&n);
    FOR(i,1,n)
     FOR(j,1,n)
      S("%d",&a[i][j]);

    FOR(i,1,n)
     S("%d",&x[i]);

    FOR(i,1,n)
     FOR(j,1,n)
     {
         int u=x[i],v=x[j];
         b[n-i+1][n-j+1]=a[u][v];
     }

    FOR(i,1,n)
     FOR(j,1,n)
      if(i==j) p[i][j]=0;
      else p[i][j]=INF;

    vector<long long>ans;

    FOR(t,1,n)
    {
        FOR(i,1,t-1)
        {
            p[i][t]=b[i][t];
            p[t][i]=b[t][i];
        }

        FOR(k,1,t-1)
        {
            FOR(i,1,t-1)
             p[i][t]=min(p[i][t],p[i][k]+p[k][t]);
            FOR(j,1,t-1)
             p[t][j]=min(p[t][j],p[t][k]+p[k][j]);
        }

        FOR(i,1,t-1)
         FOR(j,1,t-1)
          p[i][j]=min(p[i][j],p[i][t]+p[t][j]);

        long long sum=0;

        FOR(i,1,t)
         FOR(j,1,t)
          if(p[i][j]!=INF)
           sum+=p[i][j];

        ans.pb(sum);
    }

    FORD(i,ans.sz-1,0)
     P("%I64d ",ans[i]);

}




