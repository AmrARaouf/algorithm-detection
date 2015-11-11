//Language: GNU C++11


#include <iostream>
#include <algorithm>
#include <list>
#include <map>

#define lli long long int
#define mp make_pair

using namespace std;

struct E
{
	lli from , to;
	lli weight;
	lli id;
	
	int other(int p)
	{
		return (p==to ? from : to);
	}
	
} e[300005];

struct V
{
	bool visited;
	list<int> edges;
	
	V() { visited = false; }
} v[300005];

multimap< pair<lli,lli> ,int> h;		// < < all path weight , just this edge weight > , edge number >

int main()
{	
ios_base::sync_with_stdio(0);

	int n,m , u;
	cin>>n>>m;
	
	for (int i=1,f,t,w ; i<=m ; i++)
	{
		cin>>f>>t>>w;
		e[i].from = f,  e[i].to = t , e[i].weight = w , e[i].id = i;
		v[f].edges.push_back(i);
		v[t].edges.push_back(i);
	}
	cin>>u;
	
	v[u].visited = true;
	for (auto i : v[u].edges)
	{
		h.insert( mp( mp(e[i].weight , e[i].weight) , i ) );
	}
	
	int g[300005];
	lli ans = 0;
	for (int i=0 ; i<n-1 ; i++)
	{
		pair< pair<lli,lli> , int> p = *h.begin();
		h.erase(h.begin());
		
		int f,t; f=e[ p.second ].from , t=e[ p.second ].to;
		if ( v[f].visited && v[t].visited ) { i--; continue; }
		
		int l = (v[f].visited ? t : f);
		g[i] = p.second;					// edge number 
		ans += p.first.second;				// edge weight
		
		v[l].visited = true;
		int o;
		for (auto j : v[l].edges)
		{
			o = e[j].other(l);
			if ( v[o].visited == false )
				h.insert( mp( mp( e[j].weight + p.first.first , e[j].weight ) , j ) );
		}
	}
	
	cout<<ans<<"\n";
	for (int i=0 ; i<n-1 ; i++) cout<<g[i]<<" ";
	
	return 0;
}
