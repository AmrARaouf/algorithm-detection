//Language: GNU C++11


#include<bits/stdc++.h>

using namespace std;

// The codes which I use are taken from the book Competitive Programming 3 written by Steven Halim
// Shortcuts for "common" data types in contests
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
// To simplify repetitions/loops, Note: define your loop style and stick with it!
#define s(i) scanf("%d",&i)
#define sl(i) scanf("%ld",&i)
#define sll(i) scanf("%lld",&i)
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define NREP(i,a,b) \
for (int i = int(a); i >= int(b); i--)
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion

vector < ii > topo;
char str[]="DIMA";
int vis[1009][1009] , n , m , dp[1009][1009];
char a[1009][1009];
int nr[]={ 1 , -1 , 0 , 0 };
int nc[]={ 0 , 0 , -1 , 1 };

void dfs( int i , int j , int p )
{
    vis[i][j] = 2;
    REP( k , 0 , 3 )
    {
        int x = i + nr[k];
        int y = j + nc[k];
        if( x >= 0 && x < n && y >= 0 && y < m )
        {
            if( a[x][y] == str[(p + 1) % 4] && vis[x][y] == 2 )
            {
                printf("Poor Inna!\n");
                exit(0);
            }
            else if( a[x][y] == str[( p + 1 ) % 4] && vis[x][y] == -1 )
                dfs( x , y , ( p + 1 ) % 4 ) ;
        }
    }
    vis[i][j] = 1;
    topo.push_back( ii( i , j  ) );
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    memset( vis , -1 , sizeof(vis) );
    s(n);s(m);
    REP( i , 0 , n - 1 )
        scanf("%s",a[i]);
    REP( i , 0 , n - 1 )
    {
        REP( j , 0 , m - 1 )
        {
            if( vis[i][j] == -1 )
            {
                REP( k , 0 , 3 )
                {
                    if( a[i][j] == 'D' )
                    {
                        dfs( i , j , 0 );
                        break;
                    }
                }
            }
        }
    }
    reverse( topo.begin() , topo.end() );
    TRvii( topo , it )
    {
        ii u = *it;
        int val = 0;
        while( val <= 3 )
        {
            if( a[u.first][u.second] == str[val] )
                break;
            val++;
        }
        REP( p , 0 , 3 )
        {
            int x = u.first + nr[p];
            int y = u.second + nc[p];
            if( x >= 0 && x < n && y >= 0 && y < m && a[x][y] == str[(val + 1) % 4] )
            {
                dp[x][y] = max( dp[x][y] , 1 + dp[u.first][u.second] );
            }
        }
    }
    int maxi = 0;
    REP( i , 0 , n - 1 )
    {
        REP( j , 0 , m - 1 )
        {
            maxi = max( maxi , dp[i][j] );
        }
    }
    int ans = ( maxi + 1 ) / 4;
    if( ans == 0 )
        printf("Poor Dima!\n");
    else
        printf("%d\n",ans);
    return 0;
}
