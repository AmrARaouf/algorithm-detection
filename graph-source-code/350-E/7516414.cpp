//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int A[310];
std::vector< pair<int,int> >  Edge;
std::vector<int> e[310];
int vis[310];
std::vector< pair<int,int> >  Ans;
void addedge(int i,int j)
{
	e[i].push_back(j);
	e[j].push_back(i);
	Edge.push_back(make_pair(min(i,j),max(i,j)));
}
void dfs(int idx,int prev = -1)
{
	if(vis[idx])
		return;
	vis[idx] = 1;
	for(int i = 0;i<e[idx].size();i++)
	{
		if(vis[e[idx][i]])
			continue;
		Ans.push_back(make_pair(min(idx,e[idx][i]),max(idx,e[idx][i])));
		dfs(e[idx][i]);
	}
}
int main()
{
	int N,M,K;
	cin>>N>>M>>K;
	for(int i = 0;i<K;i++)
	{
		cin>>A[i];
		A[i]-=1;
	}
	sort(A,A+K);
	if(K==N)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i = 0;i<N;i++)
	{
		for(int j = i+1;j<N;j++)
		{
			if(i==A[0]||j==A[1]||j==A[0]||i==A[1])
				continue;
			addedge(i,j);
		}
	}
	for(int i = 0;i<N;i++)
	{
		if(!binary_search(A,A+K,i))
		{
			addedge(i,A[0]);
			addedge(i,A[1]);
		}
		else
		{
			if(i!=A[0]&&i!=A[1])
				addedge(i,A[0]);
		}
	}
	for(int i = 0;i<N;i++)
	{
		if(!binary_search(A,A+K,i))
		{
			dfs(i);
			sort(Ans.begin(),Ans.end());
			break;
		}
	}
	if(Edge.size()<M)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i =0;i<Edge.size();i++)
	{
		if(!binary_search(Ans.begin(),Ans.begin() + N - 1,Edge[i]))
		{
			Ans.push_back(Edge[i]);
		}
	}
	for(int i = 0;i<M;i++)
	{
		cout<<Ans[i].first + 1<<" "<<Ans[i].second+1<<endl;
	}
	return 0;
}