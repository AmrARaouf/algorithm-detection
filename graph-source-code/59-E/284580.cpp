//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct stuff{
	int a,b,c;
	bool operator <(const stuff &X) const{
		if(a != X.a) return a < X.a;
		if(b != X.b) return b < X.b;
		return c < X.c;
	}
}S[100001],t1,t2;
struct point{int a,b;}tmp,ins;
int N,M,K,x,y,pred[3001][3001],P[100];
bool visit[3001][3001],flag;
vector <int> G[3001],A;
queue <point> q;

bool cmp1(int a,int b){
	return visit[a][0] < visit[b][0];
}

inline bool can(stuff a,stuff b){
	if(a.a == b.a && a.b == b.b && a.c == b.c) return 0;
	return 1;
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;++i){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=0;i<K;++i) scanf("%d%d%d",&S[i].a,&S[i].b,&S[i].c);
	sort(S,S+K);
	tmp.a = 0;
	tmp.b = 1;
	q.push(tmp);
	while(!q.empty()){
		tmp = q.front();
	//	printf("checking (%d %d) with pred %d\n",tmp, pred[tmp.a][tmp.b]);
	//	system("pause");
		q.pop();
		t1.a = tmp.a;
		t1.b = tmp.b;
		if(tmp.b == N){
			flag = 1;
			break;
		}
		for(int i=0;i<G[t1.b].size();++i)
			if(!visit[t1.b][G[t1.b][i]]){
				t1.c = G[t1.b][i];
				x = lower_bound(S,S+K,t1)-S;
				if(S[x].a == t1.a && S[x].b == t1.b && S[x].c == t1.c) continue;
				if(can(t1,t2)){
					ins.a = t1.b;
					ins.b = t1.c;
					visit[ins.a][ins.b] = 1;
					q.push(ins);
					pred[ins.a][ins.b] = tmp.a;
				}
			}
	}	
	if(!flag){
		printf("-1\n");
		return 0;
	}
	ins.a = 0;
	ins.b = 1;
	A.push_back(tmp.b);
	A.push_back(tmp.a);
//	printf("done\n");
//	system("pause");
	while(1){
//		printf("(%d %d) and pred %d\n",tmp.a,tmp.b,pred[tmp.a][tmp.b]);
//		system("pause");
		x = pred[tmp.a][tmp.b];
		if(x == 0) break;
		tmp.b = tmp.a;
		tmp.a = x;
		A.push_back(x);
	}
	reverse(A.begin(),A.end());
	printf("%d\n",A.size()-1);
	for(int i=0;i<A.size();++i) printf("%d ",A[i]);
	printf("\n");
	//system("pause");
}





