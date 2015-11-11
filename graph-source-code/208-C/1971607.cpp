//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define DOWN(i,a,b) for(int i= (a) ; i >= (b); --i)
#define FOR(i,a) for(int i = 0; i < a; ++i)

#define pb  push_back
#define ins insert
#define all(x) begin(x), end(x)
#define sz(x) size(x)
#define ms(arr,val) memset(arr, val, sizeof(arr))

#define INF 1000000000
#define PI 3.14159

#define VI vector<int>
#define VVI vector<VI>

int n;
int d[105][105];
double countWay[105][105];
bool f[105][105];

double maxSafeRoad = 0;

int main()
{
	//freopen("C.txt", "rt" , stdin);
	int m;
	cin >> n >> m;

	int u,v;

	REP(i,1,n)
		REP(j,1,n)
		{
			if(i == j)
			{
				d[i][j] = 0;
				countWay[i][j] = 1;
			}
			else
			{
				d[i][j] = INF;
				countWay[i][j] = 0;
			}
		}

	FOR(i,m)
	{
		cin >> u >> v;
		f[u][v] = f[v][u] = true;
		d[u][v] = d[v][u] = 1;
		countWay[u][v] = countWay[v][u] = 1;
	}

	REP(v,1,n)
	REP(i,1,n)
	REP(j,1,n)
	{
		if( i != j  && v != i && v != j )
		{
			int length = d[i][v] + d[v][j];
			if( d[i][j] > length)
			{
				d[i][j] = length;
				countWay[i][j] = countWay[i][v] * countWay[v][j];
			}
			else if (d[i][j] == length)
			{
				countWay[i][j] += countWay[i][v] * countWay[v][j];
			}
		}
	}

//	REP(i,1,n)
//	REP(j,1,n)
//		cout <<i << " " << j <<" " << d[i][j] <<" "<< countWay[i][j]<<endl;

	REP(i,1,n)
	{
		double total = 0;
		REP(j,1,n)
		{

			if(d[i][j] == 1)
			{
				if(d[1][i] + d[j][n] == d[1][n] - 1)
				{
					total += countWay[1][i] * countWay[j][n];
				}
				else if(d[1][j] + d[i][n] == d[1][n] - 1)
				{
					total += countWay[1][j] * countWay[i][n];
				}

			}
		}
		maxSafeRoad = max(maxSafeRoad, total);
	}

	printf("%.9lf", (double)maxSafeRoad/countWay[1][n]);
}
