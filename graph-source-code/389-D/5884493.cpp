//Language: GNU C++


#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORB(i,b,n) for(int i=b;i<n;++i)
#define REV(i,n) for(int i=n;i>=0;--i)
#define FOREACH(T, it, v) for(T::iterator it = v.begin(); it !=v.end(); ++it)

typedef unsigned int u32;
const int INF = (0u - 11)/2;

typedef long long ll;
typedef set<int> SI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef set<long long> SL;
typedef map<int, int> MII;



int DEBUG = 1;

#define print(STRING,INT) printf("%s= %d\n", STRING, INT)

#define scan(INT) scanf("%d", &INT)

void log(char* S, int a)
{
    if(DEBUG)
    {
        print(S,a);
    }
}


///////////////////////////////////////
////////////////////////////
////////////////////////

VI primes(int range = 10001)
{
    VI primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    //cout << "te111st\n";
    for(int i = 9; i< range;i++)
    {
        int j=0;
        int flag = false;
        while((long long )primes[j]*primes[j]<= i)
        {
            if(i%primes[j++]==0)
            {
                flag = true;
                break;
            }
        }
        if(flag == false) primes.push_back(i);
    }
    //cout << "tes11t\n";
    return primes;
}



char tab[1002][1002];
int A[40];
int B[40];

int main()
{
    int n=1000, k;
    //int n=20, k;
    scan(k);
    FOR(i,n)    
    {
        FOR(j,n)
        {
            tab[i][j] = 'N';
        }
    }
    int T = k;
    
    int N=0;
    while(k>0)
    {
        A[N++]=k%2;
        k/=2;
    }
    int free = 2;
    B[0] = 1;
    int current = N;
    FORB(i, 1, N)
    {
        B[i] = free++;
    }
    //cout << N << endl;
    FOR(i,N-1)
    {
        //printf("%d\n", A[i]);
        tab[B[i]][free] = 'Y';
        tab[free][B[i]] = 'Y';
        tab[B[i+1]][free] = 'Y';
        tab[free++][B[i+1]] = 'Y';
        tab[B[i]][free] = 'Y';
        tab[free][B[i]] = 'Y';
        tab[B[i+1]][free] = 'Y';
        tab[free++][B[i+1]] = 'Y';
    }
    FOR(i,N)
    {
        if(A[i])
        {
            int prev = B[i];
            FORB(j,i*2,2*(N-1))
            {
                tab[prev][free] = 'Y';
                tab[free][prev] = 'Y';
                prev = free++;
            }
                tab[prev][0] = 'Y';
                tab[0][prev] = 'Y';
        }
    }
    printf("%d\n", n);
    FOR(i,n)
    {
        tab[i][n]=0;
        printf("%s\n", tab[i]);
    }
    return 0;
}