//Language: GNU C++


#include <iostream>
#include <map>
#include <stdio.h>
#include <set>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <list>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <string.h>
#include <math.h>
using namespace std;
/**
 * @author:	Shamir14 -- Amirhossein Shapoori
 * lordamir14@gmail.com
 * ACM team: Chormangz
 * Tehran, Iran
 * Privateering
 * :P
 */

const int MAX = 100010;
int n, m;

vector <pair <int, int> > graph[MAX];
set <int> Time[MAX];
map <int, int> memo[MAX];

void Read(){
	int i, v, u, weight, j, k, temp;
	cin >> n >> m;
	for(i = 0; i < m; i++){
		scanf("%d%d%d", &v, &u, &weight);
		graph[v - 1].push_back(pair <int, int>(u - 1, weight));
		graph[u - 1].push_back(pair <int, int>(v - 1, weight));
	}
	for(i = 0; i < n; i++){
		scanf("%d", &k);
		for(j = 0; j < k; j++)
			scanf("%d", &temp), Time[i].insert(temp);
	}
}

int f(int n, int i){
	if(memo[n].find(i) != memo[n].end()) return memo[n][i];
    if(Time[n].find(i) == Time[n].end()) return memo[n][i] = 0;
	return memo[n][i] = f(n, i + 1) + 1;
}

int dijkstra(int start, int end){
	multimap<int, int> mp;
	multimap<int, int>::iterator itr;
	mp.clear();
	vector <int> dist, color;
	dist.resize(n, -1);
	color.resize(n, 0);
	mp.insert(multimap<int, int>::value_type(f(0, 0), start));
	int v, w, i, u, cur;

	while(!mp.empty()){
		itr = mp.begin();
		cur = itr->first;
		v = itr->second;
		mp.erase(itr);
		for(i = 0; i < graph[v].size(); i++){
			u = graph[v][i].first;
			w = graph[v][i].second;
			if(!color[u]){
    			if(dist[u] < 0 || dist[u] > cur + w + f(u, cur + w)){
    				dist[u] = cur + w;
    				if(Time[u].find(w + cur) != Time[u].end()) dist[u] += f(u, cur + w);
                    mp.insert(multimap<int, int>::value_type(dist[u], u));
                }
                if(u == end && (dist[u] > cur + w))
    				dist[u] = cur + w;
            }
		}
		color[v] = 1;
	}
	return dist[end];
}


int main(){
	Read();
	printf("%d\n", dijkstra(0, n - 1));
    return 0;
}
