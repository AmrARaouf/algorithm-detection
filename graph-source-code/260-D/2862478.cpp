//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct NODE{
	long h,d;
}b[100006],w[100006];
struct EDGE{
	long u,v,w;
}e[100006];
long bsum,wsum;
int main(){
	std::ios::sync_with_stdio(false);	
	long i,j,k,n;
	cin >> n;
	for (i=1;i<=n;++i){
		cin >> j >> k;
		if (j==0){
			++wsum;
			w[wsum].h=k;
			w[wsum].d=i;
		}
		else{
			++bsum;
			b[bsum].h=k;
			b[bsum].d=i;
		}
	}
	for (k=0,i=j=1;i<=bsum && j<=wsum;){
		++k;
		e[k].u=b[i].d;
		e[k].v=w[j].d;
		if (b[i].h<w[j].h){
			w[j].h-=b[i].h;
			e[k].w=b[i].h;
			++i;
		}
		else{
			b[i].h-=w[j].h;
			e[k].w=w[j].h;
			++j;
		}
	}
	for (++i;i<=bsum;++i){
		++k;
		e[k].u=b[i].d;
		e[k].v=w[1].d;
	}
	for (++j;j<=wsum;++j){
		++k;
		e[k].u=b[1].d;
		e[k].v=w[j].d;
	}
	for (i=1;i<n;++i)
		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl;
	return 0;
}

