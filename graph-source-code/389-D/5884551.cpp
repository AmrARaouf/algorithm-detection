//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
using namespace std;
#define inf 99999999
typedef long long int lli;
typedef pair<int,int> ii;

int g[1000][1000],A[20];

int cnt;
int main() {
	lli k;
	cin>>k;
	memset(g,0,sizeof g);

	int sz=0;
	lli num=k;

	while(num) {
		sz++;
		num/=10;
	}
	// cout<<sz<<endl;
	vector<int> v(sz);

	cnt=2;
	while(k) {
		// cout<<"yay "<<k<<" ";
		lli val=1;
		while(val<k) {
			if(val==k)
				break;
			val*=10;
		}
		if(val>k)
			val/=10;
		// cout<<val<<endl;
		if(val==1) {
			v[0]=cnt;
			A[0]=k;
			cnt+=k;
			for(int i=1;i<sz;i++) {
				v[i]=cnt;
				cnt++;
				A[i]=1;
			}
			k=0;			
			// for(int i=cnt;(i-cnt)<k;i++) {
			// 	g[0][i]=1;
			// 	g[i][0]=1;
			// 	g[1][i]=1;
			// 	g[i][1]=1;
			// }
			// cnt+=k;
			// k=0;
		}
		else {
			// vector<int> v;
			lli num=1;
			int idx=0;
			while(num<val) {
				v[idx]=cnt;
				cnt+=10;
				A[idx]=10;
				num*=10;
				idx++;
			}
			v[idx]=cnt;
			A[idx]=k/val;
			idx++;
			cnt+=k/val;
			for(;idx<sz;idx++) {
				v[idx]=cnt;
				A[idx]=1;
				cnt++;
			}
			// for(int i=0;i<v.size();i++)
			// 	cout<<v[i]<<" ";
			// cout<<endl;
			k=k%val;
		}
		for(int i=v[0];(i-v[0])<A[0];i++) {
			g[i][0]=1;
			g[0][i]=1;
		}
		for(int i=v[sz-1];(i-v[sz-1])<A[sz-1];i++) {
			g[i][1]=1;
			g[1][i]=1;
		}

		for(int i=0;i<(sz-1);i++) {

			for(int a=v[i];(a-v[i])<A[i];a++) {
				for(int b=v[i+1];(b-v[i+1])<A[i+1];b++) {
					// if((i+2)==v.size() && (b-v[i+1])==(k/val))
					// 	break;
					g[a][b]=1;
					g[b][a]=1;
				}
			}

		}
	}
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++) {
		for(int j=0;j<cnt;j++) {
			if(g[i][j])
				printf("Y");
			else
				printf("N");
		}
		printf("\n");
	}
	return 0;
}