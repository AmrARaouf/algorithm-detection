//Language: GNU C++


#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INT_MAX	1e8
using namespace std;
int dist[501][501];
int type[100004];
int visited[100004];
int sz[501];
int start[501];
vector<int> edge[100004];
void check(int n)
{
	if(!edge[n].size())	return;
	int i,x;
	queue<int> myqueue;
	myqueue.push(n);
	while(!myqueue.empty())
	{
		x=myqueue.front();
		for(i=0;i<edge[x].size();i++)
		{
			if(!visited[edge[x][i]])
			{
				if(type[n]==type[edge[x][i]])	visited[edge[x][i]]=1;
				myqueue.push(edge[x][i]);
			}
		}
		myqueue.pop();
	}
	return;
}
int main()
{
	int i,j,n,k,m,u,v,x,l;
	string s;
	cin >> n >> m >> k;
	u=1;
	for(i=1;i<=k;i++)
	{
		start[i]=u;
		cin >> x;
		sz[i]=x;
		for(j=u;j<u+x;j++)	type[j]=i;
		u=u+x;
	}
//	for(i=1;i<=n;i++)	cout << type[i] << endl;
	for(i=0;i<=k;i++)
	{
		for(j=0;j<=k;j++)
		{
			dist[i][j]=INT_MAX;
		}
	}
	for(i=0;i<m;i++)
	{
		cin >> u >> v >> x;
		if(dist[type[u]][type[v]]>x)
		{
			dist[type[u]][type[v]]=x;
			dist[type[v]][type[u]]=x;
		}
		if(!x)
		{
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
	}
	for(i=1;i<=k;i++)	check(start[i]);
	for(i=1;i<n;i++)
	{
		if(!visited[i] && sz[type[i]]!=1)
		{
			printf("No\n");
			return 0;

		}
	}
	printf("Yes\n");
	for (l = 1; l <= k; l++)
	{
		// Pick all vertices as source one by one
		for (i = 1; i <= k; i++)
		{
			// Pick all vertices as destination for the
			// above picked source
			for (j = 1; j <= k; j++)
			{
				// If vertex k is on the shortest path from
				// i to j, then update the value of dist[i][j]
				if (dist[i][l] + dist[l][j] < dist[i][j])
					dist[i][j] = dist[i][l] + dist[l][j];
			}
		}
	}
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=k;j++)
		{
			if(i==j)	printf("0 ");
			else if(dist[i][j]==INT_MAX)	printf("-1 ");
			else	printf("%d ",dist[i][j]);
		}
		printf("\n");
	}
	printf("");
	return 0;
}
