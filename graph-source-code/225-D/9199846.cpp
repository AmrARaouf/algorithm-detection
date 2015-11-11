//Language: GNU C++


#include <bits/stdc++.h>
using namespace std;
#define REP(a, b, c) for(int a = b; a < c; a++)
#define asd(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define asdf(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
typedef pair<int,int> ii;
typedef long long LL;

string g[16];
int n, m, dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

int encode(vector<ii>& a){
    int x = a[0].first, y = a[0].second;
    int mask = 0, here;
    
    mask = x + (y << 4);

    REP(i, 1, a.size()){
        if(a[i].first == x){
            if(a[i].second == y + 1) here = 0;
            else here = 2;
        }
        else{
            if(a[i].first == x + 1) here = 3;
            else here = 1;
        }
        x = a[i].first, y = a[i].second;
        mask |= (here  << (6 + 2*i));
    }
    return mask;
}

bool valid(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < m;
}

void print(vector<ii> b){
    vector<string> G(n, string(m, '.'));
    REP(i, 0, b.size()){
        int x = b[i].first, y = b[i].second;
//        asdf(x, y);
        G[x][y] = '1' + i;
    }
    REP(i, 0, n) cout << G[i] << endl;
    cout << endl;
}

int main(){

    cin >> n >> m;
    REP(i, 0, n) cin >> g[i];
    vector<ii> a;
    REP(i, 0, n) REP(j, 0, m) {
        if(isdigit(g[i][j])) {
            if(a.size() < g[i][j] - '0') a.resize(g[i][j] - '0');
            a[g[i][j] - '1'] = ii(i, j);
        }
    }
    //print(a);


    map<int, int> m; queue<int> q;

    int mask = encode(a);
    m[mask] = 0; q.push(mask);

    while( !q.empty() ){
        mask = q.front(); q.pop();
        int x = mask & 15, y = (mask >> 4) & 15, dist = m[mask];
        vector<ii> b, c;
        b.push_back(ii(x, y)); mask = mask >> 8;
        
        if(g[x][y] == '@'){
            cout << dist << endl;
            exit(0);
        }

        REP(i, 0, a.size() - 1){
            int here = mask & 3;
            mask = mask >> 2;
            int xx = x + dx[here], yy = y + dy[here];
            b.push_back(ii(xx, yy));
            x = xx, y = yy;
        }
  //      print(b);

        REP(i, 0, 4){
            c.resize(b.size());
            int xx = b[0].first + dx[i], yy = b[0].second + dy[i];
            if(valid(xx, yy) and g[xx][yy] != '#'){
                c[0] = ii(xx, yy);
                REP(i, 1, b.size()) {
                    c[i] = b[i-1];
                    if(c[i] == ii(xx, yy)) xx = -1;
                }
            } else continue;
            if(xx == -1) continue;
//            print(c);
            mask = encode(c);
            if(m.count(mask) == 0) m[mask] = dist + 1, q.push(mask);
        }
    }

    cout << -1 << endl;

    return 0;
}
