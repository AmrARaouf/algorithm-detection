//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;
#define pb push_back
#define INF 1000000000
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
inline void pisz(int n) { printf("%d\n",n); }
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){FOR(i,SZ(t))s<<t[i]<<" ";return s; }
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define TESTS wez(testow)while(testow--)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
      
vector<vector<string> > next(vector<string> V)
{
   int row, col;
   vector<vector<string> >  R;
   vector<string> W = V;
   FOR(j, 8)
   {
      if(W[7][j] == 'M')
      {
         row = 7;
         col = j;
      }
      W[7][j] = '.';
   }
   for(int i = 6; i >= 0; i--)
   {
      FOR(j, 8)
      {
         if(W[i][j] == 'M')
         {
            W[i][j] = '.';
            row = i;
            col = j;
         }
         if(W[i][j] == 'S')
         {
            W[i + 1][j] = 'S';
            W[i][j] = '.';
         }         
      }
   }
   int posrow, poscol;  
   for(int i = -1; i <= 1; i++)
   {
      for(int j = -1; j <=1; j++)
      {
         posrow = row + i;
         poscol = col + j;
         if(posrow >= 0 && posrow <= 7 && poscol >= 0 && poscol <= 7 && W[posrow][poscol] != 'S' && V[posrow][poscol] != 'S')
         {
            R.pb(W);
            R[R.size() - 1][posrow][poscol] = 'M';
         }
      }
   }
   return R;
}
bool dfs(vector<string> V, set<vector<string> >& visited)
{
   vector<vector<string> > E = next(V);
   set<vector<string> >::iterator it;
   visited.insert(V);
   FOR(i, E.size())
   {
      it = visited.find(E[i]);
      if(it == visited.end())
      {
         if(E[i][0][7] == 'M')
         {
            return true;
         }
         if(dfs(E[i], visited))
         {
            return true;
         }
      }
   }
   return false;
}
int main()
{
   vector<string> V0(8);
   FOR(i, 8)
   {
      cin >> V0[i];
   }
   set<vector<string> > visited;
   if(dfs(V0, visited))
   {
      cout << "WIN" << endl;
   }
   else
   {
      cout << "LOSE" << endl;
   }
   return 0;
}
