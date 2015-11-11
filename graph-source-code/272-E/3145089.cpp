//Language: GNU C++


#include <stdio.h>
#include <vector>

using namespace std;

const int maxn = 610000;

int n,m;
int g[maxn+1][4];
int result[maxn+1];

void init()
{
    int i,x,y;
    scanf("%d%d",&n,&m);
    for (i=1; i<=n; ++i)
        g[i][0]=0;
    for (i=1; i<=m; ++i)
    {
        scanf("%d%d",&x,&y);
        g[x][++g[x][0]]=y;
        g[y][++g[y][0]]=x;
    }
}

void work()
{
    bool change;
    int i,j,k;
    for (i=1; i<=n; ++i)
        result[i]=0;
    change=true;
    while (change)
    {
        change=false;
        for (i=1; i<=n; ++i)
        {
            k=0;
            for (j=1; j<=g[i][0]; ++j)
                if (result[i]==result[g[i][j]])
                    ++k;
            if (k>1)
            {
                change=true;
                result[i]=1-result[i];
            }
        }
    }
}

void output()
{
    for (int i=1; i<=n; ++i)
        printf("%d",result[i]);
    printf("\n");   
}

int main()
{
    //freopen("E.in","r",stdin);
    init();
    work();
    output();
    return 0;
}   