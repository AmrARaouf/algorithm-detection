//Language: GNU C++


#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <vector>
#include <stack>
#include <list>
#include <utility>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;
typedef vector<string> VS;

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();it++)
#define ALL(x) x.begin(),x.end()
#define CLR(x, v) memset((x),v,sizeof (x))
#define gcd(a, b) __gcd(a, b)
#define PB push_back 
#define MP make_pair
#define INF 2000000007
#define eps 1e-6

int toInt(string s){ istringstream sin(s); int t; sin>>t; return t; }
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str(); }
template<class T> void chmin(T &t, T f) { if (t > f) t = f; }
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

struct Point
{
	double x, y;
	Point() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
	double operator*(Point p)
	{
		return x*p.x+y*p.y;
	}
	Point operator*(double f)
	{
		return Point(x*f,y*f);
	}
	Point operator+(Point p)
	{
		return Point(x+p.x,y+p.y);
	}
	Point operator-(Point p)
	{
		return Point(x-p.x,y-p.y);
	}
};
double dist(Point p, Point q)
{
	return sqrt((p-q)*(p-q));
}
double dseg(Point a, Point b, Point c)
{
	Point ab = b - a;
	Point ac = c - a;
	double f = ab * ac;
	if(f < 0) return dist(a, c);
	double l = ab * ab;
	if(f > l) return dist(b, c);
	f /= l;
	Point d = a + ab * f;
	return dist(c, d);
}
double d[1010][1010];
int n, vis[1010];
Point start[1010], end[1010];
double a, b;
double dijkstra()
{
	int i, j;
	double di[1010];
	FOR(i,0,n+1) di[i] = 1e18;
	di[0] = 0;
	FOR(i,0,n) {
		double best = 1e18;
		int p = -1;
		FOR(j,0,n+1) if(!vis[j]) {
			if(di[j] < best) {
				best = di[j];
				p = j;
			}
		}
		if(p == -1) break;
		vis[p] = 1;
		if(p) di[p] += b;
		FOR(j,0,n+1) if(d[p][j] <= a) chmin(di[j], di[p] + a);
	}
	FOR(i,0,n) if(d[i][n] <= a) 
		chmin(di[n], di[i] + d[i][n]);
	if(di[n] == 1e18) return -1;
	return di[n];
}
int main()
{
	cin >> a >> b;
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	int i, j;
	cin >> n;
	n++;
	FOR(i,0,n+1) FOR(j,0,n+1) d[i][j] = 1e18;
	FOR(i,1,n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		start[i] = Point(x1,y1);
		end[i] = Point(x2,y2);
	}
	FOR(i,1,n) FOR(j,1,n) {
		chmin(d[i][j], dseg(start[i], end[i], start[j]));
		chmin(d[i][j], dseg(start[i], end[i], end[j]));
		chmin(d[i][j], dseg(start[j], end[j], start[i]));
		chmin(d[i][j], dseg(start[j], end[j], end[i]));
	}
	FOR(i,1,n) d[0][i] = d[i][0] = dseg(start[i], end[i], Point(sx,sy));
	FOR(i,1,n) d[n][i] = d[i][n] = dseg(start[i], end[i], Point(tx,ty));
	d[0][0] = d[n][n] = 0;
	d[0][n] = d[n][0] = dist(Point(sx,sy), Point(tx,ty));
//	FOR(j,0,n+1) cout << d[0][j]<<" ";cout<<endl;
	printf("%.08lf\n",  dijkstra());
	return 0;
}
