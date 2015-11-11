//Language: MS C++


#include<iostream>
#include<cstring>
#define N 50005
using namespace std;
struct node{
	int v,next;
}ed[N*2];
int head[N],use[N],ans[N],que[N];
int n,r1,r2,m,num;
void addedge(int u,int v)
{
	ed[num].v=v;
	ed[num].next=head[u];
	head[u]=num++;
}
void init()
{
	int i,j;
	memset(head,-1,sizeof(head));
	num=0;
	cin>>n>>r1>>r2;
	for(i=1;i<=n;i++)
		if(i!=r1)
		{
			cin>>j;
			addedge(i,j);
			addedge(j,i);
		}
}
void bfs()
{
	int i,j,f,r;
	memset(use,0,sizeof(use));
	f=r=0;
	que[r++]=r2;
	use[r2]=1;
	while(f<r)
	{
		i=que[f++];
		for(j=head[i];j!=-1;j=ed[j].next)
			if(!use[ed[j].v])
			{
				use[ed[j].v]=1;
				que[r++]=ed[j].v;
				ans[ed[j].v]=i;
			}
	}
	for(i=1;i<=n;i++)
		if(i!=r2)
			cout<<ans[i]<<' ';
	cout<<endl;
}
int main()
{
	init();
	bfs();
	return 0;
}
