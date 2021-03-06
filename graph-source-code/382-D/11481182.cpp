//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
int move[4][2]={0,1,0,-1,1,0,-1,0},max1,max2,ans,n,m;
char yo[]="<>^v",s[2005][2005];
int dfs(int x,int y)
{
    int a,b,c=0,d=0;
    ans++;
    for(int i=0;i<4;i++)
    {
        a=x+move[i][0];
        b=y+move[i][1];
        if(a<0||a>=n||b<0||b>=m||s[a][b]!=yo[i]) continue;
        if(s[x][y]=='#')
        {
            c=dfs(a,b);
            if(c>max1)
            {
                max2=max1;
                max1=c;
            }
            else if(c>max2) max2=c;
        }
        else d=max(d,dfs(a,b));
    }
    return d+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    ans=max1=max2=0;
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='#') dfs(i,j);
    if(ans!=n*m)
    {
        printf("-1\n");
        return 0;
    }
    if(max1==max2) ans=max1+max2;
    else ans=2*max1-1;
    printf("%d\n",ans);
    return 0;
}
