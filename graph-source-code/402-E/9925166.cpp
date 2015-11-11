//Language: GNU C++


#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

#define max_nodes_size 100005
#define max_size 100005
#define ll long long int
#define mod 1000000007

#define sl(n) scanf("%lld", &n) 
using namespace std;

ll grid[2005][2005];
ll vis[2005];

ll dfs(ll node, ll flag, ll n)
{
	vis[node] = 1;
	ll temp = 1;

	for(ll i=0; i<n; i++)
	{
		if(i!=node && vis[i]==0)
		{
			if(flag)
			{
				if(grid[i][node]>0)
					temp += dfs(i, flag, n);
			}
			else
			{
				if(grid[node][i]>0)
					temp += dfs(i, flag, n);
			}
		}
	}

	//cout<<node<<" "<<temp<<endl;
	return temp;
}

int main()
{
	ll n, a;
	cin>>n;
	ll flag = 0;
	for(ll i=0; i<n; i++)
	{
		for(ll j=0; j<n; j++)
		{
			sl(grid[i][j]);
		}
	}

	for(ll i=1; i<=n; i++)
		vis[i] = 0;

	if(dfs(0, 0, n)==n)
		flag++;

	for(ll i=1; i<=n; i++)
		vis[i] = 0;

	if(dfs(0, 1, n)==n)
		flag++;

	if(flag==2)
		cout<<"YES";
	else
		cout<<"NO";

	return 0;
}