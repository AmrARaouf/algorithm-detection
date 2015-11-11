//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define X first
#define Y second
#define mp make_pair
#define fill(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)a.size())

using namespace std;

typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

int g[222][222], d[222][222], v[222], p[222],f[222], n, m, x, y, z;

void work(int u, int v)
{
  //  cout<<u<<"  "<<v<<endl;
    vector<pii> a, b;
    for(int i = 1; i <= n; ++i)
    {
        //cout<<i<<endl;
       // cout<<d[u][i]<<" * "<<d[v][i]<<endl;
        a.push_back(mp(d[u][i], d[v][i]));
    }
    sort(a.begin(), a.end());
    int tt = sz(a), d = INF;
    for(int i = 0; i < tt; ++i)
    {

        while(sz(b) && b.back().Y <= a[i].Y) b.pop_back();
        b.push_back(a[i]);
    }

    if(b.size() == 1)
        if(b[0].X < b[0].Y) d = b[0].X << 1;
        else d = b[0].Y << 1;

    tt = sz(b);
    for(int i = 1; i< tt; ++i)
        d = min(d, g[u][v] + b[i - 1].X + b[i].Y);

    z = min(z, d);
}

int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d%d", &n, &m);
    fill(g, INF);
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        z*=2;
        g[x][y]=g[y][x]=min(g[x][y],z);
    }
    for(int i=1; i<=n; i++)
        g[i][i]=0;
    memcpy(d,g,sizeof d);
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);

    z=0x3f3f3f3f;
   // cout<<z<<endl;
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
                work(i,j);
    printf("%.8lf\n",z/4.0);
    return 0;
}
