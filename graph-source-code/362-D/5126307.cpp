//Language: GNU C++


#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdlib>
#include<utility>
#include<map>
#include<set>
#include<fstream>
#include<iomanip>
#include<cstdio>
#define D double
#define ll long long
#define PII pair<long long,long long>
#define PB push_back
#define F first
#define S second
#define MP make_pair
using namespace std;

const int maxn = 1000*100+10;
const long long inf = 1000*1000*1000;

long long par[maxn],n,m,p,q,sum[maxn],tool[maxn];
vector<int> adj[maxn];
bool mark[maxn];
set< PII > st;
vector< PII > ans;

void dfs1(int x){
	mark[x] = true;
	for(int i = 0;i < (int)adj[x].size();i++){
		int next = adj[x][i];
		if(!mark[next])
			dfs1(next);
	}
}

int find(int x){
	if(par[x] == x)
		return x;
	return par[x] = find(par[x]);
}

void uni(int x,int y,int z){
	int px = find(x) , py = find(y);
	if(px == py)
		sum[px] += z;
	else{
		par[px] = py;
		sum[py] += sum[px]+z;
		sum[px] = 0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	for(int i = 0;i < maxn; i++)
		par[i] = i;
	cin >> n >> m >> p >> q;
	PII help =MP(-1,-1);
	for(int i = 0;i < m;i++){
		int x,y,z;cin >> x >> y >> z;x--;y--;
		adj[x].PB(y);adj[y].PB(x);
		help = MP(x,y);
		uni(x,y,z);
	}
	int te = 0;
	for(int i = 0;i < n; i++)
		if(!mark[i]){
			dfs1(i);
			te++;
		}
	if(te-q > p || q > te){
		cout <<"NO";
		return 0;
	}
	for(int i = 0;i < n;i++)
		if(sum[i] || par[i] == i)
			st.insert(MP(sum[i],i));
	for(int i = 0;i < te-q; i++){
		if(st.size() < 2){
			cout << "NO";
			return 0;
		}
		set< PII > ::iterator q1 = st.begin();
		set< PII > ::iterator q2 = q1;q2++;
		PII f = *q1 , s = *q2;
		st.erase(q1);st.erase(q2);
		long long carr = sum[f.S]+sum[s.S]+1;
		if(carr > inf)
			carr = inf;
		st.insert(MP(sum[f.S]+sum[s.S]+carr,s.S));
		uni(f.S,s.S,carr);
		ans.PB(MP(f.S,s.S));
		help = MP(f.S,s.S);
	}
	for(int i = 0;i < p-(te-q);i++){
		if(help.F == -1){
			cout <<"NO";
			return 0;
		}
		ans.PB(MP(help.F,help.S));
	}
	cout <<"YES"<<endl;
	for(int i = 0;i < (int)ans.size();i++)
		cout << ans[i].F+1 <<" "<<ans[i].S+1 << endl;
	return 0;
}
