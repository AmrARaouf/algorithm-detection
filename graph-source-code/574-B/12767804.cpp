//Language: MS C++


#include <iostream>
#include <vector>
#include <fstream>
#include <map>
using namespace std;

const int N = 4002;
int A[N][N];
bool visited[N];

bool b1=false;

typedef long long ll;
map<ll, ll> m1;
ll sum, mSum=LLONG_MAX;

void DFS(int s,  vector <int> &v1)
{
	visited[s] =true;
	if(v1.size()==3)
	{
		if(A[s][v1[0]]==1)
		{
			map<ll, ll>::iterator p;
			for(int j=0; j<v1.size(); j++)
			{
				p = m1.find(v1[j]);
			//	cout<<v1[j]<<' '<<p->second<<endl;
				
				sum+=p->second-2;
			}
			cout<<endl;
			if(sum<mSum)
			{
				mSum=sum;
			}
			sum=0;
			b1=true;
		}
	}
	else 
	{
		for(int i=1; i<N; i++)
		{
			if(A[s][i]==1 && visited[i]==false && v1.size()<=2)
			{
				
				v1.push_back(i);
				DFS(i,v1);
				visited[v1[v1.size()-1]]=false;
				v1.pop_back();
			}
		}
	}
}


int main()
{
	ll n, m;
	ifstream ff("file.txt");
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		ll x, y;
		scanf("%I64d%I64d", &x, &y);
		//ff>>x>>y;
		A[x][y] = 1;
		A[y][x] = 1;
		m1[x]++;
		m1[y]++;
	}

	for(int i=1; i<=n; i++)
	{
		int level =0;
		sum=0;
		memset(visited,0,N);
		vector <int> v;
		v.push_back(i);
		DFS(i, v);
		v.clear();
	}

	if(b1==false)
	{
		cout<<-1<<endl;
		return 0;
	}
	else
	{
		cout<<mSum<<endl;
	}
	return 0;
}