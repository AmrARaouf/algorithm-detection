//Language: GNU C++11


#include<bits/stdc++.h>
using namespace std;
#define len(val) static_cast<long long>(val.size())
#define rep(i, n) for(long long i=0; i<(n); i++)
typedef long long ll;
typedef pair<ll, ll> P;

const int MAX_V = 100001;
const int mod = 1e9+21;
int N,M,S,T;
int A[MAX_V], B[MAX_V];
ll C[MAX_V];

template<int MAX_V>
class Dijkstra{
public:
    typedef pair<ll, int> P;
    struct edge{
        int to;
        ll cost;
    };
    const ll INF = 1e18;
    vector<edge> G[MAX_V];
    ll d[MAX_V];
    int V;

    Dijkstra(int v): V(v){}
    Dijkstra(){} //ちゃんとV設定してね

    void add_edge(int from, int to, ll cost){
        G[from].push_back(edge{to, cost});
    }

    void exec(int s){
        priority_queue<P, vector<P>, greater<P> > que;
        fill(d, d+V, INF);
        d[s] = 0;
        que.push(P(0, s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(int i=0; i<(int)G[v].size(); i++){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }
};


template<int MAX_V>
class NewDijkstra{
public:
    typedef pair<ll, int> P;
    struct edge{
        int to;
        ll cost;
    };
    const ll INF = 1e18;
    vector<edge> G[MAX_V];
    ll d[MAX_V];
    ll x[MAX_V];
    int V;

    NewDijkstra(int v): V(v){}
    NewDijkstra(){} //ちゃんとV設定してね

    void add_edge(int from, int to, ll cost){
        G[from].push_back(edge{to, cost});
    }

    void exec(int s){
        priority_queue<P, vector<P>, greater<P> > que;
        fill(d, d+V, INF);
        memset(x, 0, sizeof(x));
        d[s] = 0;
        x[s] = 1;
        que.push(P(0, s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(int i=0; i<(int)G[v].size(); i++){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
                x[e.to] = (x[e.to] + x[v])%mod;
            }
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> S >> T;
    S--; T--;
    Dijkstra<MAX_V> GD(N);
    Dijkstra<MAX_V> rGD(N);
    for(int i=0; i<M; i++){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--;
        GD.add_edge(A[i], B[i], C[i]);
        rGD.add_edge(B[i], A[i], C[i]);
    }
    GD.exec(S);
    rGD.exec(T);
    ll shortCost = GD.d[T];
    vector<int> shortRoad;
    NewDijkstra<MAX_V> newGD(N);
    NewDijkstra<MAX_V> newrGD(N);
    for(int i=0; i<M; i++){
        int a = A[i], b = B[i];
        ll c = C[i];
        if(GD.d[a]+c+rGD.d[b] == shortCost){
            newGD.add_edge(a, b, c);
            newrGD.add_edge(b, a, c);
        }
    }
    newGD.exec(S);
    newrGD.exec(T);
    ll maxComb = newGD.x[T];
    for(int i=0; i<M; i++){
        int a = A[i], b = B[i];
        ll c = C[i];
        //cout << GD.d[a] << " " << c << " " << rGD.d[b] << " " << newGD.x[a] << " " << newrGD.x[b] << endl;
        if(GD.d[a]+c+rGD.d[b] == shortCost){
            if(newGD.x[a] * newrGD.x[b] %mod == maxComb){
                cout << "YES" << endl;
            }else if(c != 1){
                cout << "CAN 1" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
            ll tmp = shortCost-1-GD.d[a]-rGD.d[b];
            if(tmp < 1) cout << "NO" << endl;
            else cout << "CAN " << c-tmp << endl;
        }
    }
}
