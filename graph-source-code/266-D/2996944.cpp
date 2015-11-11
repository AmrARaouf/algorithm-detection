//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <sstream>
using namespace std;

int a[222][222];
int edge[44444][3];
vector<pair<int,int> > V;
pair<int,int> z[222];
int n,m,ans;

int main(){
    while (scanf("%d%d",&n,&m)==2){
        memset(a,10,sizeof(a));
        for (int i=1,p1,p2,p3;i<=m;++i){
            scanf("%d%d%d",&p1,&p2,&p3);
            a[p1][p2]=a[p2][p1]=p3;
            edge[i][0]=p1;
            edge[i][1]=p2;
            edge[i][2]=p3;
        }
        for (int i=1;i<=n;++i) a[i][i]=0;
        for (int k=1;k<=n;++k)
            for (int i=1;i<=n;++i)
                for (int j=1;j<=n;++j)
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        ans=100000000;
        for (int j=1;j<=m;++j){
            V.clear();
            int num=0;
            for (int i=1;i<=n;++i)
                V.push_back(make_pair(a[i][edge[j][0]],a[i][edge[j][1]]));
            sort(V.begin(),V.end());
            for (int i=0;i<n;++i){
                while (num && z[num].second<V[i].second) --num;
                z[++num]=V[i];
            }
            int tmp=100000000;
            if (num==1) tmp=z[1].first+z[1].second;
            for (int i=2;i<=num;++i)
                tmp=min(tmp,z[i-1].first+z[i].second);
            ans=min(ans,tmp+edge[j][2]);
        }
        printf("%.4f\n",ans*0.5);
    }
    return 0;
}
