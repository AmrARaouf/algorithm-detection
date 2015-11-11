//Language: GNU C++11


// In the name of God

#include <bits/stdc++.h>

#define For(i,x,y) for(__typeof(y)i=(x)-((x)>(y));i!=(y)-((x)>(y));i+=1-2*((x)>(y)))
#define _ ios::sync_with_stdio(0);cin.tie(0);
#define sz(x) (((int)x.size()))
#define rep(i,n) For(i,0,n)


const int Maxn = 1e5 + 7;
const int inf = 1e9 + 7;

typedef long double dd;
typedef long long ll;
using namespace std;

vector<int> a[Maxn], v[Maxn];
int vis[Maxn], cnt[Maxn];
map<int,int> mp[Maxn];

void SpaningTree(int x = 1){
    vis[x] = true;
    For(i, v[x].begin(), v[x].end())
    if(!vis[*i]) {
        if (mp[x][*i] < mp[*i][x]){
            mp[x][*i]++;
            mp[*i][x]--;
        }
        a[x].push_back(*i);
        SpaningTree(*i);
    }
}

int dfs(int x = 1, int par = 0){
    int sum = cnt[x]%2;
    vis[x] = true;
    For(i,a[x].begin(), a[x].end())
    if (!vis[*i])
        sum += dfs(*i, x);
    
    if(par && (sum & 1))
        mp[par][x]-- , mp[x][par]++;
    
    return sum;
}

int main() { _
    
    int n, m;
    cin >> n >> m;
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        mp[x][y]++;
    }
    int pre = -1;
    
    For(i, 1, n+1) if(sz(v[i]) & 1){
        if (pre == -1)
            pre = i;
        else {
            v[pre].push_back(i);
            v[i].push_back(pre);
            mp[i][pre]++;
            m++;
            pre = -1;
        }
    }
    

    if(m & 1)
        a[1].push_back(1), a[1].push_back(1) , mp[1][1] ++, m++;

    
    SpaningTree();
    memset(vis, 0, sizeof(vis));
    
    For(i,1,n+1)
        for( map<int,int> :: iterator it = mp[i].begin(); it != mp[i].end(); ++it)
            cnt[i] += it->second;
    
    dfs();
    
    cout << m << endl;
    
    For(i,1,n+1)
        for( map<int,int> :: iterator it = mp[i].begin(); it != mp[i].end(); ++it)
            rep(j, it->second)
                cout << i << ' ' << it->first << endl;
    // :-)
}
