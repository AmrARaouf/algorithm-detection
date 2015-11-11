//Language: GNU C++



#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int (i) = 0; (i) < (n); (i) ++)
#define rep1(i, n) for (int (i) = 1; (i) <= (n); (i) ++)
#define For(i, a, b) for (int (i) = (a); (i) <= (b); (i) ++)
#define db(x) cout << #x << " = " << (x) << endl;
#define dba(a, x, y){cout << #a << " :";For(i, (x), (y))cout<<" "<<(a)[(i)];cout<<endl;}
#define dbp(p){cout << #p << " = (" << p.first << " " << p.second << ")"<< endl;}
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define pi 3.1415926535897932384626433832795028
const int INF = INT_MAX;
const ll INFL = LLONG_MAX;

int N, M, size;
vector< pair<int,int> > snake(10);
char table[16][16];
//map<pair<int,int>, int> seen;
map<int, int> seen;
queue<vector< pair<int,int> > > q;



int hash_direction(int x1, int y1)
{
    if (x1 == 1) return 0;
    if (y1 == 1) return 1;
    if (x1 == -1) return 2;
    if (y1 == -1) return 3;
}

int hash_snake(vector< pair<int,int> > sn)
{
    int h = (sn[0].first<<4)+sn[0].second;
    rep1(i, size-1)
    {
        int x = sn[i].first - sn[i-1].first;
        int y = sn[i].second - sn[i-1].second;
        int a=0;
        if (x == -1) a = 1;
        if (y == 1) a = 2;
        if (y == -1) a = 3;
        h = (h << 2) + a;
    }
    return h;
}
int get_direcition_hash(int x, int y)
{
    if (x == 1) return 0;
    if (x == -1) return 1;
    if (y == 1) return 2;
    if (y == -1) return 3;
}
int get_hash(vector< pair<int,int> > snake)
{
    int ret = snake[0].first << 4 + snake[0].second;
    rep1(i, size - 1)
    {
        ret = ret * 230009 + 16*snake[0].first + snake[0].second;
    }
    return ret;
}

int get_hash2(vector< pair<int,int> > snake)
{
    int ret = snake[0].first << 4 + snake[0].second;
    rep1(i, size - 1)
    {
        int dx = snake[i].first - snake[i-1].first;
        int dy = snake[i].second - snake[i-1].second;
        ret = (ret << 2) + get_direcition_hash(dx, dy);
    }
    return ret;
}

int was[16][16];
int dfs(int x, int y)
{
    if (! was[x][y])
    {
        was[x][y]=1;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = { 1, 0, -1, 0};
        rep(j, 4)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (1 <= nx && nx <= N && 1 <= ny && ny <= M && (table[x][y] != '#'))
            {
                dfs(nx, ny);
            }
        }

    }
}

int main()
{
	ios_base::sync_with_stdio(0); cout.precision(15);
    cin>> N >> M;
    pair<int,int> target;
    rep1(i, N)
    {
        string s;
        cin >> s;
        rep1(j, M)
        {
            char ch = s[j-1];
            if ('1' <= ch && ch <= '9')
            {
                snake[ch-'1'] = mp(i,j);
                size = max(size, ch-'0');
                ch = '.';
            }
            table[i][j] = ch;
            if (ch == '@')
                target = mp(i,j);
        }
    }
//    rep(i, 9) dbp(snake[i]);
    dfs(snake[0].first, snake[0].second);
    if (! was[target.first][target.second])
    {
        cout << -1 << endl;
        return 0;
    }
    q.push(snake);
    seen[hash_snake(snake)]=0;
    while (! q.empty())
    {
        snake = q.front();
        int dist = seen[hash_snake(snake)];
        q.pop();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        rep(i, 4)
        {
            int r = snake[0].first + dx[i];
            int c = snake[0].second + dy[i];
            if (1 <= r && r <= N && 1 <= c && c <= M)
            {
                int stepping_on_myself = 0;
                rep(j, size-1) if (snake[j] == mp(r,c)) 
                {
                    //                dbp(snake[j]);
                    stepping_on_myself = 1;
                }
                if (stepping_on_myself) continue;
                if (table[r][c] == '.')
                {
                    vector< pair<int,int> > new_snake;
                    new_snake.pb(mp(r,c));
                    rep(k, size-1) new_snake.pb(snake[k]);
                    int h = hash_snake(new_snake);
                    if (seen.find(h) == seen.end())
                    {
                        seen[h] = dist + 1;
                        q.push(new_snake);
                    }
                }
                else if (table[r][c] == '@')
                {
                    cout << dist  + 1 << endl;
                    //rep(i, size) cout << snake[i].first << " " << snake[i].second << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
