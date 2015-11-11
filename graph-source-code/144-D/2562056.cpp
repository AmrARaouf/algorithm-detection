//Language: GNU C++


#include <iostream>
#include <queue>
#include <cstdio>
#define f cin
#define g cout
#define NM 100010
#define ff first
#define ss second
#define INF 999999999999

using namespace std;

typedef pair<int, long long> PI;


int N,M;
int i,j;
int a,b,c;
int node;
int cost;
int S;
long long D[NM],L;
long long D1,D2;
int ANS,ONR;

struct CMP
{
    bool operator () (const PI& A, const PI& B) const
    {
        return A.ss>B.ss;
    }
};

priority_queue< PI, vector<PI>, CMP> Q;

vector<PI> G[NM];
vector<PI>::iterator it;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif

    f >> N >> M >> S;
    for (i=1; i<=M; i++)
    {
        f >> a >> b >> c;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    f >> L;

    for (i=1; i<=N; i++)
        D[i]=INF;

    D[S]=0;
    Q.push(make_pair(S,0));

    while (!Q.empty())
    {
        node=Q.top().ff;
        cost=Q.top().ss;
        Q.pop();

        if (D[node]!=cost) continue;

        for (it=G[node].begin(); it!=G[node].end(); ++it)
            if (cost+it->ss < D[it->ff])
            {
                D[it->ff]=cost+it->ss;
                Q.push(make_pair(it->ff,cost+it->ss));
            }
    }

    for (i=1; i<=N; i++)
    {
        if (D[i]==L) ANS++;


        if (D[i]>=L) continue;

        for (it=G[i].begin(); it!=G[i].end(); ++it)
          if (D[i]+it->ss>L)
          {
            D1=L-D[i];
            D2=it->ss-D1;
            D1+=D[i];
            D2+=D[it->ff];

            if (D1<=D2) ONR++;
            if (D1==D2 && i<it->ff) ONR--;

          }

    }


    g << ANS + ONR << '\n';

    return 0;
}
