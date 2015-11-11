//Language: GNU C++


#include <iostream>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int> >a;
int main()
{
    int n,i,x,y,j;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    map<int,vector<int> >::iterator it;
    for(it=a.begin();it!=a.end();it++)
    {
        if(a[(*it).first].size()==1)
        break;
    }
    x=a[(*it).first][0];
    y=(*it).first;
    cout<<y<<" "<<x<<" ";
    while(a[x].size()!=1)
    {
        for(j=0;j<2;j++)
        {
            if(a[x][j]!=y)
            {
                y=x;
                x=a[y][j];
                break;
            }
        }
        cout<<x<<" ";

    }
    return 0;
}
