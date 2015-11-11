//Language: GNU C++


#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,k,u[100001],v[100001],x[100001],c[501],ui,vi,check,p[100001],r[100001];
int d[505][505],t,par,cnt;
vector<int> V;
int fnd(int i){
	if(p[i]==i)
		return i;
	else return p[i];
}
void uni(int i,int j){
	i=fnd(i);
	j=fnd(j);
	if(i==j)
		return ;
	if(r[i]<r[j]){
		p[i]=j;
	}
	else{
		p[j]=i;
		if(r[i]==r[j]) r[i]++;
	}

}

int main(void){
	//freopen("input.txt","r",stdin);
	for(int i=0; i<505; i++){
		for(int j=0; j<505; j++)
			d[i][j]=999999999;
	}
	
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1; i<=n; i++){
		p[i]=i;
	}
	for(int i=0; i<k; i++){
		scanf("%d",&c[i]);
		if(c[i]==1){
			d[i][i]=0;
			cnt++;
		}
		t+=c[i];
		V.push_back(t);
	}
	
	for(int i=0; i<m; i++){
		scanf("%d %d %d",&u[i],&v[i],&x[i]);
		ui=upper_bound(V.begin(),V.end(),u[i]-1)-V.begin();
		vi=upper_bound(V.begin(),V.end(),v[i]-1)-V.begin();
		d[ui][vi]=min(x[i],d[ui][vi]);
		d[vi][ui]=min(x[i],d[vi][ui]);
		if(x[i]==0){
			uni(u[i],v[i]);
		}
	}
	t=0;
	for(int i=0; i<k; i++){
		for(int j=2; j<c[i]; j++){
			if(fnd(j+t)!=fnd(j-1+t))
				check=1;
		}
		t+=c[i];
	}
	/*
	for(int i=1; i<=n; i++){
		ui=upper_bound(V.begin(),V.end(),i-1)-V.begin();
		if(c[ui]!=1){
			if(par!=fnd(i))
				check=1;
		}
	}*/
	

	for(int q=0; q<k; q++){
		for(int i=0; i<k; i++){
			for(int j=0; j<k; j++){
				d[i][j]=min(d[i][j],d[i][q]+d[q][j]);
				
			}
			
		}
	}

	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			if(i==j && d[i][j]!=0)
				check=1;
			if(d[i][j]==999999999)
				d[i][j]=-1;
		}
	}
	
	if(check){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			printf("%d ",d[i][j]);
		}
		puts("");
	}
	return 0;
}