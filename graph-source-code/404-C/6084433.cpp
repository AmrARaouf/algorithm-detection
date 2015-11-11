//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair <int,int> pii;

int d[100010];
vector<int> v[100010];

int main()
{
    int n,k;
    cin>>n>>k;
    int mmax=0;
    for(int i=0;i<n;++i)
    {
        cin>>d[i];
        v[d[i]].push_back(i);
        mmax=max(mmax,d[i]);
    }
    sort(d,d+n);
    if(d[0]!=0 || (n>1 && d[0]==0 && d[1]==0))
    {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;i<n;++i)
    {
        if(d[i]-d[i-1]>1)
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    int ret=0;
    if(n>1 && v[1].size()>(ll)k*(ll)v[0].size())
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n>1) ret+=v[1].size();
    for(int i=2;i<=mmax;++i)
    {
        ret+=v[i].size();
        ll tmp=(ll)(k-1)*(ll)v[i-1].size();
        if((ll)v[i].size()>tmp)
        {
            cout<<-1<<endl;
           // cout<<111<<endl;
            return 0;
        }
    }
    cout<<ret<<endl;
    for(int i=1;i<=mmax;++i)
    {
   	int kkk=0;
        for(int j=0;j<v[i-1].size();++j)
        {
            int kk=0;
            while(kk<(i==1?k:k-1) && kkk<v[i].size())
            {
                cout<<v[i-1][j]+1<<" "<<v[i][kkk]+1<<endl;
                ++kk;
		++kkk;
            }
        }
    }
    return 0;
}
