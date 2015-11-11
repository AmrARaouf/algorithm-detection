//Language: GNU C++


#include <iostream>

using namespace std;

const int maxn=100000+10;
int n,m;
struct Tside
{
	int y,num;
	Tside *next;
}*h[maxn];
int x,y,tot;
int res[maxn][2],len=0;


void ins(int x,int y,int num)
{
	Tside *tmp=h[x];
	h[x]=new(Tside);
	h[x]->y=y;
	h[x]->next=tmp;
	h[x]->num=num;
	tmp=h[y];
	h[y]=new(Tside);
	h[y]->y=x;
	h[y]->next=tmp;
	h[y]->num=num;
}


void dfs(int k,int fa,int sfa)
{
	Tside *tmp=h[k];
	int last=sfa;
	while (tmp!=NULL)
	{
		if (tmp->y!=fa)
		{
			if (last!=0) {len++;res[len][0]=last;res[len][1]=tmp->num;}
			last=tmp->num;
			dfs(tmp->y,k,tmp->num);
		}
		tmp=tmp->next;
	}
}


int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) h[y]=NULL;
	cout<<n-1<<endl;
	for (int i=1;i<n;i++)
	{
		cin>>x>>y;
		ins(x,y,i);
		cout<<2<<' '<<x<<' '<<y<<endl;
	}
	tot=0;
	dfs(1,0,0);
	for (int i=1;i<=len;i++) cout<<res[i][0]<<' '<<res[i][1]<<endl;
	return 0;
}
