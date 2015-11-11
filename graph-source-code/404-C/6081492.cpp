//Language: GNU C++


#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long int Lint;
typedef pair <Lint,Lint> ii;
Lint N,M,cnt[110000],yer[110000],say[110000];
vector <Lint> v[110000];
vector <ii> res;
ii ar[110000];

int main(){
	
	cin >> N >> M;
	
	for( int i=1 ; i<=N ; i++ ){	scanf(" %d",&ar[i].fi); ar[i].se=i;	cnt[ar[i].fi]++; v[ar[i].fi].push_back( i ); }
	
	sort( ar+1 , ar+1+N );
	int root=ar[1].se;
	
	if( cnt[0] != 1 || cnt[1] > M ){
		printf("-1\n");
		return 0;
	}
	M--;
	for( int i=2 ; i<N ; i++ ) if( cnt[i]>cnt[i-1]*M ){
		printf("-1\n");
		return 0;
	}
	
	for( int i=2 ; i<=N ; i++ ){
		
		if( (v[ar[i].fi-1][yer[ar[i].fi-1]] != root && say[v[ar[i].fi-1][yer[ar[i].fi-1]]] == M) || v[ar[i].fi-1][yer[ar[i].fi-1]] == root && say[root] == M+1 )	yer[ar[i].fi-1]++;
		//~ if( v[ar[i].fi-1].size() ==yer[ar[i].fi-1] ){
			//~ printf("-1\n");
			//~ return 0;
		//~ }
		res.push_back( ii(v[ar[i].fi-1][yer[ar[i].fi-1]],ar[i].se) );
		say[v[ar[i].fi-1][yer[ar[i].fi-1]]]++;
	}
	
	cout << res.size() << endl;
	for( int i=0 ; i<(int)res.size() ; i++ ) printf("%I64d %I64d\n",res[i].fi,res[i].se);
	
	return 0;
	
}
