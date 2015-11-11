//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
int C[100001];
int different_types[100001];
set<int> S[100001];
set<int> indi;
int main()
{  int ans=-1;
    int n,m,a,b,max_color=-1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        {
            scanf("%d",&C[i]);
            max_color=max(max_color,C[i]);
            indi.insert(C[i]);
        }
    while(m--)
    {
        scanf("%d %d",&a,&b);
        if(C[a]!=C[b])
        {
            S[C[a]].insert(C[b]);
            S[C[b]].insert(C[a]);
        }
    }
    int color;
    for(set<int> :: iterator it=indi.begin();it!=indi.end();it++)
    {
         int vv=*it;
        int sizee=S[vv].size();
        if(ans< sizee)
        {
            ans=sizee;
            color=vv;
        }
    }
    printf("%d\n",color);
    return 0;
}
