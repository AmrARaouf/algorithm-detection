//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
using namespace std;
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define s second
#define f first
#define ll long long
#define MAX 10000007
#define MOD 1000000007
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FOREACH(iter, m) for(map<int,int>::iterator (iter) = (m).begin(); (iter) != (m).end(); (iter)++)  
#define RFOR(j, a, b) for(int j = (a); j > (b); j--)
int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

int n, m;
int a[1005][1005];
int main() 
{
    cin >> n >> m;
    FOR(i, 0, m)
    {
        int x,y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    int cen = 0;
    FOR(i, 1, n+1)
    {
        int r = 0;
        FOR(j, 1, n+1)
        {
            r += a[i][j];
        }
        if(!r)
        {
            cen = i;
            break;
        }
    }
    cout << n - 1 << endl;
    FOR(i, 1, n+1)
        if(i != cen)
        {
            cout << cen << " " << i << endl;
        }
    return 0;
}
