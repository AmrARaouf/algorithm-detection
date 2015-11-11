//Language: GNU C++


#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <list>
using namespace std;
//#define IN 1

vector<long> graph[100001];
//long dist[100001] = {0};
bool isCycle = 0;
long k;
long lenway = 0;
long way[100001];
bool used[100001];
enum cond
{
    UNKNOWN=0, INCYCLE, NOTIN
} condit[100001] = {UNKNOWN};
void DFS(long first, long st, long last, long step)
{
    //cout << st << ' ';
    if (step>k && first==st)
        {
            isCycle = true;
            lenway = step;
        }
    else if ((step!=0 && first==st) || step > k*10) return;

    else
    {
        way[step] = st;
        for (int i = 0; i<graph[st].size(); i++)
            if (!isCycle && !used[graph[st][i]] && last!=graph[st][i])
            {
                used[graph[st][i]]=1;
                DFS(first,graph[st][i],st,step+1);
                if (isCycle) break;
                else condit[graph[st][i]] = NOTIN;
                used[graph[st][i]]=0;
            }
    }

}
int main()
{
#ifdef IN
   freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
#endif // IN
    long n,m;
    cin >> n >> m>> k;
    for (long i = 0; i<m; i++)
    {
        long v,v1;
        cin >> v >> v1;
        graph[v-1].push_back(v1-1);
        graph[v1-1].push_back(v-1);
    }

    for (long i = 0; i<n; i++)
    {
        //cout << i << endl;
        //if (condit[i]!=NOTIN)
            DFS(i,i,i,0);
        if (isCycle)
        {
            cout << lenway << endl;
            for (int i = 0; i<lenway; i++)
                cout << way[i]+1 << ' ';
            break;
        }
    }
    return 0;
}
