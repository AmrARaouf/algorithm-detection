//Language: GNU C++


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>

#define add push_back
#define create make_pair
#define u adj[v][i].first
#define cost adj[v][i].second

using namespace std;

ifstream fin ("in.in");
ofstream fout ("out.out");

typedef unsigned long long ull;
const int N = 100000+10, K = 510;
int n, m, k, c[K], a[N], cnt[K], d[K][K], f[K][K];
vector< pair<int, int> > adj[N];
bool mark[N];

inline void input()
{
    cin >> n >> m >> k;
    
    for(int i = 1 ; i <= k ; i++)
       cin >> c[i]; 
    
    int s = 0;
    
    for(int i = 1 ; i <= k ; i++)
    {
          for(int j = s+1 ; j <= s+c[i] ; j++)
                a[j] = i;
                
          s += c[i];  
    }
    
    for(int i = 0 ; i < m ; i++)
    {
         int v1, v2, x;
         cin >> v1 >> v2 >> x;
         adj[v1].add(create(v2, x)); 
         adj[v2].add(create(v1, x));   
    }
}

void DFS(int v)
{
    mark[v] = true;
    cnt[a[v]]++;
    
    for(int i = 0 ; i < adj[v].size() ; i++)
          if(!mark[u] && !cost)
                  DFS(u); 
                
}

bool check()
{
    for(int i = 1 ; i <= k ; i++)
         if(cnt[i] && cnt[i] < c[i])
               return false;
    return true; 
}

void floyd()
{ 
    for(int v = 2 ; v <= k ; v++)
    {
        for(int i = 1 ; i < v ; i++)   
           for(int j = 1 ; j < v ; j++)
                f[v][i] = f[i][v] = min(f[v][i], d[v][j] + f[j][i]); 
        
        for(int i = 1 ; i < v ; i++)
           for(int j = i+1 ; j < v ; j++)
                f[i][j] = f[j][i] = min(f[i][j], f[i][v]+f[v][j]);             
    }  
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    input();
         
    for(int i = 1 ; i <= n ; i++)
         if(!mark[i])
         {
              DFS(i);
              if(!check())
              {
                  cout << "No";
                  return 0;        
              }       
         }
         
    for(int i = 1 ; i <= k ; i++)
         for(int j = 1 ; j <= k ; j++)
               if(i != j)
                     d[i][j] = f[i][j] = 100000000;
         
    for(int v = 1 ; v <= n ; v++)
          for(int i = 0 ; i < adj[v].size() ; i++)
                d[a[v]][a[u]] = d[a[u]][a[v]] = min(d[a[v]][a[u]], cost);
                     
                
    floyd();
    
    cout << "Yes" << endl;
    
    for(int i = 1 ; i <= k ; i++)
    {
         for(int j = 1 ; j <= k ; j++)
         {
              if(f[i][j] < 100000000) cout << f[i][j] << ' ';
              else cout << -1 << ' ';   
         }
         
         cout << endl;
    }
    
    //system("PAUSE");
    return 0;
}
