//Language: MS C++


#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;

int const N = 2e5;
int n, m, dest[N], byEdge[N], edgeId, priority[N], used[N];


struct node
{
    int id, dest, prior;
    node(){};
    node(int id1, int dest1, int priopr1)
    {
        id = id1;
        dest = dest1;
        prior = priopr1;
    };
    bool operator () (node a, node b)
    {
        if(a.dest < b.dest)
            return true;
        if(a.dest == b.dest && a.prior < b.prior)
            return true;
        if(a.dest > b.dest)
            return false;
        if(a.dest == b.dest && a.prior > b.prior)
            return false;
        return a.id < b.id;
    };
};

struct edge
{
    int f, t, c, id;
    edge(){};
    edge(int a, int b, int c1)
    {
        f = a;
        t = b;
        c = c1;
        id = edgeId;
    };
    bool operator () (edge a, edge b)
    {
        if(a.c < b.c)
            return true;
        if(a.c > b.c)
            return false;
        return a.id < b.id;
    };
};

vector<edge> e[N], answer;
edge from[N];
set<node, node> q;
void prepare()
{
    q.insert(node(0, 0, 0));
    for(int i=1;i<N;++i)
        dest[i] = priority[i] = 1e9;
}

void findWay()
{
    int pos = n-1;
    while(pos)
    {
        edge curEdge= from[pos];
        used[curEdge.id] = 1;
        if(curEdge.c == 1)
            answer.push_back(curEdge);
        pos = curEdge.f;
    }
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<e[i].size();++j)
        {
            edge cur = e[i][j];
            if(!used[cur.id] && cur.c == 0)
            {
                cur.c = 0;
                answer.push_back(cur);
                used[cur.id] = 1;
            }
        }
    }
}

int main()
{
#ifdef _DEBUG
    freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
#endif

    scanf("%d %d",&n,&m);   
    for(int i=0;i<m;++i)
    {
        int f, t, c;
        scanf("%d%d%d",&f,&t,&c);
        --f;
        --t;
        c = 1 - c;
        e[f].push_back(edge(f, t, c));
        e[t].push_back(edge(t, f, c));
        ++edgeId;
    }

    prepare();
    
    while(q.size())
    {
        node cur = *q.begin();
        q.erase(cur);
        int id = cur.id;
        int d = cur.dest;
        int pr = cur.prior;
        for(int i=0;i<e[id].size();++i)
        {
            edge curEdge = e[id][i];
            int to = curEdge.t;
            int cost = curEdge.c;
            if(d + 1 < dest[to] || (d + 1 == dest[to] && pr + cost < priority[to]))
            {
                node remNode;
                remNode.dest = dest[to];
                remNode.id = to;
                remNode.prior = priority[to];
                q.erase(remNode);

                remNode.dest = d + 1;
                remNode.prior = pr + cost;
                from[to] = curEdge;
                dest[to] = d + 1;
                priority[to] = pr + cost;


                q.insert(remNode);
            }
        }
    }

    findWay();
    printf("%d\n",answer.size());
    for(int i=0;i<answer.size();++i)
    {
        printf("%d %d %d\n",answer[i].f + 1,answer[i].t + 1,answer[i].c);
    }

    return 0;
}