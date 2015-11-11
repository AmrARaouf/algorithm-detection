//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#define inf 0x3f3f3f3f
#define LL long long
#define maxn 101000
#define IN freopen("in.txt","r",stdin);
using namespace std;

struct node{
    int pos,rep;
};

int n;
vector<node> edge[maxn];
bool visit[maxn];
int path[maxn],paths;

int dfs(int x,int repair)
{
    int ans=0;
    for(int i=0;i<edge[x].size();i++){
        int tmp=edge[x][i].pos;
        if(!visit[tmp]){
            visit[tmp]=1;
            if(edge[x][i].rep==2) ans+=dfs(tmp,2);
            else ans+=dfs(tmp,1);
        }
    }

    if(repair==2&&ans==0){
        path[paths++]=x;
        return 1;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    //IN;

    while(~scanf("%d",&n))
    {
        memset(visit,0,sizeof(visit));
        paths=0;memset(edge,0,sizeof(edge));

        for(int i=1;i<n;i++){
            int a,b,c;
            node tmp;
            scanf("%d %d %d",&a,&b,&c);
            tmp.pos=b;tmp.rep=c;
            edge[a].push_back(tmp);
            tmp.pos=a;tmp.rep=c;
            edge[b].push_back(tmp);
        }

        visit[1]=1;
        dfs(1,1);

        printf("%d\n",paths);
        for(int i=0;i<paths;i++){
            printf("%d ",path[i]);
        }
        printf("\n");
    }
    return 0;
}

   		   	 		  		 		 		 		  		 	