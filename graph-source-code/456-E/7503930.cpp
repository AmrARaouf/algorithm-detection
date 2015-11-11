//Language: GNU C++


#include<math.h>
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#define pb push_back

using namespace std;
int farthest_node,farthest_dis;
bool visited[300005]={false};
int diameter[300005];
int owner[300005];
vector<int>temp;
vector<int>graph[300005];

void dfs(int index,int dis)
{
    int i;
    if(visited[index])
    return ;

    visited[index]=1;
    temp.pb(index);
    if(dis > farthest_dis)
    {
        farthest_dis=dis;
        farthest_node=index;
    }
    dis++;

    for(i=0;i<graph[index].size();i++)
    {
        if(visited[graph[index][i]])
        continue;

        dfs(graph[index][i],dis);
    }
}
int find(int index)
{
    if(owner[index]==-1 || owner[index]==index)
    return index;
    vector<int>backup;
    int it=index;int i,j;

    while(true)
    {
        if(owner[it]==-1 || owner[it]==it)
        break;
        backup.pb(it);
        it=owner[it];
    }
    for(i=0;i<backup.size();i++)
    owner[backup[i]]=owner[it];

    backup.clear();
    return owner[it];
}

int main()
{
    //freopen("C:\\Users\\NAVIGATOR\\Desktop\\Codechef\\input.txt", "r", stdin);
	//freopen("C:\\Users\\NAVIGATOR\\Desktop\\Codechef\\output.txt", "w", stdout);
    memset(owner,-1,sizeof(owner));
    int i,j,k,n,m,q,x,a,y,b,px,py;
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        graph[a].pb(b);
        graph[b].pb(a);
    }
    for(i=1;i<=n;i++)
    {
        if(visited[i])
        continue;

        temp.clear();
        farthest_dis=0;
        farthest_node=1;
        dfs(i,0);
        a=farthest_node;
        for(j=0;j<temp.size();j++)
        {
            visited[temp[j]]=0;
            owner[temp[j]]=i;
        }
        temp.clear();
        farthest_dis=0;
        farthest_node=1;
        dfs(a,0);
        diameter[i]=farthest_dis;
    }
    while(q--)
    {
        scanf("%d",&k);
        if(k==1)
        {
            scanf("%d",&x);
            int p=find(x);
            printf("%d\n",diameter[p]);
        }
        else
        {
            scanf("%d %d",&x,&y);
            if(x==y)
            continue;
            px=find(x);
            py=find(y);
            if(px==py)
            continue;
            owner[px]=py;
            diameter[py]=max(max(diameter[px],diameter[py]),(int)(ceil(diameter[px]/2.0)+ceil(diameter[py]/2.0)+1));
        }
    }
}
