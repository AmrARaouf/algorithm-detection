//Language: GNU C++


/*
username: leandro
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

//////////////////////////////////////
typedef long long i64;
typedef complex<double> pnt;
typedef pair<int, int> pii;
typedef vector<int> vi;
//////////////////////////////////////
const int oo = 1 << 30;
//const double PI = M_PI;
const double EPS = 1e-15;
//////////////////////////////////////
#define F first
#define S second
#define foreach(i, u) \
        for (typeof(u.begin()) i = u.begin(); i != u.end(); i++)
#define REP(i, n) \
        for (int i = 0; i < (n); i++)
#define FOR(i, n) \
        for (int i = 1; i <= (n); i++)
//////////////////////////////////////
#define DEBUG(x) \
        cout << #x << " = " << x << endl

const int
    MaxN = 105;

/*
 * Relation Ship Between Two Nodes.
 * 0) No Relation
 * 1) Different
 * 2) Same
 * */
int R[MaxN][MaxN];

/*
 * Value Of A Node
 * 0) No Set Yet
 * 1) Touched
 * 2) No Touched
 * */
int A[MaxN];

int V, E;

bool setNode(int node, int value)
{
    A[ node ] = value;

    queue<int> Q;
    for (Q.push( node ); !Q.empty(); Q.pop())
    {
        node = Q.front();
        for (int i = 0; i < V; i++)
        {
            //If There Is Not Relation...
            if (R[ node ][ i ] == 0) continue;

            if (R[ node ][ i ] == 1) //Different Relationship
            {
                if (A[ i ] == 0)
                {
                    A[ i ] = ((A[node] == 1)? 2 : 1);
                    Q.push( i );
                }
                else
                {
                    if (A[ node ] == A[ i ]) return false;
                }
            }
            else //Same Relationship
            {
                if (A[ i ] == 0)
                {
                    A[ i ] = A[ node ];
                    Q.push( i );
                }
                else
                {
                    if (A[ i ] != A[ node ]) return false;
                }
            }
        }
    }

    return true;
}

bool tryToSetNode(int node, int value)
{
    int aux[MaxN];
    for (int i = 0; i < V; i++)
        aux[ i ] = A[ i ];
    bool ret = setNode(node, value);
    if (!ret)
    {
        for (int i = 0; i < V; ++i)
            A[ i ] = aux[ i ];
    }
    return ret;
}

int main()
{
    cin.sync_with_stdio(false);

    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v, o;
        cin >> u >> v >> o;
        u--;
        v--;
        R[u][v] = o + 1;
        R[v][u] = o + 1;
    }

    for (int i = 0; i < V; i++)
        if (A[ i ] == 0)
        {
            if (!tryToSetNode(i, 1) && !tryToSetNode(i, 2))
            {
                cout << "Impossible\n";
                return 0;
            }
        }

    int answer = 0;
    for (int i = 0; i < V; i++)
        answer += (A[ i ] == 1);

    cout << answer << endl;
    for (int i = 0; i < V; i++)
        if (A[ i ] == 1) cout << 1+i << " ";

    return 0;
}
