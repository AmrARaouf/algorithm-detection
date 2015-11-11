//Language: GNU C++11


#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cmath>
#include <climits>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <functional>
#include <numeric>

using namespace std;
typedef long long ll;

#define debug(x) cout << #x << " = " << (x) << endl;
#define sqr(x) ((x) * (x))
#define sp system("PAUSE");
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

//////////////////////////////////
//    Average execution time    //
// Of a for Loop from 1 to 10^9 //
//  for 1 operation is 1.35 sec //
//////////////////////////////////

//bool vis[100][100];
short dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 },
dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int main()
{
    ios::sync_with_stdio(false);
    std::clock_t CLOCK;
    // Declarations
    set<int> nums;
    queue<pair<int, int>> q;
    int n, m, num, lvl;
    // Input
    cin >> n >> m;
    // Process
    CLOCK = clock();

    q.push(mp(n, 0));
    while (true)
    {
        num = q.front().first;
        lvl = q.front().second;
        q.pop();
        
        if (num == m)
            break;
        if (!nums.count(num))
        {
            if (num < m)
                q.push(mp(num * 2, lvl + 1));
            q.push(mp(num - 1, lvl + 1));
            nums.insert(num);
        }
        
    }

    // Output
    cout << lvl;
    //cout << endl << endl << setiosflags(ios::fixed) << setprecision(10) << double(clock() - CLOCK) / CLOCKS_PER_SEC << endl;
    return 0;
}