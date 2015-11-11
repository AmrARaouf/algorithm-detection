//Language: GNU C++


#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

#define fi first
#define se second
#define mk make_pair

int n;
vector < pair < int , int > > v[2];

int main()
{
    int i,j,k;

    scanf("%d",&n);
    for (i = 1; i <= n; ++i)
        scanf("%d %d",&j,&k),v[j].push_back(mk(k,i));
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    for (i = j = 0; i < (int)v[0].size() && j < (int)v[1].size(); )
    {
        k = min(v[0][i].fi,v[1][j].fi);
        printf("%d %d %d\n",v[0][i].se,v[1][j].se,k);
        v[0][i].fi -= k,v[1][j].fi -= k;
        if (v[0][i].fi < v[1][j].fi) ++i;
        else if (v[0][i].fi > v[1][j].fi) ++j;
        else if (i < (int)v[0].size()-1) ++i;
        else ++j;
    }

    return 0;
}
