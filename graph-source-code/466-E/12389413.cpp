//Language: GNU C++


#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cassert>
#include <map>
 
#define ll long long int
#define vi vector <int>
#define vl vector <ll> 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >
 
 
#define f first
#define s second
 
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
 
#define pb push_back
#define pob pop_back
#define mp make_pair
 
#define max_size 100005
#define max_capacity INT_MAX
#define max_string_size 1000
#define max_node_size 340
#define max_power 26
#define max_sieve_size 105
#define max_log 17
#define MOD 1000000007L
 
using namespace std;

pair<ll, vector<ll> > documents[max_size];
ll requests[max_size][4];
ll parent[max_size];

vector <ll> edges[max_size];
ll vis[max_size][2];
ll tick = 0;

void dfs(ll node){
	tick++;
	vis[node][0] = tick;

	rep(i,0,(ll)edges[node].size()-1){
		dfs(edges[node][i]);
	}

	tick++;
	vis[node][1] = tick;
}

class DisjointSet
{
	public:
		ll num;
		ll parent[max_size];
		ll rank[max_size];

		void init(ll n)
		{
			num = n;
			for(ll i=1; i<=n; i++)
				parent[i] = i, rank[i] = 1;
		}

		ll find_parent(ll index)
		{
			while(parent[index]!=index)
			{
				parent[index] = parent[parent[index]];
				index = parent[index];
			}

			return index;
		}

		void merge(ll i, ll j)
		{
			ll parent1 = find_parent(i);
			ll parent2 = find_parent(j);

			if(parent1!=parent2)
			{
				if(rank[parent1]>rank[parent2])
				{
					rank[parent1] += rank[parent2];
					parent[parent2] = parent1;
				}
				else
				{
					rank[parent2] += rank[parent1];
					parent[parent1] = parent2;
				}
			}
		}
}disjoint_set;

int main(){
	ll n, m;
	cin>>n>>m;

	ll packet = 1;
	rep(i,1,m){
		cin>>requests[i][0];

		if(requests[i][0]==1){
			cin>>requests[i][1]>>requests[i][2];
			edges[requests[i][2]].pb(requests[i][1]);
			parent[requests[i][1]] = requests[i][2];
		}
		else if(requests[i][0]==2){
			cin>>requests[i][1];
			documents[packet].f = requests[i][1];
			packet++;
		}
		else{
			cin>>requests[i][1]>>requests[i][2];
			documents[requests[i][2]].s.pb(i);
		}
	}

	rep(i,1,n){
		if(parent[i]==0)
			dfs(i);
	}	

	packet = 1;
	disjoint_set.init(n);
	rep(i,1,m){
		if(requests[i][0]==1){
			disjoint_set.merge(requests[i][1], requests[i][2]);
		}
		else if(requests[i][0]==2){
			rep(j,0,(ll)documents[packet].s.size()-1){
				ll node = requests[documents[packet].s[j]][1];
				if(disjoint_set.find_parent(node)==disjoint_set.find_parent(requests[i][1]) && vis[node][0]<=vis[requests[i][1]][0] && vis[node][1]>=vis[requests[i][1]][1])
					requests[documents[packet].s[j]][3] = 1;
				else
					requests[documents[packet].s[j]][3] = 0;
			}
			packet++;
		}
		else{
			if(requests[i][3]==1)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}

	return 0;
}