//Language: GNU C++


#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cstdio>

using namespace std;

vector <int> Gr[4000], kollan, dor;
bool mark[4000], flag, isindor[4000];
int res[4000];
queue <int> Q;

void dfs(int now, int last)
{
    if(flag)
        return;
    mark[now]=1;
    kollan.push_back(now);
    for(int i=0;i<Gr[now].size();i++)
    {
        if(mark[Gr[now][i]]&&Gr[now][i]!=last)
        {
            flag=1;
            int f=0;
            for(int j=0;j<kollan.size();j++)
            {
                if(kollan[j]==Gr[now][i])
                    f = 1;
                if(f)
                {
                    isindor[kollan[j]]=1;
                    dor.push_back(kollan[j]);
                }
            }
        }
        else if(!mark[Gr[now][i]])
                dfs(Gr[now][i], now);
    }
    kollan.pop_back();
    return;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        Gr[a].push_back(b);
        Gr[b].push_back(a);
    }
    dfs(1,0);
    for(int i=0;i<=n;i++)
        if(isindor[i])
        {
            res[i]=0;
            Q.push(i);
        }
        else
            res[i]=-1;
    //bfs b raveshe man!:D
    /*for(int i=1;i<=n;i++)
    {
        if(res[i]!=-1)
            for(int j=0;j<Gr[i].size();j++)
                if(res[Gr[i][j]]!=-1)
                    res[Gr[i][j]] = min(res[Gr[i][j]], res[i]+1);
                else
                    res[Gr[i][j]] = res[i]+1;
        else
            for(int j=0;j<Gr[i].size();j++)
                if(res[Gr[i][j]]!=-1)
                    if(res[i]==-1)
                        res[i] = res[Gr[i][j]]+1;
                    else
                        res[i] = min(res[i], res[Gr[i][j]]+1);
        

        if(res[i]!=-1)
            for(int j=0;j<Gr[i].size();j++)
                if(res[Gr[i][j]]!=-1)
                    res[Gr[i][j]] = min(res[Gr[i][j]], res[i]+1);
                else
                    res[Gr[i][j]] = res[i]+1;
    }
    if(n==3000)
    {
        for(int i=1;i<=n;i++)
            if(res[i]==0)
                cout << i << " ";
        return 0;
    }*/
    //ye BFS ekhtera karDma ... :|:|:|

    int count =0;
    while(Q.size()&&count <n)
    {
        for(int i=0;i<Gr[Q.front()].size();i++)
        {
            if(!isindor[Gr[Q.front()][i]])
            {
                if(res[Gr[Q.front()][i]]!=-1)
                    res[Gr[Q.front()][i]] = min(res[Gr[Q.front()][i]], res[Q.front()]+1);
                else
                    res[Gr[Q.front()][i]] = res[Q.front()]+1;
                Q.push(Gr[Q.front()][i]);
                isindor[Gr[Q.front()][i]] =1;
                count ++;
            }
        }
        Q.pop();
    }
    for(int i=1;i<=n;i++)
        if(res[i]==-1)
            cout << "WoW BADBAKHT SHODIM :(((( " << endl;
    for(int i=1;i<n;i++)
        cout << res[i] << " ";
    cout << res[n] << endl;
    cin >> n;
}