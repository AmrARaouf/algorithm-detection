//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef long long int LL;

const int maxn=100100;

int n,m,id=1;
LL Len[maxn],R[maxn];
map<string,int> mp;

typedef pair<int,int> PII;

vector<PII> bian;

struct Edge
{
	int from,to,next;
}edge[maxn],edge2[maxn];

int Adj[maxn],Size;
int Adj2[maxn],Size2;

void init()
{
	Size=0; memset(Adj,-1,sizeof(Adj));
}

void init2()
{
	Size2=0; memset(Adj2,-1,sizeof(Adj2));
}

void Add_Edge(int u,int v)
{
	edge[Size].from=u; edge[Size].to=v; edge[Size].next=Adj[u]; Adj[u]=Size++;
}

void Add_Edge2(int u,int v)
{
	edge2[Size2].from=u; edge2[Size2].to=v; edge2[Size2].next=Adj2[u]; Adj2[u]=Size2++;
}


int Low[maxn],DFN[maxn],Stack[maxn],Belong[maxn];
int Index,top,scc;
bool Instack[maxn]; int num[maxn];
LL GoalR[maxn],GoalLen[maxn];

void tarjan(int u)
{
	int v;
	Low[u]=DFN[u]=++Index;
	Stack[top++]=u;
	Instack[u]=true;
	for(int i=Adj[u];~i;i=edge[i].next)
	{
		v=edge[i].to;
		if(!DFN[v])
		{
			tarjan(v);
			Low[u]=min(Low[u],Low[v]);
		}
		else if(Instack[v])
		{
			Low[u]=min(Low[u],DFN[v]);
		}
	}
	if(Low[u]==DFN[u])
	{
		scc++;
		do
		{
			v=Stack[--top];
			Instack[v]=false;
			num[scc]++;
			Belong[v]=scc;
			if(R[v]<GoalR[scc])
			{
				GoalR[scc]=R[v];
				GoalLen[scc]=Len[v];
			}
			else if(R[v]==GoalR[scc]&&Len[v]<GoalLen[scc])
			{
				GoalLen[scc]=Len[v];
			}
		}while(v!=u);
	}
}

void scc_solve(int n)///id
{
	memset(DFN,0,sizeof(DFN));
	memset(Instack,0,sizeof(Instack));
	memset(num,0,sizeof(num));
	memset(GoalR,63,sizeof(GoalR));
	memset(GoalLen,63,sizeof(GoalLen));

	Index=scc=top=0;

	for(int i=1;i<=n;i++)
		if(!DFN[i]) tarjan(i);
}

///..............debug...............
void debug(int n)
{
	cout<<"scc: "<<scc<<endl;
	for(int i=1;i<=scc;i++) cout<<num[i]<<"--";
	cout<<endl;
	for(int i=1;i<n;i++)
	{
		cout<<"ID: "<<i<<" DFN: "<<DFN[i]<<", LOW: "<<Low[i]<<" Belong: "<<Belong[i]<<endl;
	}
	cout<<endl;
}
///..............debug...............

void ReBuild()
{
	init2();
	//cout<<"m: "<<m<<endl;
	for(int i=0;i<m;i++)
	{
		int u=bian[i].first,v=bian[i].second;
		int U=Belong[u],V=Belong[v];
		//cout<<u<<" "<<U<<" "<<v<<" "<<V<<endl;
		if(U==V) continue;
		///连边
		//cout<<"Link: "<<U<<"  "<<V<<endl;
		Add_Edge2(U,V);
	}
}

vector<string> str;

bool vis[maxn];
LL dp_r[maxn],dp_l[maxn];

void dfs(int u)
{
	if(vis[u]==true) return ;	
	//cout<<"dfs... "<<u<<"   "<<Belong[u]<<endl;
	vis[u]=true;
	LL R=GoalR[u],L=GoalLen[u];
	for(int i=Adj2[u];~i;i=edge2[i].next)
	{
		int v=edge2[i].to;
		dfs(v);
		if(dp_r[v]<R)
		{
			R=dp_r[v]; L=dp_l[v];
		}
		else if(dp_r[v]==R&&dp_l[v]<L)
		{
			L=dp_l[v];
		}
	}
	dp_r[u]=R; dp_l[u]=L;
}


int main()
{
	scanf("%d",&n);
	string word;
	for(int i=0;i<n;i++)
	{
		cin>>word;
		for(int i=0,sz=word.size();i<sz;i++)
		{
			if(word[i]>='A'&&word[i]<='Z')
				word[i]=word[i]-'A'+'a';
		}
		str.push_back(word);
		if(mp[word]==0) mp[word]=id++;
		else continue;
		int it=mp[word];
		Len[it]=word.size();
		for(int i=0;i<Len[it];i++)
		{
			if(word[i]=='r')
				R[it]++;
		}
		//cout<<word<<": "<<Len[it]<<" , "<<R[it]<<endl;
	}
	scanf("%d",&m);
	string Fr,To;
	init();
	for(int _=0;_<m;_++)
	{
		cin>>Fr>>To;
		int r1=0,r2=0;
		for(int i=0,sz=Fr.size();i<sz;i++)	
		{
			if(Fr[i]>='A'&&Fr[i]<='Z')
				Fr[i]=Fr[i]-'A'+'a';
			if(Fr[i]=='r') r1++;
		}
		if(mp[Fr]==0) 
		{
			Len[id]=Fr.size();
			R[id]=r1;
			mp[Fr]=id++;
		}
		for(int i=0,sz=To.size();i<sz;i++)	
		{
			if(To[i]>='A'&&To[i]<='Z')
				To[i]=To[i]-'A'+'a';
			if(To[i]=='r') r2++;
		}
		if(mp[To]==0) 
		{
			Len[id]=To.size();
			R[id]=r2;
			mp[To]=id++;
		}
		bian.push_back(make_pair(mp[Fr],mp[To]));
		//cout<<" add : "<<mp[Fr]<<" ---> "<<mp[To]<<endl;
		Add_Edge(mp[Fr],mp[To]);
	}
	scc_solve(id);
	//........
	//debug(id);
	//cout<<"now rebulid\n";
	ReBuild();
	///DFS............

	///Goal............
	/*
	for(int i=1;i<=scc;i++)
	{
		cout<<i<<": "<<GoalR[i]<<" , "<<GoalLen[i]<<endl;
	}
	*/
	///Goal............
	LL RRR=0,LLL=0;
	for(int i=0;i<n;i++)	
	{
		int id=mp[str[i]];
		//cout<<"str: "<<str[i]<<"   "<<id<<endl;
		dfs(Belong[id]);
		RRR+=dp_r[Belong[id]];
		LLL+=dp_l[Belong[id]];
	}
	//cout<<"RRR: "<<RRR<<"  LLL: "<<LLL<<endl;
	cout<<RRR<<" "<<LLL<<endl;
	return 0;
}
