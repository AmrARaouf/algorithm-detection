//Language: MS C++


#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdio>

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;


#define mp make_pair
#define pb push_back

#define DEBUG(x) cout << #x << ": " << (x) << endl;

char A[12][12];
char B[12][12];
    int n, t;
bool _dp[70][12][12][12][12];
bool dp[12][12][12][12];

int tim[12][12];

void setdp(int tt, int x, int y, int x0, int y0) {
    if (t >= 70) return;
    if (x < 0 || x >= n || y < 0 || y >= n)
        return;
    if (A[x][y] < '0' || A[x][y] > '9')
        return;
    if (tt > t+1)
        return;
    if (_dp[tt][x][y][x0][y0])
        return;
    if (tt > tim[x][y] && tim[x][y] != 0)
        return;
    if (tt == tim[x][y] && tim[x][y] != 0 && (B[x][y] > '9' || B[x][y] <= '0'))
        return;
    _dp[tt][x][y][x0][y0] = true;

	if (tt < tim[x][y])
	{
    setdp(tt+1, x, y, x0, y0);
    setdp(tt+1, x+1, y, x0, y0);
    setdp(tt+1, x-1, y, x0, y0);
    setdp(tt+1, x, y+1, x0, y0);
    setdp(tt+1, x, y-1, x0, y0);
	}
}

int cur[210];
vector<vector<int> > G;
int F[210][210];
int E[210], H[210];
int C[210][210];

int pN[11][11];

int main() {
#ifndef ONLINE_JUDGE
    freopen( "1.txt", "rt", stdin );
    //freopen("output.txt", "wt", stdout);
#endif


    cin >> n >> t;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    deque<pair<int,int> > q;
	//for (int ___Q = 0;___Q < 13; ___Q++)
	{
		memset(pN, 0, sizeof(pN));
		memset(dp, 0, sizeof(dp));
		memset(_dp, 0, sizeof(_dp));
		G.clear();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tim[i][j] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] == 'Z')
            {
                tim[i][j] = 0;
                q.push_back(mp(i,j));
            }

    int di[] = {-1, 0, 1, 0};
    int dj[] = {0, -1, 0, 1};
   
    while (!q.empty())
    {

        pair<int,int> p = q.front();
        q.pop_front();
        if (tim[p.first][p.second] >= t)
            continue;
        for (int d = 0; d <= 3; d++)
        {
            pair<int,int> np = mp(p.first+di[d], p.second+dj[d]);
            if (np.first >= 0 && np.first < n && np.second >= 0 && np.second < n &&
                A[np.first][np.second] >= '0' && A[np.first][np.second] <= '9' && tim[np.first][np.second]==-1)
            {
                tim[np.first][np.second] = tim[p.first][p.second]+1;
                q.push_back(np);
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (tim[i][j] == -1)
                tim[i][j] = t;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] >= '0' && A[i][j] <= '9')
                setdp(0,i,j,i,j);
	
    vector<int> st;
    G.pb(st);

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            for (int i2 = 0; i2 < n; i2++)
                for (int j2 = 0; j2 < n; j2++)
                    for (int nt = 0; nt <= t; nt++)
                        dp[i1][j1][i2][j2] |= _dp[nt][i1][j1][i2][j2];
	

    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            if (A[i1][j1] > '0' && A[i1][j1] <= '9')
            {
                int k = G.size();
                vector<int> g;
                G.push_back(g);
                E[k] = A[i1][j1] - '0';

                for (int i2 = 0; i2 < n; i2++)
                    for (int j2 = 0; j2 < n; j2++)
                        if (B[i2][j2] > '0' && B[i2][j2] <= '9')
                        if (dp[i2][j2][i1][j1])
                        {
                            int _k;
                           
                            if (pN[i2][j2] == 0)
                            {
                                vector<int> _g;
                                _k = G.size();
                                G.push_back(_g);
                                pN[i2][j2] = _k;
                            }
                            else
                            {
                                _k = pN[i2][j2];
                            }
                           
                            G[k].pb(_k);
                            G[_k].pb(k);
                            C[k][_k] = 10000;
                            C[_k][k] = 0;
                        }
            }

    for (int i2 = 0; i2 < n; i2++)
        for (int j2 = 0; j2 < n; j2++)
            if (B[i2][j2] > '0' && B[i2][j2] <= '9' && pN[i2][j2] > 0)
            {
                int _k;
                _k = pN[i2][j2];
                G[_k].push_back(0);

                C[_k][0] = B[i2][j2] - '0';
				C[0][_k] = 0;
            }

			}
	deque<int> en0;
	en0.clear();
	for (int i = 1; i < G.size(); i++)
		if (E[i] > 0)
			en0.push_back(i);

	int cn = 0;
	while (!en0.empty() && cn <= en0.size())
	{
		int i = en0.front();
		en0.pop_front();
		
		//cur[i] = 0;
		for (; cur[i] < G[i].size(); cur[i]++)
        {
			int j = G[i][cur[i]];
			if (C[i][j] - F[i][j] > 0)
			{
				//minH = min(minH, H[j]);
				if (H[i] == H[j]+1)
				{
					int d = min(C[i][j] - F[i][j], E[i]);
					F[i][j] += d;
					F[j][i] -= d;
					E[i] -= d;
					E[j] += d;
					cn = 0;
					if (E[j] == d && j != 0) 
						en0.push_front(j);
					if (E[i] == 0)
						goto next;
				}
			}
		}

		cur[i] = 0;

		int minH = 10000;
		for (int j=0; j < G[i].size(); j++)
		{
			int _j = G[i][j];
			if (C[i][_j] - F[i][_j] > 0)
				minH = min(minH, H[_j]);
		}

		if (minH != 10000)
			cn = 0,
			H[i] = minH+1;
		else cn++;
		en0.push_back(i);
next:;
	}


exit:
    cout << E[0];
    return ( 0 );
}