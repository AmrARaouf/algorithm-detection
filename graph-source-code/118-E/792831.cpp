//Language: GNU C++


#include<stdio.h>
#include"iostream"
#include<memory.h>
#include<vector>
using namespace std;
#define VSIZE 1010000 //顶点数
struct Edge
{
    int to;
    int next;
    bool flag;
}edge[VSIZE*10];
int head[VSIZE],Stack[VSIZE],instack[VSIZE],DFN[VSIZE],low[VSIZE],Belong[VSIZE],out[VSIZE],num[VSIZE];
int now,index,top,Bcnt;
vector<int> ans[VSIZE];
void insert(int f,int t)
{
    edge[now].to=t;
    edge[now].next=head[f];
    edge[now].flag=true;
    head[f]=now++;
}
void tarjan(int i,int fa)
{
    int j;
    DFN[i]=low[i]=++index;
    instack[i]=1;
    Stack[++top]=i;
    int h,t;
    for(h=head[i];h!=-1;h=edge[h].next)
    {
        t=edge[h].to;
        if(t==fa||!edge[h].flag)
            continue;
        ans[i].push_back(t);
        edge[h^1].flag=false;
        if(!DFN[t])
        {
            //ans[i].push_back(t);
            tarjan(t,i);
            if(low[t]<low[i])
                low[i]=low[t];
        }
        else if(instack[t]&&DFN[t]<low[i]){

            low[i]=DFN[t];
        }
    }
    if(low[i]==DFN[i])
    {
        Bcnt++;
        do
        {
            j=Stack[top--];
            instack[j]=0;
            Belong[j]=Bcnt;
            num[Bcnt]++;
        }while(j!=i);
    }
}
int main()
{
    int n,m;//n为顶点数，m为边数

    while(scanf("%d%d",&n,&m)!=EOF)
    {
        top=Bcnt=index=now=0;
        memset(DFN,0,sizeof(DFN));
        memset(head,-1,sizeof(head));
        memset(out,0,sizeof(out));
        memset(num,0,sizeof(num));
        int i,j,k,f,t;
        for(i=0;i<m;i++)
        {
            //f--;t--;
            scanf("%d%d",&f,&t);
            f--;t--;
            insert(f,t);
            insert(t,f);
        }
        for(i=0;i<n;i++)
            if(!DFN[i])
                tarjan(i,-1);
        if(Bcnt>1)
            puts("0");
        else
        {
            for(i=0;i<n;i++)
                for(j=0;j<ans[i].size();j++)
                    cout<<i+1<<" "<<ans[i][j]+1<<endl;
        }
    }
    return 0;
}
