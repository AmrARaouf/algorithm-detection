//Language: GNU C++0x


#include <functional>/*{{{*/
#include <algorithm>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;typedef long long ll;typedef long double real;void run();int main(){ios::sync_with_stdio(0);run();}/*}}}*/

unsigned v[200];
unsigned n,m,k;
unsigned st[1<<7][200];
unsigned fr[1<<7][200];
unsigned freud[200][200];

vector<int> edges(int x){/*{{{*/
  vector<int> res;
  if (x%m) res.push_back(x-1);
  if ((x+1)%m) res.push_back(x+1);
  if (x>=m) res.push_back(x-m);
  if (x+m<n*m) res.push_back(x+m);
  return res;
}/*}}}*/

ll val=0;
void dfs(int mask,int x){
  if (not mask) return; if (~v[x]) val+=v[x], v[x]=-1; if (!~fr[mask][x]) return;

  int tom=fr[mask][x]&0x7F;
  int top=fr[mask][x]>>7;

  if (tom!=mask){
    dfs(mask^tom,x);
    dfs(mask&tom,x);
  }else{
    while (x!=top){
      for (int y: edges(x))
        if (freud[x][y]+freud[y][top]==freud[x][top])
          {x=y;break;}
      if (~v[x]) val+=v[x], v[x]=-1;
    }
    dfs(tom,top);
  }
}

void run(){
  memset(freud,-1,sizeof freud);
  memset(st,-1,sizeof st);
  memset(fr,-1,sizeof fr);

  cin>>n>>m>>k;

  for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
      cin>>v[i*m+j];

  for (int i=0; i<n*m; freud[i][i]=0,++i)
    for (int j: edges(i))
      freud[i][j]=v[j];

  for (int i=n*m; i--;)
    for (int j=n*m; j--;)
      for (int k=n*m; k--;)
        if (~(freud[j][i]|freud[i][k]))
          freud[j][k]=min(freud[j][k],freud[j][i]+freud[i][k]);

  for (int i=n*m; i--;) st[0][i]=v[i];

  for (int i=0; i<k; i++){
    int r,c; cin>>r>>c; --r,--c;
    st[1<<i][r*m+c]=v[r*m+c];
  }

  for (int msk=0,steps=pow(3,k)+0.5; msk<steps; ++msk){
    int mask=0,musk=0;
    for (int i=msk,j=0; j<k; j++,i/=3) (mask<<=1)|=(i%3==1), (musk<<=1)|=(i%3==2);

    if (not mask)
      for (int i=n*m; i--;)
        for (int j=n*m; j--;)
          if ((~st[musk][j]) and st[musk][i]>st[musk][j]+freud[j][i])
            st[musk][i]=st[musk][j]+freud[j][i],
            fr[musk][i]=(j<<7)|musk;

    if (not musk)
      for (int i=n*m; i--;)
        for (int j=n*m; j--;)
          if ((~st[mask][j]) and st[mask][i]>st[mask][j]+freud[j][i])
            st[mask][i]=st[mask][j]+freud[j][i],
            fr[mask][i]=(j<<7)|mask;

    for (int i=n*m; i--;)
      if ((~st[mask][i]) and (~st[musk][i]))
        if (st[mask|musk][i]>st[mask][i]+st[musk][i]-v[i])
          st[mask|musk][i]=st[mask][i]+st[musk][i]-v[i],
          fr[mask|musk][i]=(i<<7)|mask;
  }

  unsigned res=-1,rex=-1;
  for (int i=n*m; i--;)
    if (st[(1<<k)-1][i]<res)
      res=st[(1<<k)-1][i],
      rex=i;

  if (!~res) res=rex=0;

  dfs((1<<k)-1,rex);
  cout<<res<<endl;
  for (int i=0; i<n; i++,cout<<'\n')
    for (int j=0; j<m; j++)
      cout<<(~v[i*m+j]?'.':'X');

//  if (res!=val) cout<<"WRONG"<<endl;
}
