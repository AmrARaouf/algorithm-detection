//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define MP(x, y) make_pair(x, y)
#define FOR(i, x, y) for((i) = (x); (i) <= (y); (i)++)

typedef long long llg;

const int N = 8;
const int M = 800;

struct node{
    int x, y;
}stone[N*N];

struct vnode{
    int x, y, step;
    vnode(){}
    vnode(int a, int b, int c){
        x = a, y = b, step = c;
    }
};

int n, dis[N][N][M];

bool check(int tx, int ty, int td){
    for(int i = 0; i < n; i++){
        if(stone[i].x+td==tx && stone[i].y==ty)
            return  false;
        if(stone[i].x+td-1==tx && stone[i].y==ty)
            return  false;
    }
    return  true;
}

bool spfa(){
    queue <vnode> q;
    vnode u, v;
    int tx, ty, td;
    q.push(vnode(7, 0, 0));
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(int px = -1; px <= 1; px++)
            for(int py = -1; py <= 1; py++){
                tx = u.x + px;
                ty = u.y + py;
                td = u.step + 1;
                if(tx<0 || tx>=8)  continue;
                if(ty<0 || ty>=8)  continue;
                if(td >= M)  continue;
                if(check(tx, ty, td) && dis[tx][ty][td]==false){
                    dis[tx][ty][td] = true;
                    if(tx==0 && ty==7)
                        return  true;
                    q.push(vnode(tx, ty, td));
                }
            }
    }
    return  false;
}

int main()
{
    string str;
    //freopen("data.txt", "r", stdin);
    for(int i = n = 0; i < 8; i++){
        cin >> str;
        for(int j = 0; j < 8; j++)
            if(str[j] == 'S'){
                stone[n].x = i;
                stone[n++].y = j;
            }
    }
    memset(dis, false, sizeof(dis));
    dis[7][0][0] = true;
    bool flag = spfa();
    if(flag)  cout << "WIN" << endl;
    else  cout << "LOSE" << endl;
    return  0;
}









