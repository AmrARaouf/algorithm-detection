//Language: GNU C++


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>

#define add push_back
#define create make_pair

using namespace std;

ifstream fin ("in.in");
ofstream fout ("out.out");

typedef unsigned long long ull;
const int N = 300+10;
int n, m, k, a[N];
bool mark[N], flag[N];

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> k;
    
    for(int i = 1 ; i <= k ; i++)
    {
         cin >> a[i];
         flag[a[i]] = true;
    }
         
    if(m > n*(n-1)/2-(k-1) || k == n) 
    {
         cout << -1;
         return 0;
    }
    
    int v, u, w;
    
    for(int i = 1 ; i <= n ; i++)
         if(!flag[i])
         {
               v = i; 
               break;       
         }
         
    u = a[1];
    w = a[2];
    
    for(int i = 1 ; i <= n ; i++)
         if(i != v)
              cout << v << ' ' << i << endl;
              
    m -= n-1;
    
    for(int i = 1 ; i <= n && m; i++)
    {
         if(i == v || i == u || i == w) continue;
         
         for(int j = i+1 ; j <= n && m; j++)
         {
              if(j == v || j == u || j == w) continue;
              
              cout << i << ' ' << j << endl; 
              
              m--;
         } 
    }
    
    for(int i = 1 ; i <= n && m ; i++)
         if(i != v && i != u && i != w)
         {
              cout << u << ' ' << i << endl;
              m--;
         }
         
    for(int i = 1 ; i <= n && m ; i++)
         if(i != v && i != u && i != w && !flag[i])
         {
              cout << w << ' ' << i << endl;
              m--;
         }
      
    //system("PAUSE");
    return 0;
}
