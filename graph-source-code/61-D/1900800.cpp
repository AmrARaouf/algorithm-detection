//Language: GNU C++


// ether


#include <iostream>


#include <string>


#include <algorithm>

#include <vector>


using namespace std;



const int MaxV=1000*1000;



vector < pair<int,int> > G[MaxV];
bool mark[MaxV];



long long int dfs(int v)

{

    mark[v]=1;

    long long int maxW=-1;

    for(int i=0;i<G[v].size();i++)

        if(!mark[G[v][i].first])

            maxW=max(maxW,dfs(G[v][i].first)+G[v][i].second);

    return ((maxW==-1)?0:maxW);

}


int main()
{
    ios::sync_with_stdio(0);

    int n,a,b,w;
    long long SumW=0;

    cin >>n;

    for(int i=0;i<n-1;i++)

    {

        cin >>a>>b>>w;

        G[a].push_back(make_pair(b,w));

        G[b].push_back(make_pair(a,w));

        SumW+=w;

    }

    cout <<2*SumW-dfs(1)<<endl;
    return 0;
}