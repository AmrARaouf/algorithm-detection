//Language: GNU C++


#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>

using namespace std; 

#define vc vector
#define pb push_back
#define mp make_pair
#define fr(i,n) for (int (i)=0; (i)<(n); (i)++)

string s; 
long long n,e=0;
long long head[10000],next[10000],v[10000];
long long ans[5000],path[5000];
bool u[5000]; 
bool ok=false; 

void go(int x, int pr,int n) {
	if (u[x]) {
		ans[x]=0; 
		for (int i=n; i>=0; i--) if (path[i]==x) { ok=true; return; } else ans[path[i]]=0; 
	} else {
		int p=head[x];
		u[x]=true;  
		path[n]=x; 
		while (p>0) {
			if (v[p]!=pr && !ok) go(v[p],x,n+1);
			p=next[p];   
		}
		u[x]=false; 
		path[n]=0;
	}
}

int x,y,cnt,cn; 

void go1(int x, int pr) {
	if (ans[x]==0) {
		cn=cnt;
		ok=true; 
		return;
	} else {
		int p=head[x];
		while (p>0) {
			if (v[p]!=pr && !ok) { cnt++; go1(v[p],x); cnt--;}
			p=next[p];   
		}
	}
}

int main() {
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	cin >> n;
	fr(i,n+1) ans[i]=-1; 
	fr (i,n) {
		cin >> x >> y; 
		e++; 
		next[e]=head[x]; 
		v[e]=y; 
		head[x]=e; 

	        swap(x,y);
	        e++; 
		next[e]=head[x]; 
		v[e]=y; 
		head[x]=e;
	}

	go(1,-1,0);

	for (int i=1; i<=n; i++) if (ans[i]==-1) {
		ok=false;  
		cnt=0;cn=0;  
	        go1(i,-1);
		ans[i]=cn; 
	}

	for (int i=1; i<=n; i++) cout << ans[i] << " "; 
	return 0; 
}
