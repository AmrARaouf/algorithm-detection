//Language: GNU C++


#include <iostream>
#include <stdio.h>

using namespace std;

#define For(i,a,b) for(int i=a; i<=b; i++)
#define maxn 100002

int start[maxn],ht[maxn];
int next[3*maxn],dinh[3*maxn],val[3*maxn];
bool ok[maxn],co[maxn],chon[maxn];
int n,l,kq;

void push(int u,int v,int c)
{
    if (start[u]==0) {
        l++; start[u]=l; ht[u]=l;
    }
    l++; next[ht[u]]=l; ht[u]=l; dinh[l]=v; val[l]=c;
}
int dfs(int i)
{
    int j,t,sum=0;
    ok[i]=true;
    t=start[i];
    while (next[t]!=0) {
        t=next[t]; j=dinh[t];
        if (!ok[j]) {
            if(val[t]==1) co[j]=true;
            sum+=dfs(j)+val[t];
        }
    }
    if ((sum==0)&&(co[i])) chon[i]=true;
    return(sum);
}
main()
{
    int u,v,c;
    cin>>n;
    For(i,1,n-1) {
        cin>>u>>v>>c;
        push(u,v,c-1); push(v,u,c-1);
    }
    dfs(1);
    For(i,1,n) kq+=chon[i];
    cout<<kq<<endl;
    For(i,1,n)
    if (chon[i]) cout<<i<<" ";
}
