//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <climits>
#include <cstdlib>

const double Pi=acos(-1.0);

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

#define Set(a, s) memset(a, s, sizeof (a))
#define Rd(r) freopen(r, "r", stdin)
#define Wt(w) freopen(w, "w", stdout)
#define mp make_pair
#define MAXN 1111
#define MAXK 9

int N, K;
int Number[MAXK][MAXK][MAXN];
int Index[MAXK][MAXN];
int Dy[MAXN];
int main(int argc, char **argv) 
{
    scanf("%d %d", &N, &K);
    for(int i=1; i<=K; i++)
        for(int j=1; j<=N; j++) 
        {
            cin >> Number[i][1][j];
            Index[i][ Number[i][1][j] ] = j;
        }
    for(int i=1; i<=K; i++) 
    {
        for(int j=1; j<=N; j++) Index[i][ Number[i][i][j] ] = j;
        for(int j=i+1; j<=K; j++) 
            for(int k=1; k<=N; k++) 
                Number[j][i+1][k] = Index[i][ Number[j][i][k] ];
    }
    Dy[1]=1;
    int Answer=1;
    for(int i=2; i<=N; i++) 
    {
        int max=0;
        for(int j=1; j<i; j++) 
        {
            bool flag = true;
            for(int k=2; k<=K; k++) 
            {
                if(Number[K][k][j] > Number[K][k][i]) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag && max<Dy[j]) max = Dy[j];
        }
        Dy[i] = max + 1;
        if(Answer<Dy[i]) Answer = Dy[i];
    }
    cout << Answer << "\n";
}