//Language: GNU C++0x


#include <bits/stdc++.h>


using namespace std;
#define int long long 
const int maxN = 100 * 1000 + 100;
const int mod = 1000*1000*1000 + 7;

int state[maxN];
int mark[maxN];
int ans[maxN];
vector<int> a[maxN];
vector<int> ar[maxN];
void dfs(int v)
{
    mark[v] = 1;
    ans[v] = 1;
    for(int i = 0; i < a[v].size(); i ++)
    {
	  int u = a[v][i];
	  if(!mark[u]) dfs(u);
    }
}
void dfs1(int v)
{
    mark[v] = 1;
    ans[v] ++;
    if(state[v] == 1) return;
    for(int i = 0; i < ar[v].size(); i ++)
    {
	  int u = ar[v][i];
	  if(!mark[u]) dfs1(u);
    }
}
main()
{
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i ++) cin >> state[i];
    for(int i = 0; i < m; i ++)
    {
	  int d, k; cin >> d >> k; d --; k --;
	  a[d].push_back(k);
	  ar[k].push_back(d);
    }
    for(int i = 0; i < n; i ++)
	  if(!mark[i] && state[i] == 1) dfs(i);

    memset(mark, 0 , sizeof mark);
    for(int i = 0; i < n; i ++)
	  if(!mark[i] && state[i] == 2) dfs1(i);

    for(int i = 0; i < n; i ++)
	  if(ans[i] == 2) cout << "1\n";
	  else cout << "0\n";
    return 0;
}

