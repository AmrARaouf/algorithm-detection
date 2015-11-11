//Language: GNU C++0x


#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <utility>
#define F first
#define S second
using namespace std;
typedef long long ll;
char v[2000][2000];
int used[2000][2000];
vector<pair<int, int> > roots;

int f1(int x, int y, int u) {
    if(used[x][y]) return 0;
    if(v[x][y] == '#') {
        return 3;
    }
    used[x][y] = u;
    if(v[x][y] == '^') {
        if(used[x-1][y] == u) return 1;
        int q = f1(x-1, y, u); 
        if(q == 1) return 1;
        if(q == 3) roots.push_back({x, y});
    }
    if(v[x][y] == 'v') {
        if(used[x+1][y] == u) return 1;

        int q = f1(x+1, y, u);
        if(q == 1) return 1;
        if(q == 3) roots.push_back({x, y});
    }
    if(v[x][y] == '<') {
        if(used[x][y-1] == u) return 1;
        int q = f1(x, y-1, u);
        if(q == 1) return 1;
        if(q == 3) roots.push_back({x, y});

    }
    if(v[x][y] == '>') {
        if(used[x][y+1] == u) return 1;
        int q = f1(x, y+1, u);
        if(q == 1) return 1;
        if(q == 3) roots.push_back({x, y});
    }
    return 0;
}
int f2(int x, int y) {
    if(used[x][y]) return 0;
    used[x][y] = 1;
    int ma = 0;
    if(v[x+1][y] == '^') {
        ma = max(ma, f2(x+1, y));
    }
    if(v[x-1][y] == 'v') {
        ma = max(ma, f2(x-1, y));
    }
    if(v[x][y+1] == '<') {
        ma = max(ma, f2(x, y+1));
    }
    if(v[x][y-1] == '>') {
        ma = max(ma, f2(x, y-1));
    }
    return ma+1;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin>>v[i][j];
        }
    }
    int u = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(!used[i][j]) {
                ++u;
                if(f1(i, j, u) == 1) {
                    cout<<-1<<'\n';
                    return 0;
                }
            }
        }
    }
    memset(used, 0, sizeof(used));
    vector<int> lol;
    for(auto x: roots) {
        lol.push_back(f2(x.F, x.S));
    }
    sort(lol.begin(), lol.end());
    if(lol.size() == 0) {
        cout<<0<<'\n';
    }
    else if(lol.size() == 1) {
        cout<<lol[0]*2-1<<'\n';
    }
    else {
        cout<<max(lol.back()+*(++lol.rbegin()), lol.back()*2-1)<<'\n';
    }

}
