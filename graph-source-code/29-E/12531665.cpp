//Language: GNU C++11


/*  In the name of Allah */

#include<iostream>
#include<queue>
#include <cstring>
#include <algorithm>


using namespace std;

const int max_n= 503;
typedef pair<int,int> pii;

struct tri
{
	int x;
	int y;
	int z;
	tri(int x = 0,int y = 0, int z = 0): x(x), y(y), z(z) {}
};

vector<int> v[max_n];
int dp[max_n][max_n][2];
bool check[max_n][max_n][2];
queue<tri> bfs;
tri dad[max_n][max_n][2];

int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>> x>> y;
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(dp,63,sizeof dp);
	int inf=dp[0][0][0];
	
	dp[0][n-1][1]=0;
	check[0][n-1][1]=1;
	bfs.push(tri(0,n-1,1));
	vector<int> masir1,masir2;
	while(!bfs.empty())
	{
		tri a= bfs.front();
		bfs.pop();
		if(a.z==1)
			for(auto i:v[a.y])
			{
				if(!check[a.x][i][0])
				{
					bfs.push(tri(a.x,i,0));
					check[a.x][i][0]=true;
					dp[a.x][i][0]=dp[a.x][a.y][1];
					dad[a.x][i][0]=tri(a.x,a.y,1);
				}
			}
		else
			for(auto i:v[a.x])
			{
				if(!check[i][a.y][1]&& i!=a.y)
				{
					bfs.push(tri(i,a.y,1));
					check[i][a.y][1]=true;
					dp[i][a.y][1]=dp[a.x][a.y][0]+1;
					dad[i][a.y][1]=tri(a.x,a.y,0);
				}
			}
	}

	if(dp[n-1][0][1]==inf){ cout<< -1<< endl; return 0;}
	tri id=tri(n-1,0,1);
	while(id.x!=0 || id.y!=n-1)
	{
		masir1.push_back(id.x);
		masir2.push_back(id.y);
		id=dad[id.x][id.y][id.z];
		id=dad[id.x][id.y][id.z];
	}
	masir1.push_back(0);
	masir2.push_back(n-1);
	reverse(masir1.begin(),masir1.end());
	reverse(masir2.begin(),masir2.end());
	cout<< masir1.size()-1<< endl;
	for(auto i:masir1)
		cout<< i+1 <<' ';
	cout<< endl;
	for(auto i:masir2)
		cout<< i+1<<' ';

}
