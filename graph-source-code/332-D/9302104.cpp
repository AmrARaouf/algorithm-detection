//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
typedef long long LL;
const int Maxn=2005;
int n,k,cnt[Maxn];
LL sum[Maxn];

inline int get() {
	char ch; bool f=0;
	while (!isdigit(ch=getchar())) f|=ch=='-';
	int v=ch-48;
	while (isdigit(ch=getchar())) v=v*10+ch-48;
	return f?-v:v;
}

LL comb(int n,int k) {
	if (k>2) k=n-k;
	if (k==0) return 1;
	if (k==1) return n;
	return n*LL(n-1)/2;
}

int main() {
	n=get(); k=get();
	LL ans=0;
	for (int i=1;i<=n;i++) {
		for (int j=i+1,c;j<=n;j++)
			if ((c=get())!=-1) {
				sum[i]+=c;
				sum[j]+=c;
				++cnt[i];
				++cnt[j];
			}
		ans+=comb(cnt[i]-1,k-1)*sum[i];
	}
	ans/=comb(n,k);
	cout<<ans<<endl;
	return 0;
}