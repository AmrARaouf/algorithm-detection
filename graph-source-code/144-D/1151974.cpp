//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define INF 0x3f3f3f3f
#define MAX 100005

bool myFunction (int i,int j) { return (i>j); }

struct grafo
{
    vector<int> vertice;
    vector<int> peso;
};

int custo[MAX], l;
grafo G[MAX];
int visit[MAX];

void spfa(int part, int qtdVert)
{
    queue<int> Q;
    Q.push(part);

    for ( int i=1; i<=qtdVert; i++ )
    {
        custo[i] = INF;
        visit[i] = 0;
    }

    custo[part] = 0;
    visit[part] = 1;

    while (!Q.empty())
    {
        part = Q.front();
        Q.pop();
        visit[part] = 0;

        for ( int p=0; p<G[part].vertice.size(); p++ )
        {
            int b = G[part].vertice[p];
            int w = G[part].peso[p];

            if ((w + custo[part]) < custo[b])
            {
                custo[b] = w + custo[part];

                if (!visit[b])
                {
                    Q.push(b);
                    visit[b] = 1;
                }
            }
        }
    }
}

int main()
{
    int n, m, s, v, u, w;
    double res = 0;

    scanf("%d %d %d", &n, &m, &s);

    for ( int i=0; i<m; i++ )
    {
        scanf("%d %d %d", &v, &u, &w);
        G[v].vertice.push_back(u);
        G[v].peso.push_back(w);
        G[u].vertice.push_back(v);
        G[u].peso.push_back(w);
    }

    scanf("%d", &l);

    spfa(s, n);

    for ( int i=1; i<=n; i++ )
        if ( custo[i] == l )
            res += 1.0;

        else if ( custo[i] < l )
            for ( int j=0; j<G[i].vertice.size(); j++ )
                if (( ((l-custo[i]) > 0 ) && ((l-custo[i]) < G[i].peso[j])) )
                    if ( ((l-custo[i])+(l-custo[G[i].vertice[j]])-G[i].peso[j]) == 0 )
                        res += 0.5;
                    else if ( G[i].peso[j] > ((l-custo[i])+(l-custo[G[i].vertice[j]])) )
                        res += 1;

    printf("%d\n", (int)res);

    return 0;
}