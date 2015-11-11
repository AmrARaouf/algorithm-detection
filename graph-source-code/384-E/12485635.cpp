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
#define nMax 200000+9
vvi G;
int n, m;
ii A[nMax];
int I[nMax];
int L[nMax], B[nMax], E[nMax];
int timer;
int FT[nMax + 1];
//
void DFS(int u){
    B[u] = ++timer;
    int sz = G[u].size();
    for(int i=0, v; i<sz; i++)
    {
        v = G[u][i];
        if(B[v] == -1)
            L[v] = L[u] + 1, DFS(v);
    }
    E[u] = timer;
}
bool cmp(ii l, ii r){
    return B[ l.second ] < B[ r.second ];
}
void insert(int idx, int val){
    while(idx <= n)
    {
        FT[idx] += val;
        idx += (idx & -idx);
    }
}
int freqTo(int idx){
    int sum = 0;
    while(idx > 0)
    {
        sum += FT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
void debug(){
    for(int i=0; i<n; i++)
        printf("%d %d %d %d %d\n", i, A[i].second, A[i].first, B[A[i].second], E[A[i].second]);
    printf("\n");
}
//
int main()
{
    read_file();
    while(scanf("%d %d\n", &n, &m) != EOF)
    {
        G.assign(n, vi());
        for(int i=0; i<n; i++)
            scanf("%d ", &A[i].first), A[i].second = i;
        
        for(int i=0, u, v; i<n-1; i++)
            scanf("%d %d\n", &u, &v), G[--u].PB(--v), G[v].PB(u);
        
        memset(B, -1, sizeof B);
        memset(FT, 0, sizeof FT);
        timer = -1;
        L[0] = 0;
        DFS(0);
        sort(A, A+n, cmp);
        for(int i=0; i<n; i++)
            I[ A[i].second ] = i;
        //debug();
        
        while(m--)
        {
            int cmd;    scanf("%d\n", &cmd);
            if(cmd == 1)
            {
                int x, v;  scanf("%d %d\n", &x, &v);
                x--;
                int t = x;
                x = I[x];
                if(L[t]%2 == 1) v *= -1;
                insert(B[t]+1, v);
                insert(E[t]+1+1, -v);
            }
            else
            {
                int x;  scanf("%d\n", &x);
                x--;
                int t = x;
                x = I[x];
                int sum = freqTo(x+1);
                if(L[t]%2 == 1) sum *= -1;
                printf("%d\n", A[x].first + sum);
                //DEBUG(sum);
            }
        }
    }
}
