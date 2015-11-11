//Language: GNU C++


#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int Max = 30000 * 10+20;
vector <int> E[Max];
int en[Max];
int Part[Max];
set < pair <int,int> > S;
int n,m;


void fix ( int v ){
	Part[v] = 1 ^ Part[v];
	S.erase( make_pair( en[v] , v ) );
	en[v] = E[v].size() - en[v];
	S.insert( make_pair( en[v] , v ) );

	for ( int i = 0 ; i < E[v].size() ; i++ ){
		if ( Part[ E[v][i] ] == Part[v] ){
			S.erase( make_pair( en[ E[v][i] ] , E[v][i] ) );
			en[ E[v][i] ]++;
			S.insert( make_pair( en[ E[v][i] ] , E[v][i] ) );
		} else{
			S.erase( make_pair( en[ E[v][i] ] , E[v][i] ) );
			en[ E[v][i] ]--;
			S.insert( make_pair( en[ E[v][i] ] , E[v][i] ) );
		}
	}
}

int main()
{
	cin >> n >> m;
	for ( int i = 0 ; i < m ; i++ ){
		int x,y;
		cin >> x >> y;
		x--;y--;
		E[x].push_back(y); E[y].push_back(x);
	}
	for ( int i = 0 ; i < n ; i++ ){
		en[i] = E[i].size();
		Part[i] = 1;
		S.insert( make_pair(en[i],i) );
	}

	while ( S.rbegin()->first > 1 ){
		int v = S.rbegin()->second;
		fix(v);
	}

	for ( int i = 0 ; i < n ; i++ )
		cout << Part[i];
	return 0;
}