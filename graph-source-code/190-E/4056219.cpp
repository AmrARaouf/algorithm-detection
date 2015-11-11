//Language: GNU C++


#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

vector <int> graph[500005];

int degree[500005];
int vis[500005];
int rank[500005], parent[500005];
int n, m;

int find(int x)
{	
	if(parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);

}

void merge(int x, int y)
{
	int x_r = find(x);
	int y_r = find(y);
	
	if(x_r == y_r)
		return;
		
	if(rank[x_r] > rank[y_r])
		parent[y_r] = x_r;
	else if(rank[x_r] < rank[y_r])
			parent[x_r] = parent[y_r];
		else
		{
			parent[y_r] = x_r;
			rank[x_r] ++;
		}
}

void solve (int x)
{
	queue <int> q;

	
	for (int i = 0; i < graph[x].size(); i ++)
	{
		vis[graph[x][i]] ++;
		q.push(graph[x][i]);
	}
	
	for(int i = 0; i < n; i ++)
	{
		if(x == i)
			continue;
		if(vis[i] == 0)
			merge(x,i);
			
	}
	
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		
		if(find(node) == find(x))
			continue;
		
		for(int i = 0; i < n + 2; i ++)
		{
			vis[i] = 0;
		}
		
		for (int i = 0; i < graph[node].size(); i ++)
		{
			vis[graph[node][i]] ++;
		}
		for(int i = 0; i < n; i ++)
		{
			if(node == i)
				continue;
			if(vis[i] == 0)
				merge(node,i);
		}
	}
		
}


int main ()
{
	int a, b, minimal, idx;
	scanf("%d%d",&n,&m);
	
	
	for (int i = 0; i < m; i ++)
	{
		scanf("%d%d",&a,&b);
		a --, b --;
		graph[a].push_back(b);
		graph[b].push_back(a);
		degree[a] ++;
		degree[b] ++;
	}
	for (int i = 0 ; i < n + 1 ; i ++)
    {
        parent [i] = i;
        rank [i] = 0;
    }
	
	minimal = degree[0];
	idx = 0;
	
	for (int i = 1; i < n; i ++)
	{
		if (degree[i] < minimal)
		{
			idx = i;
			minimal = degree[i];
		}
	}
	vector <int> ans[n + 3];
	solve(idx);
	
	int cont = 0;
	for(int i = 0; i < n; i ++)
	{
		if(ans[find(i)].size() == 0)
			cont ++;
		ans[find(i)].push_back(i + 1);
	}

	printf("%d\n",cont);
	
	for(int i = 0; i < n; i ++)
	{
		if(ans[i].size() > 0)
		{
			printf("%d ",ans[i].size());
			
			for(int j = 0; j < ans[i].size(); j ++)
			{
				if(j != 0)
					printf(" ");
				printf("%d",ans[i][j]);
			}
			printf("\n");
		}
	}
	
	return 0;
}
















