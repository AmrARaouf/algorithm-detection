//Language: GNU C++0x


#include <bits/stdc++.h>

using namespace std;

const int maxn = 300 * 1000 + 12;
vector <int> nei[maxn];
bool col[maxn];
queue <int> myq;

void input(int m, int n){
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b, a --, b --;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    for(int i = 0; i < n; i ++)
        myq.push(i);
}
void solve(int n){
    while(myq.size()){
        int v = myq.front();
        int cnt = 0;
        for(int i = 0; i < nei[v].size(); i ++)
            if(col[nei[v][i]] == col[v])
                cnt ++;
        if(cnt > 1){
            col[v] = !col[v];
            for(int i = 0; i < nei[v].size(); i ++)
                myq.push(nei[v][i]);
        }
        myq.pop();
    }
    for(int i = 0; i < n; i ++)
        cout << col[i];
}
int main()
{
    int n, m;
    cin >> n >> m;
    input(m, n);
    solve(n);
    return 0;
}
