//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
#define openfile{freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);}
#define debug 0
#define fs first
#define sc second

int n,m,ds[200020],ke[200020],a[100010],b[100010],c[100010],kq,sl,dem;
bool check[100010];
pair <int,int> te[100010];
int main()
{
    if (debug) openfile;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&c[i]);
        te[i].fs=c[i];
        te[i].sc=i;
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        ds[a[i]+2]++;
        ds[b[i]+2]++;
    }
    ds[2]=1;
    for (int i=3; i<=n+2; i++) ds[i]+=ds[i-1];
    for (int i=1; i<=m; i++)
    {
        ke[ds[a[i]+1]]=b[i];
        ds[a[i]+1]++;
        ke[ds[b[i]+1]]=a[i];
        ds[b[i]+1]++;
    }
    ds[1]=1;
    sort(te+1,te+n+1);
    memset(check,false,sizeof check);
    dem=0;
    sl=0;
    int t=0;
    for (int i=1; i<=n; i++)
    {
        for (int j=ds[te[i].sc]; j<ds[te[i].sc+1]; j++)
            if (check[c[ke[j]]]==false && c[ke[j]]!=te[i].fs)
            {
                dem++;
                check[c[ke[j]]]=true;
            }
        if (te[i].fs!=te[i+1].fs)
        {
            if (sl<dem)
                sl=dem,kq=te[i].fs;
            dem=0;
            for (int k=t+1; k<=i; k++)
                for (int j=ds[te[k].sc]; j<ds[te[k].sc+1]; j++)
                    check[c[ke[j]]]=false;
            t=i;
        }
    }
    if (kq==0) kq=te[1].fs;
    cout<<kq;
    return 0;
}
