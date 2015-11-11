//Language: GNU C++


#include <vector>
#include <stdio.h>
#include <algorithm>

#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

using namespace std;
const int MAXN = 200009;

int n, m, u, v, tim;
vector <int> E[MAXN];
int A[MAXN], T[MAXN*2], in[MAXN], out[MAXN], lvl[MAXN];

void dfs(int node, int prev)
{
	in[node] = ++tim;
	
	tr(j, E[node])
	{
		int to = *j;
		
		if (to==prev)
			continue;
		
		lvl[to] = lvl[node]+1;
		
		dfs(to, node);
	}
	
	out[node] = ++tim;
}

void update(int x, int y)
{
	for (int i=x; i<=2*n; i+=(i&-i))
		T[i] += y;
}
int query(int x)
{
	int res = 0;
	
	for (int i=x; i>=1; i-=(i&-i))
		res += T[i];
	
	return res;
}

int main()
{
	scanf("%d %d" ,&n ,&m);
	
	for (int i=1; i<=n; i++)
		scanf("%d" ,&A[i]);
	
	for (int i=1; i<n; i++)
	{
		scanf("%d %d" ,&u ,&v);
		
		E[u].push_back(v);
		E[v].push_back(u);
	}
	
	dfs(1, 0);
	
	while(m--)
	{
		int type, nod, val;
		
		scanf("%d" ,&type);
		
		if (type==1)
		{
			scanf("%d %d" ,&nod ,&val);
			
			if (lvl[nod]%2==0)
			{
				update(in[nod], +val);
				update(out[nod], -val);
			}			
			else
			{
				update(in[nod], -val);
				update(out[nod], +val);
			}
		}
	
		else
		{
			scanf("%d" ,&nod);
			
			if (lvl[nod]%2==0)
				printf("%d\n" ,A[nod] + query(in[nod]));
			
			else
				printf("%d\n" ,A[nod] - query(in[nod]));
		}
	}
}
