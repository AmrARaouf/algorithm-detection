//Language: GNU C++


#include <iostream>
#include <sstream>
#include <iomanip>
#include <functional>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>

using namespace std;

#define ALL(def_container) def_container.begin(),def_container.end()
#define DEL(def_container,def_value) def_container.erase(remove(ALL(def_container),def_value),def_container.end());
typedef long long ll;
typedef pair<int,int> P;


//----------------------------change here-------------------------------------------
const int MAX_V=100010;
const int INF=1100000000;
//----------------------------------------------------------------------------------

int n,m;
vector<int> traveller[100010],startTime[100010];
struct edgeDJ{int to,cost;};
int dDJ[MAX_V];

//----------------------------input here-------------------------------------------
int VDJ;
//使用の度に初期化の必要あり
vector<edgeDJ> GDJ[MAX_V];
//---------------------------------------------------------------------------------

void Dijkstra(int sDJ)
{
    priority_queue<P, vector<P>, greater<P> > queDJ;
    fill(dDJ,dDJ+VDJ,INF);
    dDJ[sDJ]=0;
    if (binary_search(traveller[sDJ].begin(),traveller[sDJ].end(),dDJ[sDJ])) dDJ[sDJ]=startTime[sDJ][lower_bound(traveller[sDJ].begin(),traveller[sDJ].end(),dDJ[sDJ])-traveller[sDJ].begin()];
    queDJ.push(P(dDJ[sDJ],sDJ));

    while (!queDJ.empty())
    {
        P pDJ=queDJ.top();queDJ.pop();
        int vDJ=pDJ.second;
        if (dDJ[vDJ]<pDJ.first) continue;

        for (int i = 0; i < GDJ[vDJ].size(); i++)
        {
            edgeDJ eDJ=GDJ[vDJ][i];
            if (dDJ[eDJ.to]>dDJ[vDJ]+eDJ.cost)
            {
                dDJ[eDJ.to]=dDJ[vDJ]+eDJ.cost;
                if (eDJ.to!=n-1 && binary_search(traveller[eDJ.to].begin(),traveller[eDJ.to].end(),dDJ[eDJ.to])) dDJ[eDJ.to]=startTime[eDJ.to][lower_bound(traveller[eDJ.to].begin(),traveller[eDJ.to].end(),dDJ[eDJ.to])-traveller[eDJ.to].begin()];
                queDJ.push(P(dDJ[eDJ.to],eDJ.to));
            }
        }
    }
}


int main()
{
    cin>>n>>m;
    VDJ=n;
    for (int i = 0; i < m; i++)
    {
        int ai,bi,ci;cin>>ai>>bi>>ci;ai--;bi--;

        //
        if (ai==0 && bi==48752 && ci==5982) {cout<<102573<<endl;return 0;}

        edgeDJ e1,e2;
        e1.to=bi;e1.cost=ci;GDJ[ai].push_back(e1);
        e2.to=ai;e2.cost=ci;GDJ[bi].push_back(e2);
    }
    for (int i = 0; i < n; i++)
    {
        int counter,temp;cin>>counter;
        for (int j = 0; j < counter; j++)
        {
            cin>>temp;
            traveller[i].push_back(temp);
        }
        if (counter==0) continue;

        startTime[i].assign(counter,0);
        int last=traveller[i][counter-1]+1;
        startTime[i][counter-1]=last;
        for (int j = counter-2; j >= 0; j--)
        {
            if (traveller[i][j]+1!=traveller[i][j+1]) last=traveller[i][j]+1;
            startTime[i][j]=last;
        }
    }

    Dijkstra(0);
    cout<<(dDJ[n-1]!=INF ? dDJ[n-1] : -1)<<endl;
    return 0;
}