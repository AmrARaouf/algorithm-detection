//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

const int MaxN=105;
const int N=100;

int vis[MaxN][MaxN];

int C(int n,int m)
{
    int res=1;
    for(int i=0;i<m;i++) res*=n-i;
    for(int i=1;i<=m;i++) res/=i;
    return res;
}

int main()
{
    int K;
    while(scanf("%d",&K)!=EOF)
    {
        memset(vis,0,sizeof(vis));

        int ind=-1;
        for(int i=2;i<N;i++) if(C(i+1,3)>K)
        {
            ind=i; break;
        }
        K-=C(ind,3);

        for(int i=0;i<ind;i++)
        {
            for(int j=0;j<ind;j++) if(i!=j)
            {
                vis[i][j]=1;
            }
        }

        int ans=ind;
        while(K)
        {
            ind=-1;
            for(int i=2;i<100;i++) if(C(i+1,2)>K)
            {
                ind=i; break;
            }
            K-=C(ind,2);
            for(int i=0;i<ind;i++)
            {
                vis[ans][i]=vis[i][ans]=1;
            }
            ans++;
        }
        printf("%d\n",ans);
        for(int i=0;i<ans;i++,puts(""))
        {
            for(int j=0;j<ans;j++) printf("%d",vis[i][j]);
        }
    }
    return 0;
}
