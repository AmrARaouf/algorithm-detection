//Language: MS C++


#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace::std;

int n,m,sum,m1,m2,sx,sy,mm,q,e;
int a[1005][1005];
int s[3][1005][1005];
int la[1005][1005];
bool ch[1005][1005];
int que[1000015][3];
int dx[5]={0,1,0,-1,};
int dy[5]={1,0,-1,0,};

int GCD(int v1,int v2){
    if(v1==v2 || v2==0)
        return v1;
    if(v1==0)
         return v2;
    if(v1>v2)
        return GCD(v2,v1%v2);
    return GCD(v1,v2%v1);
}

int main(){
    int i,j,k,l,j1,k1,ll=-1;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==1 && sx==0)
                sx=i,sy=j;
            if(a[i][j]==1 && i==sx && j>m2)
                m2=j;
            if(a[i][j]==1 && j==sy && i>m1)
                m1=i;
            sum+=a[i][j];
            s[0][i][j]=s[0][i][j-1]+a[i][j];
            s[1][i][j]=s[1][i-1][j]+a[i][j];
        }
    if(sx!=0){
        que[++q][0]=sx;
        que[q][1]=sy;
        ch[sx][sy]=true;
        while(q!=e){
            e++;
            for(i=0;i<4;i++)
                if(a[que[e][0]+dx[i]][que[e][1]+dy[i]]==1 && !ch[que[e][0]+dx[i]][que[e][1]+dy[i]]){
                    que[++q][0]=que[e][0]+dx[i];
                    que[q][1]=que[e][1]+dy[i];
                    ch[que[e][0]+dx[i]][que[e][1]+dy[i]]=true;
                }
        }
        if(e!=sum){
            printf("-1");
            ll++;
        }
    }
    else{
            printf("-1");
            ll++;
        }
    if(ll==-1){
    mm=GCD(m1-sx,m2-sy);
    for(i=2;i<=mm;i++){
        if(mm%i==0){
            int no1=0,no2=0;
            for(j=sx%i;j<=n;j+=i)
                for(k=sy%i;k<=m;k+=i)
                    la[j][k]=0;
            for(j=sx%i;j<=n;j+=i)
                for(k=sy%i;k<=m;k+=i)
                    if(a[j][k]==1){
                        no1++;
                        for(l=0;l<2;l++){
                            j1=j+dx[l]*i;
                            k1=k+dy[l]*i;
                            if(j1<=n && k1<=m && a[j1][k1]==1 && s[l][j1][k1]-s[l][j][k]==i){
                                no2++;
                                la[j][k]++;
                                la[j1][k1]++;
                            }
                        }
                    }
            if(no1+no2*(i-1)==sum){
                int la1=0;
                for(j=sx%i;j<=n;j+=i)
                    for(k=sy%i;k<=m;k+=i)
                        if(la[j][k]%2==1)
                            la1++;
                if(la1==0 || la1==2){
                    ll++;
                    printf("%d ",i);
                }
            }
        }
    }
    if(ll==-1)
        printf("%d",ll);
    }
    return 0;
}