//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int a[100005],x[200005];
vector<int>v[200005];
map<int,int>mp;
int rmp[200005],hash[200005];
pair<int,int>p[200005];
void dfs(int u,int fa)
{
    printf("%d ",rmp[u]);
    for(int i = 0;i<v[u].size();i++)
    {
        if(v[u][i] == fa)continue;
        dfs(v[u][i],u);
    }
}
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        mp.clear();
        int cnt = 0;
        memset(hash,0,sizeof(hash));
        for(i = 1;i<=n;i++)
        {
            scanf("%d%d",&p[i].first,&p[i].second);
            x[cnt++] = p[i].first;
            x[cnt++] = p[i].second;
        }
        sort(x,x+cnt);
        mp[x[0]] = 1;
        hash[1]++;
        rmp[1] = x[0];
        for(i = 1;i<cnt;i++)
            if(x[i]!=x[i-1])
            {
                int pre = mp[x[i-1]];
                mp[x[i]] = pre+1;
                hash[pre+1]++;
                rmp[pre+1] = x[i];
            }
            else hash[mp[x[i-1]]]++;
        int bg;
        for(i = 1;i<=mp[x[cnt-1]];i++)
        {
            if(hash[i] == 1)
            {
                bg = i;
                break;
            }
        }
        for(i = 0;i<=cnt;i++)v[i].clear();
        for(i = 1;i<=n;i++)
        {
            int x = mp[p[i].first];
            int y = mp[p[i].second];
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(bg,-1);
        printf("\n");
    }
    return 0;
}
