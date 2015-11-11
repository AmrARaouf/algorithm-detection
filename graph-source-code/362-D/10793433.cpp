//Language: GNU C++11


#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const int inf=100009;
typedef long long ll;
const ll MX=1e9;
int tree[inf];
ll sz[inf];
int rnk[inf];
set<pair<ll,int> >s;
int root(int a)
{
	while(a!=tree[a])
	{
		tree[a]=tree[tree[a]];
		a=tree[a];
	}
	return a;
}
int main()
{
	int n,m,p,q,a,b;
	ll c;
	pair<int,int>lst;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for (int i=1;i<=n;++i)
		tree[i]=i;
	for (int i=0;i<m;++i)
	{
		scanf("%d%d%I64d",&a,&b,&c);
lst.first=a,lst.second=b;
		a=root(a);
		b=root(b);
		
		if (a==b)
			sz[a]+=c;
		else
		{
			if (rnk[a]<rnk[b])
				swap(a,b);
			sz[a]+=sz[b]+c;
			sz[b]=-1;
			tree[b]=a;
			if (rnk[a]==rnk[b])
				++rnk[a];
		}
	}
	for (int i=1;i<=n;++i)
		if (sz[i]!=-1)
			s.insert(make_pair(sz[i],i));
	int g=s.size();
	if (g<q || g-p>q || (g==n && q==n && p>0))
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	while((int)s.size()>q && p)
	{
		a=s.begin()->second;
		s.erase(s.begin());
		b=s.begin()->second;
		s.erase(s.begin());
		printf("%d %d\n",a,b);
		lst.first=a,lst.second=b;
		sz[a]+=sz[b];
		ll g=min(sz[a]+1,MX);
		sz[a]+=g;
		s.insert(make_pair(sz[a],a));
		p--;
	}
	while(p--)
		printf("%d %d\n",lst.first,lst.second);
}