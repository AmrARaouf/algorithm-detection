//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
string word[N];
int get_lower(string &word){
    int sz = word.size() , res = 0;
      for(int pos = 0; pos < sz; ++pos){
            if(word[pos] >= 'A' && word[pos] <= 'Z')
            word[pos] = 'a' + word[pos] - 'A';
            if(word[pos] == 'r') res++;
        }
    return res;
}

string a[N] , b[N];

int tam[3*N] , R[3*N] , n;
int tam_valid[3*N] , R_valid[3*N];
vector<int> adj[3*N] , G[3*N];
int t[3*N] , counter , mini[3*N] , id[3*N] , scc;
vector<int> s;
void dfs(int u){
    s.push_back(u);
    t[u] = mini[u] = counter++;
    for(int j = 0; j < adj[u].size(); ++j){
    int v = adj[u][j];
        if(t[v] == 0)
            dfs(v);
        if(t[v] != -1)
        mini[u] = min(mini[u],mini[v]);
    }

    if(t[u] == mini[u]){
        int v;
        do{
            v = s.back(); s.pop_back(); t[v] = -1;
            id[v] = scc;
            if(R[v] < R_valid[scc] || (R[v] ==R_valid[scc] && tam[v] < tam_valid[scc] ))
            R_valid[scc] = R[v] , tam_valid[scc] = tam[v];

        }while( v != u);
    scc++;
    }

}

void build(int u){
    t[u] = 1;
    for(int j = 0; j < adj[u].size(); ++j){
        int v = adj[u][j];
            if(id[u] != id[v] )
                G[id[u]].push_back(id[v]);
            if(t[v] == 0)
                build(v);
    }
}
#define ii pair<int,int>
ii dp[3*N];
ii solve(int u){
    if(dp[u] != ii(-1,-1)) return dp[u];

    ii res = ii(R_valid[u],tam_valid[u]);
    for(int j = 0; j < G[u].size(); ++j)
    {   ii aux = solve(G[u][j]);
        if( aux.first < res.first || (aux.first == res.first && aux.second < res.second))
        res = aux;
    }
    return dp[u] = res;
}

int main(){
 // freopen("in.c","r",stdin);

    int m;
    scanf("%d",&m);

    map<string,int> mapeo;
    for(int i = 0; i < m; ++i){
        cin >> word[i];

        int c = get_lower(word[i]);
        if(mapeo.find(word[i]) == mapeo.end())
        {   tam[n] = word[i].size();
            R[n] = c;
            mapeo[word[i]] = n++;
        }
    }

    int relations;
    scanf("%d",&relations);
    for(int i = 0; i < relations; ++i){
        cin >> a[i] >> b[i];
        int x = get_lower(a[i]);
        int y = get_lower(b[i]);
        if(mapeo.find(a[i]) == mapeo.end())
        {   tam[n] = a[i].size();
            R[n] = x;
            mapeo[a[i]] = n++;
        }
        if(mapeo.find(b[i]) == mapeo.end())
        {   tam[n] = b[i].size();
            R[n] = y;
            mapeo[b[i]] = n++;
        }
        x = mapeo[a[i]]; y = mapeo[b[i]];
        adj[x].push_back(y);
    }

    for(int i = 0; i < n; ++i)
    {   tam_valid[i] = 1<<30;
        R_valid[i] = 1<<30;
    }

    counter = 1;
    for(int i = 0; i < n; ++i)
        if(t[i] == 0)
            dfs(i);

    for(int i = 0; i < n; ++i)
        t[i] = 0;

    for(int i = 0; i < n; ++i)
    {    if(t[i] == 0)
            build(i);
        dp[i] = ii(-1,-1);
    }

    long long x = 0 , y = 0;
    for(int i = 0; i < m; ++i){
        ii s = solve(id[mapeo[word[i]]]);
        x += s.first; y += s.second;
    }

    cout << x <<" "<<y<<endl;


    return 0;
}


