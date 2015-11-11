//Language: GNU C++


//Lasha Bukhnikashvili
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<string>
#define Pi 3.14159265358
#define mod9 %1000000009
#define INF 1000000000
#define mod7 %1000000007
#define LL  unsigned long long
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
 int i,j,k,num,sum,maxlen,child[500001],d,ind[1001][1001],a[1001][1001],viz[1001][1001],n,m,sx,sy,ans[1001],s;
 void dfs(int vx,int vy){
      num++;
      viz[vx][vy]=1;
      if (!viz[vx-1][vy] && a[vx-1][vy]) dfs(vx-1,vy);
      if (!viz[vx+1][vy] && a[vx+1][vy]) dfs(vx+1,vy);
      if (!viz[vx][vy+1] && a[vx][vy+1]) dfs(vx,vy+1);
      if (!viz[vx][vy-1] && a[vx][vy-1]) dfs(vx,vy-1);
 };
 bool ones_num(int a1,int b1,int a2,int b2,int t){
      int out=0;
      if (a1==a2) {
         for (k=b1;k<=b2;k++)
             out+=a[a1][k];
      } else {
        for (k=a1;k<=a2;k++)
             out+=a[k][b1];
      };
      if (out!=t+1) return 0;
      if (a1==a2) {
         for (k=b1;k<=b2;k++)
             viz[a1][k]=1;
      } else {
        for (k=a1;k<=a2;k++)
             viz[k][b1]=1;
      };
      return 1;
 };
 void connect(int a1,int b1,int a2,int b2){
      child[ind[a1][b1]]++;
      child[ind[a2][b2]]++;
 };
 bool f(int x){
      for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
              viz[i][j]=0,ind[i][j]=0;
      for (i=1;i<=1000000/2;i++)
          child[i]=0;
      int x0,y0;
      if (sx%x==0) x0=x; else x0=sx%x;
      if (sy%x==0) y0=x; else y0=sy%x;
      int v=0;
      for (i=x0;i<=n;i+=x)
         for (j=y0;j<=m;j+=x)
             if (a[i][j]){
                if (ind[i][j]==0) ++v,ind[i][j]=v;
                if (ones_num(i,j,i+x,j,x)) {if (ind[i+x][j]==0) ++v,ind[i+x][j]=v;connect(i,j,i+x,j);};
                if (ones_num(i,j,i,j+x,x)) {if (ind[i][j+x]==0) ++v,ind[i][j+x]=v;connect(i,j,i,j+x);};
             };
      int even=0,odd=0;
     for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
              if (viz[i][j]==0 && a[i][j]) return 0;
     for (i=1;i<=v;i++){
         if (child[i]%2==0) even++; else odd++;
     };
     if (odd==2 || odd==0) 
     return 1; else return 0;
 };
int main(){
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
 #endif
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++){
            cin>>a[i][j],sum+=a[i][j];
            if (a[i][j] && !sx) sx=i,sy=j;
        }; 
    dfs(sx,sy);
    for (i=1;i<=n;i++)
          for (j=1;j<=n;j++)
              viz[i][j]=0;
    if (sum>num) {cout<<-1; return 0;};
    num=0;
     for (i=1;i<=n;i++){
        num=0;
        for (j=1;j<=m;j++){
            if (a[i][j]==1) num++; else num=0;
            maxlen=max(maxlen,num);
        };
    };
    for (j=1;j<=m;j++){
        num=0;
        for (i=1;i<=n;i++){
            if (a[i][j]==1) num++; else num=0;
            maxlen=max(maxlen,num);
        };
    };
    for (d=1;d*d<=maxlen-1;d++)
        if ((maxlen-1)%d==0){
           if (d!=1 && f(d)) ans[++s]=d;
           if (d!=(maxlen-1)/d && f((maxlen-1)/d)) ans[++s]=(maxlen-1)/d;
        }; 
    sort(ans+1,ans+s+1);
    if (s==0) {cout<<-1; return 0;};
    for (i=1;i<=s;i++)
        cout<<ans[i]<<" ";
 return 0;
}
