//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> tab[4001];
bool czy[4001][4001];
int n, m, x, y, w = 10000001, i, j, k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for( int a = 1; a <= m; a++ )
	{
		cin>>x>>y;
		tab[x].push_back(y);
		tab[y].push_back(x);
		czy[x][y] = 1;
		czy[y][x] = 1;
	}
	for( int a = 1; a <= n; a++ )
	{
		for( int b = a + 1; b <= n; b++ )
		{
			for( int c = 0; czy[a][b] && c < tab[a].size(); c++ )
			{
				if( czy[ tab[a][c] ][ b ] )
				{
//					cout<<a<<" "<<b<<" "<<c<<" "<<i+j+k;
					i = tab[a].size();
					j = tab[b].size();
					k = tab[tab[a][c]].size();
//					cout<<a<<" "<<b<<" "<<tab[a][c]<<" "<<i+j+k<<endl;
					w = min( w, i+j+k );
				}
			}
		}
	}
	if( w != 10000001 )cout<<w - 6;
	else cout<<"-1";
	return 0;
}