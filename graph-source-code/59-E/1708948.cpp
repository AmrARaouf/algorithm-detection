//Language: GNU C++


#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

#define N 3005
typedef pair<int,int> P2;
typedef pair<P2,int> P3;
set<P3>s;

int n,m,k;
vector<int>g[N],ans;
bool tag;

bool ok[N][N];
int p[N][N];
void print(int y,int v){

    if(v==1)
    {
        cout<<ans.size()<<endl;
        cout<<1;
        for(int i=ans.size()-1;i>=0;i--) cout<<" "<<ans[i];
        cout<<endl;
        return;
    }
    ans.push_back(v);
    print(p[y][v],y);
}
void bfs(){


    ok[0][1]=-1;

    ok[0][1]=true;
    queue<P2>q;
    q.push(P2(0,1));

    while(!q.empty())
    {
        P2 u=q.front();q.pop();

        int x=u.first;
        int y=u.second;

        for(int i=0;i<g[y].size();i++)
        {
            int v=g[y][i];

            if(ok[y][v]||s.find(P3(u,v))!=s.end()) continue;

             ok[y][v]=1;
             p[y][v]=x;

             if(v==n)
             {
                 tag=1;
                 print(y,v);
                 return;
             }
             q.push(P2(y,v));
        }
    }



}
int main()
{
    cin>>n>>m>>k;

    for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
    }

    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        s.insert(P3(P2(a,b),c));
    }

    tag=0;

    bfs();

    if(!tag) cout<<-1<<endl;

}
