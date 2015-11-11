//Language: GNU C++


#include <iostream>
#include <set>
using namespace std;
set<int>s[100005];
int c[100005],ans=9999999,z;
int main()
{
    int a,b,q,w;cin>>a>>b;
    for(int i=1;i<=a;i++)
    {
        cin>>c[i];
        ans=(c[i]>ans)?ans:c[i];
    }
    for(int i=1;i<=b ;i++)
    {
        cin>>q>>w;
        //q--;w--;
        if(c[q]!=c[w])
        {
            s[c[q]].insert(c[w]);
            s[c[w] ].insert(c[q]);
        }
    }
    int x=0;
    for(int i=1;i<=100001;i++)
    {
        if((int)s[i].size()>x)
        {
            x=s[i].size();
            ans=i;
        }
    }

    cout<<ans;
}
