//Language: GNU C++


#include <cstdio>
const int N=100010;
struct node{int p;node *next;}h[N],rh[N],v[N*2];
int vtop=0,type[N],ff[N],d;
bool flag[2][N];
void add(int x,int y,node h[])
{
    node *tmp=&v[vtop++];
    tmp->p=y;tmp->next=h[x].next;
    h[x].next=tmp;
}
void DFS(int x,node h[],bool flag[])
{
    flag[x]=true;
    for(node *tmp=h[x].next;tmp!=NULL;tmp=tmp->next)
        if(!flag[tmp->p]&&type[tmp->p]!=1)
            DFS(tmp->p,h,flag);
}
bool check(int x,node h[],bool flag[],int chk)
{
    if(flag[x])return true;
    ff[x]=d;
    for(node *tmp=h[x].next;tmp!=NULL;tmp=tmp->next)
        if(ff[tmp->p]!=d&&type[tmp->p]!=chk)
        {
            if(check(tmp->p,h,flag,chk))return true;
        }
    return false;
}
int main()
{
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&type[i]);
        h[i].next=rh[i].next=NULL;
    }
    while(m--)
    {
        scanf("%d%d",&x,&y);
        add(x,y,h);
        add(y,x,rh);
    }
    for(int i=1;i<=n;i++)
        if(type[i]==1)
            DFS(i,h,flag[0]);
        else if(type[i]==2)
            DFS(i,rh,flag[1]);
    for(int i=1;i<=n;i++)
        if(type[i]==1)
        {
            ++d;
            if(check(i,h,flag[1],1))
                flag[1][i]=flag[0][i]=true;
        }
        else if(type[i]==2)
        {
            ++d;
            if(check(i,rh,flag[0],-1))
                flag[1][i]=flag[0][i]=true;
        }
    for(int i=1;i<=n;i++)
        printf("%d\n",flag[0][i]&flag[1][i]);
    scanf(" ");
}
