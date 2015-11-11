//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 1e2 + 5;
const int INF = 1e9;
typedef long long LL;
typedef pair<int, int> P;

//int G[maxn][maxn][maxn];
int fa[maxn][maxn];

int Find(int x, int color){
    return x==fa[x][color]?x:fa[x][color]=Find(fa[x][color], color);
}

int main(){
    int n, m;
    while(cin >> n >> m){
        for(int i = 0;i < maxn;i++)
            for(int j = 0;j < maxn;j++)
                fa[i][j] = i;

        while(m--){
            int a, b, c;
            cin >> a >> b >> c;
            a--;b--;
            int x = Find(a, c);
            int y = Find(b, c);
            if(x != y){
                fa[x][c] = y;
            }
        }
        int q;
        cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b;
            a--;b--;
            int ans = 0;
            for(int i = 0;i < maxn;i++){
                int x = Find(a, i);
                int y = Find(b, i);
                if(x == y){
                    ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
