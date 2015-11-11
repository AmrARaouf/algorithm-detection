//Language: GNU C++


//tonynater - CodeForces 2014

#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;

#define sz(x) ((int) x.size())

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const double pi = acos(-1);
const double tau = 2*pi;
const double epsilon = 1e-9;

const int INF = 510000000;

const int MAX_N = 510;

int N, M;

vector<pii> adj[MAX_N];

int dist[MAX_N][MAX_N];

int in[MAX_N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    fill_n(&dist[0][0], MAX_N*MAX_N, INF);
    for(int i = 0; i < M; i++)
    {
        int u, v, l;
        cin >> u >> v >> l;
        --u; --v;
        
        adj[u].push_back(pii(v,l));
        adj[v].push_back(pii(u,l));
        
        dist[u][v] = dist[v][u] = l;
    }
    
    for(int i = 0; i < N; i++)
        dist[i][i] = 0;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                dist[j][k] = min(dist[j][i]+dist[i][k], dist[j][k]);
    
    for(int i = 0; i < N; i++)
    {
        memset(in, 0, sizeof(in));
        for(int j = 0; j < N; j++)
            for(int k = 0; k < sz(adj[j]); k++)
                if(dist[i][adj[j][k].first]+adj[j][k].second == dist[i][j])
                    ++in[j];
        
        for(int j = i+1; j < N; j++)
        {
            int nRoads = 0;
            for(int k = 0; k < N; k++)
                if(dist[i][k]+dist[k][j] == dist[i][j])
                    nRoads += in[k];
            
            cout << nRoads << ' ';
        }
    }
    cout << '\n';
    
    return 0;
}