//Language: GNU C++


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

#define F first
#define S second
#define pb push_back

using namespace std;
const int maxn=1500;

typedef pair <int , int> pii;
typedef pair<pair<int,int>,int> ppi;
int dist[maxn][maxn][2];
ppi par[maxn][maxn][2];
bool marked[maxn][maxn][2];
int n ,m;

vector<int> mat[maxn],ans[2];
vector<ppi> f;
void print(ppi x)
{
    int a , b ,c;
    a=x.F.F;
    b=x.F.S;
    c=x.S;
    if(a==-1 && b==-1)
        return;
    print(par[a][b][c]);

    if(c==0)
    {
        ans[0].pb(a);
        ans[1].pb(b);
    }
}
void bfs()
{
    int k;
    for(int i=0; i<f.size(); i++)
    {
        if(f[i].S==0)
        {
            for(int j=0; j<mat[f[i].F.F].size(); j++)
            {
                k=mat[f[i].F.F][j];
                if(!marked[k][f[i].F.S][1])
                {
                    dist[k][f[i].F.S][1]=dist[f[i].F.F][f[i].F.S][0]+1;
                    par[k][f[i].F.S][1]=ppi(pii(f[i].F.F,f[i].F.S),0);
                    f.pb(ppi(pii(k,f[i].F.S),1));
                    marked[k][f[i].F.S][1]=true;
                }
            }
        }
        else
        {
            for(int j=0; j<mat[f[i].F.S].size(); j++)
            {
                k=mat[f[i].F.S][j];
                if(!marked[f[i].F.F][k][0] && f[i].F.F!=k)
                {
                    dist[f[i].F.F][k][0]=dist[f[i].F.F][f[i].F.S][1];
                    par[f[i].F.F][k][0]=ppi(pii(f[i].F.F,f[i].F.S),1);
                    f.pb(ppi(pii(f[i].F.F,k),0));
                    marked[f[i].F.F][k][0]=true;
                }
            }
        }
    }   
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[x-1].pb(y-1);
        mat[y-1].pb(x-1);
    }
    marked[0][n-1][0]=true;
    par[0][n-1][0]=ppi(pii(-1,-1),0);
    f.pb(ppi(pii(0,n-1),0));
    bfs();
    if(!dist[n-1][0][0])
        cout << -1 <<'\n';
    else
    {
        cout << dist[n-1][0][0]<<'\n';
        print(ppi(pii(n-1,0),0));
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<ans[i].size(); j++)
                cout <<ans[i][j]+1 <<" ";
            cout << endl;   
        }

    }
    return 0;
}
