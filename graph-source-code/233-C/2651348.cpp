//Language: MS C++


/*
ID: Tariqul
PROG: 
LANG: C++
*/

#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector>

using namespace std; 

#define fo(i,j,n) for(i=j;i<n;++i)
#define Fo(i,j,n) for(i=n-1;i>=j;--i)
#define foo(i,j,v) fo(i,j,sz(v))
#define Foo(i,j,v) Fo(i,j,sz(v))
#define li(v) v.begin(),v.end()
#define sz(v) ((int)v.size())
#define CLR(a,v) memset((a),(v),sizeof(a))
#define inf 1000000001
//typedef long long Long;
typedef __int64 Long;
#define pi (2*acos(0))
#define eps 1e-9

#define two(X) (1<<(X))
#define twoL(X) (((Long)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)

char BUFFER[100000 + 5];
bool readn(int &n)	{ return scanf("%d",&n) == 1; } 
bool readl(Long &n)	{ return scanf("%I64d",&n) == 1; } 
bool readd(double &n){ return scanf("%lf",&n) == 1; } 
bool reads(string &s){ s = ""; int n = scanf("%s",BUFFER); if(n == 1)s = BUFFER; return n == 1; }
bool readln(string &s){ char *valid = gets(BUFFER); if(valid)s = BUFFER; return ((bool)valid); }

int tri[110];
vector <int> v;
string graph[110];

void add_edge(int a, int b){
    graph[a][b] = '1';
    graph[b][a] = '1';
}

int main()
{
	#ifdef localhost
	freopen("D://input.txt","r",stdin);
	//freopen("D://output.txt","w",stdout);
	#endif

	int E,i,j;
    
    cin >> E;
    
    int K;
    for(K=100;;K--)
	{
        int K3 = K * (K-1) * (K-2) / 6;
        if(K3 <= E)
		{
            E -= K3;
            break;
        }
    }
    
    while(E > 0)
	{
        for(i=K;;i--)
		{
            int tmp = i * (i-1) / 2;
            if(tmp <= E)
			{
                E -= tmp;
                break;
            }
        }
        v.push_back(i);
    }
    
    int N = K + v.size();
    fo(i,0,N) fo(j,0,N) graph[i] += '0';
    fo(i,0,K) fo(j,0,i) add_edge(i,j);
    fo(i,0,v.size()) fo(j,0,v[i]) add_edge(K+i,j);
    
    cout << N << endl;
    fo(i,0,N) cout << graph[i] << endl;
	//printf("\n");
	return 0;
} 