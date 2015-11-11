//Language: GNU C++


//
//  main.cpp
//  Practice
//
//  Created by Neel Shah on 11/27/14.
//  Copyright (c) 2014 Neel Shah. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>
#include <map>
#include<stack>
#include<map>
#include<queue>
#include <math.h>
#include<set>
#include<stdint.h>
#include <utility>
#include <cmath>
#include <iostream>
#include <iomanip>
#define MAXN 100005
#define MAXLG 17
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

using namespace std;
typedef long long int ll;
typedef pair<int, int> mp;
template<class T> void chmin(T &t, const T &f) { if (t > f) t = f; }
template<class T> void chmax(T &t, const T &f) { if (t < f) t = f; }

map<int, int> v[2*MAXN];;
vector<pair<int, int> > ans;
int n, m, deg[2*MAXN], eid = 0, self[2*MAXN]={0};

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x--; y--;
        if(x == y)
        {
            self[x]++;
            continue;
        }
        
        deg[x]++; deg[y]++;
        v[x][eid] = y;
        v[y][eid] = x;
        eid++;
    }
    
    vector<int> odd;
    for(int i=0; i<n; ++i)
    {
        if(deg[i]%2)
            odd.push_back(i);
        if(odd.size() == 2)
        {
            int x = odd[0];
            int y = odd[1];
            
            v[x][eid] = y;
            v[y][eid] = x;
            odd.clear();
        }
    }
    
    vector<int> path;
    stack<int> s;
    s.push(0);
    
    while(!s.empty())
    {
        int node = s.top();
        if(v[node].size() == 0)
        {
            s.pop();
            path.push_back(node);
            if(self[node] > 0)
            {
                for(int i=0; i<self[node]; ++i)
                    path.push_back(node);
                self[node] = 0;
            }
            continue;
        }
        
        map<int, int>::iterator it = v[node].begin();
        int id = it->first;
        int next = it->second;
        
        map<int, int>::iterator it1 = v[next].find(id);
        v[next].erase(it1);
        map<int, int>::iterator it2 = v[node].find(id);
        v[node].erase(it2);
        
        s.push(next);
    }
    
//    for(int i=0; i<path.size(); ++i)
//        printf("%d ", path[i]+1);
//    printf("\n");
    
    path.erase(path.end()-1);
    for(int i=1; i<path.size(); i+=2)
    {
        ans.push_back(mp(path[i-1], path[i]));
        if(i+1 < path.size())
            ans.push_back(mp(path[i+1], path[i]));
    }
    
    ans.push_back(mp(path[0], path[path.size()-1]));
    if(path.size()%2)
        ans.push_back(mp(path[path.size()-1], path[path.size()-1]));
    
    printf("%ld\n",ans.size());
    for(int i=0; i<ans.size(); ++i)
        printf("%d %d\n", ans[i].first+1, ans[i].second+1);
    return 0;
}