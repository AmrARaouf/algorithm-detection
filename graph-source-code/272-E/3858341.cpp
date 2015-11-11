//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 300000 + 5;

vector<int> G[maxn];
int ans[maxn];

void dfs(int x){
    int cnt = 0;
    for(int i = 0;i < G[x].size();i++){
        int to = G[x][i];
        //printf("%d %d\n",ans[to],ans[x]);
        if(ans[to] == ans[x]) cnt++;
    }
    if(cnt > 1){//cout << 'x';
        ans[x] = !ans[x];
        for(int i = 0;i < G[x].size();i++){
            int to = G[x][i];
            if(ans[to] == ans[x]) dfs(to);
        }
    }
}

int main(){
    int n,m;
    while(cin >> n >> m){
        for(int i = 1;i <= n;i++) G[i].clear();
        for(int i = 0;i < m;i++){
            int a,b;
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(ans,0,sizeof(ans));
        for(int i = 1;i <= n;i++)
            dfs(i);
        for(int i = 1;i <= n;i++) cout << ans[i];
        cout << endl;
    }
    return 0;
}
