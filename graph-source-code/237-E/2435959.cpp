//Language: GNU C++


#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int mm=120000;
int len=1,i,j,k,l,n,m,next[mm],head[mm],c[mm],v[mm],
    dis[mm],flag[mm],st[mm],bfs[mm],ans,e[mm],s,t,r,x,cnt;
char ch[mm],C[mm];
void add(int x,int y,int p,int k){
    next[++len]=head[x]; head[x]=len; e[len]=y; c[len]=p; v[len]=k;
    next[++len]=head[y]; head[y]=len; e[len]=x; c[len]=0; v[len]=-k;
}
void Minflow(){
    while(true){
        cnt++;
        for(i=s;i<=t;++i)dis[i]=1e9,flag[i]=0;
        dis[s]=0;
        bfs[l=r=1]=s;
        while(l<=r){
            x=bfs[l++]; flag[x]=0;
            for(i=head[x];i;i=next[i])if(c[i] && dis[x]+v[i]<dis[e[i]]){
                dis[e[i]]=dis[x]+v[i];
                st[e[i]]=i;
                if(!flag[e[i]]){
                    flag[e[i]]=1;
                    bfs[++r]=e[i];
                }
            }
        }
        if(dis[t]>=1e8)return;
        ans+=dis[t];
        for(i=t;i!=s;i=e[st[i]^1]){
            c[st[i]]--;
            c[st[i]^1]++;
        }
    }
}
int main(){
    scanf("%s",C+1);
    scanf("%d",&n);
    s=0;
    for(i=1;i<=n;++i){
        scanf("%s",ch+1);
        l=strlen(ch+1);
        scanf("%d",&x);
        add(s,i,x,i);
        for(j=1;j<=l;++j)add(i,n+ch[j]-96,1,0);
    }
    t=n+27;
    for(i=1;i<=strlen(C+1);++i)add(n+C[i]-96,t,1,0);
    Minflow();
    if(cnt==strlen(C+1)+1)printf("%d\n",ans);
    else printf("-1\n");
}