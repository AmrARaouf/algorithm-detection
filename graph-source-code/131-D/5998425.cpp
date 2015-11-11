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
vector<int> c;
int n;
vector < vector<int> > g;
//int a[3001][3001];
bool used[3001];
bool cyc[3001];
bool findC;
vector<int> cl;
vector<int> p;
int cycle_st, cycle_end;

void dfs(int k, int root, int parent, vector<int> gr)
{

    if(parent!=k && root==k)
    {
        findC = true;
        c = gr;
        return;
    }
    //cout<< k;
    gr.push_back(k);
    if(root != k) used[k]=true;
    for (vector<int>::iterator i=g[k].begin(); i!=g[k].end(); ++i){

        if(*i!=parent && !used[*i])
        {
            dfs(*i, root,k, gr);
            if(findC) return;
        }
    }
}

bool dfs3 (int v, int parent) {
    cl[v] = 1;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if(to == parent)continue;
        if (cl[to] == 0) {
            p[to] = v;
            if (dfs3 (to,v))  return true;
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
        //cout<<k<<"  l";
        cout<<step<<" ";
        return true;
    }
    used[k]=true;
    for (vector<int>::iterator i=g[k].begin(); i!=g[k].end(); ++i)
    {
        if(!used[*i])
        {
            //cout<<step<<" "<< k <<"\n";
            //step++;
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
    for (int i=0; i<n; i++) {
        int k1; cin>>k1;
        int k2; cin>>k2;
        g[k1-1].push_back(k2-1);
        g[k2-1].push_back(k1-1);
    }

    p.assign (n, -1);
    cl.assign (n, 0);
    cycle_st = -1;
    for (int i=0; i<n; ++i)
        if (dfs3 (i,i))
            break;

    cyc[cycle_st]= true;
    for (int v=cycle_end; v!=cycle_st; v=p[v]){
        cyc[v]= true;
    }

    for (int i=0; i<n; i++) {
        std::fill_n(used, n, false);
        dfs2(i, 0);
    }
    return 0;
}



