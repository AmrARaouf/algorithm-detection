//Language: MS C++


#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > aEdges;
vector<int> aUsed;
int iStart;
int dfs(int i,int depth)
{
	if(aUsed[i])
	{
		if(i!=iStart)
			return 0;
		if(depth==2)
			return 0;
		return 1;
	}
	aUsed[i] = 1;
	for(int j=0;j<aEdges[i].size();j++)
	{
		int k = dfs(aEdges[i][j],depth+1);
		if(k==1)
			return 1;

	}
	aUsed[i] = 0;
	return 0;
}

vector<int> aDist;

void flood(int i,int dist)
{
	if(aUsed[i])
		return;
	if(aDist[i]==-1)
		aDist[i] = dist;
	if(aDist[i]==0)
		dist = 0;
	aUsed[i] = 1;
	for(int j=0;j<aEdges[i].size();j++)
		flood(aEdges[i][j],dist+1);
}

int main()
{
	int N;
	int i;
	int a,b;
	vector<int> v;
	cin >> N;
	for(i=0;i<N;i++)
	{
		aEdges.push_back(v);
		aUsed.push_back(0);
		aDist.push_back(-1);
	}
	for(i=0;i<N;i++)
	{
		cin >> a >> b;
		a--,b--;
		aEdges[a].push_back(b);
		aEdges[b].push_back(a);
	}
	for(i=0;i<N;i++)
	{
		iStart = i;
		if(dfs(i,0))
			break;
	}
	for(i=0;i<N;i++)
		if(aUsed[i])
		{
			aDist[i] = 0;
			aUsed[i] = 0;
		}
	flood(iStart,0);
	cout << aDist[0];
	for(i=1;i<N;i++)
		cout << " " << aDist[i];
	cout << endl;
}