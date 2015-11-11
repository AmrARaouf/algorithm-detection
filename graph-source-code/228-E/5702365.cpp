//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<set>
#include<iomanip>
#include<complex>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<bitset>
#include<memory.h>
#include<cassert>
#include<ctime>


#pragma comment(linker, "/stack:30000000")

using namespace std;

#define For(i,l,r) for (int i = l ;i <= r ;i ++ )
#define ForI(it , s , T) for (T :: iterator it = s.begin(); it != s.end() ;it ++ )
#define LL long long
#define READ(Tp,l,r,a) For(i,l,r) scanf(((Tp=="int")?"%d":"%I64d"),&a[i]);
#define iinf 2000000000
#define linf 2000000000000000000LL
#define MOD  1000000007
#define Pi 3.1415926535897932384
#define bit(mask,i) ((mask>>i)&1)
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define pause cin.get();cin.get();
#define fin freopen("input.txt","r",stdin)
#define fout freopen("output.txt","w",stdout)
#define fir first
#define sec second
#define ln(x) log(x)


const int mx[4] = {1, -1, 0, 0};
const int my[4] = {0, 0, 1, -1};

const int Direct[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int Nmax = 200000; 

vector<vector<int> > g,ig;
int used[Nmax],timer;
int Comp[Nmax];
int Comps = 0;
int TopSort[Nmax];
int n,m;
int inv(int x)
{
    if (x > n) return x - n;
    else
     return x + n;
}
void sort(int v)
{
     used[v] = 1;
     for (int i = 0 ; i < g[v].size(); i ++ )
      if (!used[g[v][i]])
       sort(g[v][i]);
     TopSort[++timer] = v;
}
int dfs(int v,int Comps)
{
    Comp[v] = Comps;
    for (int i = 0 ;i < ig[v].size(); i ++ )
     if (!Comp[ig[v][i]])
      dfs(ig[v][i],Comps);
}
void add(int x,int y)
{
     g[inv(x)].pb(y);
     g[inv(y)].pb(x);
     ig[y].pb(inv(x));
     ig[x].pb(inv(y));
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin >> n >> m;
   g.resize(2*n+1);
   ig.resize(2*n+1);
   For(i,1,m)
   {
      int x,y,c;
      cin >> x >> y >> c;
      if (c)
       add(x,inv(y)) , add(inv(x),y);
      else
       add(x,y), add(inv(x),inv(y));
   }  
   For(i,1,2*n)
    if (!used[i]) sort(i);
   Comps = 0;
   for (int i = 2*n ;i >= 1; i -- )
    if (Comp[TopSort[i]] == 0)
     dfs(TopSort[i],++Comps);
   for (int i = 1 ;i <= n ; i ++ )
    if (Comp[i] == Comp[inv(i)])
    {
                cout << "Impossible"<<endl;
                return 0;
    }
   vector<int> list;
   for (int i = 1; i <= n ; i ++ )
    if (Comp[i] > Comp[inv(i)])
     list.pb(i);
   cout << list.size() << endl;
   for (int i = 0 ; i < list.size() ; i ++ )
    cout << list[i] << " ";
   cout<<endl;
   return 0;
}