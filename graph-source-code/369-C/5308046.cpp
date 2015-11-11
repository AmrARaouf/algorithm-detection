//Language: MS C++


#include<cstdio>
#include<cstring>
#define MN 100001

int box[MN];
struct
{
	int pre;
	int to;
	bool type;
	bool disabled;
}edge[MN*2];
int len = 0;
void addDirEdge(int frm,int to,int type)
{
	edge[len].pre = box[frm];
	edge[len].to = to;
	edge[len].type = type==2;
	edge[len].disabled = false;
	box[frm] = len++;
}
void addEdge(int a,int b,int type)
{
	addDirEdge(a,b,type);
	addDirEdge(b,a,type);
}


int readInt()
{
	int rtn = 0;
	char c;
	do
	{
		c=getchar();
	}while(c<48||c>58);
	do
	{
		rtn*=10,rtn+=c-48;
		c = getchar();
	}while(c>=48&&c<=58);
	return rtn;
}


int n,ans[MN],rblen;

bool dfs(int rt,bool wroad)
{
	int it;
	bool rtn=false;
	for(it = box[rt];it!=-1;it= edge[it].pre)
	{
		if(!edge[it].disabled)
		{
			edge[it^1].disabled=true;
			rtn = dfs(edge[it].to,edge[it].type)||rtn;
		}
		
	}
	if(wroad&&rtn==false)
	{
		ans[rblen++] = rt;
		return true;
	}
	return rtn;
}

void solve()
{
	int i;
	rblen = 0;
	dfs(1,false);
	printf("%d\n",rblen);
	for(i=0;i<rblen;i++)
	{
		printf("%d ",ans[i]);
	}
	if(rblen)printf("\n");
}


int main()
{
	int i;
	while(~scanf("%d",&n))
	{
		int frm,to,type;
		len =0;
		memset(box,-1,sizeof(box));
		for(i=0;i<n-1;i++)
		{
			//scanf("%d%d%d",&frm,&to,&type);
			frm = readInt(),to=readInt(),type=readInt();
			addEdge(frm,to,type);
		}
		solve();
	}
	return 0;
}