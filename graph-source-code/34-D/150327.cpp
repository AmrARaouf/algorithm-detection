//Language: MS C++



#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int fa[50010];
int son[50010];
int fa1[50010];
int main()
{
    int n,r1,r2;
    cin>>n>>r1>>r2;
    int i;
    
    for(i=1;i<=n;i++)
    {
        if(i==r1)
            continue;
        cin>>fa[i];
    }
    int now=r2;
    memset(fa1,-1,sizeof(fa1));
    while(now!=r1)
    {
        int f1=fa[now];
        fa1[f1]=now;
        now=f1;
    }
    for(i=1;i<=n;i++)
    {
        if(i==r2)
            continue;
        if(fa1[i]==-1)
            cout<<fa[i]<<" ";
        else
            cout<<fa1[i]<<" ";
    }
    cout<<endl;
//  system("pause");
    return 0;
}
