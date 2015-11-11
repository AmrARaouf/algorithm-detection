//Language: GNU C++


#include <cstdio>
#include <vector>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ;i++)
struct Edge{
    int s,t,id;
    Edge(int s,int t,int id) : s(s) , t(t) , id(id) {}
    Edge(){}
};

// ============== 閉路検出用関数 ここから ============== 
Edge e[100000];
vector<Edge> pre_graph[100000];
int pre_depth[100000];
int pre_parent[100000];
int used_edge[100000];
void pre_dfs(int v){
    for(int i = 0 ; i < pre_graph[v].size() ; i++){
        int u = pre_graph[v][i].t;
        int eid = pre_graph[v][i].id;
        if( pre_depth[u] == -1 ){
            used_edge[eid] = true;
            pre_depth[u] = pre_depth[v]+1;
            pre_parent[u] = v;
            pre_dfs(u);
        }
    }
}
vector<int> getCycle(int v,int u){
    vector<int> ans;
    //高さが同じになるように調節する
    if( pre_depth[v] < pre_depth[u] ) swap(v,u);
    while( pre_depth[v] > pre_depth[u] ){
        ans.push_back(v);
        v = pre_parent[v];
    }
    //高さが同じになったら両方を1つずつ
    while( u != v ){
        ans.push_back(u);
        ans.push_back(v);
        u = pre_parent[u];
        v = pre_parent[v];
    }
    ans.push_back(v); // 最後は共通祖先をサイクルに加えてるだけなので、vでもuでも良い。
    return ans;
}
// ============== 閉路検出用関数 ここまで ============== 

// ============== 閉路圧縮済グラフでのLCA構築・LCAクエリ応答 ここから ============== 
int belong[100000];
int haveLoop[100000] = {};

vector<Edge> graph[100000];
int depth[100000];
int parent[20][100000];
int weight[20][100000]; // weight[i][j] := [i,i+2^j)が含む重み

void dfs(int v){
    for(int i = 0 ; i < graph[v].size() ; i++){
        int u = graph[v][i].t;
        if( depth[u] == -1 ){
            depth[u] = depth[v]+1;
            parent[0][u] = v;
            weight[0][u] = haveLoop[u];
            dfs(u);
        }
    }
}
void generateLCA(){
    for(int i = 1 ; i < 20 ; i++){
        for(int j = 0 ; j < 100000 ; j++){
            if( parent[i-1][j] != -1 ){
                parent[i][j] = parent[i-1][parent[i-1][j]];
                weight[i][j] = weight[i-1][parent[i-1][j]] + weight[i-1][j];
            }
        }
    }
}

// 再掲: weight[i][j] := [i,i+2^j)が含む重み
int getPathWeight(int v,int u){
    int ans = 0;
    if( depth[v] < depth[u] ) swap(v,u);
    for(int i = 19 ; i >= 0 ; i--){
        if( (depth[v] - depth[u]) >> i & 1){
            ans += weight[i][v];
            v = parent[i][v];
        }
    }
    
    if( u == v ) return ans + weight[0][v];
    
    for(int i = 19 ; i >= 0 ; i--){
        if( parent[i][v] != parent[i][u] ){
            ans += weight[i][v];
            ans += weight[i][u];
            v = parent[i][v];
            u = parent[i][u];
        }
    }
    ans += weight[0][v] + weight[0][u];
    v = parent[0][v];
    
    return ans + weight[0][v];
}

// ============== 閉路圧縮済グラフでのLCA構築・LCAクエリ応答 ここまで ============== 

int pow2[100001];
int main(){
    //　初期化
    rep(i,100000) pre_depth[i] = pre_parent[i] = depth[i] = belong[i] = -1;
    rep(i,20)rep(j,200000) parent[i][j] = -1;
    rep(i,20)rep(j,200000) weight[i][j] = 0;
    pow2[0] = 1;
    for(int i = 1 ; i <= 100000 ; i++) pow2[i] = ( pow2[i-1] * 2 ) % 1000000007;
    
    // グラフ入力・全域木構築
    int n,m,q;
    scanf("%d%d",&n,&m);
    rep(i,m){
        scanf("%d%d",&e[i].s,&e[i].t);
        e[i].s--,e[i].t--,e[i].id=i;
        pre_graph[e[i].s].push_back(Edge(e[i].s,e[i].t,e[i].id));
        pre_graph[e[i].t].push_back(Edge(e[i].t,e[i].s,e[i].id));
    }
    pre_depth[0] = 0;
    pre_dfs(0);
    
    // 閉路検出+グラフ(木)再構築
    int K = 0;
    for(int i = 0 ; i < m ; i++){
        if( !used_edge[i] ){
            vector<int> cycle = getCycle(e[i].s,e[i].t);
            for(int j = 0 ; j < cycle.size() ; j++){
                belong[cycle[j]] = K;
            }
            haveLoop[K] = 1;
            K++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if( belong[i] == -1 ){
            belong[i] = K++;
        }
    }
    
    for(int i = 0 ; i < m ; i++){
        int u = belong[e[i].s];
        int v = belong[e[i].t];
        // 別に自己辺・重複辺が存在しても構築の仕方によっては問題ない
        graph[u].push_back(Edge(u,v,i));
        graph[v].push_back(Edge(v,u,i));
    }
    depth[0] = 0;
    weight[0][0] = haveLoop[0];
    dfs(0);
    
    // LCA構築・応答
    generateLCA();
    scanf("%d",&q);
    for(int i = 0 ; i < q ; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        u--,v--;
        u = belong[u];
        v = belong[v];
        printf("%d\n",pow2[getPathWeight(u,v)]);
    }
}