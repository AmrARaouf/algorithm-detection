//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <ctime>

#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vint vector<int>
#define rep(i,n) for (int i=0; i<n; i++)
#define ll long long

using namespace std;

const int INF=~(1<<31);
const double EPS=1;
const double PI=3.141592653589793;

int main() {
#ifdef HOME
freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
#endif
	int n,m,k,a,b,c;
	cin>>n>>m;
	vector<vector<pair<int,int> > >g(n);
	rep(i,m) {
		scanf("%d%d%d",&a,&b,&c);
		g[a-1].pb(mp(b-1,c));
		g[b-1].pb(mp(a-1,c));
	}
	vector<map<int,int> >rec(n);
	rep(i,n) {
		scanf("%d",&k);
		vector<int>v(k);
		rep(j,k) {
			scanf("%d",&v[j]);
		}
		if (k==0) continue;
		int l=v[k-1]+1;
		rec[i][v[k-1]]=l;
		for(int j=k-2; j>=0; j--) {
			if (v[j]+1!=v[j+1]) l=v[j]+1;
			rec[i][v[j]]=l;
		}
	}
	vector<int>d(n,INF);
	vector<bool>u(n,0);
	d[0]=rec[0][0];
	priority_queue<pair<int,int> >q;
	q.push(mp(-d[0],0));
	while(!q.empty()) {
		int v=q.top().second;
		int l=-q.top().first;
		q.pop();
		if (u[v]) continue;
		u[v]=1;
		rep(i,g[v].sz) {
			int to=g[v][i].first;
			if (!u[to]) {
				int len=g[v][i].second;
				if (to==n-1) {
					d[to]=min(d[to],l+len);
				} else {
					int t_len=rec[to][l+len];
					if (t_len==0) t_len=l+len;
					d[to]=min(d[to],t_len);
				}
				q.push(mp(-d[to],to));
			}
		}
	}
	if (d[n-1]==INF) {
		cout<<-1<<endl;
	} else {
		cout<<d[n-1]<<endl;
	}
	return 0;
}