//Language: GNU C++0x


// Enjoy your stay.

#include <bits/stdc++.h>

#define EPS 1e-9
#define INF 1070000000LL
#define MOD 1000000007LL
#define fir first
#define foreach(it,X) for(auto it=(X).begin();it!=(X).end();it++)
#define ite iterator
#define mp make_pair
#define mt make_tuple
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define pb push_back
#define sec second
#define sz(x) ((int)(x).size())

using namespace std;

typedef istringstream iss;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef stringstream sst;
typedef vector<ll> vi;

int n,m,K,u[310];
int ans1[90010],ans2[90010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>n>>m>>K;
	if(K==n)return cout<<-1,0;
	rep(i,K){
		int a;
		cin>>a;
		u[a-1]=1;
	}
	int unused;
	rep(i,n)if(u[i]==0){unused=i;break;}
	
	int v1=-1,v2=-1;
	rep(i,n)if(i!=unused && u[i]){
		if(v1==-1)v1=i;
		else{
			v2=i;
			break;
		}
	}
	rep(i,n)if(i!=unused){
		if(v1==-1)v1=i;
		else if(v2==-1){
			v2=i;
			break;
		}else break;
	}
	
	int cur=0;
	rep(i,n)if(i!=unused){
		ans1[cur]=unused,ans2[cur]=i;
		cur++;
	}
	
	rep(i,n)if(i!=unused && i!=v1 && i!=v2){
		if(cur==m)continue;
		ans1[cur]=v1,ans2[cur]=i;
		cur++;
		if(u[i]==0){
			if(cur==m)continue;
			ans1[cur]=v2,ans2[cur]=i;
			cur++;
		}
	}
	
	rep(i,n)if(i!=unused && i!=v1 && i!=v2){
		rep2(j,i+1,n)if(j!=unused && j!=v1 && j!=v2){
			if(cur==m)continue;
			ans1[cur]=i,ans2[cur]=j;
			cur++;
		}
	}
	
	end:;
	if(cur!=m)cout<<-1<<endl;
	else rep(i,m)cout<<ans1[i]+1<<" "<<ans2[i]+1<<endl;
}
