//Language: GNU C++


#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<algorithm>
#include<list>
#include<cstdio>
#include<stack>
#include<cstring>
#include <climits>
#include<cmath>
#include<string>
#include <functional>
#include<sstream>
#include<map>

using namespace std;
#define     For(i,a,b)        for (int i=a; i<b; i++)
#define     Rep(i,a)          for (int i=0; i<a; i++)
#define     ALL(v)            (v).begin(),(v).end()
#define     Set(a,x)          memset((a),(x),sizeof(a))
#define     EXIST(a,b)        find(ALL(a),(b))!=(a).end()
#define     Sort(x)           sort(ALL(x))
#define     UNIQUE(v)         Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define     MP                make_pair
#define     SF                scanf
#define     PF                printf
#define     MAXN               2001
#define     MAXM               1001
#define     MOD               1000000007
#define     Dbug             cout<<"";
#define     EPS              1e-15
typedef long long ll;
typedef pair<int,int> pii;
int n, m, vis[MAXN][MAXN], col;
string b[MAXN];
bool cycle;
void DFS(int r, int c)
{
	while(b[r][c]!='#')
	{
		vis[r][c]=col;
		if(b[r][c]=='^') r--;
		else if(b[r][c]=='>') c++;
		else if(b[r][c]=='<') c--;
		else r++;
		if(vis[r][c]==col) 
		{
			cycle=1;
			return;
		}
	}
}
pair<char, pii> ed[MAXN][MAXN];
int dp[MAXN][MAXN];
pii par[MAXN][MAXN];
int rec(int r, int c)
{
	int kr=r, kc=c;
	if(~dp[r][c]) return dp[r][c];
	while(b[r][c]!='#')
	{
		if(~dp[r][c]) break;
		int nr=r, nc=c;
		if(b[r][c]=='^') r--;
		else if(b[r][c]=='>') c++;
		else if(b[r][c]=='<') c--;
		else r++;
		par[r][c]=MP(nr, nc);
	}
	int tr=r, tc=c;
	if(b[tr][tc]=='#')
	{
		dp[tr][tc]=0;
		ed[tr][tc]=MP('#', MP(r, c));
	}
	while(kr!=r || kc!=c)
	{
		int nr=r, nc=c;
		r=par[nr][nc].first, c=par[nr][nc].second;
		dp[r][c]=dp[nr][nc]+1;
		ed[r][c]=ed[nr][nc];
		if(dp[r][c]==1) ed[r][c].first=b[r][c]; 
	}
	return dp[kr][kc];
}
vector<pair<int, pair<char, pii> > > len, tmp;
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("a.in","r",stdin);
	cin>>n>>m;
	col=0;
	if(n*m==1)
	{
		cout<<0<<endl;
		return 0;
	}
	Set(dp, -1);
	Rep(i, n) cin>>b[i];
	Set(vis, -1);
	cycle=0;
	Rep(i, n) Rep(j, m) if(vis[i][j]==-1)
	{
		col++;
		DFS(i, j);
		if(cycle) 
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	Rep(i, n) Rep(j, m) if(b[i][j]!='#') len.push_back(MP(rec(i, j), ed[i][j]));
	len.push_back(MP(0, MP('#', MP(-1, -1))));
	len.push_back(MP(0, MP('#', MP(-2, -2))));
	Sort(len);
	int mx=len[len.size()-1].first;
	Rep(i, len.size()) if(mx==len[i].first) tmp.push_back(len[i]);
	if(tmp.size()==1) cout<<len[len.size()-1].first+len[len.size()-2].first;
	else
	{
		bool fi=0;
		Rep(i, tmp.size())
		{
			if(tmp[i].second.second.second!=tmp[0].second.second.second || tmp[i].second.first!=tmp[0].second.first || tmp[i].second.second.first!=tmp[0].second.second.first)
			{
				fi=1;
				break;
			}
		}
		if(fi) cout<<mx*2;
		else cout<<(mx*2)-1;
	}
	return 0;
}