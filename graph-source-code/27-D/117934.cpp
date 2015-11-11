//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<cassert>
#include<sstream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

#define LET(x,a) 	__typeof(a) x(a)
#define IFOR(i,a,b) 	for(LET(i,a);i!=(b);++i)
#define EACH(it,v)  	IFOR(it,v.begin(),v.end())
#define FOR(i,a,b)  	for(int i=(int)(a) ; i < (int)(b);++i)
#define REP(i,n) 	FOR(i,0,n)
#define PB		push_back
#define MP 		make_pair
#define EPS		1e-9
#define INF 2000000000

typedef vector<int>	VI;
typedef long long	LL;
typedef pair<int,int>	PI;

int visited[1000];
int graph[500][500];
bool valid;
int n,m;

void dfs(int ver,int side){
	visited[ver] = side;
	REP(i,m)if(i!=ver && graph[ver][i]){
		if(visited[i]==-1)dfs(i,1-side);
		else if(visited[i]!=1-side)valid = false;
	}
	return;
}

int main(){
	cin>>n>>m;
	int roads[m+1][2];
	memset(graph,0,sizeof(graph));
	memset(visited,-1,sizeof(visited));
	REP(i,m){
		cin>>roads[i][0]>>roads[i][1];
		roads[i][0]--;
		roads[i][1]--;
		if(roads[i][0] > roads[i][1])swap(roads[i][0],roads[i][1]);
	}
	REP(i,m)REP(j,m)if(i!=j){
		if((roads[j][0]>roads[i][0] && roads[j][0]<roads[i][1] && roads[j][1]>roads[i][1])){
			graph[i][j]=1;
			graph[j][i]=1;
		}
	}
	//check if the graph is bipartite
	valid = true;
	REP(i,m)if(visited[i]==-1)dfs(i,0);	
	if(!valid)puts("Impossible");
	else {
		REP(i,m){
			if(!visited[i])printf("o");
			else printf("i");
		}
		cout<<endl;
	}
}
