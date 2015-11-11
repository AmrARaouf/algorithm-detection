//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 105;
struct twosat
{
    int n;
    vector<int> ji[maxn<<1];
    bool mark[maxn<<1];
    int sta[maxn<<1],top;
    bool dfs(int x)
    {
        if(mark[x^1])
            return 0;
        if(mark[x])
            return 1;
        mark[x] = 1;
        sta[top++] = x;
        for(int i=0;i<ji[x].size();i++)
            if(!dfs(ji[x][i]))
                return 0;
        return 1;
    }
    void init(int n)
    {
        this->n = n;
        for(int i=0;i<2*n;i++)
            ji[i].clear();
        memset(mark,0,sizeof(mark));
    }
    void add(int x,int y)
    {
        ji[x].push_back(y);
    }
    bool solve()
    {
        for(int i=0;i<n*2;i+=2)
            if(!mark[i]&&!mark[i+1])
            {
                top = 0;
                if(!dfs(i))
                {
                    while(top)
                        mark[sta[--top]] = 0;
                    if(!dfs(i+1))
                        return 0;
                }
            }
        return 1;
    }
    void out()
    {
                int cnt = 0;
                for(int i=1;i<2*n;i+=2)
            if(mark[i])
                cnt++;
        printf("%d\n",cnt);
        for(int i=1;i<2*n;i+=2)
            if(mark[i])
                printf("%d ",i/2+1);
    }
}slo;

#define add slo.add
int main()
{
    int n,m,a,b,c;
    scanf("%d%d",&n,&m);
    slo.init(n);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a--;b--;
        if(c)
        {
            add(a<<1,b<<1);
            add(b<<1,a<<1);
            add(a<<1|1,b<<1|1);
            add(b<<1|1,a<<1|1);
        }
        else
        {
            add(a<<1,b<<1|1);
            add(b<<1,a<<1|1);
            add(a<<1|1,b<<1);
            add(b<<1|1,a<<1);
        }
    }
    if(!slo.solve())
        puts("Impossible");
    else
        slo.out();
}
