//Language: GNU C++


//IN THE NAME OF GOD
#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#define PB push_back
#define pii pair<int,int>
#define pdd pair<double,double>
#define double long double
#define For(i,a,b) for(int (i)=int (a);i<int(b);i++)
#define foR(i,b,a) for(int (i)=int (b);i>int (a);i--)
#define S second 
#define F first
using namespace std;
const int maxn=100+20;
vector<pii>ed;
int n,m;
bool q;
vector<int>vec[maxn];
int mark[maxn];
bool f(int a,int b){
    int h=ed[a].F;
    int hh=0;
    while(h!=ed[a].S){
        h++;
        if(h==n)
            h=0;
        if(h==ed[b].F && h!=ed[a].F && h!=ed[a].S)
            hh++;
        if(h==ed[b].S && h!=ed[a].F && h!=ed[a].S)
            hh++;
    }
    if(hh==1 && ed[a].F!=ed[b].F && ed[a].S!=ed[b].S)
        return true;
    return false;
}
void dfs(int a){
    For(i,0,vec[a].size())
        if(mark[vec[a][i]]==mark[a])
            q=true;
        else if(mark[vec[a][i]]==0){
            if(mark[a]==1)
                mark[vec[a][i]]=2;
            else
                mark[vec[a][i]]=1;
            dfs(vec[a][i]);
        }
}           
int main(){
    cin >> n >> m;
    For(i,0,m){
        int x,y;
        cin >> x >> y;
        x--;y--;
        if(x>y)
            swap(x,y);
        ed.PB(pii (x,y));
    }
    For(i,0,ed.size())  
        For(j,0,ed.size())
            if(f(i,j)){
                vec[i].PB(j);
                vec[j].PB(i);
            }
    For(i,0,ed.size())
        if(mark[i]==0){
            mark[i]=1;
            dfs(i);
        }
    //cout << "**** " << f(0,2) << '\n';
    if(q){
        cout << "Impossible" << '\n';
//      system ("pause");
        return 0;
    }
    For(i,0,m)
        if(mark[i]==1)
            cout << "i";
        else
            cout << "o";
    cout << '\n';
//  system ("pause");
    return 0;
}
