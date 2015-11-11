//Language: GNU C++


#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<ld,ld>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define MAXINT ((~0) ^ (1 << 31))
#define MAXLL ((~0) ^ ((ll)1 << 63))
#define INF ((int)2e9)
#define INFL ((ll)9e18)
#define FOR(i,j,k) for(int i = j; i < k; i++)
#define REP(i,j,k) for(int i = j; i >= k; i--)
#define setmax(i) const int maxn = (int) i;
#define setmod(i) const int MOD = (int) i;
#define all(a) a.begin(),a.end()


//srand (time(NULL));

using namespace std;

setmax(1e5+10);

int n,m,q[maxn],p[maxn],pr[20][maxn],tt[maxn],mx[20][maxn],cnt,svq[maxn],svp[maxn],parent[maxn],d[maxn],tim[maxn];
vector<int> num[maxn];
bool visited[maxn];

int fnd(int a)
{
    return (parent[a] == a? a:parent[a] = fnd(parent[a]));
}

void dfs(int v, int par, int dep)
{
    d[v] = dep;
   // if(visited[num[v][i]]) return;
    visited[v] = true;
    FOR(h,1,20)
    {
	pr[h][v] = pr[h-1][pr[h-1][v]];
	mx[h][v] = max(mx[h-1][v],mx[h-1][pr[h-1][v]]);
    }
    FOR(i,0,num[v].size()) if(num[v][i] != par) dfs(num[v][i],v,dep+1);
}

int getparent(int v, int l)
{
    FOR(h,0,20)
    {
	if((1 << h) & l)
	{
	    v = pr[h][v];
	}
    }
    return v;
}

int getmax(int v, int l)
{
    int maxi = -1;
    FOR(h,0,20)
    {
	if((1<<h) & l)
	{
	    maxi = max(maxi, mx[h][v]);
	    v = pr[h][v];
	}
    }
    return maxi;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    

    cin >> n >> m;
    FOR(i,0,maxn) parent[i] = i;
    FOR(i,0,m)
    {
	int t;
	cin >> t;
	tt[i] = t;

	if(t == 1)
	{
	    int a,b;
	    cin >> a >> b;
	    num[a].pb(b);
	    num[b].pb(a);
	    parent[a] = b;
	    pr[0][a] = b;
	    mx[0][a] = i;
	}
	if(t == 2)
	{
	    int a;
	    cin >> a;
	    q[cnt] = a;
	    p[cnt] = fnd(a);
	    tim[cnt] = i;
	    cnt++;
	}
	if(t == 3)
	{
	    int a , b;
	    cin >> a >> b;
	    svq[i] = a;
	    svp[i] = b;
	}
    }

   // FOR(i,1,n+1) cout << fnd(i) << " ";
    //cout << endl;

   // FOR(i,0,cnt) cout << q[i] << " " << p[i] << endl;

    FOR(i,1,n+1)if(!pr[0][i]) dfs(fnd(i),-1,0);
    
  /*  FOR(i,1,n+1)
    {
	cout <<"* " << i << " " << pr[0][i] << " " << pr[1][i] << " " << pr[2][i]  <<endl;
    }*/

    FOR(i,0,m)
    {
	if(tt[i] == 3)
	{
	    int x = svq[i];
	    int qq = q[svp[i]-1];
	    int pp = p[svp[i]-1];
	    int t = tim[svp[i]-1];
	    
	//    cout <<"* " << x << " " << qq << " " << pp << " " << d[x] << " " << d[qq] << " " << d[pp] << " " << getparent(x,d[x]-d[pp]) << " " << getmax(x,d[qq] - d[pp]) << " " << endl; 
	    cout << ( d[x] <= d[qq] && d[x] >= d[pp] && getparent(qq,d[qq]-d[x]) == x && getmax(qq,d[qq] - d[pp]) <= t && t < i + 1? "YES\n":"NO\n");
	}
    }

}
