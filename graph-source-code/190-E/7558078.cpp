//Language: GNU C++


#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<ld,ld>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define MAXINT ((~0) ^ (1 << 31))
#define MAXLL ((~0) ^ ((ll)1 << 63))
#define INF ((int)2e9)
#define INFL ((ll)9e18)
#define FOR(i,j,k) for(int i = j; i < k; i++)
#define REP(i,j,k) for(int i = j; i >= k; i--)
#define setmax(i) const int maxn = (int) i;
#define setmod(i) const int MOD = (int) i;
#define all(a) a.begin(),a.end()


//srand (time(NULL));

using namespace std;

setmax(5e5+10);
int n,m,comp[maxn],c;
bool mask,mark[maxn];
vector<int> num[maxn],node[2],ans[maxn];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        int v = q.front();
        comp[v] = c;
        q.pop();
        FOR(i,0,num[v].size()) mark[num[v][i]] = true;
        FOR(i,0,node[mask].size())
        {
            if(mark[node[mask][i]]) node[!mask].pb(node[mask][i]);
            else q.push(node[mask][i]);
        }
        node[mask].clear();
        FOR(i,0,num[v].size()) mark[num[v][i]] = false;
        mask = !mask;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    FOR(i,0,m)
    {
        int a,b;
        cin >> a >> b;
        num[a].pb(b);
        num[b].pb(a);
    }
    FOR(i,1,n+1) node[mask].pb(i);


    FOR(i,1,n+1) if(!comp[i])
    {
        c++;
        bfs(i);
    }
    cout << c <<endl;

    FOR(i,1,n+1) ans[comp[i]-1].pb(i);
    FOR(i,0,c)
    {
        cout << ans[i].size() << " ";
        FOR(j,0,ans[i].size()) cout << ans[i][j] << " ";
        cout << endl;
    }
}
