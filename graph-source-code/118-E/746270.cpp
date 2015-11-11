//Language: MS C++


#pragma comment (linker, "/STACK:100000000")
#include <iostream>  
#include <sstream>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <memory>  
#include <cctype>  
#include <string>  
#include <vector>  
#include <list>  
#include <queue>  
#include <deque>  
#include <stack>  
#include <map>  
#include <set>  
#include <algorithm>  
using namespace std; 
  
#define FOR(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) 
#define RFOR(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i)) 
#define CLEAR(a) memset((a),0,sizeof(a)) 
#define INF 1000000000 
#define PB push_back 
#define ALL(c) (c).begin(), (c).end() 
#define pi acos(-1.0) 
#define SQR(a) (a)*(a) 
#define MP make_pair 
#define MOD 100000000
  
typedef long long Int; 

int n, m, t;
vector <int> G[100000];
int T[100000], F[100000];
bool B[100000];
set < pair<int, int> > S;
vector < pair<int, int> > R;

void dfs(int v, int p)
{
        B[v] = true;    
        t++;
        T[v] = t;
        F[v] = t;
        FOR (i,0,G[v].size())
        {
                int to = G[v][i];
                if (to == p)
                        continue;
                if (B[to])
                        F[v] = min(F[v], T[to]);
                else
                {
                        dfs(to, v);
                        F[v] = min(F[v], F[to]);
                }
                if (F[to] > T[v])
                        S.erase(S.find(MP(min(v, to), max(v, to))));
        }
}

void dfs2(int v, int p)
{
        B[v] = true;
        FOR (i,0,G[v].size())
        {
                int to = G[v][i];
                if (to == p)
                        continue;
                if (B[to] == false || T[to] < T[v])
                        R.PB(MP(v, to));
                if (B[to] == false)
                {
                        dfs2(to, v);
                }
        }
}

int main()
{
        cin >> n >> m;
        FOR (i,0,m)
        {
                int u, v;
                scanf("%d %d", &u, &v);
                u--;
                v--;
                G[u].PB(v);
                G[v].PB(u);
                S.insert(MP(min(u, v), max(u, v)));
        }

        t = 0;
        dfs(0, -1); 
        if (S.size() != m)
        {
                cout << 0 << endl;
                return 0;
        }

        CLEAR(B);
        dfs2(0, -1);
        FOR (i,0,R.size())
                cout << R[i].first+1 << ' ' << R[i].second+1 << endl;
        
      
        return 0;
} 
 