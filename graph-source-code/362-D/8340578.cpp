//Language: GNU C++


#include <set>
#include <queue>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
class DREAD{
	friend int fread();
	static const int buff_max=20000000+10;
	char buf[buff_max],*pt;
	public:
		void clear(){ for(; isspace(*pt); ++pt); }
		void Init(){ buf[fread(buf,1,buff_max,stdin)]=EOF;pt=buf; }
		bool eoln(){ return *pt=='\n'; }
		inline bool eof(){ return *pt==EOF; }
		int Int(){
			bool pos=1;int res=0;
			for (; !isdigit(*pt) && *pt!='-' && !eof(); ++pt);if (*pt=='-') pos=0,++pt;
			for (; isdigit(*pt); ++pt) res=res*10+(*pt-'0');
			return pos?res:-res;
		}
}READ;
typedef long long int64;
const int N_MAX=100000+10;
const int64 inf=1000000000;
struct Tufset{
	struct Titem{
		int fa;int64 len;
		Titem(){}
		Titem(int _fa,int64 _len){ fa=_fa,len=_len; }
	}item[N_MAX];
	Titem& operator[](const int p){ return item[p]; }
	void init(int _N){ for (int i=1; i<=_N; ++i) item[i]=Titem(i,0); }
	int root(int x){ return item[x].fa==x?x:item[x].fa=root(item[x].fa); }
	int merge(int x,int y,int64 len=1){
		x=root(x); y=root(y);
		if (x==y){ item[x].len+=len;return y; }
		item[x].fa=y; item[y].len+=item[x].len+len;
		return y;
	}
}S;
int N,M,P,Q,u=-1,v;
namespace Ninit{
	void init(){
		N=READ.Int(),M=READ.Int(),P=READ.Int(),Q=READ.Int();
		S.init(N);
		for (int i=1; i<=M; ++i){
			u=READ.Int(),v=READ.Int();int len=READ.Int();
			S.merge(u,v,len);
		}
	}
}
#define item Tufset::Titem
namespace Nwork{
	struct cmp1{
		bool operator()(item &a,item &b){ return a.len>b.len; }
	};
	priority_queue<item,vector<item>,cmp1> Q1;
	struct AddEdge{
		int u,v;
		AddEdge(){}
		AddEdge(int _u,int _v){ u=_u,v=_v; }
		void print(){ printf("%d %d\n", u, v); }
	};
	vector<AddEdge> vec;bool vis[N_MAX];
	void main(){
		for (int i=1; i<=N; ++i) if (i==S[i].fa) Q1.push(S[i]);
		if (Q1.size()<Q){ puts("NO");return; }
		for (int i=1; i<=P; ++i)
			if (Q1.size()>Q){
				item a=Q1.top(); Q1.pop();
				item b=Q1.top(); Q1.pop();
				item c=item(S.merge(a.fa,b.fa),a.len+b.len+min(inf,a.len+b.len+1));
				vec.push_back(AddEdge(a.fa,b.fa));
				u=a.fa,v=b.fa;
				Q1.push(c);
			}
			else if (u!=-1) vec.push_back(AddEdge(u,v));
		if (vec.size()<P || Q1.size()>Q) puts("NO");
		else{
			puts("YES");
			for (int i=0; i<vec.size(); ++i) vec[i].print();
		}
	}
}
int main(){
	READ.Init();
	Ninit::init();
	Nwork::main();
	return 0;
}
 		 	 	 	      	 	 		  			  		