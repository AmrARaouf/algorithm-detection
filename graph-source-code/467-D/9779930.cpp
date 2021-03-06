//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int best[100005],A[100005],cnt[100005];
map<string,int>ind;
map<int,string>inv;
vector<string> str;
vector<int> adj[100005];
int t;
long long res1,res2;
bool visit[100005];
int count(string &s){
	int ans=0;
	for (int i=0;i<s.size();i++){
		if (s[i]=='r'){
			ans++;
		}
	}
	//cout<<"count"<<" "<<s<<ans<<endl;
	return ans;
}
int c;
void add(string &s){
	if (ind.find(s)!=ind.end()){
		return;
	}
	c++;
	ind[s]=c;
	inv[c]=s;
	cnt[c]=count(s);
	return;
}
void lower(string &s){
	for (int i=0;i<s.size();i++){
		s[i]=tolower(s[i]);
	}
	return ;
}
bool cmp(string x,string y){
	if (cnt[ind[x]]!=cnt[ind[y]]){
		return cnt[ind[x]]<cnt[ind[y]];
	}
	else{
		return x.size()<y.size();
	}
}
void dfs(int x,int col){
	if (visit[x]==1){
		return;
	}
	visit[x]=1;
	best[x]=col;
	for (int i=0;i<adj[x].size();i++){
		dfs(adj[x][i],col);
	}
	return;
}
int main(){
	int n;
	cin>>n;
	t=n;
	for (int i=1;i<=n;i++){
		string s;
		cin>>s;
		lower(s);
		//cout<<"lower "<<s<<endl;
		add(s);
		A[i]=ind[s];
	}
	cin>>n;
	for (int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		lower(a);
		lower(b);
		add(a);
		add(b);
		adj[ind[b]].push_back(ind[a]);
	}
	for (map<string,int>::iterator it=ind.begin();it!=ind.end();it++){
		str.push_back(it->first);
	}
	sort(str.begin(),str.end(),cmp);
	for (int i=0;i<str.size();i++){
		dfs(ind[str[i]],ind[str[i]]);
	}
	for (int i=1;i<=t;i++){
		res1+=cnt[best[A[i]]];
		res2+=inv[best[A[i]]].size();
	}
	cout<<res1<<" "<<res2<<endl;
	return 0;
}

