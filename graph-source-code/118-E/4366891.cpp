//Language: GNU C++


#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define  ForEach(i,c) for(__typeof((c).begin()) i = (c).begin();i != (c).end();i++)
using namespace std;

const int N = 100010;
int head[N], cnt, n, m;
struct Edge{
	int e, next;
}edge[N * 10];

void addedge(int a, int b){
	edge[cnt].e = b;
	edge[cnt].next = head[a];
	head[a] = cnt++;
}

//----------------BCC---------------------//
int low[N], dfn[N], sta[N * 5], instack[N];
struct Tarjan{	
	int index, top, block;
	void dfs(int u, int pre){
	    int e;
	    low[u] = dfn[u] = ++index;
	    sta[top++] = u;
	    instack[u] = 1;
	    for(int i = head[u];i != -1;i = edge[i].next){
	        e = edge[i].e;
	        if(e == pre)
				continue;
	        if(!dfn[e]){
	            dfs(e, u);
	            low[u] = min(low[u], low[e]);
	        }
	        else if(instack[e] && low[u] > dfn[e])
	            low[u] = dfn[e];
	    }
	    if(low[u] == dfn[u]){
    		block++;
	        do{
	            e = sta[--top];
	            instack[e] = 0;
	        }while(e != u);
	    }
	}
	int tarjan(){
		top = 0, block = 0, index = 0;
		for(int i = 1;i <= n;i++)
			if(!dfn[i])
				dfs(i, -1);
		return block;
	}
}BCC;
//----------------end--------------------//

int vis[N * 6], vis1[N];
void dfs(int to){
	vis1[to] = 1;
	for(int it = head[to];it != -1;it = edge[it].next){
		if(!vis[it] && !vis[it ^ 1]){
			vis[it] = vis[it ^ 1] = 1;
			printf("%d %d\n", to, edge[it].e);
		}
		if(!vis1[edge[it].e])
			dfs(edge[it].e);
	}
}	

int main(){
	memset(head, -1, sizeof head);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		int a, b;
		scanf("%d%d", &a, &b);
		addedge(a, b);
		addedge(b, a);
	}
	if(BCC.tarjan() > 1)
		cout << 0 << endl;
	else
		dfs(1);
	return 0;
}