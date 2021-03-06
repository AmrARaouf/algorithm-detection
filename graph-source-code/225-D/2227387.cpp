//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for(int i=a;i>=b;i--)
#define maxn 20
#define piii pair<ll,pair<int,int> >
#define pb push_back
#define mp make_pair
using namespace std;


int n,m,len,cur[maxn][maxn];
string a[maxn];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int dd[]={2,3,0,1};

piii start;
map<piii, int > d;

bool inside(int u,int v) {
	return 1<=u && u<=m && 1<=v && v<=n;
}

void init() {
	vector<pair<int,int> > x;
	FOR(k,1,len)  FOR(i,1,m) FOR(j,1,n) if(a[i][j]==k+48) x.pb(mp(i,j));
	ll s=0;
	FOR(i,0,len-2) FOR(k,0,3) if(x[i].first+dx[k]==x[i+1].first && x[i].second+dy[k]==x[i+1].second) {
	s=s*4+k;
	}
	
	start=mp(s,mp(x[0].first,x[0].second));
}

int main() {
	cin >> m >> n;
	FOR(i,1,m) {
		cin >> a[i];
		a[i]=" "+a[i];
		FOR(j,1,n) if('0'<=a[i][j] && a[i][j]<='9') len=max(len,a[i][j]-48);
	}
	init();
	queue<piii > q;
	q.push(start);
	d[start]=0;
	int c=0;
	int step[11];
	while(!q.empty()) {
		piii f=q.front();q.pop();
		int u=f.second.first,v=f.second.second;
		c++;
		ll s=f.first;
		cur[u][v]=c;
		int x=u,y=v;
		FOR(i,0,len-2) {
			int k=s%4;
			step[i]=k;
			s/=4;
		}
		
		DOWN(i,len-2,1) {
			int k=step[i];
			x=x+dx[k];y=y+dy[k];
			cur[x][y]=c;
//			cout << x << " "<< y << endl;
		}
		FOR(k,0,3) {
			x=u+dx[k],y=v+dy[k];
			if(inside(x,y) && a[x][y]!='#' && cur[x][y]!=c) {
//				cout << x << " " << y << " " <<a[x][y] <<" " << cur[x][y] << endl;
				s=f.first/4;
				s=s+(dd[k]<<(2*(len-2)));
//				cout << s << endl;
				piii g=mp(s,mp(x,y));
				if(d.find(g)==d.end()) {
					d[g]=d[f]+1;
					q.push(g);
					if(a[x][y]=='@') {
						cout << d[g];
						return 0;
					}
				}
			}
		}
	}
	cout << -1;
}