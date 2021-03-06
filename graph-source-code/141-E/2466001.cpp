//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct P
{int w,num,x,y;}a[100010];
int n,m,p[1010],ans[1010],cnt,S,M;
inline int find(int x)
{return p[x] == x ? x : p[x] = find(p[x]);}
inline bool cmp(const P & a, const P & b)
{return a.w < b.w;}
int main()
{
    scanf("%d%d",&n,&m);
    if(~n&1){puts("-1");return 0;}
    for(int i = 1; i <= m; i++)
    {
        char s[2];
        scanf("%d%d%s",&a[i].x,&a[i].y,s);
        if(s[0] == 'S') a[i].w = 0;
        else a[i].w = 1;    
        a[i].num = i;
    }
    sort(a+1,a+m+1,cmp);
    for(int i = 1; i <= n; i++)p[i] = i;
    for(int i = m; i >= 1; i--)
    if(find(a[i].x) != find(a[i].y))
    {
        p[find(a[i].x)] = find(a[i].y);
        if(!a[i].w) a[i].w = -1;
    }
    S = M = 0;
    sort(a+1,a+m+1,cmp);
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= m; i++)
    if(a[i].w > 0 || S < (n-1>>1))
    {
        if(find(a[i].x) != find(a[i].y))
        {
            p[find(a[i].x)] = find(a[i].y);
            ans[++cnt] = a[i].num;
            if(a[i].w>0) M ++;
            else S ++;
        } 
    }
    if(M < (n-1>>1) || S < (n-1>>1))
    {puts("-1");return 0;}
    printf("%d\n",n-1);
    for(int i = 1; i <= cnt; i++)
    printf("%d ",ans[i]);
    return 0;
}
