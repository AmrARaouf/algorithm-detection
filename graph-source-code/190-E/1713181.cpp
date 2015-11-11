//Language: GNU C++


#include<set>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 500009;
vector<int>v[maxn];
typedef set<int>si;
vector<si>vs;
si s1,s2;
si::iterator sit;

queue<int>q;
int main()
{
    int n,m,x,y,i;
    while(scanf("%d%d", &n, &m)!=EOF)
    {
        vs.clear();
        for(i=0; i<n; ++i) v[i].clear();

        for(i=0; i<m; ++i)
        {
            scanf("%d%d", &x, &y);
            --x; --y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(i=0; i<n; ++i)
        {
            s1.insert(i);
            sort(v[i].begin(), v[i].end());
        }

        while(!s1.empty())
        {
            x=*s1.begin();
            s1.erase(x);

            s2.clear();

            q.push(x);

            while(!q.empty())
            {
                x=q.front(); q.pop();
                s2.insert(x);

                for(sit=s1.begin(); sit != s1.end();)
                {
                    y=*sit;
                    ++sit;
                    if(!binary_search(v[x].begin(), v[x].end(), y))
                    {
                        q.push(y); s1.erase(y);
                    }
                }
            }
            vs.push_back(s2);
        }
        printf("%u\n", vs.size());
        for(i=0; i<vs.size(); ++i)
        {
            printf("%u", vs[i].size());
            for(sit=vs[i].begin(); sit != vs[i].end(); ++sit)
            {
                printf(" %d", *sit+1);
            }
            puts("");
        }
    }
    return 0;
}
