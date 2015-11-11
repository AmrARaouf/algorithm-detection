//Language: MS C++


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define sqr(x) ((x)*(x))
#define LL long long
#define eps 1e-9
#define INF 0x7fffffff
#define pi acos(-1.0);
#define CLR(x,v) memset(x,v,sizeof(x));
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define maxn 505
LL a[maxn][maxn];
LL b[maxn];
LL c[maxn];
int main(int argc,char* argv[])
{
    std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    FOR(i,0,n)
        FOR(j,0,n)
        cin>>a[i][j];
    for(int i=n-1;i>=0;b[i]--,i--)
        cin>>b[i];
    FOR(k,0,n)
    {
        FOR(i,0,n)
            FOR(j,0,n)
            if(a[b[i]][b[j]]>a[b[i]][b[k]]+a[b[k]][b[j]])
                a[b[i]][b[j]]=a[b[i]][b[k]]+a[b[k]][b[j]];
        FOR(i,0,k+1)
            FOR(j,0,k+1)
            c[k]+=a[b[i]][b[j]];
    }
    for(int i=n-1;i>=1;i--) cout<<c[i]<<" ";
    cout<<c[0]<<endl;
	return 0;
}

