//Language: GNU C++


#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, -1, 0, 1};

int h, w;
bool a[1000][1000], b[1000][1000];

vector<pi> v[1000*1000];

void dfs(int y, int x){
	b[y][x] = 1;
	rep(d, 4){
		int ny = y + dy[d], nx = x + dx[d];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		
		if(a[ny][nx] && !b[ny][nx]) dfs(ny, nx);
	}
}
bool rec(int l, int p){
	b[p / w][p % w] = 1;
	bool res = 1;
	
	rep(i, v[p].size()){
		
		int to = v[p][i].first;
		
		if(v[p][i].second % l) return 0;
		if(!b[to / w][to % w]) res &= rec(l, to);
	}
	return res;
}

int main(){
	
	int len = 0;
	
	cin >> h >> w;
	rep(i, h) rep(j, w) cin >> a[i][j];
	
	rep(i, h) rep(j, w) if(a[i][j]) rep(d, 4){
		
		int ny = i + dy[d], nx = j + dx[d];
		if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
		
		if(a[ny][nx]) v[i * w + j].pb(mp(ny * w + nx, 1)), len++;
	}
	
	len /= 2;
	
	int cnt = 0;
	int odd = 0;
	int lastodd = -1;
	
	rep(i, h) rep(j, w) if(a[i][j]){
		
		if(!b[i][j]){
			cnt++;
			dfs(i, j);
		}
		if(v[i * w + j].size() % 2) odd++, lastodd = i * w + j;
	}
	
	if(cnt > 1 || odd > 2){
		cout << -1 << endl;
		return 0;
	}
	
	rep(i, h) rep(j, w) if(v[i * w + j].size() == 2){
		
		vi p, q;
		int len = 0;
		
		rep(d, 4){
			int ny = i + dy[d], nx = j + dx[d];
			if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
			
			if(a[ny][nx]) p.pb(d);
		}
		if(p[0] != (p[1] ^ 2)) continue;
		
		
		rep(k, 2){
			len += v[i * w + j][k].second;
			q.pb(v[i * w + j][k].first);
		}
		rep(k, 2){
			int pos = q[k];
			
			rep(l, v[pos].size()) if(v[pos][l].first == i * w + j){
				
				v[pos][l].first = q[1 - k];
				v[pos][l].second = len;
				break;
			}
		}
		b[i][j] = 0;
	}
	
	//cerr<<"?"<<endl;
	
	vi ans;
	
	if(lastodd < 0) rep(i, h) rep(j, w) if(a[i][j] && b[i][j]) lastodd = i * w + j;
	
	for(int i = 2; i <= len; i++) if(len % i == 0){
		
		memset(b, 0, sizeof(b));
		if(rec(i, lastodd)) ans.pb(i);
	}
	if(ans.empty()) cout << -1 << endl;
	else rep(i, ans.size()) cout << ans[i] << (i==ans.size()-1?"\n":" ");
	
	return 0;
}
