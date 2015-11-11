//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <cstdio>
#include <assert.h>
 
#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define RFOR(i,x,y) for(int i=(x);i>=(y);i--)
#define ABS(x) ((x)>0?(x):-(x))
#define SQ(x) ((x)*(x))
#define mset(x,y) memset(x,y,sizeof(x))
#define INF 1000000000
#define MOD 1000000007
#define pb(X) push_back(X) 
 
using namespace std;
 
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<double> vd;

int a[3010];
int vis[3010];
int n;
vector<int> cyc[3010];
vector<pi> ans;
int size;

void create_cyc()
{
	mset(vis,0);
	for(int i=0;i<n;i++) cyc[i].clear();
	size=0;
	for(int i=0;i<n;i++)
	if(!vis[i])
	{
		int curr=i;
		while(!vis[curr])
		{
			vis[curr]=1;
			cyc[size].pb(curr);
			curr=a[curr];
		}
		size++;
	}
}

void doit()
{
	int ind=0;
	while(cyc[ind].size()==1) ind++;

	int ind2=1;
	for(int i=1;i<cyc[ind].size();i++) if(cyc[ind][ind2]>cyc[ind][i]) ind2=i;
	swap(a[cyc[ind][0]],a[cyc[ind][ind2]]);
	// cout<<cyc[ind][0]<<" "<<cyc[ind][ind2]<<endl;
	ans.pb(pi(cyc[ind][0],cyc[ind][ind2]));
	create_cyc();
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("inp.txt","r",stdin);
    #endif

    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&a[i]);
    	a[i]--;
    }

    int m;
	scanf("%d",&m);
	create_cyc();
	int swaps=n-size;
	if(swaps<m)
	{
		for(int i=1;i<size&&swaps<m;i++)
		{
			ans.pb(pi(cyc[0][0],cyc[i][0]));
			swaps++;
		}
	}
	else
	{
		while(swaps>m)
		{
			doit();
			// cout<<"* ";
			// for(int i=0;i<n;i++) cout<<a[i]<<" ";
			// cout<<endl;
			// for(int i=0;i<size;i++)
			// {
			// 	for(int j=0;j<cyc[i].size();j++) cout<<cyc[i][j]<<" ";
			// 	cout<<endl;
			// }
			// cout<<endl;
			swaps--;
		}
	}

	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++) printf("%d %d ",ans[i].first+1,ans[i].second+1);
	printf("\n");

    return 0;
}