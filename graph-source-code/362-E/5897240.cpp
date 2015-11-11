//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<(n);i++)
#define forup(i,a,b) for(int i=(a);i<=(b);i++)
#define fordn(i,a,b) for(int i=(a);i>=(b);i--)
#define drep(i,n) for(i=0;i<(n);i++)
#define dforup(i,a,b) for(i=(a);i<=(b);i++)
#define dfordn(i,a,b) for(i=(a);i>=(b);i--)
#define all(x) x.begin(),x.end()
#define permute(x) next_permutation(all(x))
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define gi(x) scanf("%d",&x)

// MinCostMaxFlow Codechunk
const int inv=int(1e9);
const int max_v=55;

// u:neighbour, p:price per unit flow, c:capacity, f:flow
// oix: if adjlel a belongs to adjl[v] then oix is s.t. adjl[a.u][a.oix].u=v;
// oix: abbreviation for 'opposite index'
struct adjlel
{
	int u,p,c,f,oix;
	adjlel(){}
	adjlel(int u_, int p_, int c_, int f_, int oix_){u=u_; p=p_; c=c_; f=f_; oix=oix_;}
};
struct less_adjlel : public binary_function < adjlel, adjlel, bool >
{
	bool operator()(const adjlel &a, const adjlel &b){ return pii(a.u,a.p)<pii(b.u,b.p); }
};

int s,t;
int v,e;
vector< adjlel > fadjl[max_v], adjl[max_v];
// fadjl is useful only as a temporary storage to facilitate construction of adjl
// fadjl should be used only if the original graph has multiple edges which are replaceable by a single edge
// If not, both fadjl and less_adjlel are useless. This will be the case for most problems.
// fadjl and less_adjlel are highly problem specific and should be used only after analysis

int dst[max_v];
int par[max_v];
int pvix[max_v];
int vpix[max_v];
int aug[max_v];
queue<int> Q;
int augval;
bool inQ[max_v];
 
bool augmentingpath()
{
	while(!Q.empty()) Q.pop();
	fill(dst,dst+v,inv);
	fill(inQ,inQ+v,false);
	fill(pvix,pvix+v,-1);
	fill(vpix,vpix+v,-1);
	
	dst[s]=0; par[s]=s; aug[s]=inv;
	Q.push(s);
	inQ[s]=true;
	
	while(!Q.empty())
	{
		int vt=Q.front(); Q.pop();
		inQ[vt]=false;
		
		rep(i,adjl[vt].size())
		{
			int nb=adjl[vt][i].u;
			
			if(adjl[vt][i].c-adjl[vt][i].f>0 and dst[vt]!=inv and dst[vt]+adjl[vt][i].p<dst[nb])
			{
				if(not inQ[nb]) { Q.push(nb); inQ[nb]=true; }
				dst[nb]=dst[vt]+adjl[vt][i].p;
				pvix[nb]=i; vpix[nb]=adjl[vt][i].oix;
				par[nb]=vt;
				aug[nb]=min(aug[vt],adjl[vt][i].c-adjl[vt][i].f);
			}
		}
	}
	
	augval=aug[t];
	return (dst[t]!=inv);
}
 
void augmentflow(int vt)
{
  if(par[vt]!=vt)
  {
    adjl[par[vt]][pvix[vt]].f+=augval;
    adjl[vt][vpix[vt]].f-=augval;
    augmentflow(par[vt]);
  }
}

int findmincostmaxflow()
{
    while(augmentingpath())
      augmentflow(t);
	
	int mincostmaxflow=0;
	/*rep(vt,v)
		rep(nb,v)
			if(f[vt][nb]>0)
				mincostmaxflow+=f[vt][nb]*p[vt][nb];*/
	rep(vt,v)
		rep(i,adjl[vt].size())
		{
			if(adjl[vt][i].f>0)
				mincostmaxflow+=(adjl[vt][i].f*adjl[vt][i].p);
		}
	return mincostmaxflow;
}
// End of Codechunk

int n,k,c[max_v][max_v];

void add_edge(int u,int v,int cap,int price) {
	int szu=adjl[u].size(),szv=adjl[v].size();
	//printf("%d %d %d %d\n",u,v,cap,price);
	adjl[u].pb(adjlel(v,price,cap,0,szv));
	adjl[v].pb(adjlel(u,-price,0,0,szu));
}

bool possible(int flow) {
	rep(i,v) adjl[i].clear();
	rep(i,n)
		rep(j,n)
			if(c[i][j]>0) {
				add_edge(i,j,c[i][j],0);
				add_edge(i,j,inv,1);
			}
	add_edge(s,0,flow,0);
	add_edge(n-1,t,flow,0);
	int mcf=findmincostmaxflow();
	if(adjl[s][0].f<flow or mcf>k) return false;
	return true;
}

int main() {
	gi(n); gi(k);
	rep(i,n)
		rep(j,n)
			gi(c[i][j]);
	v=n+2;
	s=n; t=n+1;
	int l=0,r=int(1e8);
	while((l+1)<r) {
		int flow=(l+r)/2;
		if(possible(flow)) l=flow;
		else r=flow;
	}
	printf("%d\n",l);
	return 0;
}
