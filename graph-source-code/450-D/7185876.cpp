//Language: GNU C++


#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
		int x;
		unsigned int c;
		bool operator <(const node &p)const
		{
				return p.c<c;
		}
};
vector<node>v[100005];
priority_queue<node>q;
unsigned int dj[100005];
int bi[100005];
int main()
{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		int n,m,i,k,a,b;
		unsigned int d;
		int o=0;
		memset(dj,-1,sizeof(dj));
		cin>>n>>m>>k;
		node e;
		for(i=0;i<m;i++)
		{
				cin>>a>>b>>d;
				e.x=b;
				e.c=d;
				v[a].push_back(e);
				e.x=a;
				v[b].push_back(e);
		}
		for(i=0;i<k;i++)
		{
				cin>>a>>d;
				e.x=a;
				e.c=d;
				q.push(e);
				if(dj[0]!=dj[a])o++;
				dj[a]=min(dj[a],d);
				bi[a]=1;
		}
		e.x=1;
		e.c=0;
		q.push(e);
		dj[1]=0;
		int x,sz,nx;
		unsigned int c,nc;
		while(!q.empty())
		{
				x=q.top().x;
				c=q.top().c;
				q.pop();
				if(dj[x]!=c)continue;
				dj[x]=0;
				sz=v[x].size();
				for(i=0;i<sz;i++)
				{
						nx=v[x][i].x;
						nc=v[x][i].c+c;
						if(dj[nx]>nc)
						{
								dj[nx]=nc;
								e.x=nx;
								e.c=nc;
								q.push(e);
						}
						if(dj[nx]==nc)
						{
								if(bi[nx])o++;
								bi[nx]=0;
						}
				}
		}
		cout<<o<<'\n';
}
