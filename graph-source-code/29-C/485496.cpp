//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

map<int,vector<int> > e;

int main()
{
    int n,a,b,start,prev;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for(map<int,vector<int> >::iterator it = e.begin(); it != e.end(); it++)
    {
        if(it->second.size() == 1)
        {
            start = it->first;
            break;
        }
    }
    printf("%d",start);
    prev = start;
    start = e[start][0];
    while(1)
    {
        printf(" %d",start);
        if(e[start].size() == 1)
            break;
        else if(e[start][0] == prev)
        {
            prev = start;
            start = e[start][1];
        }
        else
        {
            prev = start;
            start = e[start][0];
        }
    }
    printf("\n");

    return 0;
}
