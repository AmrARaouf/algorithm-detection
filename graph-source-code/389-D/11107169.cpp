//Language: GNU C++


#include<bits/stdc++.h>
#define in freopen("input.txt","r",stdin)
#define out freopen("output.txt","w",stdout)

#define inp freopen(".in","r",stdin)
#define outp freopen(".out","w",stdout)

using namespace std;

#define pb push_back
#define pf push_front
#define p_f pop_front
#define p_b pop_back
#define LL long long int
#define LD long double
#define MP make_pair
#define sqr(x) (x*x)
#define fi first
#define dist(x,y,xx,yy) sqrt( (x-xx)*(x-xx)+(y-yy)*(y-yy) )
#define lenint int intsi(int x){ int cnt=0; while(x>0){cnt++;x/=10;} return (cnt); }
#define se second
#define all(v) v.begin(),v.end()
#define sc scanf
#define DEBUG(a) cout<<#a<<" -> "<<a<<endl;
#define pr printf
#define si size()
#define str strlen
#define time clock()/(double)CLOCKS_PER_SEC
#define gcd LL GCD(LL a,LL b){ if(b==0)return a;else return GCD(b,a%b); }
const int INF=(-1u)/2;
const long long int INF2=(-1ull)/2;
int a,b,i,j,k,n,m,timer=0,l,r,x,y,len=0,flag,d[100010],vertex;
int c[1100][1100],cnt=0,fl=0,a2,a3=-1000000,ans=0,node=2;
main()
{
    #ifndef ONLINE_JUDGE
        in;out;
    #endif
    ios_base::sync_with_stdio(0);
    cin>>k;
    cnt=0;
    fl=1;
    for( i=1;i<=29;i++ )fl*=2;
    cnt=29;
    x=1;
    while( cnt>0 )
    {
        c[x][node+1]=1;
        c[node+1][x]=1;
        c[x][node+2]=1;
        c[node+2][x]=1;
        c[node+3][node+1]=1;
        c[node+1][node+3]=1;
        c[node+3][node+2]=1;
        c[node+2][node+3]=1;
        x=node+3;
        cnt--;
        node+=3;
    }
    vertex=node;
    len=0;
    while(k>0)
    {
        if( k-fl>=0 )
        {
            if(vertex==2)vertex--;
            for( i=1;i<=len;i++ )
            {
                if( i==1 )c[vertex][node+1]=1,c[node+1][vertex]=1,node++;
                else c[node][node+1]=1,c[node+1][node]=1,node++;
            }
            c[node][2]=1;
            c[2][node]=1;
            k-=fl;
        }
        fl/=2;
        len+=2;
        vertex-=3;
    }
    cout<<node<<endl;
    for( i=1;i<=node;i++ )
    {
        for( j=1;j<=node;j++ )
        {
            if( c[i][j]==1 )cout<<"Y";
            else cout<<"N";
        }
        cout<<endl;
    }
    return 0;
}
