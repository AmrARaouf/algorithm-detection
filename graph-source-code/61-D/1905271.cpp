//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

#define MOD 100000000
#define ll long long

int N;
vector<pair<int,int> > g[100005];
ll totalWeight;

ll maxHeight(int n, int p) {
    ll res = 0;
    for(int i = 0;i<g[n].size();i++) {
        if(p == g[n][i].first) continue;
        ll height = g[n][i].second + maxHeight(g[n][i].first, n);
        totalWeight += g[n][i].second;
        if(res < height)
            res = height;
    }
    return res;
}

int main() {
    scanf("%d",&N);
    for(int i = 0;i<N-1;i++) {
        int x, y, w;
        scanf("%d %d %d",&x,&y,&w);
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
    }
    ll h = maxHeight(1,-1);
    cout<<2*totalWeight - h<<endl;
    
    
    return 0;
}
