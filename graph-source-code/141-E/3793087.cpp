//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;
const int nmax = 1010;
int n,m;
int se[nmax][nmax],me[nmax][nmax],u,v;
int color_s[nmax],color[nmax];
int nc=1;
vector < int > res;
void dfs(int u,int c){
  color_s[u] = c;
  for(int j = 1;j<=n;j++)
    if(color_s[j]==0 && me[u][j]>0)
     dfs(j,c);
}
void uni(int u,int v){
 int c = color[u];
 for(int i=1;i<=n;i++)
  if(color[i]==c)
   color[i] = color[v];
}
int main() {
	int u,v; char c;
    scanf("%d%d", &n, &m);
    for(int i=1;i<=m;i++){
	 scanf("%d %d %c",&u,&v,&c);
     if(c == 'S') se[u][v] = i; else me[u][v] = i;
     if(c == 'S') se[v][u] = i; else me[v][u] = i;
    }
    for(int i=1;i<=n;i++)
     if(color_s[i]==0)
      dfs(i,nc++);
    if(n%2==0){ cout << -1 << endl; return 0; }
    if(n == 1 ){ cout << 0 << endl; return 0; }
    
    u = (n-1)/2;
    for(int i=1;i<=n;i++) color[i] = i; 

    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(se[i][j]>0 && color_s[i]!=color_s[j] && color[i]!=color[j] && u!=0)
        {
        uni(i,j); res.push_back(se[i][j]); u--;}

   for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(se[i][j]>0 && color_s[i]==color_s[j] && color[i]!=color[j] && u!=0)
        {
        uni(i,j); res.push_back(se[i][j]); u--;}
    if(u!=0){
	  cout << -1 << endl; return 0;
    }
    u = (n-1) / 2;
   for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      if(me[i][j]>0 && color[i]!=color[j] && u!=0)
        {
        uni(i,j); res.push_back(me[i][j]); u--;}   
  if(res.size()!=n-1){
	 cout << -1 << endl; return 0;
  }
  cout << n-1 << endl;
  for(int i=0;i<n-1;i++)
   cout << res[i] << ' ';
cout << endl;
return 0;
}