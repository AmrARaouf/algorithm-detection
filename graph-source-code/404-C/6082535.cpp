//Language: GNU C++


#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <string> vs;

typedef long long LL; //NOTES:int64
typedef unsigned long long ULL; //NOTES:uint64
typedef unsigned uint;

const double pi = acos(-1.0); //NOTES:pi
const double eps = 1e-11; //NOTES:eps
const int MAXI = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dz[] = "SENW";

#define rep(i,n)        for (int i=0;i<n;i++)
#define loop(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define rloop(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define Reset(a,b)      memset((a),(b),sizeof(a))

#define endline         putchar('\n')
#define space           putchar(' ')
#define EXIT(x)         {cout << x;return 0;}

#define fi              first
#define se              second
#define pb              push_back

#define S(x)            scanf("%d",&x);
#define input freopen("input.txt","r",stdin);
#define deb(i,a,n) for(i=0;i<n;i++){cout<<a[i]<<" ";}
#define db(x,y)          printf("%d %d\n",x,y);
#define debug(args...)  {dbg,args; cerr<<endl;}
#define dline           cerr<<endl  
#define INF             (int)1e9
#define LINF            (long long)1e18
#define EPS             1e-9
#define maX(a,b)        ((a)>(b)?(a):(b))
#define miN(a,b)        ((a)<(b)?(a):(b))
#define abS(x)          ((x)<0?-(x):(x))
#define mod             1000000007

struct debugger
{
    template<typename T> debugger& operator , (const T& v)
    {   
        cerr<<v<<" ";   
        return *this;   
    }
} dbg;

void debugarr(int * arr,int n)
{
    cout<<"[";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"]"<<endl;
}

int a[100010];
char str[100010];
vector < pair<int,int> > b,ans;
int cnt[1000010];
int main()
{
    #ifndef ONLINE_JUDGE
        input;
    #endif
    int n,i,j,k,l,m,t,s=0,d;
    S(n);S(k);
    for(i=0;i<n;i++)
    {
        S(a[i]);    
        b.pb(make_pair(a[i],i+1));
    }
    sort(b.begin(),b.end());
    
    if(b[0].first!=0)
    {
        printf("-1\n");
        return (0);
    }
    if(n>1&&b[0].first==b[1].first)
    {
        printf("-1\n");
        return (0);
    }
    // cout<<"HI"<<endl;
    i=0;
    s=k;
    j=1;
    l=j;
    m=k;
    while(1)
    {
        // cout<<b[j].first<<' '<<b[i].first<<endl;
        if(j>=n)
            break;
        if(cnt[i]==k) {i++;cnt[i]=1;}

        if(b[j].first-b[i].first!=1)
        {
            
            printf("-1\n");
            return (0);
        }
        cnt[i]++;
        ans.pb(make_pair(b[i].second,b[j].second));
        j++;
        if(j>=n)
            break;
        if(b[j].first!=b[j-1].first) { i=l;l=j; if(i!=0) cnt[i]=1;}


    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return (0);
}