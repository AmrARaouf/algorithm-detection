//Language: GNU C++


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector < vector <long long> > adj1;
vector < vector <long long> > adj2;

long long T[1005], C[1005], D[1005][1005], visited[1005];

struct nodo
{
	long long ind, d;
	nodo(long long n1, long long n2)
	{
		ind = n1;
		d = n2;
	}
};

bool operator <(nodo n1, nodo n2)
{
	return n1.d > n2.d;
}

int main()
{
	long long n, m;
	while(cin>>n>>m)
	{
		long long x, y;
		cin>>x>>y;
		x--;
		y--;
		
		adj1 = vector < vector <long long> > (n);
		adj2 = vector < vector <long long> > (n);
		
		for(int i=0; i<m; i++)
		{
			long long u, v, w;
			cin>>u>>v>>w;
			
			adj1[u-1].push_back(v-1);
			adj1[v-1].push_back(u-1);
			
			adj2[u-1].push_back(w);
			adj2[v-1].push_back(w);
		}
		
		for(int i=0; i<n; i++)
			cin>>T[i]>>C[i];
		
		memset(D, -1, sizeof(D));
		
		priority_queue <nodo> Q;
		
		for(int i=0; i<n; i++)
		{
			Q.push(nodo(i, 0));
			
			while(!Q.empty())
			{
				nodo q = Q.top();
				Q.pop();
				
				long long ind = q.ind, d = q.d;
				if(D[i][ind] != -1) continue;
				
				D[i][ind] = d;
				
				for(int j=0; j<adj1[ind].size(); j++)
					if(D[i][adj1[ind][j]] == -1)
						Q.push(nodo(adj1[ind][j], d + adj2[ind][j]));
			}
		}
		
		memset(visited, 0, sizeof(visited));
		
		bool ok = 0;
		
		Q.push(nodo(x, 0));
		while(!Q.empty())
		{
			nodo q = Q.top();
			Q.pop();
			
			long long ind = q.ind, d = q.d;
			if(visited[ind]) continue;
			
			visited[ind] = 1;
			if(ind == y)
			{
				ok = 1;
				cout<<d<<endl;
				break;
			}
			
			for(int i=0; i<n; i++)
				if(!visited[i] && D[ind][i] != -1 && D[ind][i] <= T[ind])
					Q.push(nodo(i, d + C[ind]));
		}
		
		if(!ok) cout<<-1<<endl;
	}
	
	return 0;
}
