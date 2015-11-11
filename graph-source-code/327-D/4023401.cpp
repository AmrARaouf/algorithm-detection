//Language: GNU C++


#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<string>
#include<list>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<deque>
#include<stack>

typedef long long lld;
typedef unsigned long long llu;
typedef unsigned int uint;

#define PI 3.14159265359
#define INFINITY ( 1 << 29 )
#define INFINITY_LONG ( 1LL << 50 )
#define OFFSET 32000
#define MODVAL 1000000007
#define E 2.71828182845904523
#define MAX 300
#define ISDIGIT(c) ( (c) >= '0' && (c) <= '9' )
#define CHECK_BIT(n,i) ( ( n >> i ) & 1 )
#define CHECK_ODD(n) ( n & 1 )
#define CHECK_VOWEL_Ucase(c) ( (c) == 'A' || (c) == 'E' || (c) == 'I' || (c) == 'O' || (c) == 'U' )
#define CHECK_VOWEL_Lcase(c) ( (c) == 'a' || (c) == 'e' || (c) == 'i' || (c) == 'o' || (c) == 'u' )
#define SET(arr,v) memset( arr , v , sizeof(arr) )
#define pf printf
#define sf scanf
#define ASMGETVAL(var) asm("movl %%eax, %0;" : "=r" (var))
#define FRO freopen("c:\\a.txt","r",stdin)

using namespace std;


//#define BUF 1048576
#define BUF 65536
class Reader {
    char buf[BUF], b; int bi, bz;
    
    void read() {
        if (bi==bz) { bi=0; bz = fread(buf, 1, BUF, stdin); }
        b = bz ? buf[bi++] : 0; }
    void skip() { while (b > 0 && b <= 32) read(); }
    
public:
    Reader(){ bi=bz=0; read(); }
    uint nextInt() {
        uint v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
};

class Job
{
public:
    int type, x, y;
    
    Job(){}
    
    Job( int a , int b , int c )
    {
        type = a;
        x = b;
        y = c;
    }
};

struct Point
{
    int x, y;
}t;

char grid[505][505];
bool v[505][505];
int r, c;
int move[][2] = { {-1,0} , {1,0} , {0,1} , {0,-1} };
vector<Job> jobs;
stack<Point> st;

inline bool valid( int i , int j )
{
    return i >= 0 && i < r && j >= 0 && j <= c;
}

void dfs( int i , int j )
{
    v[i][j] = true;
    int x, y, k;
    
    t.x = i;
    t.y = j;
    st.push(t);
    jobs.push_back(Job('B',i,j));
    
    for( k = 0 ; k < 4 ; k++ )
    {
        x = i + move[k][0];
        y = j + move[k][1];
        
        if( valid(x,y) && !v[x][y] && grid[x][y] == '.' )
            dfs(x,y);
    }
}

void build( int i , int j )
{
    while( !st.empty() )
        st.pop();
    dfs(i,j);
    
    Point a;
    
    while( !st.empty() )
    {
        a = st.top();
        st.pop();
        if( !st.empty() )
        {
            jobs.push_back(Job('D',a.x,a.y));
            jobs.push_back(Job('R',a.x,a.y));
        }
    }
}

int main()
{
    //FRO;
    
    int i, j, s;
    
    sf("%d%d",&r,&c);
    
    gets( grid[0] );
    
    for( i = 0 ; i < r ; i++ )
        gets(grid[i]);
    
    for( i = 0 ; i < r ; i++ )
        for( j = 0 ; j < c ; j++ )
            if( !v[i][j] && grid[i][j] =='.' )
                build(i,j);
        
    pf("%d\n",(s=jobs.size()));
        
    for( i = 0 ; i < s ; i++ )
        pf("%c %d %d\n",jobs[i].type,jobs[i].x+1,jobs[i].y+1);
        
    return 0;
}