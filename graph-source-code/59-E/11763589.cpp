//Language: GNU C++11


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int> 
#define PTI pair <PII, int> 
#define PIII pair <PII, PII>
map <PTI, int> is;  
set <int> edges [3005]; 
vector <int> keep [3005]; 
vector <int> answer;
PII last [3005]; 
map <PII, int> ekey; 
int key [3005]; 
void solve ()
{
    queue <PIII> hold;
    hold.push(PIII(PII(0, 1), PII(0, 1)));
    last[1]=PII(0, 1);
    while (hold.size())
    {
        PIII x = hold.front(); 
        hold.pop();
        if (key[x.first.second]==1e18) key[x.first.second]=x.first.first, last[x.first.second]=x.second;
        ekey[x.second]=x.first.first;
        if (!edges[x.first.second].size()) continue;
        set <int> toerase; 
        for (set <int> :: iterator t=edges[x.first.second].begin(); t!=edges[x.first.second].end(); t++)
        {
            if (is[PTI(x.second, *t)]) continue; 
            hold.push(PIII(PII(x.first.first+1, *t), PII(x.first.second, *t)));
            toerase.insert(*t); 
        }
        while (toerase.size())
        {
            int xx = *toerase.begin();
            edges[x.first.second].erase(xx); 
            toerase.erase(toerase.begin());
        }
    }
}
main()
{
    for (int g=0; g<=3000; g++) key[g]=1e18; 
    ios_base::sync_with_stdio(0); 
    int n, m, k; cin >> n >> m >> k; 
    for (int g=0; g<m; g++)
    {
        int a, b; cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
        keep[a].push_back(b);
        keep[b].push_back(a); 
    }
    for (int t=0; t<k; t++)
    {
        int r, e, f; cin >> r >> e>> f;
        is[PTI(PII(r,e),f)]=1;
    }
    solve(); 
    if (key[n]==1e18)
    {
        cout << -1; return 0; 
    }
    cout << key[n] << '\n'; 
    answer.push_back(last[n].second); 
    PII curedge = last[n];
    int curnode = last[n].first;  
    while (curnode!=1)
    {
        answer.push_back(curnode); 
        for (int t=0; t<keep[curnode].size(); t++)
        {
            if (ekey[PII(keep[curnode][t], curedge.first)]+1==ekey[curedge])
            {
                if (!is[PTI(PII(keep[curnode][t], curnode), curedge.second)])
                {
                    curedge=PII(keep[curnode][t], curedge.first);
                    curnode=keep[curnode][t];
                    break;
                }
            }
        }
    }
    reverse(answer.begin(),answer.end());
    cout << 1 << ' '; 
    for (int g=0; g<answer.size(); g++) cout << answer[g] << ' '; 
    return 0;
}