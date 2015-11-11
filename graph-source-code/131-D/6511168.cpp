//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <deque>
#include <sstream>

using namespace std;

int seen[3001];
int counter;
bool ciclo[3001];
int dist[3001];
vector <int> arr[3001];
bool marked[3001];
int n;

int bfs (int i){

queue <pair <int,int> > cola;
cola.push(make_pair(i,0));
memset(marked,0,sizeof(marked));

while (!cola.empty()){

pair <int,int> p=cola.front();
cola.pop();

if (ciclo[p.first])
return p.second;

if (marked[p.first]) continue;

marked[p.first]=true;

for (int i=0;i<arr[p.first].size();++i){
	
	int destino=arr[p.first][i];
	if (marked[destino]) continue;

	cola.push(make_pair(destino,p.second+1));
	

}

}

return 0;
}


int dfs(int x, int parent)
{
    int low = 0x3f3f3f3f;
    seen[x] = ++counter;

    for (int i = 0; i < (int)arr[x].size(); i++) {
	int y = arr[x][i];
	if (y == parent) continue;
	if (seen[y] == 0) {
	low = min(low, dfs(y, x));
	} else if (seen[y] <= seen[x]) {
	low = min(low, seen[y]);
	}
    }

    ciclo[x] = (low <= seen[x]);
    return low;
}

int main(){

counter=0;
cin>>n;
for (int i=0;i<n;++i){
   int a,b;
   cin>>a>>b;
   arr[a-1].push_back(b-1);
   arr[b-1].push_back(a-1);
}

memset(ciclo,0,sizeof(ciclo));
memset(dist,0,sizeof(dist));

dfs(0,-1);

for (int i=0;i<n;++i){
if (ciclo[i]){printf("%d ",0); continue;}

printf("%d ",bfs(i));


}
printf("\n");


return 0;
}