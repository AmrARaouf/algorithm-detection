//Language: MS C++


#include <cstring>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cstdlib>
#include <string>
#include <ctime>
#include <bitset>
using namespace std;

int n;
char input[110][110];
vector<int> myList[26];
int prefix[26];

bool init(){
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		scanf("%s", input[i]);
	for(int i=0; i<n-1; ++i){
		int curr=0;
		while(input[i][curr]==input[i+1][curr] && input[i][curr]!='\0') ++curr;
		if(input[i][curr]=='\0') continue;
		else if(input[i+1][curr]=='\0') return false;
		int left=input[i][curr]-'a', right=input[i+1][curr]-'a';
		bool flag=false;
		for(int j=0; j<myList[left].size(); ++j)
			if(myList[left][j]==right){flag=true; break;}
		if(!flag) myList[left].push_back(right);
	}
	for(int i=0; i<26; ++i)
		for(int j=0; j<myList[i].size(); ++j)
			prefix[myList[i][j]]++;
	return true;
}
void topoSort(){
	queue<int> q;
	string ans;
	for(int i=0; i<26; ++i)
		if(prefix[i]==0) q.push(i);
	while(!q.empty()){
		int curr=q.front(); q.pop();
		for(int i=0; i<myList[curr].size(); ++i)
			if(--prefix[myList[curr][i]]==0) q.push(myList[curr][i]);
		ans+=(curr+'a');
	}
	if(ans.size()==26) cout<<ans<<endl;
	else cout<<"Impossible"<<endl;
}
int main(){
	if(!init()) cout<<"Impossible"<<endl;
	else topoSort();
	return 0;
}