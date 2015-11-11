//Language: MS C++


#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<vector>
#include<cmath>
#include<memory.h>
#include<set>
#include<cctype>

#define ll long long

#define eps 1e-8

const int inf = 1<<30;

const ll INF = 1ll<<61;

using namespace std;

//vector<pair<int,int> > G;
//typedef pair<int,int > P;
//vector<pair<int,int> > ::iterator iter;
//
//map<ll,int >mp;
//map<ll,int >::iterator p;

vector<pair<int,int >> G;

char mp[1000 + 55][1000 + 55];

int n,m;

int cnt;

int mark = 0;

int dir[4][2] = {-1,0,0,-1,1,0,0,1};

int dp[1000 + 55][1000 + 55];

bool flag[200][200];

bool vis[1000 + 55][1000 + 55];

void init() {
	G.clear();
	memset(vis,false,sizeof(vis));
	memset(flag,false,sizeof(flag));
	memset(dp,-1,sizeof(dp));
	flag['D' - 'A']['I' - 'A'] = true;
	flag['I' - 'A']['M' - 'A'] = true;
	flag['M' - 'A']['A' - 'A'] = true;
	flag['A' - 'A']['D' - 'A'] = true;
}

bool input() {
	while(cin>>n>>m) {
		for(int i=0;i<n;i++) {
			scanf("%s",mp[i]);
			for(int j=0;j<m;j++) {
				if(mp[i][j] == 'D')
					G.push_back(make_pair(i,j));
			}
		}
		return false;
	}
	return true;
}

int dfs(int posx,int posy,char ch) {
	if(dp[posx][posy] != -1)return dp[posx][posy];
	dp[posx][posy] = 0;
	if(mp[posx][posy] == 'A') {
		dp[posx][posy] = 1;
		cnt = 1;
	}
	int ret = 0;
	for(int i=0;i<4;i++) {
		int dx = posx + dir[i][0];
		int dy = posy + dir[i][1];
		if(!flag[ch - 'A'][mp[dx][dy] - 'A'])continue;
		if(dx < 0 || dx >= n || dy < 0 || dy >= m)continue;
		if(vis[dx][dy]){mark = 1;break;}
		vis[dx][dy] = true;
		int tmp = dfs(dx,dy,mp[dx][dy]);
		ret = max(ret,tmp);
		vis[dx][dy] = false;
	}
	return dp[posx][posy] += ret;
}

void cal() {
	int ans = 0;
	cnt = 0;
	mark = 0;
	for(int i=0;i<G.size();i++) {
		int u = G[i].first;
		int v = G[i].second;
		if(!vis[u][v]) {
			vis[u][v] = true;
			dfs(u,v,'D');
			int now = dp[u][v];
			ans = max(ans,now);
			vis[u][v] = false;
		}
	}
	if(!cnt)puts("Poor Dima!");
	else if(mark)puts("Poor Inna!");
	else cout<<ans<<endl;
}

void output() {

}

int main() {
	while(true) {
		init();
		if(input())return 0;
		cal();
		output();
	}
	return 0;
}
