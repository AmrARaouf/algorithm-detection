//Language: GNU C++0x


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <memory.h>
using namespace std;
#define lp(i,n) for(i=0;i<n;++i)
#define lp2(i,a,b) for(i=a;i<=b;++i)
#define lpn(i,n) for(i=n-1;i>=0;--i)
#define lpn2(i,a,b) for(i=a;i>=b;--i)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>
#define vvi vector<vi>
#define vvll vector<vll>
#define sz size
#define F first
#define S second
#define mp(x,y) make_pair(x,y)
#define get(i,n) ( ((n)>>(i)) & 1)
char a[1005][1005];
char h[2][1005];
int print(int n)
{
    printf("%d\n",n);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int k,msb;
    scanf("%d",&k);
    memset(a,'N',sizeof a);
    if(k==1)
    {
        a[1][2]=a[2][1]='Y';
        print(2);
        return 0;
    }

    for(int i=31;i>=0;--i)if(get(i,k)){msb=i;break;}
    int n = 5*msb;
    int x = 3*msb+1;
    a[1][2]=a[2][1]=a[1][3]=a[3][1]= a[x][x-1]=a[x-1][x]= a[x][x-2]=a[x-2][x]='Y';
    for(int i=4;i<x;i+=3)
    {
        a[i][i-1]=a[i-1][i]=a[i][i-2]=a[i-2][i]=a[i][i+1]=a[i+1][i]=a[i][i+2]=a[i+2][i]='Y';
    }
    a[x][n] = a[n][x] ='Y';
    for(int i=x+2;i<=n;++i)a[i][i-1]=a[i-1][i]='Y';
    for(int i=0;i<msb;++i)
    {
        if(get(i,k))
        {
            a[3*i+1][x+1+2*i]=a[x+1+2*i][3*i+1] = 'Y';
        }
    }

    for(int i=1;i<=n;++i)
    {
      swap(a[2][i],a[x][i]);
    }
    for(int i=1;i<=n;++i)
    {
        swap(a[i][2],a[i][x]);
    }
    print(n);
    return 0;
}
