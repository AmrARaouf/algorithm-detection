//Language: GNU C++


#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include <map>


using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

const   int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int     n, m, cnt, des;
char mt[20][20];


set<lld> v;
map<pii, int> dr;


struct  Node{
    int t[9],h,dis;
    lld  hash(){
        lld  ret = 0;;
        int x = (t[h]>>4), y = (t[h]&15);
        ret = t[h];
        for (int i = 0, j = (h+1)%cnt; i< cnt; i++) {
            int xx = (t[j]>>4), yy = (t[j]&15);
            ret = ((ret<<2)|dr[pii(xx-x, yy-y)]);
            x = xx, y = yy;
            j++;
            if ( j == cnt ) j = 0;
        }
        return ret;
    }
};

queue<Node> q;

bool    in_R(int x, int y ) {
    return x >= 0 && x < n && y >=0 && y < m ;
}
bool check(Node& x, int xx, int yy){
     int nu = ((xx<<4)|yy);
     int tail = (x.h-1+cnt)%cnt;
     for (int i = 1, j = (x.h+1)%cnt; i < cnt; i++, j = (j+1)%cnt){
         if (x.t[j] == nu && j != tail)return false;
     }
     return true;
}


int work(){
     Node s;
     cnt = 0;
     for (int i = 0; i < n; i++){
         for (int j = 0; j < m; j++){
             if (mt[i][j] == '@')des = ((i<<4)|j );
             else if (mt[i][j] > '0' && mt[i][j] <= '9'){
                  cnt = max(cnt, int(mt[i][j] - '0'));
                  s.t[int(mt[i][j] - '1')] = ((i<<4)|j );
                  mt[i][j] = '.';
             }
         }
     }
     s.h = s.dis = 0;
     q.push(s);
     v.insert(s.hash());
     while (!q.empty()){
          Node x = q.front(); q.pop();
          for (int i = 0, j = x.h; i < cnt; i++, j = (j+1)%cnt){
              mt[x.t[j]>>4][x.t[j]&15] = char(i+'1');
          }
       /*   for (int i = 0; i<n; i++){
              for (int j = 0; j<m; j++){
                  printf("%c" , mt[i][j]);
              }
               puts("");
          }*/ 
           for (int i = 0; i < 4; i++){
               Node y = x;
               int xx = (y.t[y.h] >>4) + dir[i][0], yy = (y.t[y.h] &15)+dir[i][1];
               if (!in_R(xx, yy) || mt[xx][yy] == '#' || !check(x, xx, yy)){
                     continue;
               }

               y.h = (y.h-1+cnt)%cnt;
               y.t[y.h] = ((xx<<4)|yy);
               y.dis = x.dis + 1;
               
               if (y.t[y.h] == des){ 
                            return y.dis;
               }
               int num = y.hash();
               if (v.count(num))continue;
               v.insert(num);
               q.push(y);
           }
           for (int i = 0, j = x.h; i < cnt; i++, j = (j+1)%cnt){
              mt[x.t[j]>>4][x.t[j]&15] = '.';
          }
     }
     return -1; 
     
}





void init(){
     dr[pii(0, -1)] = 0;
     dr[pii(-1, 0)] = 1;
     dr[pii(0, 1)] = 2;
     dr[pii(1, 0)] = 3;
     scanf("%d%d", &n, &m );
     for (int i = 0; i<n; i++){
          scanf("%s", mt[i] );
     }
}
int  main(){
  // freopen("in.txt", "r", stdin);
 //   freopen("out.txt", "w", stdout);

    init();
    printf("%d\n" , work() );
   return 0;
}
