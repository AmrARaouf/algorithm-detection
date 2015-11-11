//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
bool flag[3010],map[3010][3010];
int mark[3010],n,v[3010],vi;

bool dfs(int sta,int fa)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(i==fa)   continue;
        if(map[sta][i])
        {
            if(!flag[i])
            {
                flag[i]=1;
                v[vi++]=i;
                //cout<<i<<" ";
                if(dfs(i,sta)) return true;
                vi--;
                flag[i]=0;
            }
            else
            {
                for(j=vi-1;v[j]!=i;j--)
                    mark[v[j]]=0;
                mark[i]=0;
                return true;
            }
        }
    }
    return false;
}

void dfs2(int sta,int len,int fa)
{
    int i;
    mark[sta]=len;
    for(i=1;i<=n;i++)
    {
        //cout<<i<<endl;
        if(map[sta][i] && mark[i]==-1 && i!=fa)
        {
            //cout<<i<<" "<<len<<endl;
            dfs2(i,len+1,sta);
        }
    }
}

int main()
{
    int i,a,b;
    while(~scanf("%d",&n))
    {
        memset(map,0,sizeof(map));
        memset(mark,-1,sizeof(mark));
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            map[a][b]=1;
            map[b][a]=1;
        }
        memset(flag,0,sizeof(flag));
        vi=1;   v[0]=1;
        flag[1]=1;
        dfs(1,-1);
        for(i=1;i<=n;i++)
            if(mark[i]==0)
            {
                //cout<<i<<endl;
                dfs2(i,0,-1);
            }
        for(i=1;i<n;i++)
            printf("%d ",mark[i]);
        printf("%d\n",mark[n]);
    }
    return 0;
}
