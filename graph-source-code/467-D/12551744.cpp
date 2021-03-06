//Language: GNU C++


#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
map<string, int> mp;
int dic, words;
bool vis[300000];
vector<int> essay, adj[300000];
pair<int, int> mem[300000];
int hash_(string str)
{
	for(int i=0;str[i];i++) str[i]=tolower(str[i]);
	map<string,int>::iterator it = mp.find(str);
	if (it == mp.end())
    {
        int num=mp.size();
		mp[str]=num;
		int rcnt=0;
		for(int i=0;str[i];i++)
			rcnt+=(str[i]=='r' || str[i]=='R');
		mem[num]= make_pair(rcnt,str.size());
		return num;
	}
	return it->second;
}
void go(int a,int b)
{
	if (vis[a]) return;
	vis[a] = true;
	mem[a] = mem[b];
	for(int i=0;i<(signed)adj[a].size();i++)
        go(adj[a][i], b);
}
bool compare(string a, string b) {return mem[mp[a]]<mem[mp[b]];}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>words;
	for (int i=0;i<words;i++)
    {
		string str;
		cin>>str;
		essay.pb(hash_(str));
	}
	cin>>dic;
	for (int i=0;i<dic;i++)
    {
		string s1,s2;
		cin>>s1>>s2;
		int num1=hash_(s1),num2=hash_(s2);
		adj[num2].pb(num1);
	}
	int tot=mp.size();
	vector<string> vec;
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
        vec.pb(it->first);
	sort(vec.begin(),vec.end(),compare);
	for(int i=0;i<tot;i++)
        go(mp[vec[i]],mp[vec[i]]);
	ll MnR = 0, len = 0;
	for(int i=0;i<words;i++)
		MnR+=mem[essay[i]].first,len+=mem[essay[i]].second;
	cout<<MnR<<' '<<len<<endl;
	return 0;
}