//Language: GNU C++


#include<cstdio>
using namespace std;
const int maxn=101;
struct NOD{
    int x,y;
}nod[maxn];
int par[maxn];
int gr(int c){
    while(par[c])c=par[c];
    return c;
}
int mask[maxn];
int used(int i){
    while(i&&!mask[i]){
        mask[i]=1;
        i=par[i];
    }
    return i;
}
int main(){
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i)scanf("%d%d",&nod[i].x,&nod[i].y);
    int ra,rb;
    for(i=1;i<=n;++i){
        for(j=i+1;j<=n;++j){
            if(nod[i].x==nod[j].x||nod[i].y==nod[j].y){
                ra=gr(i);
                rb=gr(j);
                if(ra!=rb){
                    par[i]=j;
                    par[ra]=rb;
                }
            }
        }
    }
    int res=0;
    for(i=1;i<=n;++i){
        if(!used(i))++res;
    }
    printf("%d\n",res-1);
    return 0;
}