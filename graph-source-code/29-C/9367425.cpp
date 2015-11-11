//Language: GNU C++


#include <map>
#include <cstdio>
#include <vector>
#include <iterator>
using namespace std;
map< int, vector<int> >adj;
void dfs(int node, int prev){
    printf("%d ", node);
    for (int i = 0; i < adj[node].size(); i++){
        if (adj[node][i] == prev) continue;
        dfs(adj[node][i], node);
    }
}
int main(){
    int n, C = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (map< int, vector<int> >::iterator it = adj.begin(); it != adj.end(); it++){
        if (it->second.size() == 1){
            C = it->first;
            break;
        }
    }
    dfs(C, -1);
    //system("pause");
}