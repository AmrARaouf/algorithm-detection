//Language: MS C++


#pragma comment(linker, "/STACK:500000000")
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <time.h>
#include <map>
using namespace std;
#define Int long long
#define inf 0x3f3f3f3f
#define eps 1e-9

struct point
{
	point(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	bool operator < (const point &f) const
	{
		return x < f.x || x == f.x && y < f.y;
	}
	int x, y;
} A[222];

map <point, int> m;
map <point, int>::iterator iter;

vector <int> v[222];
bool used[222];

void dfs(int node)
{
	used[node] = true;
	for(int i = 0; i < v[node].size(); i++)
		if(!used[v[node][i]])
			dfs(v[node][i]);
}

int main()
{
	int n, i, j;
	cin >> n;
	for(i = 0; i < n; i++)
		cin >> A[i].x >> A[i].y, m.insert(make_pair(point(A[i].x, A[i].y), 0));
	int cnt = 0;
	for(iter = m.begin(); iter != m.end(); iter++)
		iter->second = cnt++;
	memset(used, false, sizeof(used));
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(i != j && (A[i].x == A[j].x || A[i].y == A[j].y))
				v[m[A[i]]].push_back(m[A[j]]);
	int comp = 0;
	for(i = 0; i < cnt; i++)
		if(!used[i])
			comp++, dfs(i);
	printf("%d\n", comp - 1);
    return 0;
}