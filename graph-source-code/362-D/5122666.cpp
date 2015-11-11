//Language: GNU C++


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
typedef long double ld;
typedef pair<int,int> pii;
void read(int&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
char getc(){char c;for(c=getchar();c<=32;c=getchar());return c;}

const int inf=1000000000;
int n,m,i,j,k,l,p,q,e[100010][3],x,y,z,d,c1,c2,xx,yy;
ll sum[100010];
multiset<pair<ll,int> > S;
multiset<pair<ll,int> >::iterator i1,i2;
int fa[100010];
ll ans,res,t1,t2;

int get(int i){return fa[i]==i?i:fa[i]=get(fa[i]);}

vector<pii> V;vector<pii>::iterator pos;

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    read(n);read(m);read(p);read(q);

    rep(i,1,n)fa[i]=i;
    rep(i,1,m)
    {
        read(e[i][0]),read(e[i][1]),read(e[i][2]);
        x=e[i][0];y=e[i][1];
        fa[get(x)]=get(y);

        xx=x;yy=y;
    }
    rep(i,1,m)
    {
        x=e[i][0];y=e[i][1];z=e[i][2];
        sum[get(x)]+=z;
    }
    rep(i,1,n)if(get(i)==i)d++,S.insert(mp(sum[i],i));

    if(d<q){printf("NO\n");return 0;}

    if(q==d&&q==n&&(p>0)){printf("NO\n");return 0;}


    while(p>0&&d>q)
    {
        t1=(*S.begin()).fi;
        c1=(*S.begin()).se;
        S.erase(S.begin());
        t2=(*S.begin()).fi;
        c2=(*S.begin()).se;
        S.erase(S.begin());
        res=min(t1+t2+1,1LL*inf);
        ans+=res;
        S.insert(mp(res+t1+t2,c1));
        V.push_back(mp(c1,c2));
        xx=c1;yy=c2;d--;p--;
    }
    if(d>q){printf("NO\n");return 0;}



    while(p)p--,ans+=1000,V.push_back(mp(xx,yy));

    printf("YES\n");
    ALL(pos,V)printf("%d %d\n",pos->fi,pos->se);
    //cout<<ans<<endl;

    scanf("\n");
    return 0;
}
