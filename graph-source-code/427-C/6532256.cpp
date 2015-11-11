//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
int n,m;int intm[MAXN]; //标记进入顶点时间
int belg[MAXN]; //存储强连通分量,其中belg[i]表示顶点i属于第belg[i]个强连通分量
int stk1[MAXN]; //辅助堆栈
int stk2[MAXN]; //辅助堆栈
int v[MAXN];
int mined[MAXN];
int nummined[MAXN];
vector<int> adj[MAXN]; //邻接表
//深搜过程,该算法的主体都在这里
void Visit(int cur, int &sig, int &scc_num){
    int i;
    intm[cur] = ++sig;
    stk1[++stk1[0]] = cur;
    stk2[++stk2[0]] = cur;
    for ( i=1; i<=adj[cur][0]; ++i )
    {
        if ( 0==intm[adj[cur][i]] )
        {
            Visit(adj[cur][i],sig,scc_num);
        }
        else if ( 0==belg[adj[cur][i]] )
        {
            while ( intm[stk2[stk2[0]]]>intm[adj[cur][i]] )
            {
                -- stk2[0];
            }
        }
    }
    if ( stk2[stk2[0]]==cur )
    {
        -- stk2[0]; ++ scc_num;
        do
        {
            belg[stk1[stk1[0]]] = scc_num;
        }
        while ( stk1[stk1[0]--]!=cur );
    }
}
//Gabow算法,求解belg[1..n],且返回强连通分量个数,
int Gabow_StronglyConnectedComponent(){
    int i, sig, scc_num;
    memset(belg+1,0,sizeof(int)*n);
    memset(intm+1,0,sizeof(int)*n);
    sig = 0; scc_num = 0; stk1[0] = 0; stk2[0] = 0;
    for ( i=1; i<=n; ++i )
    {
        if ( 0==intm[i] )
        {
            Visit(i,sig,scc_num);
        }
    }
    return scc_num;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    scanf("%d",&m);
    int x,y;
    for(int i=1;i<=n;i++)
        adj[i].push_back(0);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x][0]++;
        adj[x].push_back(y);
    }
    int numfenliang=Gabow_StronglyConnectedComponent();
    for(int i=1;i<=n;i++)
        mined[i]=INT_MAX;
    for(int i=1;i<=n;i++)
        if(v[i]<mined[belg[i]])
        {
            mined[belg[i]]=v[i];
            nummined[belg[i]]=1;
        }
        else if(v[i]==mined[belg[i]])
        {
            nummined[belg[i]]++;
        }
    long long sum=0;long long aans=1;
    for(int i=1;i<=numfenliang;i++)
        if(nummined[i]>=1)
        {
         sum+=mined[i];
         aans=aans*nummined[i]%1000000007;
        }
    cout<<sum<<endl<<aans;
    return 0;
}