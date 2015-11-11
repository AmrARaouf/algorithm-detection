//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;
#define REP(i,n) for(int i = 0; i < (int)n; i++)
#define FOREACH(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define ALL(c) (c).begin(), (c).end()
template <class T> void pp(T v) { FOREACH(it, v) cout << *it << ' '; cout << endl ; }
template <class T> void pp(T v, int n) { REP(i,n) cout<<v[i]<< ' '; cout << endl; }
typedef vector<int> vint;
typedef pair<int, int> pint;
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef unsigned uint;
const int INF = 1<<28;
const double EPS = 1.0e-9;

struct Record {
    int t;
    int jumpid, posid;
};

struct Input {
    int x, d, t, p;
};

struct Edge {
    int from, to, time, id;
};

int main(void)
{
    int N, L; cin>>N>>L;
    vector<Input> inputs(N);
    map<int, int> dist2id; //
    dist2id[0]++; dist2id[L]++;
    REP(i,N) {
        int x, d, t, p; cin>>x>>d>>t>>p;
        inputs[i] = (Input) {x,d,t,p};
        if(x-p < 0) continue;
        dist2id[x-p]++; dist2id[x+d]++;
    }
    vector<int> positions; positions.reserve(N);
    {
        int id = 0;
        for(map<int, int>::iterator it = dist2id.begin(); it != dist2id.end(); ++it) {
            it->second = id++;
            positions.push_back(it->first);
            //cout << it->first << " " << it->second << endl;
        }
    }
    int n = positions.size();
    vector <vector<Edge> > G(n);
    for(int i = 1; i < n; i++) {
        Edge e1 = (Edge){i-1, i, positions[i] - positions[i-1], 0};
        Edge e2 = (Edge){i, i-1, positions[i] - positions[i-1], 0};
        G[i-1].push_back(e1);
        G[i].push_back(e2);
    }
    REP(i,N) {
        const int x = inputs[i].x, d = inputs[i].d, t = inputs[i].t, p = inputs[i].p;
        if(x-p >= 0 && x+d <= L) {
            const int fid = dist2id[x-p];
            Edge e = (Edge){fid, dist2id[x+d], p + t, i+1};
            G[fid].push_back(e);
        }
    }
    vector <Record> rec(n);
    REP(i,n) rec[i].t = L+1; // infinity

    priority_queue<pint, vector<pint>, greater<pint> > q;
    q.push(mp(0, 0)); // time, pos
    const int goal = n - 1;
    while(! q.empty()) {
        const int time = q.top().first;
        const int pid = q.top().second;
        //cout << time << " " << pid << " " << positions[pid] << endl;
        q.pop();
        if(pid == goal) {
            //cout << "Answer = " << endl;
            cout << time << endl;
            deque<int> ans; int posid = goal;
            while(posid != 0) {
                int jumpid = rec[posid].jumpid;
//                cout << "...." << route << endl;
                if(jumpid > 0)
                    ans.push_front(jumpid);
                posid = rec[posid].posid;
            }
            cout << ans .size() << endl;
            pp(ans);
#ifdef NOVECANS
#endif
            break;
        }
        for(vector<Edge>::iterator it = G[pid].begin(); it != G[pid].end(); ++it) {
            const int nid = it->to;
            const int ntime = time + it->time;
            if(ntime < rec[nid].t) {
                rec[nid].t = ntime;
                rec[nid].posid = pid;
                rec[nid].jumpid = it->id;
                q.push(mp(ntime, nid));
            }
        }
    }

    return 0;
}
