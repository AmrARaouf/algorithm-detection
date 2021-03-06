//Language: GNU C++


#include <bits/stdc++.h>
#define maxn 100020
#define fi first
#define se second

using namespace std;

typedef pair<int,int> ii;
ii ar[maxn];
int a,b,bs[maxn];
vector <ii> w;

int main()
{
	scanf("%d %d",&a,&b);
	
	for(int i=1;i<=a;i++)
		scanf("%d",&ar[i].fi) , ar[i].se = i;
	
	sort( ar+1 , ar+1+a );
	
	if( ar[1].fi ) {
		printf("-1\n");
		return 0;
	}
	
	for(int i=2,k=1;i<=a;i++) {
		while( ar[k].fi < ar[i].fi - 1 && k<i ) k++;
		//~ printf("asdas %d %d\n",k,i);
		while( bs[ar[k].se] == b && k<i ) k++;
		if( k >= i || ar[i].fi - ar[k].fi != 1 ) {
			printf("-1");
			return 0;
		}
		w.push_back( ii( ar[k].se , ar[i].se ) );
		bs[ar[k].se]++;
		bs[ar[i].se]++;
		if( bs[ar[k].se] == b ) k++;
	}
	
	printf("%d\n",w.size());
	for(int i=0;i<w.size();i++)
		printf("%d %d\n",w[i].fi,w[i].se);
	
	return 0;
}
