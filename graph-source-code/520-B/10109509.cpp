//Language: GNU C++


#include<cstdio>
#include<cstring>
#define N 100010
int d[N],q[N],n,k;
bool can_go(int x){
    if(x<0||x>100000)  return false;
    return true;
}
void bfs(){
    memset(d,-1,sizeof(d));
    int l=0,r=0;
    q[r++]=n;d[n]=0;
    while(l<r){
        int now=q[l];
        if(now==k){printf("%d\n",d[now]);return ;}
        if(can_go(now-1)&&d[now-1]==-1)d[now-1]=d[now]+1,q[r++]=now-1;
        if(can_go(now<<1)&&d[now<<1]==-1)d[now<<1]=d[now]+1,q[r++]=now<<1;
        l++;
    }
}
int main()
{
//	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
    scanf("%d%d",&n,&k);
    if(k<=n)return printf("%d\n",n-k),0;
    bfs(); 
    return 0;
}
