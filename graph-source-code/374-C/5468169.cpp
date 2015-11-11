//Language: GNU C++0x


#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<iostream>
#include<map>
#include<queue>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)n; i++)
#define st first
#define nd second
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpii;
typedef set<int> SI;

#ifdef DEBUG
const bool debug = true;
#else
const bool debug = false;
#endif
int n,m,k,l;
const int inf = 1000 * 1000 * 1000 ;
const int MAKSN = 1000 + 13; // UZUPElnic
string s[MAKSN];

map<char,char> nast;
map<char,char> poprz;
vector<pair<int,int> > E[MAKSN][MAKSN];
bool cykl = false;
int vis[MAKSN][MAKSN];
int kroki[MAKSN][MAKSN];
int wyn[MAKSN][MAKSN];
pi oj[MAKSN][MAKSN];


void readIn()
{
	cin>>n>>m;
	rep(i,n)
	{
		cin>>s[i];
	}

	rep(i,n)
	rep(j,m)
	{
		kroki[i][j] = 0;
		vis[i][j] = false;
		wyn[i][j] = 0;
		oj[i][j] = mp(-1,-1);
	}

	nast['D'] = 'I';
	nast['I'] = 'M';
	nast['M'] = 'A';
	nast['A'] = 'D';
}

void zrobKraw()
{
	rep(i,n)
	{
	rep(j,m)
	{
		for(int ii=-1;ii<2;ii++)
		for(int jj=-1;jj<2;jj++)
		{
			if(i+ii >= 0 && i + ii < n)
			{
				if(j+jj >= 0 && j + jj < m)
				{
					if((abs(ii) + abs(jj)) == 1)
					{
						if(s[i+ii][j+jj] == nast[s[i][j]] )
						{
							E[i][j].pb(mp(i+ii,j+jj));

						}
					}
				}
			}


		}

	}
	}


}


int dfs(int xs,int ys)
{
	vis[xs][ys] = 1;
	wyn[xs][ys] = 1;
	for(int i=0;i<(int)E[xs][ys].size();i++)
	{
		pi akt = E[xs][ys][i];

		if(!vis[akt.st][akt.nd])
		{
				vis[akt.st][akt.nd] = 1;
				wyn[xs][ys] = max(wyn[xs][ys],dfs(akt.st,akt.nd)+1);
		}
		else
		{
			if(vis[akt.st][akt.nd] == 1)
				cykl = true;
			else
				wyn[xs][ys] = max(wyn[xs][ys], wyn[akt.st][akt.nd]+1);
		}
	}


	vis[xs][ys] = 2;


	return wyn[xs][ys];
}

void wypiszKraw()
{
	rep(i,n)
	rep(j,m){
	rep(k,E[i][j].size())
	{
		cout<<"("<<E[i][j][k].st<<","<<E[i][j][k].nd<<") ";
	}
	cout<<"\n";
	}

}
void solve()
{
	zrobKraw();

	//wypiszKraw();
	int aa;
	int aktWyn = 0;
	rep(i,n)
	rep(j,m)
	{
		if(!vis[i][j] && s[i][j] == 'D')
		{
			aa = dfs(i,j);
			aktWyn = max(aktWyn,aa);
		}

	}

	//cout<<aktWyn<<"\n";


	if(cykl)
		cout<<"Poor Inna!\n";
	else
		if(aktWyn < 4)
			cout<<"Poor Dima!\n";
		else cout<<aktWyn/4<<"\n";

}

int main()
{
	readIn();
	solve();
	return 0;
}
