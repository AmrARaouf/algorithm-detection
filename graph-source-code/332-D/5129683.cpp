//Language: GNU C++


/*
    Problem:
    Algorithm:
    Note:
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<string>
#include<iomanip>
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

#define rep(i,x,y) for(i=x;i<=y;i++)
#define _rep(i,x,y) for(i=x;i>=y;i--)
#define CL(S,x) memset(S,x,sizeof(S))
#define CP(S1,S2) memcpy(S1,S2,sizeof(S2))
#define ALL(x,S) for(x=S.begin();x!=S.end();x++)
#define sqr(x) ((x)*(x))
#define mp make_pair
#define fi first
#define se second
#define upmin(x,y) x=min(x,y)
#define upmax(x,y) x=max(x,y)

typedef long long ll;
typedef long double real;
void read(int&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
char getc(){char c;for(c=getchar();c<=32;c=getchar());return c;}

const real eps=1e-6;
const int N=2010;
int n,i,j,k,l,p,x,cnt,d;
int a[N][N],C[N][N];ll sum;
real res,ans;ll u;

int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    read(n);read(k);
    CL(a,-1);rep(i,1,n)rep(j,i+1,n)read(x),a[i][j]=a[j][i]=x;
    
    rep(i,1,n)
    {
        sum=0;d=0;rep(j,1,n)if(a[i][j]>=0)d++,sum+=a[i][j];
        
        if(d>=k)
        {
            res=1.0*sum*k/n;rep(j,1,k-1)res*=1.0*(d-j)/(n-j);
            ans+=res;
        }
    }
    
    u=ll(ans+eps);
    cout<<u<<endl;
    scanf("\n");
    return 0;
}
