//Language: GNU C++0x


#include <iostream>
#include <vector>
using namespace std;
const int nmax = 1e5+5;
int depth[nmax],sent_to[nmax],boss[nmax][20],start[nmax][20];
vector<int> children[nmax];
vector<pair<int,int> > quiz;
bool visited[nmax];
void dfs(int pos, int d){
	if(visited[pos])
		return;
	depth[pos]=d;
	for(int i = 0; i < children[pos].size(); ++i){
		int nxt = children[pos][i];
		dfs(nxt,d+1);
	}
}
bool solve(int reader, int sender, int package){
	if(depth[sender]<depth[reader])
		return false;
	int first_got = 0;
	for(int i = 19; i >= 0; --i){
		if(depth[sender]-(1<<i)>=depth[reader]){
			first_got=max(first_got,start[sender][i]);
			sender=boss[sender][i];
		}
	}
	if(sender == reader && first_got < package)
		return true;
	return false;
}
int main(){
	int n,m;
	cin >> n >> m;
	int sent = 0;
	for(int i = 0; i < m; ++i){
		int type;
		cin >> type;
		if(type==1){
			int a,b;
			cin >> a >> b;
			boss[a][0]=b;
			start[a][0]=sent;
			children[b].push_back(a);
		}
		if(type==2){
			int a;
			cin >> a;
			sent_to[++sent]=a;
		}
		if(type==3){
			pair<int,int> q;
			cin >> q.first >> q.second;
			quiz.push_back(q);
		}
	}
	for(int i = 1; i <= n; ++i)
		if(boss[i][0]==0)
			dfs(i,0);
	for(int i = 1; i < 20; ++i){
		for(int j = 1; j <= n; ++j){
			boss[j][i]=boss[boss[j][i-1]][i-1];
			start[j][i]=max(start[j][i-1],start[boss[j][i-1]][i-1]);
		}
	}
	for(int i = 0; i < quiz.size(); ++i){
		int reader = quiz[i].first, sender = sent_to[quiz[i].second];
		bool result = solve(reader,sender,quiz[i].second);
		if(result)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
