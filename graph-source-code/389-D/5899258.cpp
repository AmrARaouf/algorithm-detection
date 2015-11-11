//Language: GNU C++


#include<bits/stdc++.h>
using namespace std;

#define REP0(i,n) for(int i=0;i<n;++i)
#define REP1(i,n) for(int i=1;i<=n;++i)
#define ALL(c) (c).begin(),(c).end()
vector<string> G(1000);
int now=1;

void con(int a,int b){
//	if(b==1 || a==1) cout << a << b << endl;
	G[a][b]='Y';
	G[b][a]='Y';
	return;
}
int main(){
	int k;
	cin >> k;
	string sss(1000,'N');
	REP0(i,1000) G[i]=sss;
	for(int i=0;k>0;i++){
		if(k%10){
			REP1(p,k%10){
				con(0,now+p);
				con(now+k%10+1,now+p);
			}
			now=now+k%10+1;
			REP0(j,i){
				REP1(p,10){
					con(now,now+p);
					con(now+11,now+p);
				}
				now=now+11;
			}
			REP0(j,20-2*i){
				con(now,now+1);
				now++;
			}
			con(now,1);
			now++;
		}
		k/=10;
		if(k==0) break;
	}
	cout << now << endl;
	REP0(i,now){
		REP0(j,now){
			//if(G[i][j]=='Y') cout << i << " " << j << endl;
			cout << G[i][j];
		}
		cout << endl;
	}
	return 0;
}