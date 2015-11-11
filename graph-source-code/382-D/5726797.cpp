//Language: GNU C++


/***************************************************
   #>File Name: d1.cpp
   #>Auther: wintowanti
   #>Mail: wintowanti@163.com
   #>Created Time: 2014/1/18 6:28:03
***************************************************/

#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<cmath>
#include<set>

using namespace std ;

#define int int
#define pb push_back
#define mp make_pair
#define ft first
#define sd second
#define it iterator
#define mt(a,b) memset(a,b,sizeof(a))

typedef pair<int,int> pii;
typedef long long ll;

const int INF=0x3f3f3f3f;
const int MV=2008;
const int ME=4000006;
const int MOD=1000000007;

int g1[ME];
struct G{
	int head[ME],next[ME],ev[ME];
	int en;
	void init(){
		mt(head,-1);
		en=0;
	}
	void add(int u,int v){
		ev[en]=v;next[en]=head[u];head[u]=en++;
	}
}g2;
int n,m;
int judge(int x,int y){
	if(x<0||x>n-1||y<0||y>m-1) return 1;
	return 0;
}
int o[4][2]={
	0,-1,
	0,1,
	-1,0,
	1,0,
};
int num[MV][MV];
char map1[MV][MV];
int en;
int vis[ME];
int dp[ME];
int f(char p){
	if(p=='<') return 0;
	if(p=='>') return 1;
	if(p=='^') return 2;
	if(p=='v') return 3;
}
int dfs_=0;
void dfs(int u,int flag){
	vis[u]=flag;
	if(dfs_) return ;
	for(int i=0;i<1;i++){
		int v=g1[u];
		if(v==0) continue;
		if(vis[v]){
			if(vis[v]==flag){
				dfs_=1;
				return ;
			}
		}else{
			dfs(v,flag);
		}
	}
}
int dfs1(int u){
	if(dp[u]!=-1) return dp[u];
	dp[u]=1;
	for(int i=g2.head[u];i!=-1;i=g2.next[i]){
		int v=g2.ev[i];
		int t1=dfs1(v);
		if(t1+1>dp[u]) dp[u]=t1+1;
	}
	return dp[u];
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;i++) scanf("%s",map1[i]);
		int en=1;
		mt(vis,0);
		g2.init();
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) if(map1[i][j]!='#') num[i][j]=en++;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]!='#'){
					int next1=f(map1[i][j]);
					int x1=i+o[next1][0];
					int y1=j+o[next1][1];
					if(judge(x1,y1)) continue;
					if(map1[x1][y1]=='#') continue;
					int t1=num[i][j];
					int t2=num[x1][y1];
					g1[t1]=t2;
					g2.add(t2,t1);
				}
			}
		}
		dfs_=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]!='#'){
					if(vis[num[i][j]]==0) dfs(num[i][j],num[i][j]);
				}
			}
		}
		if(dfs_){
			puts("-1");
			continue;
		}
		mt(dp,-1);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]!='#'){
					dfs1(num[i][j]);
				}
			}
		}
		int ans[3];mt(ans,0);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map1[i][j]!='#'){
					int t1=dp[num[i][j]];
					ans[0]=t1;
					sort(ans,ans+3);
				}
			}
		}
		int tans=ans[1]+ans[2];
		printf("%d\n",tans);
	}
	return 0;
}
/*
7 5
#####
##v##
##v##
##<##
##^##
##^##
##^##
 * 
  */
