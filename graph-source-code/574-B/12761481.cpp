//Language: GNU C++


#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int minsum = 10000000, visitado[5000];
set<int> graus;
vector<vector<int> > g;

void dfs(int first, int ini, int cont, int sum){
    visitado[ini] = 1;
    if(cont == 3){
        for(int i = 0 ; i < g[ini].size() ; i++){
            if(g[ini][i] == first){
                if(sum < minsum){
                    minsum = sum;
                }
                break;
            }
        }
        visitado[ini] = 0;
        return;
    }

    for(int i = 0 ; i < g[ini].size() ; i++){
        if(!visitado[g[ini][i]] && g[g[ini][i]].size() >= 2){
            dfs(first, g[ini][i], cont+1, sum + g[g[ini][i]].size());
        }
    }
    visitado[ini] = 0;
}

int main(){
    int n, m, orig, dest;
    scanf("%d %d", &n, &m);
    memset(visitado, 0, sizeof visitado);
    g.resize(n+1);

    for(int i = 0 ; i < m ; i++){
        scanf("%d %d", &orig, &dest);
        g[orig].push_back(dest);
        g[dest].push_back(orig);
    }

    for(int i = 1 ; i <= n ; i++){
        if(g[i].size() >= 2){
            memset(visitado, 0, sizeof visitado);
            dfs(i, i, 1, g[i].size());
        }
    }

    printf("%d\n", minsum == 10000000 ? -1 : minsum-6);

    return 0;
}
