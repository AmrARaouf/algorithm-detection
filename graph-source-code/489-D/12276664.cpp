//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi> vvi;
typedef vector <ii> vii;
typedef vector <vii> vvii;
#define PB push_back
#define MP make_pair
#define OO (1000000000)
#define EPS (1e-9)
#define MOD (1000000007)
#define all(v) ((v).begin()),((v).end())
#define DEBUG(x) cout<< #x <<" = "<<"\""<< (x) <<"\""<<endl
void read_file(bool outToFile = true){
#ifdef LOCAL_TEST
    freopen("in.in", "rt", stdin);
    if(outToFile)
    freopen("out.out", "wt", stdout);
#endif
}
//
#define DEBUGING 0
#define nMax 3000+1+9
#define P 3000
vvi G;
vvii R;
int n, m;
bool vis[nMax][nMax];
ll C[nMax][nMax];
int H[nMax][nMax];
//
void build_C(){
    memset(C, 0, sizeof C);
    for(int i=0; i<=n; i++)
        C[i][0] = C[i][i] = 1;
    for(int i=2; i<=n; i++)
        for(int j=1; j<i; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
}
void debug(int u){
    printf("%d:", u+1);
    int sz = R[u].size();
    for(int i=0; i<sz; i++)
        printf(" (%d, %d)", R[u][i].first+1, R[u][i].second+1);
    printf("\n");
}
void read(){
    //build_C();
    G.assign(n, vi());
    R.assign(n, vii());
    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d\n", &u, &v);
        u--, v--;
        G[u].PB(v);
    }
}
void DFS(int u, int gp = P, int p = P){
    if(gp != P && p != P && u != gp)
        R[u].PB( MP(gp, p) );
    
    if(vis[u][p]) return;
    vis[u][p] = true;
    
    int sz = G[u].size();
    for(int i=0; i<sz; i++)
    {
        int v = G[u][i];
        DFS(v, p, u);
    }
}
void solve_DFS(){
    memset(vis, false, sizeof vis);
    for(int i=0; i<n; i++) DFS(i);
    for(int i=0; i<n; i++)
    {
        sort(all(R[i]));
        //R[i].resize( unique(all(R[i])) - R[i].begin() );
        if(DEBUGING) debug(i);
    }
    
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        int sz = R[i].size();
        for(int j=0; j<sz; j++)
        {
            int k = 0;
            for(k=j; k<sz && R[i][j].first == R[i][k].first; k++);
            ans += C[k-j][2];
            j = k-1;
        }
    }
    
    cout<< ans <<endl;
}
void BFS(int u){
    queue <ii> Q;
    if(!vis[u][P])
        vis[u][P] = true, Q.push( MP(P, u) );
    
    while(!Q.empty())
    {
        int gp = Q.front().first;
        u = Q.front().second;
        Q.pop();
        
        int sz = G[u].size();
        for(int i=0; i<sz; i++)
        {
            int v = G[u][i];
            if(gp != v && gp != P)
                R[v].PB( MP(gp, u) );
            if(!vis[v][u])
                vis[v][u] = true, Q.push( MP(u, v) );
        }
    }
}
void solve_BFS(){
    memset(vis, false, sizeof vis);
    for(int i=0; i<n; i++)
        BFS(i);
    
    for(int i=0; i<n; i++)
    {
        sort(all(R[i]));
        //R[i].resize( unique(all(R[i])) - R[i].begin() );
        if(DEBUGING) debug(i);
    }
    
    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        int sz = R[i].size();
        for(int j=0; j<sz; j++)
        {
            int k = 0;
            for(k=j; k<sz && R[i][j].first == R[i][k].first; k++);
            ans += C[k-j][2];
            j = k-1;
        }
    }
    
    cout<< ans <<endl;
}
void BFS1(int u){
    queue <ii> Q;
    if(!vis[u][P])
        vis[u][P] = true, Q.push( MP(P, u) );
    
    while(!Q.empty())
    {
        int gp = Q.front().first;
        u = Q.front().second;
        Q.pop();
        
        int sz = G[u].size();
        for(int i=0; i<sz; i++)
        {
            int v = G[u][i];
            if(gp != v && gp != P)
                H[gp][v]++;
            if(!vis[v][u])
                vis[v][u] = true, Q.push( MP(u, v) );
        }
    }
}
void solve(){
    memset(vis, false, sizeof vis);
    memset(H, 0, sizeof H);
    for(int i=0; i<n; i++)
        BFS1(i);
    
    ll ans = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            ans += 1LL* H[i][j] * (H[i][j]-1) /2;
    
    cout<< ans <<endl;
}
//
int main()
{
    read_file();
    while(scanf("%d %d\n", &n, &m) != EOF)
    {
        read();
        //solve_DFS();
        //solve_BFS();
        solve();
    }
}
/*
 * for while true false or xor and union int float double long bool typedef
 * struct class virtual friend public static protected return continue break
 * namespace using void if else sizeof
 * if you are reading my code wish me good luck in my exams :D
 */
