//Language: GNU C++


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <map>

#define foru(i,l,r) for(int i=l; i<=r; i++)
#define ford(i,r,l) for(int i=r; i>=l; i--)
#define vi vector < int >
#define pi pair < int, int >
#define pb push_back
#define ll long long

using namespace std;

int head[3003], d[3003], adj[600006], X[30003], Y[30003];
int M, N;

void nhap()
{
    scanf("%d%d",&N,&M);
    memset(head,0,sizeof(head));
    for(int i=1; i<=M; i++)
    {
        scanf("%d%d",&X[i],&Y[i]);
        head[X[i]]++;
    }
    for(int i=2; i<=N+1; i++)
        head[i]+=head[i-1];
    for(int i=1; i<=M; i++)
    {
        adj[head[X[i]]--]=Y[i];
    }
}

void tinh()
{
    long long res = 0;
    for(int a=1; a<=N; a++)
    {
        memset(d,0,sizeof(d));
        for(int j=head[a]+1; j<=head[a+1]; j++)
        {
            int b=adj[j];
            for(int k=head[b]+1; k<=head[b+1]; k++)
            {
                int c=adj[k];
                if (c==a)
                    continue;
                res+=d[c];
                d[c]++;
            }
        }
    }
    cout<<res;
}

int main()
{
    nhap();
    tinh();
    return 0;
}
