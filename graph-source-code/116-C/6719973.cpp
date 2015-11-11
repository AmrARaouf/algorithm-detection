//Language: GNU C++


#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n,b,kq=0;
int cha[2001];
int main()
{
    //freopen("116c.inp","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>cha[i];
    for(int i=1;i<=n;i++)
    {
        int p=i;
        int cnt=1;
        while(cha[p]!=-1)
        {
            cnt++;
            p=cha[p];
        }
        kq=max(kq,cnt);
    }
    cout<<kq<<"\n";
}
