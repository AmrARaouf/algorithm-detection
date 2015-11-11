//Language: GNU C++


#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back 

struct node
{
    long long next;
    long long val;
}t;
long long n,m,s,e;
long long d[1001],area[1001][1001];
vector <node> v[1001];
queue <long long> q;
bool b[1005];

void spfa(int s) 
{
    while(!q.empty()) q.pop();
    memset(b, 0,sizeof(b));
    q.push(s);
    for (int i = 0; i <= m; i++) d[i] =0x7fffffffffffffffLL;
    d[s] = 0;
    while (!q.empty()) 
    {
        int cur = q.front();
        q.pop();
        b[cur] = 0;
        for (int i = 0; i < v[cur].size(); i++) 
        {
            if (d[v[cur][i].next] > d[cur] + v[cur][i].val) 
            {
                d[v[cur][i].next] = d[cur] + v[cur][i].val;
                if (!b[v[cur][i].next])
                {
                    b[v[cur][i].next] = 1;
                    q.push(v[cur][i].next);
                }
            }
        }
    }
}

int main()
{
    long long i,a,j,b;
    while(cin >> m >> n >> s >> e)
    {
        for( i=1; i<=n; ++i)
        {
            cin >> a >> t.next >> t.val;
            v[a].PB(t);
            b=a;
            a=t.next;
            t.next=b;
            v[a].PB(t);
        }
        for( i=1; i<=m; ++i)
        {
            spfa(i);
            for( j=1; j<=m; ++j)
            {
                area[i][j]=d[j];
            }
        } 
        for( i=0; i<1001; ++i) v[i].clear();
        for( i=1; i<=m; ++i)
        {
            cin >> a >> b;
            for( j=1; j<=m; ++j)
            {
                if(i!=j)
                {
                    if(area[i][j]<=a) 
                    {
                        t.next=j;
                        t.val=b;
                        v[i].PB(t);
                    }
                }
            }
        }
        spfa(s);
        if(s==e) printf("0\n");
        else if(d[e]==0 || d[e]==0x7fffffffffffffffLL) printf("-1\n");
        else cout << d[e] << endl;
    }
    return 0;
}



/*
4 4
1 3
1 2 3
1 4 1
2 4 1
2 3 5
2 7
7 2
1 2
7 7

4 3
1 4
1 2 1
2 3 1
3 4 1
1 10
1 10
1 10
1 10
*/











