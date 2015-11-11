//Language: GNU C++


#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>

using namespace std;

vector<int> ss;
vector<int> v[300005];
int vis[300005];
int n, m, k;

void dfs(int pos, int pre)
{
        vis[pos] = 1;
        ss.push_back(pos);

        for(int i = 0; i < v[pos].size(); i++) {
            if(vis[v[pos][i]] == 2 || v[pos][i] == pre) continue;
            if(!vis[v[pos][i]]) {
                dfs(v[pos][i], pos);
            }
            else {
                int pp = ss.size()-1;
                int c = 0;
                while(ss[pp] != v[pos][i]) pp--, c++;;
                if(c >= k) {
                    cout << c+1 << endl;
                    for(int j = ss.size()-1; ss[j] != v[pos][i]; j--) {
                        cout << ss[j]+1 << " ";
                    }
                    cout << v[pos][i]+1 << endl;
                    exit(0);
                }
            }
        }
        ss.pop_back();
        vis[pos] = 2;
}

int main()
{
    cin >> n >> m >> k;
    int x, y;
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(0, -1);
}
