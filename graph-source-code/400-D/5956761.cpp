//Language: MS C++


#include<cstdio>
#include<cstring>
const int N = 505;
const int M = 100005;
const int INF = 1000000005;
int d[N][N],bg[M],f[M],h[N];
int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
int main()
{
    int n,m,k,i,j,t=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&h[i]);
        for(j=1;j<=h[i];j++)
        {
            t++;
            bg[t]=i;
        }
    }
    for(i=1;i<=k;i++)for(j=1;j<=k;j++)
    {
        if(i==j)d[i][j]=0;
        else d[i][j]=INF;
    }
    for(i=1;i<=n;i++)f[i]=i;
    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if(!z)
        {
        	int a=find(x),b=find(y);
        	if(a!=b)f[a]=b;
        }
        if(d[bg[x]][bg[y]]>z)
        {
            d[bg[x]][bg[y]]=d[bg[y]][bg[x]]=z;
        }
    }
    t=0;
    for(i=1;i<=k;i++)
    {
    	t++;
    	int x=find(t);
    	for(j=2;j<=h[i];j++)
    	{
    		t++;
    		int y=find(t);
    		if(x!=y){puts("No");return 0;}
    	}
    }
    puts("Yes");
    int p;
    for(p=1;p<=k;p++)
    {
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(d[i][j]>d[i][p]+d[p][j])
                {
                    d[i][j]=d[j][i]=d[i][p]+d[p][j];
                }
            }
        }
    }
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(d[i][j]==INF)d[i][j]=-1;
            printf("%d ",d[i][j]);
        }
        puts("");
    }
    return 0;
}