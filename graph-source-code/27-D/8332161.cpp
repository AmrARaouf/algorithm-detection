//Language: GNU C++


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <bitset>

#define psb push_back
#define ppb pop_back
#define psf push_front
#define ppf pop_front
#define create make_pair
#define ppi pair<int, int>

using namespace std;

ifstream fin ("in.in");
ofstream fout ("out.out");

const int N = 100+10;
int n, m, k, c[N<<1], v[N<<1];
vector<int> outro[N<<1], intro[N<<1], scc[N<<1], q;
bool mark[N<<1][2];

struct road
{
    int x, y;   
}r[N<<1];

void DFS(int u, int x)
{
    mark[u][x] = true;
     
    if(!x)
    {
         for(int i = 0 ; i < outro[u].size() ; i++)
              if(!mark[outro[u][i]][0])
                    DFS(outro[u][i], 0);
                    
         q.psb(u);
    }  
    
    else
    {
         scc[k].psb(u);
         c[u] = k;
         
         for(int i = 0 ; i < intro[u].size() ; i++)
              if(!mark[intro[u][i]][1])
                    DFS(intro[u][i], 1);
    }
}

void addEdge(int x, int y)
{
    outro[x].psb(y);
    intro[y].psb(x);
    intro[x].psb(y);
    outro[y].psb(x);
}

bool intersect(int i, int j)
{
    return (r[i].x < r[j].x && r[j].x < r[i].y && r[i].y < r[j].y || r[j].x < r[i].x && r[i].x < r[j].y && r[j].y < r[i].y); 
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    
    for(int i = 0 ; i < m ; i++)
    {
         cin >> r[i].x >> r[i].y;
         r[i].x--;
         r[i].y--;  
         if(r[i].x > r[i].y) swap(r[i].x, r[i].y);        
    }
    
    for(int i = 0 ; i < m ; i++)
       for(int j = i+1 ; j < m ; j++)
          if(intersect(i, j))
          {
             addEdge(2*i, 2*j+1);
             addEdge(2*i+1, 2*j);
          }
    
    for(int i = 0 ; i < 2*m ; i++)
       if(!mark[i][0])
          DFS(i, 0);
    
    for(int i = q.size()-1 ; i >= 0 ; i--)
       if(!mark[q[i]][1])
       {
          k++;          
          DFS(q[i], 1);
       }
         
    for(int i = 0 ; i < 2*m ; i+=2)
       if(c[i] == c[i+1])
       {
          cout << "Impossible";
          return 0;  
       }
       else if(c[i] > c[i+1])
          v[i+1] = 1;
       else
          v[i] = 1;
             
    for(int i = 0 ; i < 2*m ; i += 2)
       if(v[i]) cout << 'o';
       else cout << 'i';
    
    //system("PAUSE");
    return 0;
}
