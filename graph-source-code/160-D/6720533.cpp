//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define NONE 2
#define  ANY 1
#define  MAY 0
struct Edge {
    int from , to , len , id;
    void read(int i) {
        id = i;
        scanf("%d%d%d" , &from , &to , &len);
    }
    bool operator < (const Edge &b) const {
        return len < b.len;
    }
}E[100010];
int pa[100010];
int find(int x) {
    return (x == pa[x]) ? x : pa[x] = find(pa[x]);
}
void merge(int x , int y) {
    x = find(x) , y = find(y);
    if (x != y)
        pa[x] = y;
}
int ans[100010];
int ind;
int head[100010] , next[200010] , end[200010] , label[200010];
void addedge(int a , int b , int _label) {
    static int q = ind++;
    end[q] = b;
    next[q] = head[a];
    head[a] = q;
    label[q++] = _label;
}
int dfn[100010] , low[100010];
void Tarjan(int x , int lastEdge , int depth) {
    dfn[x] = low[x] = depth;
    for(int j = head[x] ; j ; j = next[j]) {
        if (label[j] != lastEdge && dfn[end[j]])
            low[x] = min(low[x] , dfn[end[j]]);
        else if (!dfn[end[j]]) {
            Tarjan(end[j] , label[j] , depth + 1);
            low[x] = min(low[x] , low[end[j]]);
            if (low[end[j]] > dfn[x])
                ans[label[j]] = ANY;
        }
    }
}
int main() {
    int n , m;
    scanf("%d%d" , &n , &m);
    int i , j , k;
    for(i = 1 ; i <= m ; ++i)
        E[i].read(i);
    sort(E + 1 , E + m + 1);
    for(i = 1 ; i <= n ; ++i)
        pa[i] = i;
    for(i = 1 ; i <= m ;) {
        ind = 1;
        for(j = i ; E[j].len == E[i].len && j <= m ; ++j);
        for(k = i ; k < j ; ++k) {
            int tmpx = find(E[k].from);
            int tmpy = find(E[k].to);
            if (tmpx == tmpy)
                ans[E[k].id] = NONE;
            else {
                dfn[tmpx] = dfn[tmpy] = 0;
                head[tmpx] = head[tmpy] = 0;
            }
        }
        for(k = i ; k < j ; ++k) {
            if (ans[E[k].id] != NONE) {
                int tmpx = find(E[k].from);
                int tmpy = find(E[k].to);
                addedge(tmpx , tmpy , E[k].id);
                addedge(tmpy , tmpx , E[k].id);
            }
        }
        for(k = i ; k < j ; ++k) {
            if (ans[E[k].id] != NONE) {
                int tmpx = find(E[k].from);
                int tmpy = find(E[k].to);
                if (!dfn[tmpx])
                    Tarjan(tmpx , -1 , 1);
                if (!dfn[tmpy])
                    Tarjan(tmpy , -1 , 1);
            }
        }
        for(k = i ; k < j ; ++k)
            merge(E[k].from , E[k].to);
        i = j;
    }
    for(i = 1 ; i <= m ; ++i) {
        if (ans[i] == 2)
            puts("none");
        else if (ans[i] == 1)
            puts("any");
        else
            puts("at least one");
    }
    return 0;
}