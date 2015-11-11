//Language: GNU C++


//
//  main.cpp
//  Code131D
//
//  Created by Матвей Кравцов on 11.03.14.
//  Copyright (c) 2014 Матвей Кравцов. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int n;
vector < vector<int> > g;
vector<bool> used;
vector<bool> cyc;
vector<int> cl;
vector<int> p;
int cycle_st, cycle_end;

bool dfs(int v, int parent) {
    cl[v] = 1;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if(to == parent)continue;
        if (cl[to] == 0) {
            p[to] = v;
            if (dfs(to, v))  return true;
        }
        else if (cl[to] == 1) {
            cycle_end = v;
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}

bool dfs2(int k, int step)
{
    if(cyc[k])
    {
        cout<<step<<" ";
        return true;
    }
    used[k]=true;
    for (vector<int>::iterator i=g[k].begin(); i!=g[k].end(); ++i)
    {
        if(!used[*i])
        {
            if(dfs2(*i, step+1)) return true;

        }
    }
    return false;
}


int main(int argc, const char * argv[])
{

    cin >>n;
    vector<int> temp;
    g.assign(n,temp);
    cyc.assign (n, false);

    for (int i=0; i<n; i++) {
        int k1,k2; cin>>k1>>k2;
        g[k1-1].push_back(k2-1);
        g[k2-1].push_back(k1-1);
    }

    p.assign (n, -1);
    cl.assign (n, 0);
    cycle_st = -1;
    for (int i=0; i<n; ++i)
        if (dfs(i, i))
            break;

    cyc[cycle_st]= true;
    for (int v=cycle_end; v!=cycle_st; v=p[v]){
        cyc[v]= true;
    }

    for (int i=0; i<n; i++) {
        used.assign (n, false);
        dfs2(i, 0);
    }
    return 0;
}



