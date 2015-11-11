//Language: GNU C++


//============================================================================
// Name        : D.cpp
// Author      : Luis Mariano Savigne
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>

#define MAXN 50005

using namespace std;

int n, ai, ri, pi, pos, items[MAXN];
bool used[MAXN];
vector<int> graph[MAXN];

void dfs(int nodo)	{

	used[nodo] = true;

	for(unsigned i = 0; i < graph[nodo].size(); ++i)
		if(!used[graph[nodo][i]])	{

			items[graph[nodo][i]] = nodo;
			dfs(graph[nodo][i]);
		}
}

int main() {

/*
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
*/

	scanf("%d%d%d", &n, &ri, &pi);
	for(int i = 1, pos = 1; i < n; ++i, ++pos)	{

		pos += (pos == ri);
		scanf("%d", &ai);

		graph[ai].push_back(pos);
		graph[pos].push_back(ai);
	}

	dfs(pi);

	bool possible = 0;

	for(int i = 1; i <= n; ++i)	{

		if(i == pi)	continue;

		if(possible)	printf(" ");
		else	possible = true;

		printf("%d", items[i]);
	}

	puts("");

	return 0;
}
