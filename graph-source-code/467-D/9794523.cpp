//Language: GNU C++0x


#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define INF 1000000007
#define EPS 1e-10
#define mp make_pair
/*
	Problem: Fedor and Essay
	Source: Codeforces 467D
	Author: fts2001
*/
using namespace std;
typedef pair<pair<int,int>,int> ppi;
int n,m,cnt;
long long resr,resl;
bool vis[100005];
map<string,int> ind;
vector<int> ess,g[100005];
priority_queue<ppi,vector<ppi>,greater<ppi> > pq;
pair<int,int> r[100005];
int index(const string &ss){
	string t;
	for(int i=0;i<ss.length();i++){
		if(ss[i]>='A' && ss[i]<='Z'){
			t.push_back(ss[i]+'a'-'A'); 
		}
		else{
			t.push_back(ss[i]);
		}
	}
	if(ind[t])return ind[t];
	ind[t]=++cnt;
	int cntr=0;
	for(int i=0;i<t.length();i++){
		if(t[i]=='r')cntr++;
	}
	r[ind[t]]=mp(cntr,t.length());
	pq.push(mp(r[ind[t]],ind[t]));
	return ind[t];
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m;
	for(int i=0;i<m;i++){
		string u;
		cin>>u;
		ess.push_back(index(u));
	}
	cin>>n;
	for(int i=0;i<n;i++){
		string u,v;
		cin>>u>>v;
		g[index(v)].push_back(index(u));
	}
	while(!pq.empty()){
		int c=pq.top().second;
		pq.pop();
		if(vis[c])continue;
		vis[c]=true;
		for(int i=0;i<g[c].size();i++){
			if(r[c]<r[g[c][i]]){
				r[g[c][i]]=r[c];
				pq.push(mp(r[g[c][i]],g[c][i]));
			}
		}
	}
	for(int i=0;i<ess.size();i++){
		resr+=r[ess[i]].first;
		resl+=r[ess[i]].second;
	}
	cout<<resr<<' '<<resl<<'\n';
	return 0;
}
