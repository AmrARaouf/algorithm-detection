//Language: GNU C++


//#pragma comment(linker, "/STACK:1024000000,1024000000")//C++加栈
#include<iostream>
#include<cstdio>
#include<cstring>
#include<numeric>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<string>
#include<cmath>
#include<stack>
using namespace std;
#if defined (_WIN32) || defined (__WIN32) || defined (WIN32) || defined (__WIN32__)
#define LL __int64
#define LLS "%" "I" "6" "4" "d"
#define LLU "%" "I" "6" "4" "u"
#define LL_MAX _I64_MAX

#else
#define LL long long
#define LLS "%" "l" "l" "d"
#define LLU "%" "l" "l" "u"
#define LL_MAX _I64_MAX
#endif
#define N 2005
#define M 4000005
int n, m;
//有向图的tarjan
//belong[i]表示节点i所属的强连通分量
int head[N], pos;
int bcnt, belong[N], pre[N], cok;
int top, stk[N];
struct L {
	int v, nxt;
} e[M];
void add(int u, int v) {
	e[pos].v = v;
	e[pos].nxt = head[u];
	head[u] = pos++;
}
void InitEdge(){
	memset(head,-1,sizeof(head));
	pos=0;
}
int dfs(int u) {
	int lowu = pre[u] = ++cok;
	stk[top++] = u;
	for (int i = head[u]; i != -1; i = e[i].nxt) {
		int v = e[i].v;
		if (!pre[v]) {
			int lowv = dfs(v);
			lowu = min(lowu, lowv); //如果该点的子节点能达到更高的节点
		} else if (!belong[v]) //只能通过没有确定编号的其他点
			lowu = min(lowu, pre[v]);
	}
	if (lowu == pre[u]) { //如果u只能连回自己，那么u就是第一个被发现的节点
		bcnt++;
		do {
			belong[stk[top - 1]] = bcnt;
		} while (stk[--top] != u);
	}
	return lowu;
}
void tarjan() {
	top = cok = bcnt = 0;
	memset(pre, 0, sizeof(pre));
	memset(belong, 0, sizeof(belong));
	for (int i = 1; i <= n; i++)
		if (!pre[i])dfs(i);
}
int main(){
	while(~scanf("%d",&n)){
		int x;
		InitEdge();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				scanf("%d",&x);
				if(i!=j&&x){
					add(i,j);
				}
			}
		}
		tarjan();
		if(bcnt>1)puts("NO");
		else puts("YES");
	}
}

	 	    	 		   			   	  			