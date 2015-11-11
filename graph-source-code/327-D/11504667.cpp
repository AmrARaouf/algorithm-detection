//Language: GNU C++


#include<bits/stdc++.h>

using namespace std;

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

vector < pair < char , ii > > ans;
ii root;
int nr[] = { -1 , 1 , 0 , 0 } , n , m ;
int nc[] = { 0 , 0 , 1 , -1 };
char a[509][509];

void dfs( int x , int y )
{
    ans.push_back( make_pair( 'B' , ii( x , y ) ) ) ;
    a[x][y] = 'B';
    REP( i , 0 , 3 )
    {
        int nx = x + nr[i];
        int ny = y + nc[i];
        if( nx >= 0 && nx < n && ny >= 0 && ny < m )
        if( a[nx][ny] == '.' )
            dfs( nx , ny );
    }
    if( x != root.first || y != root.second )
    {
        a[x][y] = 'R';
        ans.push_back(make_pair('D',ii(x,y)));
        ans.push_back(make_pair('R',ii(x,y)));
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    s(n);s(m);
    REP( i , 0 , n - 1 )
    {
        scanf("%s",a[i]);
    }
    REP( i  , 0 , n - 1 )
    {
        REP( j , 0 , m - 1  )
        {
            if( a[i][j] == '.' )
            {
                root = make_pair( i , j );
                dfs( i , j );
            }
        }
    }
    printf("%d\n",ans.size());
    REP( i , 0 , ans.size() - 1)
    {
        pair < char , ii > u = ans[i];
        printf("%c %d %d\n",u.first , u.second.first + 1 , u.second.second + 1 );
    }
    return 0;
}
