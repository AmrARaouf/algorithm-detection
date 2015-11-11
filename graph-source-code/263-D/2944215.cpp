//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX_N 100000

using namespace std;

typedef pair<int,int> pii;
int n,m,k;
vector<int> adjList[MAX_N + 100];
int parent[MAX_N + 100];
int visit[MAX_N + 100];

pii dfs(int ind,int depth)
{
    //cerr << ind << endl;
    //getchar();
    pii ret = pii(-1,-1);
    visit[ind] = depth;
    EACH(adjList[ind],it)
    {
        if(parent[*it] != -1)
        {
            if(depth - visit[*it] >= k) 
            {
                parent[*it] = 0;
                return pii(depth - visit[*it],ind);
            }
            else continue;
        }
        parent[*it] = ind;
        ret = dfs(*it,depth+1);
        if(ret.first != -1) return ret;
    }
    return ret;
}

void printAnswer(int node)
{
    if(parent[node] == 0) 
    {
        printf("%d",node);
        return;
    }
    printAnswer(parent[node]);
    printf(" %d",node);
}

int main()
{
    scanf("%d %d %d",&n,&m,&k);
    while(m--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(parent,-1,sizeof(parent));
    parent[1] = 0;
    pii a = dfs(1,0);
    assert(a.first > 0);
    printf("%d\n",a.first + 1);
    printAnswer(a.second);
    puts("");
    return 0;
}
