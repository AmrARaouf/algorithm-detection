//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<functional>
using namespace std;

const int N = 501000;
int x,d,p,n,L;
map<int, int> coll;

inline int getIndex(int x)
{
	static int num = 0;
	if (!coll.count(x))
	{
		return coll[x] = num++;
	}
	else
	{
		return coll[x];
	}
}

struct Node 
{
	int st,to,t,num;
	Node(){}
	Node(int a, int b):st(a), to(b){}
	void readin(int xx)
	{
		scanf("%d%d%d%d",&x,&d,&t,&p);
		st = x - p;
		to = x + d;
		if (t >= d)
			st = -1;
		t = t + p;
		num = xx;
	}
	bool check()
	{
		return st >= 0;
	}
	friend bool operator<(const Node &a, const Node &b)
	{
		return a.st < b.st || a.st == b.st && a.to < b.to;
	}
}node[N];

const int M = 8000000;

int head[N];
int edge[M],nxt[M],len[M];
int chze[M];
int en,pre[N],prg[N];
int dis[N], visit[N],ans[N],an;

void add(int a,int b,int l, int c = 0)
{
	if (a == b) return;
	edge[en] = b;
	chze[en] = c;
	nxt[en] = head[a];
	len[en] = l;
	head[a] = en++;
}

void spfa(int st, int to)
{
	static int queue[M];
	int h = 0, t = 1;
	queue[0] = st;
	memset(dis, 0x3f, sizeof dis);
	dis[st] = 0;
	while(h != t)
	{
		int cur = queue[h++];
		if (h == M) h = 0;
		visit[cur] = 0;
		for (int i = head[cur]; i != -1;i = nxt[i])
		{
			int tmp = edge[i];
			if (dis[tmp] > dis[cur] + len[i])
			{
				pre[tmp] = cur;
				prg[tmp] = chze[i];
				dis[tmp] = dis[cur] + len[i];
				if (!visit[tmp])
				{
					visit[tmp] = 1;
					if (dis[queue[h]] > dis[tmp])
					{
						if (--h == -1) h = M - 1;
						queue[h] = tmp;
					}
					else
					{					
						queue[t++] = tmp;
						if (t == M) t = 0;
					}
				}
			}
		}
	}

	for (int i = to;i != st;i = pre[i])
	{
		if (prg[i])
		{
			ans[an++] = prg[i];
		}
	}

	printf("%d\n%d\n",dis[to],an);
	if (an)
	{
		for (int i = an - 1;i;i--)
			printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
}

int idx[N],in;

int main()
{
	scanf("%d%d",&n,&L);
	for (int i = 1;i<=n;i++)
	{
		node[i].readin(i);
	}
	int last = 0;
	for (int i = 1;i<=n;i++)
	{
		if (node[i].check())
		{
			node[++last] = node[i];
		}
	}
	n = last;
	if (last == 0)
	{
		printf("%d\n0\n",L);
	}
	else
	{
		memset(head, -1, sizeof head);
		en = 0;
		for (int i = 1;i<=n;i++)
		{
			idx[in++] = node[i].st;
			idx[in++] = node[i].to;
		}
		idx[in++] = 0;
		idx[in++] = L;
		sort(idx,idx+in);
		int last = idx[0];
		for (int i = 1;i<in;i++)
		{
			if (idx[i] != last)
			{
				int len = idx[i] - last;
				add(getIndex(last), getIndex(idx[i]), len);
				add(getIndex(idx[i]), getIndex(last), len);
				last = idx[i];
			}
		}
		for (int i = 1;i<=n;i++)
		{
			add(getIndex(node[i].st), getIndex(node[i].to), node[i].t, node[i].num);
		}
		spfa(getIndex(0), getIndex(L));
	//	cout<<en<<' '<<in<<' '<<an<<endl;
	}
	return 0;
}
      			 				 					  		 	