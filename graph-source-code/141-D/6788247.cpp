//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define N 210000

struct Node{
	int x;
	int id;
	Node(){}
	Node(int a, int b) {
		x = a;
		id = b;
	}
}node[N<<3];
bool cmpByX(const Node &a, const Node &b) {
	return a.x < b.x;
}

struct Graph{
	struct Edge{
		int to;
		int next;
		int cost;
		int xieid;
	}e[N<<6];
	int p;
	int head[N];
	void clear() {
		p = 0;
		memset(head, -1, sizeof(head));
	}

	void add(int u, int v, int cost, int xieid = -1) {
		//printf("add %d->%d(cost = %d)\n", u, v, cost);
		e[p].to = v;
		e[p].cost = cost;
		e[p].next = head[u];
		e[p].xieid = xieid;
		head[u] = p++;
	}
}g;


int dis[N<<1];
int pre[N<<1];
int vis[N<<1];
const int INF = 0x3f3f3f3f;

inline bool relax(int u, int v, int cost) {
	//printf("relax %d->%d(cost=%d)\n", u, v, cost);
	//printf("dis[u] = %d, dis[v] = %d\n", dis[u], dis[v]);
	if (dis[v] > dis[u] + cost) {
		pre[v] = u;
		dis[v] = dis[u] + cost;
		//printf("relax %d->%d(cost=%d), newdis = %d\n", u, v, cost, dis[v]);
		return true;
	}
	return false;
}

int spfa(int start, int end) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
    double sumDisInQue = 0;
	dis[start] = 0;
	deque <int> que;
	que.push_back(start);
	vis[start] = true;
	while (!que.empty()) {
		int now = que.front();
        sumDisInQue -= dis[now];
		que.pop_front();
		vis[now] = false;
		for (int i = g.head[now]; ~i; i = g.e[i].next) {
			int to = g.e[i].to;
			int cost = g.e[i].cost;
			if (relax(now, to, cost) && !vis[to]) {
                if (!que.empty() && (dis[to] > dis[que.front()] || dis[to] > sumDisInQue/que.size())) que.push_back(to);
                else que.push_front(to);
                sumDisInQue += dis[to];
				vis[to] = true;
			}
		}
	}
	return dis[end];
}

bool havePo[N];

int main() {
	int n, l;
	while (scanf("%d%d", &n, &l) != EOF){
		g.clear();
		node[0] = Node(0,0);
		node[1] = Node(l,1);
		memset(havePo, 0, sizeof(havePo));
		for (int i = 1; i <= n; i++) {
			int x, d, t, p;
			scanf("%d%d%d%d", &x, &d, &t, &p);
			node[i*2] = Node(x-p, i*2);
			node[i*2+1] = Node(x+d, i*2+1);
			if (x-p >= 0 && t < d) {
				havePo[i] = true;
				g.add(i*2,i*2+1,t+p,i);
			}
		}
		sort(node, node+(n+1)*2, cmpByX);
		int end = (n+1)*2;

		for (int i = 0; i < end-1; i++) {
			g.add(node[i].id, node[i+1].id, node[i+1].x-node[i].x);
			g.add(node[i+1].id, node[i].id, node[i+1].x-node[i].x);
		}
		spfa(0,1);
		printf("%d\n", dis[1]);
		stack<int> stk;
		int now = 1;
		while (now) {
			int tmppre = pre[now];
			if (!tmppre) break;
			if (tmppre % 2 == 0 && now == tmppre+1) {
				int id = tmppre/2;
				if (havePo[id]) {
					stk.push(id);
				}
			}
			now = pre[now];
		}
		printf("%d\n", stk.size());
		while (!stk.empty()) {
			printf("%d\n", stk.top());
			stk.pop();
		}
	}
	return 0;
}
