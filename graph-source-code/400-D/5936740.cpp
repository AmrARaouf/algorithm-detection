//Language: GNU C++


#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<cstdio>
#include<queue>
#include<sstream>
#include<ctime>
using namespace std;

typedef long long Int;
#define FOR(i,a,b) for(int i=(a); i<=(b);++i)
#define mp make_pair
#define pb push_back
#define sz(s) (int)((s).size())
const int inf = 1000000001;
const int MOD = 1000000007;
const double pi=acos(-1.0);

int id[100009];
int d[555][555];
int fath[100009];

int getfath(int v) {
	if(v==fath[v]) return v;
	return fath[v]=getfath(fath[v]);
}


int main() {
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int s=0;
	FOR(i,1,k) {
		int c;
		cin>>c;
		FOR(j,s+1,s+c) id[j]=i;
		s+=c;
	}
	FOR(i,1,n) fath[i]=i;
	FOR(i,1,k)FOR(j,1,k)d[i][j]=inf*(i!=j);
	while(m--) {
		int x,y,z;
		cin>>x>>y>>z;
		int len = min(d[id[x]][id[y]], z);
		d[id[x]][id[y]]=d[id[y]][id[x]]=len;
		if(z==0) {
			int t1=getfath(x),
				t2=getfath(y);
			if(rand()&1) swap(t1, t2);
			fath[t1]=t2;
		}
	}
	bool ok=true;
	FOR(i,2,n) if(id[i]==id[i-1] && getfath(i)!=getfath(i-1))ok=false;
	if(!ok) {
		cout<<"No"<<endl;
		return 0;
	}
	FOR(w,1,k)FOR(i,1,k)FOR(j,1,k)d[i][j]=min(d[i][j], d[i][w]+d[w][j]);

	cout<<"Yes"<<endl;
	FOR(i,1,k) {
		FOR(j,1,k) {
			if(d[i][j]>=inf)d[i][j]=-1;
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
}