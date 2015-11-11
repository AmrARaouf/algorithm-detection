//Language: GNU C++


#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define LL long long
#define LB long double
#define mod 1000000007
#define inf 0x7f7f7f7f
#define infl 0x7f7f7f7f7f7f7f7fll
using namespace std;
inline int lowbit(int x){return x&-x;}
inline int ABS(int x){return x<0?-x:x;}
inline LL ABS(LL x){return x<0?-x:x;}
inline void MAX(int &a,int b){if(b>a)a=b;}
inline void MAX(LL &a,LL b){if(b>a)a=b;}
inline void MIN(int &a,int b){if(b<a)a=b;}
inline void MIN(LL &a,LL b){if(b<a)a=b;}
int fast(int x,int v){int ans=1;for(;v;v>>=1,x=(LL)x*x%mod)if(v&1)ans=(LL)ans*x%mod;return ans;}
LL fast(LL x,LL v){LL ans=1;for(;v;v>>=1,x=x*x%mod)if(v&1)ans=ans*x%mod;return ans;}

#define N 100005
#define M 300005

int n,m,son[N],next[M],ed[M],w[N],top,
	dfn[N],low[N],index,st[N];
LL ans1,ans2=1;
bool inst[N];

void tarjan(int x){
	dfn[x]=low[x]=++index;
	st[++top]=x;
	inst[x]=true;
	for(int j=son[x];j;j=next[j])
		if(inst[ed[j]]){
			MIN(low[x],low[ed[j]]);
		}else{
			if(dfn[ed[j]]) continue;
			tarjan(ed[j]);
			MIN(low[x],low[ed[j]]);
		}
	if(low[x]==dfn[x]){
		int Min=inf,cnt=0;
		while(st[top]!=x){
			if(w[st[top]]==Min)++cnt;
			if(w[st[top]]<Min){
				Min=w[st[top]];
				cnt=1;
			}
			inst[st[top]]=false;
			--top;
		}
		if(w[x]==Min)++cnt;
		if(w[x]<Min) Min=w[x],cnt=1;
		inst[x]=false;
		--top;
		ans2=ans2*cnt%mod;
		ans1+=Min;
	}
}

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",w+i);
	scanf("%d",&m);
	rep(i,1,m){
		int x,y; scanf("%d%d",&x,&y);
		next[i]=son[x],son[x]=i,ed[i]=y;
	}
	rep(i,1,n) if(!dfn[i]) tarjan(i);
	printf("%I64d %I64d\n",ans1,ans2);
}

