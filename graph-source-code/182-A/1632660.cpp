//Language: GNU C++


#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define dist DIST
#define pow2(x) ll(x)*(x)
typedef pair<int,int> point;
typedef long long ll;
#define X first
#define Y second
const int MAXn=1000+10;
const ll INF=1e18;
ll shoot,charge;
point s,t;
point p1[MAXn],p2[MAXn];
bool mark[MAXn];
bool am[MAXn][MAXn];
int level[MAXn];
int n;

ll dist(point p1, point p2) { return pow2(p1.X-p2.X)+pow2(p1.Y-p2.Y); }

ll find(point a, point b, point c)
{
	if(a>b) swap(a,b);
	if(a.X==b.X)
	{
		if(c.Y<=a.Y)
			return dist(a,c);
		else if(a.Y<=c.Y&&c.Y<=b.Y)
			return pow2(c.X-a.X);
		else
			return dist(b,c);
	}
	else
	{
		if(c.X<=a.X)
			return dist(a,c);
		else if(a.X<=c.X&&c.X<=b.X)
			return pow2(c.Y-a.Y);
		else
			return dist(b,c);
	}
}

int main()
{
	cin >> charge >> shoot;
	cin >> s.X >> s.Y >> t.X >> t.Y;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> p1[i].X >> p1[i].Y >> p2[i].X >> p2[i].Y;
	if(dist(s,t)<=charge*charge)
	{
		cout << sqrt(dist(s,t)) << endl;
		return 0;
	}
	for(int i = 0; i < n; i++)
		for(int j = i+1; j < n; j++)
		{
			ll d=min(find(p1[i],p2[i],p1[j]),find(p1[i],p2[i],p2[j]));
			d=min(d,find(p1[j],p2[j],p1[i]));
			d=min(d,find(p1[j],p2[j],p2[i]));
			if(d<=charge*charge)
				am[i][j]=am[j][i]=true;
		}
	queue<int> q;
	for(int i = 0; i < n; i++) level[i]=-1;
	for(int i = 0; i < n; i++)
		if(find(p1[i],p2[i],s)<=charge*charge)
		{
			q.push(i);
			mark[i]=true;
			level[i]=1;
		}
	while(!q.empty())
	{
		int v=q.front(); q.pop();
		for(int u=0; u < n; u++)
			if(!mark[u]&&am[v][u])
			{
				level[u]=level[v]+1;
				mark[u]=true;
				q.push(u);
			}
	}
	double mn=INF;
	for(int i = 0; i < n; i++)
	{
		ll f=find(p1[i],p2[i],t);
		if(level[i]!=-1&&f<=charge*charge)
			mn=min(mn,level[i]*(charge+shoot)+sqrt(f));
	}
	if(mn==INF)
		cout << -1 << endl;
	else
		cout << setprecision(6) << fixed << mn << endl;
	return 0;
}
