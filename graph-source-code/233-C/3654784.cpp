//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MOD (1000000000+7) 
#define INF 1000000000
typedef long long  ll;
typedef unsigned long long  ull;
typedef pair<ll,ll> pii;

int need, e;
int mat[128][128];
bool found;
int add;
int v;

int main()
{
	memset(mat, 0, sizeof mat);
	
	cin >> need;
	e = 0;
	while(e < need)
	{
		found = false;
		for(int i = 1; i <= v && found == false; i ++)
			for(int j = i+1; j <= v && found == false; j ++)
			{
				if(mat[i][j] == 1)	// this edge has been chosen before
					continue;
				add = 0;
				for(int k = 1; k <= v; k ++)
				{
					if(k == i || k == j)
						continue;
					if(mat[i][k] && mat[k][j])
						add ++;
				}
				if(e+add <= need)
				{
					found = true;
					e += add;
					mat[i][j] = 1;
					mat[j][i] = 1;
				}
			}
		if(found == false)
			v ++;
	}
	cout << v << endl;
	for(int i = 1; i <= v; i ++)
	{
		for(int j = 1; j <= v; j ++)
			cout << mat[i][j];
		cout << endl;
	}
	
	return 0;
}


	    			    		 						  	  	