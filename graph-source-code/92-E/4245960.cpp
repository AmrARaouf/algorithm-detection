//Language: GNU C++


#include<iostream>
#include<cstdio>
using namespace std;

int fa[200000];
int res=0;
int n,m;

int find(int x)
{
    if(fa[x]==x)
        return x;
    return fa[x]=find(fa[x]);
}

int main()
{
    int i,j,k,u,v;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        fa[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        int x=find(u);
        int y=find(v);
        if(x==y)
            res=(res*2+1)%1000000009;
        else
            fa[x]=y;
        printf("%d\n",res);
    }
    return 0;
}

			 	 	 		 	   	 		  	 	 	