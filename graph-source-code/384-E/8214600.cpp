//Language: GNU C++



//~        Author : Sarvesh Mahajan                             
//               IIIT,Hyderabad                                   
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define For(i,a,b) for(i=a;i<b;i++)
#define loop(i,b) for(i=0;i<b;i++)
#define Loop(i,b) for(i=1;i<=b;i++)
#define pi(n) printf("%d ",n)
#define si(n) scanf("%d",&n)
const int MOD=1e9+7;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef long long LL;
#define F first
#define S second
#define sz size
#define pLL(x) cout<<x<<' '
#define fill(x,c) memset(x,c,sizeof(x))
#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;

const int maxn=2e5+5;
int tin[maxn],tout[maxn];
int timer;
VI vis;

VI g[maxn];
int level[maxn];
void dfs(int s,int par)
{
	int i;
	tin[s]=++timer;
	vis.pb(s);
	int l=g[s].sz();
	//DB2(s,tin[s]);
	if(s == 1)
		level[s]=0;
	else
		level[s]=level[par]+1;
	loop(i,l)
	{
		if(g[s][i]!=par)
			dfs(g[s][i],s);
	}
	tout[s]=timer;
}
int BIT[1000006];
LL sum(int idx)
{
	 
	if(idx == 0)
		return 0;
	int res=0;
	while(idx>0)
	{
		res+=(LL)BIT[idx];
		idx-=(idx&-idx);
	}
	return res;
}
 
void update(int idx,int val)
{
	while(idx<1000006)
	{
		BIT[idx]+=val;
		idx+=idx&-idx;
	}
}



LL value[maxn];
//int pos[100005];
int main()
{
//ios_base::sync_with_stdio(false);
int n,t,m,l,k,ans,i,j,res=0,fl;
t=1;
int q,x,y;
//si(t);
while(t--)
{
	si(n);
	si(q);
	Loop(i,n)
	cin>>value[i];
	loop(i,n-1)
	{
		si(x);
		si(y);
		g[x].pb(y);
		g[y].pb(x);
	}
	vis.pb(0);
	timer=0;
	dfs(1,-1);
	
	int ct=1;
//	Loop(i,n)
//		mymap[vis[i]]=ct++;
	//Loop(i,n)
	//	DB2(tin[i],tout[i])


	while(q--)
	{
		si(x);
		if(x == 2)
		{
			int idx;
			si(idx);
			int right=tout[idx];
			int left=tin[idx];
			if(level[idx]%2 == 0)  //Even level
			cout<<value[idx]+sum(left)<<endl;  //All odd levels add -ve
			else
				cout<<value[idx]-sum(left)<<endl;
		//	DB3(tout[idx],mymap[vis[right]],sum(mymap[tout[idx]]))
		//	DB(value[idx]);
		}
		else
		{
			si(x);
			si(y);

				int left=tin[x];
				int right=tout[x];
			//	DB2(left,right);

				
			if(level[x]%2 == 0)
			{
				update(left,y);
				update(right+1,-y);
			}
			else
			{
				update(left,-y);
				update(right+1,y);
			}

		
		}

	}





	



}
return 0;
}
