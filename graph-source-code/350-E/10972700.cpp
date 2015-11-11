//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define inf 1e15

#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define f first
#define mp make_pair
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define M 360360
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	int a[k];
	rep(i,k)
		cin>>a[i],a[i]--;
	set<int>s;
	rep(i,n)
		s.insert(i);
	rep(i,k)
		s.erase(a[i]);
	if(s.size()>=1){
		int x=a[0];
		int y=a[1];
		vector<pi>ans;
		set<pi>edges;
		rep(i,n){
			for(int j=i+1;j<n;j++){
				edges.insert(mp(i,j));
			}
		}
		rep(i,k){
			if( edges.count( mp(min(x,a[i]) , max(x,a[i])))==1 and edges.count( mp(min(y,a[i]) , max(y,a[i])))==1  ){
				edges.erase(mp(min(x,a[i]) , max(x,a[i])));
			}
		}
		edges.erase(mp(x,y));
		edges.erase(mp(y,x));
		bool vis[100011]={0};
		for(auto x:edges){
			if(m==0) break;
			if(vis[x.f]==0 or vis[x.s]==0){
				vis[x.f]=1;
				vis[x.s]=1;
				ans.pb(x);
				m--;
			}
		}
		for(auto x:ans) edges.erase(x);
		for(auto x:edges){
			if(m==0) break;
			ans.pb(x);
			m--;
		}
		if(m!=0){
			cout<<-1;
			return 0;
		}
		rep(i,n){
			if(vis[i]==0){
				cout<<-1;
				return 0;
			}
		}
		for(auto x:ans){
			cout<<x.f+1<<" "<<x.s+1<<"\n";
		}
	}
	else{
		cout<<-1;
	}
}
