//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define inf 0x3fffffff
#define MAXM 100005

/*********
 * nlogn���·
 *********/

struct node
{
	int y;
	int dis;
	bool operator<(node a)const
	{
		return a.dis<dis;
	}
};
bool vis[MAXM];        //��¼���ʹ�ĵ�
vector<node> a[MAXM];
vector<int> wai[MAXM];
int dis[MAXM];
int n,m; 

int dijkstra(int s,int t)
{
    //��ʼ������
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++)
		dis[i]=inf;
	priority_queue<node> que;
	dis[s]=0;
	node tmp;
	tmp.y=s;
	tmp.dis=0;
	que.push(tmp);
	while(!que.empty())
	{
		node now=que.top();
		que.pop();
		int tp=now.y,tdis=now.dis;
		if(tp==t)
			return dis[t];
		vis[tp]=1;
		//ʱ���ӳ�
		for(int i=0;i<wai[tp].size();i++)
		{
			if(tdis==wai[tp][i])
				tdis++;
			if(tdis<wai[tp][i])
				break;
		}
		//
		//cout<<"from:"<<tp<<endl;
		for(int i=0;i<a[tp].size();i++)
		{
			node tmp=a[tp][i];
			//cout<<"to:"<<tmp.y<<endl;
			//cout<<"dis:"<<tdis<<endl;
			if(dis[tmp.y]>tmp.dis+tdis&&!vis[tmp.y])
			{
				node next;
				next.y=tmp.y;
				next.dis=tmp.dis+tdis;
				dis[tmp.y]=next.dis;
				que.push(next);
			}
		}
		/*for(int i=1;i<=n;i++)
		{
			cout<<dis[i]<<" ";
		}
		cout<<endl;*/
	}
	return inf;
}

int main()
{
	int i,j;
	while(~scanf("%d%d",&n,&m))
	{
		for(i=0;i<m;i++)
		{
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			node tmp;
			tmp.y=y;
			tmp.dis=c;
			a[x].push_back(tmp);
			tmp.y=x;
			a[y].push_back(tmp);
		}
		for(i=1;i<=n;i++)
		{
			int num;
			scanf("%d",&num);
			for(j=0;j<num;j++)
			{
				int tt;
				scanf("%d",&tt);
				wai[i].push_back(tt);
			}
		}
		int ans=dijkstra(1,n);
		for(i=0;i<MAXM;i++)
		{
			a[i].clear();
			wai[i].clear();
		}
		if(ans<inf)
		{
			printf("%d\n",ans);
		}
		else
		{
			printf("-1\n");
		}
	}
	return 0;
}
