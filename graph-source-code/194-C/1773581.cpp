//Language: GNU C++


#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cassert>
#define VAR(a,b) typeof(b) a=b
#define FOR(i, b, e) for (typeof(b) i = (b); i != (e); ++i)
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
char b[52][52];
char done[52][52];
int main() {
	int n,m;
	cin >> n >> m;
	int count=0;
	FOR(i,0,n)FOR(j,0,m){
		cin >> b[i+1][j+1];

		if(b[i+1][j+1]=='#'){
			count++;
		}
	}

	if(count <= 2){
		cout << -1;
		return 0;
	}
	n++;
	m++;
	int dx[]={-1,0,1,0};
	int dy[]={0,-1,0,1};
	vector<P> ps;
	FOR(k,0,4){
		FOR(i,1,n)FOR(j,1,m){
			int ii=i+dx[k];
			int jj=j+dy[k];
			if(b[i][j]!='#'||b[ii][jj]!='#')continue;
			b[ii][jj]='.';
			memset(done,0,sizeof(done));
			done[i][j]=1;
			ps.push_back(P(i,j));
			vector<P> db;
			int c=1;
			while(ps.size()){
				P pos=ps.back();
				db.push_back(pos);
				ps.pop_back();
				FOR(p,0,4){
					int x=pos.first+dx[p];
					int y=pos.second+dy[p];
					if(done[x][y]==0&&b[x][y]=='#'){
						done[x][y]=1;
						ps.push_back(P(x,y));
						c++;
					}
				}
			}
			if(c+1!=count){
				cout << 1 << endl;
				return 0;
			}
			b[ii][jj]='#';
		}
	}
	cout << 2 << endl;
}
