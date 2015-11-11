//Language: MS C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>
#include <cmath>
#include <queue>
#define mp make_pair
#define pb push_back
#define bit(n) (1<<(n))
using namespace std;
vector<vector<pair<int,int> > > gr;
vector<__int64> height;
vector<char> used;
vector<int> pr;
void findh(int v,__int64 h){
	height[v]=h;
	used[v]=true;
	for (int i=0;i<gr[v].size();i++){
		int to=gr[v][i].first;
		if (!used[to]){
			pr[to]=v;
			findh(to,h+gr[v][i].second);
		}
	}
}
int main(){
	//freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	gr.resize(n);
	pr.resize(n);
	used.resize(n);
	height.resize(n);
	__int64 sum=0;
	for (int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		sum=sum+c;
		gr[a].pb(mp(b,c));
		gr[b].pb(mp(a,c));
	}
	findh(0,0);
	int maxx=0;
	for (int i=1;i<n;i++){
		if (gr[i].size()==1){
			maxx=max<__int64>(maxx,height[i]);
		}
	}
	printf("%I64d",2*sum-maxx);
	return 0;
}