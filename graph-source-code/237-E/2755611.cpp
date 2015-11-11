//Language: GNU C++


/**
 *   ///////////////////////
 *   // MIN COST MAX FLOW //
 *   ///////////////////////
 *
 *   Authors: Frank Chu, Igor Naverniouk
 **/

/*********************
 * Min cost max flow * (Edmonds-Karp relabelling + Dijkstra)
 *********************
 * Takes a directed graph where each edge has a capacity ('cap') and a 
 * cost per unit of flow ('cost') and returns a maximum flow network
 * of minimal cost ('fcost') from s to t. USE THIS CODE FOR (MODERATELY)
 * DENSE GRAPHS; FOR VERY SPARSE GRAPHS, USE mcmf4.cpp.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - cost (global): a matrix where cost[u][v] is the cost per unit
 *          of flow along the edge u->v. If cap[u][v] == 0, cost[u][v] is
 *          ignored. ALL COSTS MUST BE NON-NEGATIVE!
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - the total cost through 'fcost'
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 * COMPLEXITY:
 *      - Worst case: O(n^2*flow  <?  n^3*fcost)
 * FIELD TESTING:
 *      - Valladolid 10594: Data Flow
 * REFERENCE:
 *      Edmonds, J., Karp, R.  "Theoretical Improvements in Algorithmic
 *          Efficieincy for Network Flow Problems".
 *      This is a slight improvement of Frank Chu's implementation.
 **/
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdlib>
#include<climits>
#include<cstring>




using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF =1000000000000LL;

int N;
VVL cap, flow, cost;
VI found;
VL dist, pi, width;
VPII dad;
int abc;

void Relax(int s, int k, L cap, L cost, int dir) {
	L val = dist[s] + pi[s] - pi[k] + cost;
	if (cap && val < dist[k]) {
		dist[k] = val;
		dad[k] = make_pair(s, dir);
		width[k] = min(cap, width[s] );
	}
}

L Dijkstra(int s, int t) {
	fill(found.begin(), found.end(), false);
	fill(dist.begin(), dist.end(), INF);
	fill(width.begin(), width.end(), 0);
	dist[s] = 0;
	width[s] = INF;

	while (s != -1) {
		int best = -1;
		found[s] = true;
		for (int k = 0; k < N; k++) {
			if (found[k]) continue;
			Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
			Relax(s, k, flow[k][s], -cost[k][s], -1);
			if (best == -1 || dist[k] < dist[best]) best = k;
		}
		s = best;
	}

	for (int k = 0; k < N; k++)
		pi[k] = min(pi[k] + dist[k], INF);
	return width[t];
}

pair<L, L> GetMaxFlow(int s, int t) {
	L totflow = 0, totcost = 0;
	while (L amt = Dijkstra(s, t)) {
		totflow += amt;
		for (int x = t; x != s; x = dad[x].first) {
			if (dad[x].second == 1) {
				flow[dad[x].first][x] += amt;
				totcost += amt * cost[dad[x].first][x];
			} else {
				flow[x][dad[x].first] -= amt;
				totcost -= amt * cost[x][dad[x].first];
			}
		}
	}
	return make_pair(totflow, totcost);
}

int main()
{
  int numV=151;
  //  while ( cin >> numV && numV ) {
    int i,j;
	cap.resize(200);
	flow.resize(200);
	cost.resize(200);
	found.resize(200);
	dist.resize(200);
	pi.resize(200);
	width.resize(200);
	dad.resize(200);
	for(i=0;i<200;i++)
	{
		cost[i].resize(200);
		cap[i].resize(200);
		flow[i].resize(200);
	}
   	for(i=0;i<200;i++)
		for(j=0;j<200;j++)
			cap[i][j]=0;
    // fill up cap with existing capacities.
    // if the edge u->v has capacity 6, set cap[u][v] = 6.
    // for each cap[u][v] > 0, set cost[u][v] to  the
    // cost per unit of flow along the edge i->v
    string s;
    cin>> s;
    int req=s.size();
    int c[26],m;
    memset(c,0,sizeof(c));
    for(i=0;i<s.size();i++)
	    c[s[i]-'a']++; 
    for(i=0;i<26;i++){
	    cost[101+i][150]=0;
	    cap[101+i][150]=c[i];
    }
    cin>>m;
    int a;
    for (int i=1; i<=m; i++) {
      cost[0][i]=i;
      cin>> s >> a;
      cap[0][i]=a;
      memset(c,0,sizeof(c));
      for(j=0;j<s.size();j++)
            c[s[j]-'a']++;	      
      for(j=0;j<26;j++){
	    cost[i][101+j]=0;
	    cap[i][101+j]=c[j];
      }
    }

    
   N=numV;
   pair < L , L > ret=GetMaxFlow(0,150);
   L flow=ret.first;
   L fcost=ret.second;
//    int flow = mcmf3( numV, 0, 150, fcost );
    if(flow==req)
	    printf("%lld\n",fcost);
    else
	    printf("-1\n");


    return 0;
}
