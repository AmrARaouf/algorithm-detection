//Language: GNU C++0x


#include <bits/stdc++.h>
using namespace std;
long long int ans = 100000000000;
long long int sum = 0;
int cur = 0;
map <int, vector < pair <int, int> > > g;
bool used[100001];
void dfs(int v){
    used[v] = true;
    //cout << v << endl;
    int ll = g[v].size();
    bool flag = false;
    for(int i=0; i<ll; ++i){
        if(!used[g[v][i].first]){
            flag = true;
        }
    }
    if(!flag) ans = min(ans, sum - cur);
    for(int i=0; i<ll; ++i){
        int to = g[v][i].first;
        int tos = g[v][i].second;
        if(!used[to]){
            cur += tos;
            dfs(to);
            cur -= tos;
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=1; i<n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a] . push_back({b, c});
        g[b] . push_back({a, c});
        sum += c;
    }
    sum *= 2;
    dfs(1);
    cout << ans << endl;
    return 0;
}