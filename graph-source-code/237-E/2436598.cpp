//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1000;
const int M = 100000;
const int inf = ~0U >> 2;

struct Node{
    int to, c, w, next;
}e[M];
int box[N], size, cnt[26], n;
char str[110];
int start, end, tot, LEN;

inline void add(int from, int to, int c, int w){
    e[size].to = to;
    e[size].c = c;
    e[size].w = w;
    e[size].next = box[from];
    box[from] = size++;
    
    e[size].to = from;
    e[size].c = 0;
    e[size].w = -w;
    e[size].next = box[to];
    box[to] = size++;
}
void init(){
    scanf("%s", str);
    LEN = strlen(str);
    scanf("%d", &n);
    start = 0, end = n + 26 + 1, tot = end + 1;
    memset(cnt, 0, sizeof(cnt));
    memset(box, -1, sizeof(box)), size = 0;
    
    for(int i = 0; str[i]; ++i) cnt[str[i] - 'a']++;
    for(int i = 0; i < 26; ++i) add(n + i + 1, end, cnt[i], 0);    
    for(int i = 0, c; i < n; ++i){
        scanf("%s%d", str, &c);
        memset(cnt, 0, sizeof(cnt));
        add(start, i + 1, c, 0);
        for(int j = 0; str[j]; ++j) cnt[str[j] - 'a']++;
        for(int j = 0; j < 26; ++j) add(i + 1, n + j + 1, cnt[j], i + 1);
    }
}
int dis[N], pre[N];
bool flag[N];

bool spfa(){
	queue<int> Q;
	fill(dis, dis + tot, inf);
	memset(flag, false, sizeof(flag));
	memset(pre, -1, sizeof(pre));
	dis[start] = 0;Q.push(start);
	while(!Q.empty()){
		int x = Q.front();
		Q.pop(), flag[x] = false;
		for(int i = box[x]; ~i; i = e[i].next)
			if(e[i].c && dis[e[i].to] - dis[x] > e[i].w){
				dis[e[i].to] = dis[x] + e[i].w;
				pre[e[i].to] = i;
				if(!flag[e[i].to]) flag[e[i].to] = true, Q.push(e[i].to);
			}
	}	
	return dis[end] != inf;
}
void mcmf(){
	int ret = 0, total_flow = 0;
	while(spfa()){
		int u = end, flow = inf;
		while(~pre[u]){
			flow = min(flow, e[pre[u]].c);
			u = e[pre[u] ^ 1].to;
		}
		ret += dis[end] * flow;
        total_flow += flow;
		u = end;
		while(~pre[u]){
			e[pre[u]].c -= flow;
			e[pre[u] ^ 1].c += flow;
			u = e[pre[u] ^ 1].to;
		}
	}
    if(total_flow != LEN) puts("-1");
	else printf("%d\n", ret);
}
int main(){
    init();
    mcmf();
    return 0;
}   