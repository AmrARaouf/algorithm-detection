//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<set>
#include<vector>
using namespace std;

#define FOR( i , a , n ) for(int (i)=(a);(i)< int(n);++(i))
#define mp pair< long long , int >
#define No() cout<<"NO"<<endl;return 0
typedef long long ll;
const int maxN=1e5+10;
int n,m,p,q,a[maxN],b[maxN],c[maxN],dad[maxN],rank[maxN],v;
ll tot[maxN];
ll inf=1e9;
set< pair<ll , int> > s;
int ans[maxN][2],ted=0;
inline int find(int x)
{
  if(dad[x]==x) return x;
  else return dad[x]=find(dad[x]);
}
inline void join(int x,int y,ll cur)
{
  int dx=find(x),dy=find(y),dd;
  if(dy==dx) 
    {
      tot[dx]+=cur;
      v=dx;
    }
  else 
    {
      if(rank[dx]<rank[dy])
	dd=dy,dad[dx]=dy;
      else if(rank[dy]<rank[dx])
	dd=dx,dad[dy]=dx;
      else
	{
	  dd=dx;
	  dad[dy]=dx;
	  rank[dx]++;
	}
      tot[dd]=tot[dy]+tot[dx]+cur;
      v=dd;
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin>>n>>m>>p>>q;
  FOR(i,1,n+1) dad[i]=i;
  FOR(i,0,m)
    {
      cin>>a[i]>>b[i]>>c[i];
      join(a[i],b[i],(ll)c[i]);
    }
  FOR(i,1,n+1) if(dad[i]==i) s.insert(mp(tot[i],i));
  ll cnt=s.size();
  while(cnt>q and s.size()>1 and p>0)
    {
      int fi,se;
      fi=(*s.begin()).second;
      s.erase(s.begin());
      se=(*s.begin()).second;
      s.erase(s.begin());
      ll val=min(inf,tot[fi]+tot[se]+1);
      join(fi,se,val);
      ans[ted][0]=fi,ans[ted][1]=se;
      ted++;
      s.insert(mp(tot[v],v));
      cnt--,p--;
    }
  if(cnt!=q) {No();}
  if(m!=0 and p!=0)
    {
      FOR(i,0,p) {ans[ted][0]=a[0],ans[ted][1]=b[0],ted++;}
      p=0;
    }
  if(ted>0 and p!=0)
    {
      FOR(i,0,p) ans[ted][0]=ans[0][0],ans[ted][1]=ans[0][1],ted++;
      p=0;
    }
  if(p!=0){No();}
  cout<<"YES"<<endl;
  FOR(i,0,ted)
    {
      cout<<ans[i][0]<<' '<<ans[i][1]<<'\n';
    }
  return 0;
}
