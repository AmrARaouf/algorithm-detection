//Language: MS C++


#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 101;
int N;
int x[MAXN];
int y[MAXN];
bool visited[MAXN];
vector < int > graph[MAXN];

int components;
void dfs(int node){
	visited[node] = true;
	for(int i = 0 ; i < (int)(graph[node].size()) ; i++)
		if(!visited[graph[node][i]])
			dfs(graph[node][i]);
	return;
}
int main(){
	scanf("%d" , &N);
	for(int n = 1 ; n <= N ; n++)
		scanf("%d %d" , &x[n] , &y[n]);
	for(int i = 1 ; i <= N ; i++)
		for(int j = i + 1 ; j <= N ; j++){
			if(x[i] == x[j] || y[i] == y[j]){
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	for(int n = 1 ; n <= N ; n++)
		if(!visited[n]){
			++components;
			dfs(n);
		}
	printf("%d\n" , components - 1);
	return 0;
}