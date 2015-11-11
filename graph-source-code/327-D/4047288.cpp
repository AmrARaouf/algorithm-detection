//Language: GNU C++


// http://codeforces.com/problemset/problem/327/D

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

#define db(x) cout << #x " == " << x << endl
//#define _ << ", " <<
#define Fr(a,b,c) for( int a = b ; a < c ; ++a )
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define y1 Y1
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fLL
#define ULMAX 0xffffffffffffffffULL

#define N 666
#define valid(a,b) (a>=0 && b>=0 && a<n && b<m && ent[a][b]=='.')

int n,m, ind;
char ent[N][N], resp[N*N*10][30];
int inci[4]={-1,0,1,0};
int incj[4]={0,-1,0,1};
pii fila[N*N];

void faz(int a, int b){
    fila[0]=MP(a,b);
    ent[a][b]='#';
    int ini=0, fim=1;
    while(ini<fim){
        pii at = fila[ini++];
        sprintf(resp[ind++],"B %d %d\n",at.F+1,1+at.S);
        Fr(k,0,4){
            int x=at.F+inci[k], y=at.S+incj[k];
            if(valid(x,y)) ent[x][y]='#', fila[fim++]=MP(x,y);
        }
    }
    while(--fim){
        sprintf(resp[ind++],"D %d %d\n",fila[fim].F+1,1+fila[fim].S);
        sprintf(resp[ind++],"R %d %d\n",fila[fim].F+1,1+fila[fim].S);
    }
//  Fr(i,0,n) printf("%s\n",ent[i]);
}

int main() {
//  cin.sync_with_stdio(false);
    scanf("%d%d",&n,&m);
    Fr(i,0,n) scanf("%s",ent[i]);
    ind=0;
    Fr(i,0,n) Fr(j,0,m) if(ent[i][j]=='.') faz(i,j);
    printf("%d\n",ind);
    Fr(i,0,ind) printf("%s",resp[i]);
    return 0;
}
