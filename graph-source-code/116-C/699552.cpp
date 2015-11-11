//Language: GNU C++


#include<stdio.h>
#include<stdlib.h>
int n,a[2300],head[2300][2300]={0},h[2300]={0},level[2300],q[230000],add=0,use=0;
int main()
{
    bool visited[2300] = {false};
    int max=0;

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>0)
        {
            head[a[i]][h[a[i]]++]=i;
        }
        else
        {
            visited[i]=true;
            level[i]=0;
            q[add++]=i;
        }
    }
    while(use<add)
    {
        int x=q[use];
        for(int i=0;i<h[x];i++)
        {
            if(!visited[head[x][i]])
            {
                visited[x]=true;
                q[add++]=head[x][i];
                level[head[x][i]]=level[x]+1;
            }
        }
        if(level[x]>max)max=level[x];
        use++;
    }
    printf("%d\n",max+1);
}
