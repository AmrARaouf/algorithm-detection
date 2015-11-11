//Language: GNU C++


#include<iostream>
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
#pragma comment(linker, "/STACK:16777216")
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define LL long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
using namespace std;
typedef pair<int, int> pii;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = (int)1e6 + 10;
int deg[maxn];
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int n,m,a,b;
	cin>>n>>m;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&a,&b);
		--a;
		--b;
		deg[a]++;
		deg[b]++;
	}
	LL sum = 0;
	for(int i = 0; i < n; i++)
		sum = sum + deg[i] * (n - 1 - deg[i]);
	sum /= 2;
	LL cur = 1;
	cur = cur * n * (n - 1) * (n - 2) / 3 / 2;
	cout<<cur - sum<<endl;
	return 0;
}
