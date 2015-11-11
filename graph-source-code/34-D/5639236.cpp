//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <memory.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;


/*int n;
int a[105];
int main(void)
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int diff = 1000000;
    int x;
    for (int i = 0; i < n-1; i++)
    {
        int tmp = abs(a[i+1] - a[i]);
        if (tmp < diff)
        {
            x = i;
            diff = tmp;
        }
    }
    int tmp = abs(a[0] - a[n-1]);
    if (tmp < diff)
    {
        x = n-1;
        diff = tmp;
    }
    printf("%d %d\n", x + 1, (x + 1) % n + 1);
    return 0;
}*/

/*int a[105];

int main(void)
{
    int n, m;
    scanf("%d%d",&n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            total -= a[i];
            m--;
        } else
            break;
        if (!m)
            break;
    }
    printf("%d\n",total);

}*/

/*char S[1000];

string String(int x)
{
    string res="";
    if (!x)
    {
        return "0";
    }
    while (x)
    {
        res += (x % 10 + 48);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(void)
{
    set<int> s;
    scanf("%s",&S);
    string a = (string) S;
    while (a.find(',') != -1)
    {
        int pos = a.find(',');
        string b = a.substr(0, pos);
        int x = atoi(b.c_str());
        s.insert(x);
        a = a.substr(pos+1);
    }
    s.insert(atoi(a.c_str()));
    set<int>::iterator it, itr = s.end();
    it = s.begin();
    int l = -1;
    int r = -1;
    string res = "";
    while (it != itr)
    {
        if (*it - r > 1)
        {
            if (l != -1)
            {
                if (res.length() != 0)
                {
                    res += ",";
                }
                if (l == r)
                    res += String(l);
                else
                    res += String(l) + "-" + String(r);
            }
            l = *it;
            r = *it;
        } else
            r++;
        it++;
    }
    if (l != -1)
    {
        if (res.length() != 0)
        {
            res += ",";
        }
        if (l == r)
            res += String(l);
        else
            res += String(l) + "-" + String(r);
    }
    printf("%s\n",res.c_str());
    return 0;
}*/

int n,r1,r2;
vector<vector<int> > g;
vector<int> ans;

void dfs(int v, int p = -1)
{
    ans[v] = p;
    for (int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if (u != p)
            dfs(u, v);
    }
}

int main(void)
{
    scanf("%d%d%d",&n,&r1,&r2);
    r1--;
    r2--;
    int next = 0;
    g.resize(n);
    for (int i = 0; i < n-1; i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        if (next == r1)
            next++;
        g[next].push_back(x);
        g[x].push_back(next);
        next++;
    }
    ans.resize(n);
    dfs(r2);
    vector<int> _ans;
    for (int i = 0; i < n; i++)
        if (i != r2)
            _ans.push_back(ans[i]);
    for (int i = 0; i < _ans.size(); i++)
        printf("%d%c", _ans[i] + 1, (i == (_ans.size() - 1)) ? '\n' : ' ');
    return 0;
}