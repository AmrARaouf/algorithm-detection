//Language: MS C++


#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 2005;
typedef __int64 ll;
int d[N];
typedef pair<int,int> per;
#define mp(x,y) make_pair(x,y)
vector<per>E[N];
double c[N][N];
int main()
{
    int n,i,j,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<N;i++)c[i][0]=c[i][i]=1.0;
    for(i=2;i<N;i++)for(j=1;j<i;j++)c[i][j]=c[i-1][j-1]+c[i-1][j];
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            int v;
            scanf("%d",&v);
            if(v!=-1)
            {
                d[i]++;
                d[j]++;
                E[i].push_back(mp(j,v));
                E[j].push_back(mp(i,v));
            }
        }
    }
    double r=0.0;
    for(i=1;i<=n;i++)if(d[i]>=k)
    {
        int sz=E[i].size();
        double tot=0.0;
        for(j=0;j<sz;j++)
        {
            tot+=E[i][j].second;
        }
        //printf("tot:%lf \n",tot);
        r+=(tot*(c[d[i]-1][k-1]/c[n][k])+1e-8);
    }
    //r/=c[n][k];
    ll ret=(ll)r;
    printf("%I64d\n",ret);
    return 0;
}