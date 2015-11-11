//Language: GNU C++


#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int,int> ii;
int n, m, diff= 0, counter= 0;
vector<ii> a[16005][2];
bool sign[16005][2];
int comp[16005][2], num[16005][2], low[16005][2];
stack<ii> chose;
int pos[16005][2];
//////////////////
vector<int> conn[32005];
vector<ii> supervertex[32005];
int dag[32005], value[32005], arr[32005];
bool sett[32005], into[32005];
bool result[16005][2];
map<int, map<int, map<int, map<int,bool> > > > edge;
map<int, map<int, bool> > taken;
//////////////////

void tarjan(int u, int of){
    int i, to;
    counter++;
    num[u][of]= counter;
    chose.push(ii(u,of));
    low[u][of]= num[u][of];
    to= a[u][of].size();
    for(i=0;i<to;i++){
        if(sign[a[u][of][i].first][a[u][of][i].second]==false){
            if(num[a[u][of][i].first][a[u][of][i].second]!=0){
                low[u][of]= min(low[u][of], num[a[u][of][i].first][a[u][of][i].second]);
            }
            else{
                tarjan(a[u][of][i].first, a[u][of][i].second);
                low[u][of]= min(low[u][of], low[a[u][of][i].first][a[u][of][i].second]);
            }
        }
    }
    if(low[u][of]==num[u][of]){
        diff++;
        while(chose.top().first!=u || chose.top().second!=of){
            sign[chose.top().first][chose.top().second]= true;
            comp[chose.top().first][chose.top().second]= diff;
            supervertex[diff].push_back(ii(chose.top().first, chose.top().second));
            chose.pop();
        }
        sign[chose.top().first][chose.top().second]= true;
        comp[chose.top().first][chose.top().second]= diff;
        supervertex[diff].push_back(ii(chose.top().first, chose.top().second));
        chose.pop();
    }
    return;
}

void topo(int u){
    int i, to;
    into[u]= true;
    to= conn[u].size();
    for(i=0;i<to;i++){
        if(into[conn[u][i]]==false) topo(conn[u][i]);
    }
    dag[counter]= u;
    arr[u]= counter;
    counter--;
    return;
}

void make_edge(int x, int y){
    int of1, of2, notx, noty;
    of1= x/abs(x);
    of2= y/abs(y);
    if(of1==-1){
        of1= 0;
        notx= 1;
    }
    else{
        notx= 0;
    }
    if(of2==-1){
        of2= 0;
        noty= 1;
    }
    else{
        noty= 0;
    }
    if(edge[abs(x)][notx][abs(y)][of2]==false){
        edge[abs(x)][notx][abs(y)][of2]= true;
        a[abs(x)][notx].push_back(ii(abs(y),of2));
    }
    if(edge[abs(y)][noty][abs(x)][of1]==false){
        edge[abs(y)][noty][abs(x)][of1]= true;
        a[abs(y)][noty].push_back(ii(abs(x),of1));
    }
}

bool inter(int i, int j){
    int x1, y1, x2, y2;
    x1= min(pos[i][0],pos[i][1]);
    y1= max(pos[i][0],pos[i][1]);
    x2= min(pos[j][0],pos[j][1]);
    y2= max(pos[j][0],pos[j][1]);
    if((x1<x2 && x2<y1 && y2>y1) || (x1<y2 && y2<y1 && x1>x2)) return true;
    return false;
}

int main(){
    int i, x, y, of1, of2, notx, noty, j, to;
    scanf("%d%d", &m, &n);
    for(i=1;i<=n;i++){
        scanf("%d%d", &pos[i][0], &pos[i][1]);
        for(j=1;j<i;j++){
            if(inter(i,j)){
                make_edge(i,j);
                make_edge(-i,-j);
            }
        }
    }
    for(i=1;i<=n;i++){
        if(num[i][0]==0) tarjan(i,0);
        if(num[i][1]==0) tarjan(i,1);
    }
    //////////
    for(i=1;i<=n;i++){
        if(comp[i][0]==comp[i][1]){
            printf("Impossible\n");
            return 0;
        }
    }
    //
    for(i=1;i<=n;i++){
        to= a[i][0].size();
        for(j=0;j<to;j++){
            x= a[i][0][j].first;
            y= a[i][0][j].second;
            if(comp[i][0]!=comp[x][y]){
                //into[comp[x][y]]= true;
                if(taken[comp[i][0]][comp[x][y]]==false){
                    taken[comp[i][0]][comp[x][y]]= true;
                    conn[comp[i][0]].push_back(comp[x][y]);
                }
            }
        }
        to= a[i][1].size();
        for(j=0;j<to;j++){
            x= a[i][1][j].first;
            y= a[i][1][j].second;
            if(comp[i][1]!=comp[x][y]){
                //into[comp[x][y]]= true;
                if(taken[comp[i][1]][comp[x][y]]==false){
                    taken[comp[i][1]][comp[x][y]]= true;
                    conn[comp[i][1]].push_back(comp[x][y]);
                }
            }
        }
    }
    counter= diff;
    for(i=1;i<=diff;i++){
        if(into[i]==false) topo(i);
    }
    for(i=diff;i>=1;i--){
        if(sett[arr[i]]) continue;
        sett[arr[i]]= true;
        value[arr[i]]= 1;
        to= supervertex[arr[i]].size();
        for(j=0;j<to;j++){
            result[supervertex[arr[i]][j].first][supervertex[arr[i]][j].second]= true;
            sett[comp[supervertex[arr[i]][j].first][1-supervertex[arr[i]][j].second]]= true;
        }
    }
    ///////////////////////
    counter= 0;
    for(i=1;i<=n;i++){
        if(result[i][1]){
            printf("i");
        }
        else printf("o");
    }
    printf("\n");
    return 0;
}
