//Language: MS C++


#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int m, n;
vector<vector<int> > g, g1;
int f[100005], inter[100005];
bool usd[100005];

void dfs(int v)
{
    usd[v] = 1;
    ++inter[v];
    for(int i = 0; i < g[v].size(); ++i)
    {
        int u = g[v][i];
        if(!usd[u])
        {
            dfs(u);
        }
    }
}

void dfs1(int v)
{
    ++inter[v];
    usd[v] = 1;
    if(f[v] == 1)
        return;
    for(int i = 0; i < g1[v].size(); ++i)
    {
        int u = g1[v][i];
        if(!usd[u])
        {
            dfs1(u);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%d", &f[i]);
    int fr, to;
    g1.resize(n);
    g.resize(n);
    for(int i = 0; i < m; ++i)
    {
        scanf("%d%d", &fr, &to);
        --fr, --to;
        g1[to].push_back(fr);
        g[fr].push_back(to);
    }

    for(int i = 0; i < n; ++i)
        if(!usd[i] && f[i] == 1)
            dfs(i);
    memset(usd, 0, sizeof(usd));
    for(int i = 0; i < n; ++i)
        if(!usd[i] && f[i] == 2)
            dfs1(i);

    for(int i = 0; i < n; ++i)
        printf("%d\n", inter[i] > 1 ? 1 : 0);
    return 0;
}

/*
5 4
1 0 1 0 2
1 2
2 3
3 4
4 5
*/

/*
int n, mas[100005];

int beg[100005], bsz = 0;
int a1[100005], a2[100005], asz = 0;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &mas[i]);


    for(int i = 1; i <= n+1; ++i)
    {
        int df = mas[i] - mas[i-1];
        if(df > 0)
        {
            while(df)
            {
                beg[bsz++] = i;
                --df;
            }
        }
        else if(df < 0)
        {
            while(df)
            {
                --bsz;
                a1[asz] = beg[bsz];
                a2[asz] = i-1;
                ++asz;
                ++df;
            }
        }
    }
    printf("%d\n", asz);
    for(int i = 0; i < asz; ++i)
        printf("%d %d\n", a1[i], a2[i]);
    return 0;
}
*/

/*
char str[400005];
vector<string> pref, suf;
int main()
{
    scanf("%s", &str);
    int last = -1;
    int l = strlen(str);
    bool was = 0;
    for(int i = 0; i < l; ++i)
    {
        if(str[i] == '.')
        {
            if(!was)
            {
                if(i == 0)
                {
                    printf("NO\n");
                    return 0;
                }
                pref.push_back(string(str, str+i));
                was = 1;
                last = i;
                continue;
            }
            if(i - last - 1 < 2 || i - last - 1 > 11)
            {
                printf("NO\n");
                return 0;
            }
            int b2 = min(last + 4, i - 1); 
            suf.push_back(string(str+last+1, str+b2));
            pref.push_back(string(str+b2, str+i));
            last = i;
        }
    }
    if(last == l-1 || l-last > 4 || pref.size() != suf.size() + 1)
    {
        printf("NO\n");
        return 0;
    }
    suf.push_back(string(str+last+1, str+l));
    int k = pref.size();
    printf("YES\n");
    for(int i = 0; i < k; ++i)
        printf("%s.%s\n", pref[i].c_str(), suf[i].c_str());
    return 0;
}
*/
/*
.
*/

/*
int main()
{
    int b, n, a[105];
    double md = 0;
    scanf("%d%d", &n, &b);
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        md += a[i];
    }
    md += b;
    md /= n;
    for(int i = 0; i < n; ++i)
        if(a[i] > md)
        {
            printf("-1\n");
            return 0;
        }
    for(int i = 0; i < n; ++i)
        printf("%.7lf\n", md  - a[i]);

    return 0;
}
*/
