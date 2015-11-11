//Language: GNU C++


/* CPP Tempelate
 * @author Devashish Tyagi
 */

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <fstream>
#include <stack>
#include <string>
#include <vector>
#include <list>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>


// Compiler utility
#define int_msb(x) ((31) - __builtin_clz(x))

#define sf(a) scanf("%d",&a)
#define ssf(a,b) scanf("%d %d",&a,&b)
#define pf(a) printf("%d\n",a)
#define foreach(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define pi pair<int,int>
#define vi vector<int>
#define all(v) v.begin(),v.end()

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()

#define forn(i,a,b) for(int (i) = (a); (i) < (b); ++(i))  
#define rforn(i,a,b) for(int (i) = (a)-1; (i) >= (b); --(i))  
#define init0(a) memset((a),0,sizeof(a))

#define INF 1000000000
#define MOD 1000000009
#define PI 3.1415926535897932

using namespace std;
typedef long long LL;

vector<int> parent, rank;
vector<long long> weight;


int getParent(int index) {
	if (parent[index] == index)
		return index;
	return parent[index] = getParent(parent[index]);
}

void join(int x, int y) {
	int a = getParent(x);
	int b = getParent(y);
	if (a != b) {
		if (rank[a] < rank[b])
			swap(a, b);		
		parent[b] = a;
		weight[b] = 0;
		weight[a] += weight[b];

		if (rank[a] == rank[b])
			rank[a]++;
	}
}

int main()
{
	int n, m, p, q;
	cin>>n>>m>>p>>q;

	parent.resize(n, 0);
	rank.resize(n , 0);
	weight.resize(n, 0);

	for(int i = 0; i < n; i++)
		parent[i] = i;

	for(int i = 0; i < m; i++) {
		int x, y, l;
		cin>>x>>y>>l;
		join(x-1, y-1);
		weight[getParent(y-1)] += l;
	}

	priority_queue< pair<long long, int> > S;
	int count = 0;
	for(int i = 0; i < n; i++) {
		if (parent[i] == i) {
			S.push(make_pair(-weight[i], i));
		}
		else
			count++;
	}

	if ((int)S.size() < q) {
		cout<<"NO"<<endl;
		return 0;
	}
	else if ((int)S.size()-p > q) {
		cout<<"NO"<<endl;
		return 0;
	}

	vector< pair<int, int> > edges;
	p -= (S.size()-q);
	
	while(S.size() > q) {
		pair<long long, int> first = S.top();
		S.pop();
		pair<long long, int> second = S.top();
		S.pop();
		edges.push_back(make_pair(first.second+1, second.second+1));
		join(first.second, second.second);
		long long w = -first.first - second.first + min(1000000000LL, -first.first - second.first  + 1);
		//cout<<"Weight "<<w<<endl;
		S.push(make_pair(-w, first.second));	
	}

	if (p >= 0) {
		bool found = false;
		int x, y;
		for(int i = 0; i < n; i++) {
			if (parent[i] != i) {
				x = i;
				y = parent[i];
				found = true;
			}
		}
		if (p > 0 && found || (p == 0)) {
			cout<<"YES"<<endl;
			for(int i = 0; i < edges.size(); i++)
				cout<<edges[i].first<<" "<<edges[i].second<<endl;
			while(p > 0) {
				cout<<x+1<<" "<<y+1<<endl;
				p--;
			}
		}
		else {
			cout<<"NO"<<endl;
		}
	}

	return 0;
}
