//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
queue<int>que;
struct data{
    int v,num,to;
};
vector<data>a[300005];
long long dis[300005];
int vis[300005];
queue<int>q;
int n,m;
void spfa(int k)
{
    int i;
    while(!q.empty()) q.pop();
    for(i=1;i<=n;i++)
        dis[i]=999999999999999;
    memset(vis,0,sizeof(vis));
    dis[k]=0;
    q.push(k);
    while(!q.empty())
    {
        int now=q.front();
        q.pop();
        vis[now]=0;
        int size=(int)a[now].size();
        for(i=0;i<size;i++)
        {
            if(dis[a[now][i].to]>dis[now]+a[now][i].v)
            {
                dis[a[now][i].to]=dis[now]+a[now][i].v;
                if(!vis[a[now][i].to])
                {
                    q.push(a[now][i].to);
                    vis[a[now][i].to]=1;
                }
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int p,q,v;
        scanf("%d%d%d",&p,&q,&v);
        data temp;
        temp.to=q;
        temp.v=v;
        temp.num=i;
        a[p].push_back(temp);
        temp.to=p;
        a[q].push_back(temp);
    }
    int st;
    scanf("%d",&st);
    spfa(st);
    long long sum=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(i!=st){
            int size=a[i].size();
            long long mi=99999999999;
            int mii;
            for(int j=0;j<size;j++){
                if(dis[i]==dis[a[i][j].to]+a[i][j].v){
                    if(a[i][j].v<mi){
                        mi=a[i][j].v;
                        mii=a[i][j].num;
                    }
                }
            }
            sum+=mi;
            que.push(mii);
        }
    }
    printf("%I64d\n",sum);
    while(!que.empty()){
        int temp=que.front();
        que.pop();
        if(que.empty())
            printf("%d\n",temp);
        else printf("%d ",temp);
    }
}
