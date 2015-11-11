//Language: GNU C++11


#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
#define INF 1<<30
#define MP make_pair
#define mp make_pair
#define pb push_back
#define PB push_back
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define ll long long
#define ull unsigned long long

int he[26][26];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin>>n;
	vector<string> s(n);
	REP(i,n) cin>>s[i];
	REP(i,n-1){
		int mi=min(s[i].size(),s[i+1].size());
		int j=0;
		while(j<mi && s[i][j]==s[i+1][j]) j++;
		if(j==mi && s[i+1].size()<s[i].size()){cout<<"Impossible"<<endl;return 0;}
		if(j==mi) continue;
		if(he[s[i][j]-'a'][s[i+1][j]-'a']==-1){cout<<"Impossible"<<endl;return 0;}
		he[s[i][j]-'a'][s[i+1][j]-'a']=1;
		he[s[i+1][j]-'a'][s[i][j]-'a']=-1;
	
	}
// 	REP(i,26){ REP(j,26) cout<<he[i][j]<<"  ";cout<<endl;}
// 	cout<<endl;
	REP(i,26){
		REP(j,26){
			if(he[i][j]==1){
				REP(k,26){
					if(he[j][k]==1){
						if(he[i][k]==-1 || he[k][i]==1){
							cout<<"Impossible"<<endl;return 0;
						}
						he[i][k]=1;he[k][i]=-1;
					}
				}
			}
			if(he[i][j]==-1){
				REP(k,26){
					if(he[j][k]==-1){
						if(he[i][k]==1 || he[k][i]==-1){
							cout<<"Impossible"<<endl;return 0;
						}
						he[i][k]=-1;he[k][i]=1;
					}
				}
			}

		}
	}

//  	REP(i,26){ REP(j,26) cout<<he[i][j]<<"  ";cout<<endl;}
	REP(i,26){
		REP(j,26){
			if(i!=j && he[i][j]==0){
				bool f=true;
				he[i][j]=1;he[j][i]=-1;
				REP(k,26){
					if(he[j][k]==1){
						if(he[i][k]==-1 || he[k][i]==1){ f=false;break;}
					}
				}
				if(!f){
					f=true;
					he[i][j]=-1;
					he[j][i]=1;
					REP(k,26){
					if(he[j][k]==-1){
						if(he[i][k]==1 || he[k][i]==-1){ f=false;break;}
					}
					}
					if(!f){cout<<"Impossible"<<endl;return 0;}
				}
			}
		}
	}
	pair<int,int> cnt[26];
	REP(i,26){
		cnt[i]=mp(0,i);
		REP(j,26) cnt[i].first+=he[i][j];
	}
	sort(cnt,cnt+26);
	reverse(cnt,cnt+26);
	REP(i,26) cout<<(char)(cnt[i].second+'a');
	cout<<endl;
}


