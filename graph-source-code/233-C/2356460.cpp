//Language: MS C++


#include <iostream>
#include <cstdio>
using namespace std;

bool mat[1007][1007];
int k,cur=0;

int C3(int n)
{
    return n*(n-1)*(n-2)/6;
}

int C2(int n)
{
    if (n<2)
    {
        return 0;
    }
    return n*(n-1)/2;
}

int GetMaxNum()
{
    int l=0,r=100,m;
    while(l<r)
    {
        m=(l+r+1)/2;
        if (C3(m)<=k)
        {
            l=m;
        }
        else
        {
            r=m-1;
        }
    }
    return l;
}

int GetMaxCnt(int amount)
{
    int l,r,m;
    l=0;
    r=amount;
    while(l<r)
    {
        m=(l+r+1)/2;
        if (C2(m)<=k)
        {
            l=m;
        }
        else
        {
            r=m-1;
        }
    }
    return l;
}

void Cut()
{
    int i,j,n,cnt;
    n=GetMaxNum();
//  cout << "k = " << k << "  |  " << "n = " << n << "  |  " << "C3(n) = " << C3(n) << "  |  " << "C2(n) = " << C2(n) << "  |  "; 
    k-=C3(n);
    for(i=cur;i<cur+n;i++)
    {
        for(j=i+1;j<cur+n;j++)
        {
            mat[i][j]=mat[j][i]=1;
        }
    }
    cur+=n;
    while(k!=0)
    {
        cnt=GetMaxCnt(n);
        for(i=0;i<cnt;i++)
        {
            mat[i][cur]=mat[cur][i]=1;
        }
        cur++;
        k-=C2(cnt);
    }
//  cout << "cnt = " << "  |  " << "k = " << k << endl;
}

int main()
{
    int i,j;
    cin >> k;
    Cut();
    cout << cur << endl;
    for(i=0;i<cur;i++)
    {
        for(j=0;j<cur;j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}
