//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;

#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())


const int MAX_N = 2000;

vector<int> adj[MAX_N + 5];

int N;

int vis[MAX_N + 5] = {0};
bool valid[MAX_N + 5] = {0};

queue<int> q;
bool bfs(int x) {
    while(!q.empty()) q.pop();
    q.push(x);
    vis[x] = x+1;
    
    int cnt = 0;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        cnt++;
        
        if (valid[curr]) {cnt = N; break;}
        
        REP(i, SZ(adj[curr])) if (vis[adj[curr][i]] != x+1) {
            vis[adj[curr][i]] = x+1;
            q.push(adj[curr][i]);
        }
    }
    
    return valid[x] = (cnt == N);
}

char line[5000000];

int main() {
    sscanf(gets(line), "%d", &N);
    REP(i, N) {
        gets(line);
        int j = 0;
        for (char *p = strtok(line, " "); p; p = strtok(NULL, " ")) {
            int bil = atoi(p);
            if (bil > 0) adj[i].PB(j);
            j++;
        }
    }
    
    REP(i, N) if (!bfs(i)) {
        puts("NO");
        return 0;
    }
    
    puts("YES");
    return 0;
}