//Language: GNU C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

int len,tot,c[2000001],row[2000001],lit[2000001],pos[2000001],
l,n,m,first[2000001],where[4000001],next[4000001],blt[4000001];
bool b[2000001],ok;


inline void tarjan(int now){
    b[now]=true;
    lit[now]=++tot;
    row[now]=tot;
    c[++len]=now;
    pos[now]=len;
    for (int x=first[now];x;x=next[x])
    {
        if (!blt[x] && !b[where[x]]) blt[x]=now,blt[x^1]=now,tarjan(where[x]);
        if (!blt[x]) blt[x]=now,blt[x^1]=now;
        if (blt[x]==now && row[where[x]]<row[now]) row[now]=row[where[x]];
    }
    if (row[now]==lit[now])
    {
       if (len-pos[now]+1!=n) ok=false;
       len=pos[now]-1;
    }
}


inline void makelist(int x,int y){
    where[++l]=y;
    next[l]=first[x];
    first[x]=l;
}


int main(){
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    scanf("%d%d",&n,&m);
    l=1;
    memset(first,0,sizeof(first));
    for (int i=1;i<=m;i++) 
    {
        int x,y;
        scanf("%d%d",&x,&y);
        makelist(x,y),makelist(y,x);
    }
    ok=true;
    memset(b,false,sizeof(b));
    tot=0;len=0;
    tarjan(1);
    if (!ok) printf("0\n");
    else
    {
        for (int i=1;i<=n;i++)
        {
            for (int x=first[i];x;x=next[x])
               if (blt[x]==i) printf("%d %d\n",i,where[x]);
        }
    }
}
