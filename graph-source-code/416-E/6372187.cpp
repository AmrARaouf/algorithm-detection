//Language: GNU C++


//E.cpp
//SmartCoder
#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cmath>
#include <ctime>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>

using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end();i++)
#define present(c,x)  ( (c).find(x) !=(c).end())
#define cpresent(c,x) (find(all(c),x)!= (c).end() )
#define minei(x)  min_element(x.begin(),x.end())-(x).begin()
#define maxei(x)  max_element(x.begin(),x.end())-(x).begin()

#define uns(v)     sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define acusum(x)  accumulate(x.begin(),x.end(),0)
#define acumul(x)  accumulate(x.begin(),x.end(),1, multiplies<int>()); 
#define bits(x)     __builtin_popcount( x )
#define oo INT_MAX
#define inf 1000000000

const double pi=acos(-1.0);
const double eps=1e-11;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,m;
int a[501*501],b[501*501],c[501*501];
int mat[501][501];
int cnt[501];
int ans[501][501];
int main(){
  std::ios_base::sync_with_stdio(0);

  cin>>n>>m;
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n;++j){
      mat[i][j]=(i==j?0:inf);
    }
  }

  for(int i=0;i<m;++i){
    cin>>a[i]>>b[i]>>c[i];
    mat[a[i]][b[i]]=mat[b[i]][a[i]]=c[i];
  }
  //then run floyd to get all pair shortest path

  for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);

  for(int i=1;i<=n;++i){
    memset(cnt,0,sizeof cnt);
    //loop for all edges
    for(int j=0;j<m;++j){
      if(mat[i][a[j]]==mat[i][b[j]]+c[j]) cnt[a[j]]++;
      if(mat[i][b[j]]==mat[i][a[j]]+c[j]) cnt[b[j]]++;

    }
    for(int j=1;j<=n;++j){
      for(int k=1;k<=n;++k){
        if(mat[i][j]==mat[i][k]+mat[k][j]) ans[i][j]+=cnt[k];
      }
    }

  }
  for(int i=1;i<=n;++i){
    for(int j=i+1;j<=n;++j){
      cout<<ans[i][j]<<" ";
    }
  }

  return 0;
}
