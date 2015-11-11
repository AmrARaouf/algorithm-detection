//Language: GNU C++11


#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define all(a)  a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define SL(n) scanf("%lld", &n)
#define PL(n) printf("%lld", n)
#define fill(a, x) memset(a, x, sizeof(a));
#define mod 1000000007
#define eps 0.000000001

using namespace std;
typedef long long LL;
typedef vector <LL> VL;
typedef map <LL, LL> ML;
typedef pair<LL, LL> PL;
typedef vector <PL> VPL;

vector<pair<int, int> > a;
vector<vector<int> > Edges;
bool Vis[105];

void dfs(int x){
    //cout << x << endl;
    for(int n=0;n<Edges[x].sz;++n){
        if(!Vis[Edges[x][n]]){
            Vis[Edges[x][n]] = 1;
            dfs(Edges[x][n]);
        }
    }
}

int main() {
    int N;
    cin >> N;
    int x, y;
    int Type;
    int Count = 0;
    Edges.resize(N + 5);
    for(int n=0;n<N;++n){
        scanf("%d%d%d", &Type, &x, &y);
        if(Type == 1){
            for(int m=0;m<a.sz;++m){
                if(x < a[m].ff && a[m].ff < y || x < a[m].ss && a[m].ss < y){
                    //cout << "      m = " << m << "  ->  Count = " << Count << endl; 
                    Edges[m].pb(Count);
                }
                if(a[m].ff < x && x < a[m].ss || a[m].ff < y && y < a[m].ss){
                    //cout << "      Count = " << Count << "  ->  m = " << m << endl; 
                    Edges[Count].pb(m);
                }
            }
            Count++;
            a.pb(mp(x, y));
        }
        else{
            fill(Vis, 0);
            --x;
            --y;
            dfs(x);
            if(Vis[y]){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
