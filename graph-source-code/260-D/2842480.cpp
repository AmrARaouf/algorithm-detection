//Language: GNU C++


#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;

struct node
{
    int sum, num;
    int u,v,w;
    node(int ss=0,int nn=0)
    {
        sum=ss; num=nn;
    }
};
bool operator<(const node& a, const node& b)
{
    return a.sum<b.sum;
}

int N;
int color[100011];
int parent[100011];

int parentof(int x)
{
    if(x==parent[x]) return x;
    return parent[x]=parentof(parent[x]);
}

int addEdge(int u,int v)
{
    int pu=parentof(u), pv=parentof(v);
    if(pu==pv) return 0;
    parent[pv]=pu;
    return 1;
}

int main()
{
    while(cin>>N)
    {

        int num, sum, col;
        int wj, bj;
        priority_queue<node> w,b;

        for(int i=0;i<N;i++)
        {
            num=i+1; cin>>col>>sum;
            color[num]=col;
            if(sum && col) w.push(node(sum,num));
            else b.push(node(sum,num));

            if(col) wj=num; else bj=num;
        }
        for(int i=0;i<=N;i++) parent[i]=i;

        vector<node> edges; node tmp, wn, bn;

        while(!w.empty())
        {
            wn=w.top(); w.pop(); bn=b.top(); b.pop();
            int mn=min(wn.sum,bn.sum);
            wn.sum-=mn; bn.sum-=mn;
            if(wn.sum) w.push(wn);
            if(bn.sum) b.push(bn);
            tmp.u=wn.num; tmp.v=bn.num; tmp.w=mn;
            edges.push_back(tmp);
            addEdge(tmp.u,tmp.v);
        }

        for(int i=0;i<sz(edges);i++)
        {
            cout<<edges[i].u<<' '<<edges[i].v<<' '<<edges[i].w<<endl;
        }


        for(int i=1;i<=N;i++)
        {
            if(color[i]==1 && addEdge(bj,i)) cout<<bj<<' '<<i<<' '<<0<<endl;
            else if(color[i]==0 && addEdge(wj,i)) cout<<wj<<' '<<i<<' '<<0<<endl;
        }
    }

}



/*
7
1 4
1 1
1 1
0 3
0 1
0 1
0 1


*/
