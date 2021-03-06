//Language: GNU C++


#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define iss istringstream
#define sst stringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sh(i) (1LL<<i)
#define sz size()
#define vi vector<int>
#define vc vector
#define vl vector<ll>
#define vs vector<string>

int n,m,k,a[201],b[9],d[201][201],dp[1<<7][201];
pi pre[1<<7][201];
char ans[101][101];

int f(int S,int p){
	int& res=dp[S][p];
	if(res>-1)return res;
	rep(i,k)if(S==(1<<i)){
		if(b[i]==p)return res=a[p];
	}
	res=INF;
	pi& pr=pre[S][p];
	for(int T=(S-1)&S;T>0;T=(T-1)&S){
		int c=f(T,p)+f(T^S,p)-a[p];
		if(c<res){
			res=c;
			pr=mp(T,p);
		}
	}
	rep(i,n*m)if(i!=p){
		int c=f(S,i)+d[p][i]-a[i];
		if(c<res){
			res=c;
			pr=mp(S,i);
		}
	}
	return res;
}

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int id(int x,int y){return x*m+y;}

void draw(int cur,int to){
	ans[cur/m][cur%m]='X';
	if(cur==to)return;
	int x=cur/m,y=cur%m;
	rep(i,4){
		int nx=x+dx[i],ny=y+dy[i];
		if(0<=nx&&nx<n && 0<=ny&&ny<m &&
		a[cur]+d[id(nx,ny)][to]==d[cur][to]){
			draw(id(nx,ny),to);
			break;
		}
	}
}

void g(int S,int p){
	pi P=pre[S][p];
	if(P.fir==-1){
		draw(p,p);
		return;
	}
	if(p!=P.fir)draw(p,P.sec);
	g(P.fir,P.sec);
	if(P.fir!=S)g(S^P.fir,p);
}

int main(){
	cin>>n>>m>>k;
	rep(i,n*m)cin>>a[i];
	rep(i,k){
		int x,y;
		cin>>x>>y;
		b[i]=id(x-1,y-1);
	}
	rep(i,n*m)rep(j,n*m)d[i][j]=INF;
	rep(i,n*m)d[i][i]=0;
	rep(i,n-1)rep(j,m){
		d[id(i,j)][id(i+1,j)]=a[id(i+1,j)];
		d[id(i+1,j)][id(i,j)]=a[id(i,j)];
	}
	rep(i,n)rep(j,m-1){
		d[id(i,j)][id(i,j+1)]=a[id(i,j+1)];
		d[id(i,j+1)][id(i,j)]=a[id(i,j)];
	}
	rep(ii,n*m)rep(i,n*m)rep(j,n*m){
		d[i][j]=min(d[i][j], d[i][ii]+d[ii][j]);
	}
	memset(dp,-1,sizeof(dp));
	memset(pre,-1,sizeof(pre));
	rep(i,n*m)rep(j,n*m)d[i][j]+=a[i];
	cout<<f((1<<k)-1,b[0])<<endl;
	rep(i,n)rep(j,m)ans[i][j]='.';
	g((1<<k)-1,b[0]);
	rep(i,n)cout<<ans[i]<<endl;
}
