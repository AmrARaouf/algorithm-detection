//Language: GNU C++


#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//hoj 1338
const int N = 500004;
int n,m;
vector<int> vec[N],V[N];

int p[N];

int find(int x) { return p[x] == x? x : p[x] =find(p[x]); }

bool vis[N];

vector<int> A;

int total[N];

int main()
{
    while (cin >> n >> m)
    {
        int a,b;
        for (int i = 1; i <= n; ++i) vec[i].clear(), V[i].clear(), p[i] = i;

        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d",&a,&b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        
        int id = 1;
        for (int i = 1; i <= n; ++i)
        {
            sort(vec[i].begin(),vec[i].end());
            if (vec[i].size() < vec[id].size())
            {
                id = i;
            }
        }

        memset(vis,0,sizeof(vis));
        A.clear();
        A.push_back(id);
        for (int i = 0; i < vec[id].size(); ++i)
        {
            vis[vec[id][i]] = 1;
            A.push_back(vec[id][i]);
        }

        memset(total,0,sizeof(total));
        int cnt = 0;
        for (int i = 1; i <= n; ++i) if (!vis[i])
        {
            p[i] = id;
            ++cnt;
            for (int j = 0; j < vec[i].size(); ++j)
            {
                ++total[vec[i][j]];
            }
        }

        int len = A.size();
        
        sort(A.begin(), A.end());
        for (int i = 0; i < len; ++i){
            if (total[A[i]] != cnt && find(id) != find(A[i]))
                p[find(A[i])] = id;
            for (int j = i + 1; j < len; ++j)
            {
                if (binary_search(vec[A[i]].begin(),vec[A[i]].end(),A[j]) == false)
                {
                    if (find(A[i]) != find(A[j])) p[find(A[i])] = A[j];
                }
            }
        }

        int num = 0;
        memset(vis,0,sizeof(vis));
        for (int i = 1; i <= n; ++i)
        {
            if (!vis[find(i)]) ++ num;
            vis[find(i)] = 1;
            V[find(i)].push_back(i);
        }

        printf("%d\n",num);
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i])
            {
                printf("%d",V[i].size());
                for (int j = 0; j < V[i].size(); ++j)
                {
                    printf(" %d",V[i][j]);
                }
                puts("");
            }
        }

    }
}
