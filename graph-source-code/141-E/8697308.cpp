//Language: GNU C++0x


#include <bits/stdc++.h>

using namespace std;

typedef pair <int ,int> pii;
#define X first
#define Y second
#define mp make_pair

const int maxn = 1021;
const int maxm = 100 * 1000 + 21;

int n, m, par[maxn], col[2];
pii e[maxm];
bool mark[maxm];
deque <pii> q;
vector <pii> edge;
vector <int> ans;

int find_par(int v)
{
    return (par[v] < 0 ? v : par[v] = find_par( par[v] ) );
}


bool merg(int x, int y)
{
    x = find_par(x);
    y = find_par(y);

    if(x == y)
        return false;

    if(par[x] < par[y])
        swap(x, y);

    par[y] += par[x];
    par[x] = y;
    return true;
}


bool solve(int k)
{
    memset(par, -1, sizeof par);
    q.clear();

    for(int i = 0; i < m; i++)
    {
        if(edge[i].Y == k)
            q.push_back( edge[i] );
        else
            q.push_front( edge[i] );
    }

    int cnt = 0;

    while(cnt < n - 1 && !q.empty())
    {
        int ind = q.front().X;
        int v = e[ind].X;
        int u = e[ind].Y;
        int c = q.front().Y;

        if(merg(u, v))
        {
            if(c == k)
                mark[ind] = true;
            cnt++;
        }

        q.pop_front();
    }

    if(cnt < n - 1)
        return false;

    return true;
}


void solve2(int k)
{
    q.clear();

    for(int i = 0; i < m; i++)
        if(edge[i].Y == k)
            q.push_back( edge[i] );

    int cnt = col[k];

    while(cnt < n / 2 && !q.empty())
    {
        int ind = q.front().X;
        int v = e[ind].X;
        int u = e[ind].Y;

        if(merg(u, v))
            cnt++,
            cout << ind + 1 << " ";

        q.pop_front();
    }
}


int main()
{
    cin >> n >> m;

    char x;
    for(int i = 0, a, b; i < m; i++)
        cin >> a >> b >> x,
        a--, b--,
        e[i] = mp(a, b),
        edge.push_back( mp(i, (x == 'S' ? 0 : 1) ) );

    //for(int i = 0; i < m; i++)
      //  cerr << edge[i].Y << " ";

    if(n % 2 == 0 || !solve(0) || !solve(1))
    {
        cout << "-1";
        return 0;
    }

    memset(par, -1, sizeof par);

    for(int i = 0; i < m; i++)
        if(mark[i])
            ans.push_back(i + 1),
            merg(e[i].X, e[i].Y),
            col[ edge[i].Y ]++;

    if( col[0] > n / 2 || col[1] > n / 2 )
    {
        cout << "-1";
        return 0;
    }

    cout << n - 1 << "\n";

    for(auto &u : ans)
        cout << u << " ";

    solve2(0);
    solve2(1);
}

  		  	  						   							   			