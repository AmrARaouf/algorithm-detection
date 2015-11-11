//Language: GNU C++11


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <string.h>
#include <functional>
#include <list>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
typedef long long ll;
#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 2000000000
using namespace std;
/*
int bear[200001];
int maxv[200001];
int main()
{
    int n; cin >> n;
    memset(maxv, 0, sizeof(maxv));
    for (int i = 0; i < n; i++)
    {
        int t; scanf("%d", &t);
        bear[i] = t;
        maxv[0] = max(maxv[0], t);
    }
    int idx = 1;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            bear[j] = min(bear[j], bear[j + 1]);
            maxv[idx] = max(maxv[idx], bear[j]);
        }
        idx++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << maxv[i] << " ";
    }

    return 0;
}
*/
/*
//CF_Round_300.Quasi Binary
int cache[1000000];
vector<int> bv;
void makeBinary(vector<int>& v,int n,int sum)
{
    if (n == -1)
    {
        if (sum!=0)
            v.push_back(sum);
        return;
    }
    makeBinary(v, n - 1, sum);
    makeBinary(v, n - 1, sum + (int)pow(10.0, (double)n));
}
//이번 함수는 정수가 주어지면 최소 몇번이 필요한지 계산한다.
int countFunc(int n)
{
    if (n == 0)
        return 0;
    int& ret = cache[n];
    if (ret != -1)
        return ret;
    ret = 987654321;
    for (int i = 0; i < bv.size(); i++)
    {
        if (bv[i] > n)
            break;
        ret = min(ret, countFunc(n - bv[i]) + 1);
    }
    return ret;
}
//reconstruct는 countFunc를 역추적한다.
void reconstruct(vector<int>& v,int n)
{
    if (n == 0)
        return;
    for (int i = 0; i < bv.size(); i++)
    {
        if (countFunc(n) == countFunc(n - bv[i]) + 1)
        {
            v.push_back(bv[i]);
            reconstruct(v, n - bv[i]);
            return;
        }
    }
}
int main()
{
    memset(cache, -1, sizeof(cache));
    makeBinary(bv, 6, 0);
    sort(bv.begin(), bv.end());
    int k; cin >> k;
    if (k == 1000000)
    {
        cout << "1" << endl;
        cout << "1000000";
        return 0;
    }
    cout << countFunc(k) << endl;
    vector<int> lv;
    reconstruct(lv, k);
    for (int i = 0; i < lv.size(); i++)
    {
        cout << lv[i] << " ";
    }
    return 0;
}
*/
/*
//R_303_Div2_C.WoodCutters
int n;
vector<ll> vx;
vector<ll> vh;
int maxTree(ll lb, int idx) //lb means left boundary and idx means index
{
    ll curX = vx[idx];
    ll curH = vh[idx];
    if (idx == n - 1)
        return 1;
    if (lb < curX - curH)
        return maxTree(curX, idx + 1) + 1;
    else if (vx[idx + 1] > curX + curH)
        return maxTree(curX + curH, idx + 1) + 1;
    else
        return maxTree(curX, idx + 1);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1, t2; cin >> t1 >> t2;
        vx.push_back(t1);
        vh.push_back(t2);
    }
    cout << maxTree(-1000000001, 0);
    return 0;
}
*/
//298_Div2_B.Covered Path
/*
int v1, v2, t, d;
int main()
{
    cin >> v1 >> v2;
    cin >> t >> d;
    int sum = v1;
    int cur = v1;
    for (int i = 0; i < t - 1; i++)
    {
        for (int j = d; j >= -d; j--)
        {
            if (cur + j - (t-2 - i) * d <= v2)
            {
                cur = cur + j;
                break;
            }
        }
        sum += cur;
    }
    cout << sum;
    return 0;
}
*/

//277.5_Div2_C.Given Length and Sum of Digits
/*
int main()
{
    int m, s; cin >> m >> s;
    int minv[100];
    int maxv[100];
    if (s == 0)
    {
        if (m == 1)
            cout << "0 0" << endl;
        else
            cout << "-1 -1" << endl;
        return 0;
    }
    int first = -1;
    for (int i = 1; i <= 9; i++)
    {
        if (i + (m - 1) * 9 >= s)
        {
            first = i;
            break;
        }
    }
    if (first == -1)
    {
        cout << "-1 -1"; return 0;
    }
    minv[0] = first; int curSum = first;
    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j + (m - i - 1) * 9 >= s-curSum)
            {
                curSum += j;
                minv[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << minv[i];
    }
    int second = -1;
    for (int i = 9; i >= 1; i--)
    {
        if (i <= s){
            second = i;
            break;
        }
    }
    maxv[0] = second; int curSum2 = second;
    for (int i = 1; i < m; i++)
    {
        for (int j = 9; j >= 0; j--)
        {
            if (j <= s - curSum2)
            {
                curSum2 += j;
                maxv[i] = j;
                break;
            }
        }
    }
    cout << " ";
    for (int i = 0; i < m; i++)
    {
        cout << maxv[i];
    }
    return 0;
}
*/

//272_Div2_B.Dreamoon and Wifi
/*
string s1; string s2;
int l; int a;
int countMethod(int idx,int sum)
{
    if (idx == l)
    {
        if (sum == a)
            return 1;
        else
            return 0;
    }
    if (s2[idx] == '+')
        return countMethod(idx + 1, sum + 1);
    else if (s2[idx] == '-')
        return countMethod(idx + 1, sum - 1);
    else
    {
        return countMethod(idx + 1, sum + 1) + countMethod(idx + 1, sum - 1);
    }
}
int main()
{
    cin >> s1 >> s2;
    l = s1.length();
    a = 0;
    for (int i = 0; i < l; i++)
    {
        if (s1[i] == '+')
            a++;
        else
            a--;
    }
    int ret = countMethod(0, 0);
    int m = 0;
    for (int i = 0; i < l; i++)
    {
        if (s2[i] == '?')
            m++;
    }
    double mm = pow(2.0, (double)m);
    printf("%.14f", (double)ret / mm);
    return 0;
}
*/
/*
int n;
ll cache[1001][1001];
int l[1000];
int pack(int idx, int q)
{
    if (idx == n)
        return 0;
    ll& ret = cache[idx][q];
    if (ret != -1)
        return ret;
    ret = max(pack(idx + 1, q), pack(idx + 1, q + 1) + (q + 1) * l[idx]);
    return ret;
}
int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = n ; j >= 0; j--)
        {
            if (i == n) cache[i][j] = 0;
            else
            {
                cache[i][j] = max(cache[i + 1][j], cache[i + 1][j + 1] + (j + 1)*l[i]);
            }
        }
    }
    cout<<cache[0][0]<<endl;
    return 0;
}
*/
/*
int arrayN[65600];
int arrayK[65600];
int visited[65600];
int count1(int n)
{
    if (n == 0)
        return 0;
    return count1(n / 2) + n % 2;
}
void f
int main()
{
    memset(visited, -1, sizeof(visited));
    int n, k; cin >> n >> k;
    int size = (int)pow(2.0, (double)n);
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        arrayN[i] = count1(i);
        sum += arrayN[i];
    }
    int size2 = (int)pow(2.0, (double)k);
    int gaesu = size / size2;
    int each = sum / size2;
    for (int i = 0; i < size; i++)
    {
        if (visited[i] == -1)
            find1(i);
    }

    return 0;
}
*/

//266_Div2.C Number of Ways
/*
int a[500000];
ll psum[500000];
ll pcount[500000];
int n;
ll pie;

int main()
{
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a[i] = t;
        sum += t;
        psum[i] = sum;
    }
    if (psum[n - 1] % 3)
    {
        cout << "0";
        return 0;
    }
    pie = psum[n - 1] / 3;
    ll csum = 0;
    for (int i = n-1; i >=0; i--)
    {
        csum += a[i];
        if (csum == pie)
            pcount[i] = 1;
    }
    for (int i = n - 2; i >= 0; i--)
        pcount[i] += pcount[i + 1];
    ll count = 0;
    for (int i = 0; i < n-2; i++)
    {
        if (psum[i] == pie)
        {
            count += pcount[i + 2];
        }
    }
    cout << count;
    return 0;
}
*/
//267_Div2_C.George and Job
/*
int n, m, k;
int p[5001];
ll cache[5001][5001];
ll psum[5001];
ll f(int idx, int remained)
{
    if (remained == 0)
        return 0;
    if (idx == n)
        return -987654321;
    ll& ret = cache[idx][remained];
    if (ret != -1)
        return ret;
    if (idx + m - 1 <= n - 1)
    {
        return ret=max(f(idx + m, remained - 1) + psum[idx + m - 1] - psum[idx]+p[idx],
            f(idx + 1, remained));
    }
    else
    {
        return -987654321;
    }
}
int main()
{
    cin >> n >> m >> k;
    memset(cache, -1, sizeof(cache));
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        sum += p[i];
        psum[i] = sum;
    }
    cout << f(0, k);
    return 0;
}
*/

//271_Div2_D.Flowers
/*
int t, k;
int a[100001];
int b[100001];
ll cache[100001]; 
ll psum[100001];
int l;
int r = 1000000007;
int countMethod(int n)
{
    if (n == l)
        return 1;
    ll& ret = cache[n];
    if (ret != -1)
        return ret;
    ret = countMethod(n + 1);
    if (n + k <= l)
        ret += countMethod(n + k);
    return ret=ret % 1000000007;
}
int main()
{
    cin >> t >> k;
    for (int i = 0; i < t; i++)
    {
        cin >> a[i] >> b[i];
    }
    memset(cache, -1, sizeof(cache));
    l = 100000;
    countMethod(0);
    ll sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += cache[i];
        sum %= r;
        psum[i] = sum;
    }
    for (int i = 0; i < t; i++)
    {
        ll t1 = psum[l - a[i]] + r;
        ll t2 = psum[l - b[i]] - cache[l - b[i]];
        ll t3 = (t1 - t2) % r;
        cout << t3<< endl;
    }

    return 0;
}
*/

//256_Div2_C. Painting Fence
/*
int n;
int a[5001];
int f(int l, int r, int offset)
{
    if (l == r) return 1;
    if (l > r) return 0;
    int minh = 1000000001;
    for (int i = l; i <= r; i++)
    {
        minh = min(minh, a[i]-offset);
    }
    vector<int> v;
    v.push_back(l - 1);
    for (int i = l; i <= r; i++)
    {
        if (a[i] - offset - minh == 0)
            v.push_back(i);
    }
    v.push_back(r + 1);
    int sum = 0;
    for (int i = 0; i < v.size()-1; i++)
    {
        sum+=f(v[i] + 1, v[i + 1] - 1, offset + minh);
    }
    return min(sum + minh,r-l+1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << f(1, n, 0);
    return 0;
}
*/
//#FF_Div1_A.DZY Loves Sequences
/*
int n; int a[100001];
int cache[100001][2];
int ls(int idx, int flag)
{
    if (idx == n - 1)
        return 1;
    int& ret = cache[idx][flag];
    if (ret != -1)
        return ret;
    if (flag == 0)
    {
        return ret=ls(idx + 1, 0) + (a[idx] < a[idx + 1]) ? 1 : 0;
    }
    else
    {
        if (a[idx] < a[idx + 1])
            return ret = ls(idx + 1, 1) + 1;
        else
        {

        }
            return ret = ls(idx + 1, 0) + 1;
    }

}
int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << ls(0, 1);
    return 0;
}
*/
/*
int n;
vector<pair<int,int>> xp;
vector<pair<int,int>> xm;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        if (t1 > 0)
        {
            xp.push_back(make_pair(t1,t2));
        }
        else
        {
            xm.push_back(make_pair(t1, t2));
        }
    }
    sort(xp.begin(), xp.end());
    sort(xm.begin(), xm.end());
    int sum = 0;
    if (xp.size() >= xm.size() + 2)
    {
        for (int i = 0; i < xm.size(); i++)
        {
            sum += xm[i].second;
        }
        for (int i = 0; i< xm.size()+1; i++)
        {
            sum += xp[i].second;
        }
    }
    else if (xm.size() >= xp.size() + 2)
    {
        for (int i = 0; i < xp.size(); i++)
        {
            sum += xp[i].second;
        }
        for (int i = 0; i < xp.size() + 1; i++)
        {
            int idx = xm.size() - i - 1;
            sum += xm[idx].second;
        }
    }
    else
    {
        for (int i = 0; i < xm.size(); i++)
        {
            sum += xm[i].second;
        }
        for (int i = 0; i < xp.size(); i++)
        {
            sum += xp[i].second;
        }
    }
    cout << sum;

    return 0;
}
*/
/*
int n; 
int b[100001];
int a[1000001];
int visited[1000001];
int visited2[1000001];
vector<pair<int, int>> vp;
int main()
{
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(visited, -1, sizeof(visited));
    memset(visited2, -1, sizeof(visited2));
    for (int i = 0; i < n; i++)
    {
        int t; cin >> t;
        b[i] = t;
        if (visited[t] == -1)
        {
            visited[t] = i+1;
        }
        a[t]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (visited2[b[i]] == -1)
        {
            visited2[b[i]] = i + 1;
        }
    }
    for (int i = 0; i < 1000001; i++)
    {
        
        vp.push_back(make_pair(a[i], i));
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    vector<int> va;
    int maxv = vp[0].first;
    for (int i = 0; i < vp.size(); i++)
    {
        if (vp[i].first != maxv)
            break;
        va.push_back(vp[i].second);
    }
    vector<pair<int, int>> vpp;
    for (int i = 0; i < va.size(); i++)
    {
        vpp.push_back(make_pair(visited2[va[i]] - visited[va[i]], va[i]));
    }
    sort(vpp.begin(), vpp.end());
    int te = vpp[0].second;
    cout << visited[te] << " " << visited2[te];

    return 0;
}
*/

//312_Div2_C.Amr and Chemistry
//놀랍게도, memset을 n번 반복하게 했던 코드가 시간 초과 문제를 일으켰다. 
//memset구문을 삭제하는 대신 visited의 값을 여러개 가질 수 있게 했더니 해결되었다.
/*
int n;
int cnt[100001];
int steps[100001];
int v[100001];

void bfs(int k)
{
    queue<pair<int,int>> q;
    q.push(make_pair(k,0));
    while (!q.empty())
    {
        int f=q.front().first;
        int level = q.front().second;
        cnt[f] ++;
        steps[f] += level;
        v[f] = 1;
        q.pop();
        int p = f / 2;
        if (p >= 1 && v[p] != 1)
            q.push(make_pair(p, level + 1));
        int c = f * 2;
        if (c <= 100000 && v[c] != 1)
            q.push(make_pair(c, level + 1));
    }
}
int main()
{
    int n; cin >> n;
    memset(steps, 0, sizeof(steps));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        queue<pair<int, int>> q;
        q.push(make_pair(t, 0));
        while (!q.empty())
        {
            int f = q.front().first;
            int level = q.front().second;
            cnt[f] ++;
            steps[f] += level;
            v[f] = i;
            q.pop();
            int p = f / 2;
            if (p >= 1 && v[p] != i)
                q.push(make_pair(p, level + 1));
            int c = f * 2;
            if (c <= 100000 && v[c] != i)
                q.push(make_pair(c, level + 1));
        }
    }
    int ans = INF;
    for (int i = 0; i <= 100000; i++)
    {
        if (cnt[i] == n)
        {
            ans = min(ans, steps[i]);
        }
    }
    cout << ans;
}
*/

//311_Div2_C. Authur and Table
/*
int n, l[100001], d[100001];
vector<pair<int, int>> dl;
int cnt[100001]; int sumd[100001];
int minEnergy(int k, int total)
{
    int toRemove = total - (2 * cnt[k] - 1);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (toRemove > 0)
        {
            if (dl[i].second < k)
            {
                sum += dl[i].first;
                toRemove--;
            }
        }
        else
            break;
    }
    for (int i = k-1; i >= 1; i--)
    {
        if (cnt[i])
            return min(sum, minEnergy(i, total - cnt[k]) + sumd[k]);
    }
    return sum;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t1;
        cin >> t1;
        l[i] = t1; 
        cnt[t1] ++;
    }
    for (int i = 0; i < n; i++)
    {
        int t2; 
        cin >> t2;
        d[i] = t2;
    }
    for (int i = 0; i < n; i++)
    {
        dl.push_back(make_pair(d[i], l[i]));
        sumd[l[i]] += d[i];
    }
    sort(dl.begin(), dl.end());
    for (int i = 100000; i >= 1; i--)
    {

        if (cnt[i])
        {
            cout << minEnergy(i, n);
            break;
        }
    }

    return 0;
}
*/
/*
int n;
ll a[100003];
ll cache[100003];
ll f(int k)
{
    if (k > 100000)
        return 0;
    ll& ret = cache[k];
    if (ret != -1)
        return ret;
    return ret= max(f(k + 1), f(k + 2) + a[k]*k);
}
int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        int t; scanf("%d", &t);
        a[t] ++;
    }

    cout << f(1);
    return 0;
}
*/
//#FF_Div1_A.DZY Loves Sequences
/*
int n; int a[100002];
int cache[100002];
int lis(int k)
{
    int& ret = cache[k];
    if (k == n - 1) return ret=1;
    if (ret != -1) return ret;
    for (int i = k + 1; i < n; i++)
    {
        if (a[i]>a[k])
            ret = max(ret, lis(i) + 1);
    }
    return ret;
}
int main()
{
    cin >> n;
    memset(cache, -1, sizeof(cache));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = -1;
    for (int i = 0; i < n; i++)
        ans=max(ans,lis(i));
    for (int i = 1; i < n; i++)
    {
        if (cache[i] == ans && a[i] >= 2)
        {
            cout << ans + 1;
            return 0;
        }
    }
    cout<<ans;
    return 0;
}
*/
//CF_247_Div2_C.k-Tree
/*
int n, k, d;
ll cache[101];
ll f(int t , int r)
{
    if (t == 0) return 1;
    if (t < 0) return 0;
    ll& ret = cache[t];
    if (ret!= -1)
        return ret;
    ret = 0;
    for (int i = 1; i <= r; i++)
    {
        ret += f(t - i,r);
        ret = ret % 1000000007;
    }
    return ret;
}
int main()
{
    memset(cache, -1, sizeof(cache));
    cin >> n >> k >> d;
    ll total = f(n, k);
    memset(cache, -1, sizeof(cache));
    ll remained = f(n, d-1);
    cout << (total+1000000007 - remained)%1000000007<< endl;
    return 0;
}
*/

//RCC 2014 Warm up_Div2_C.Football
int n, k;
int main()
{
    cin >> n >> k;
    if (n < 2 * k + 1)
    {
        cout << "-1";
        return 0;
    }
    int m = n*k;
    cout << m << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= i+k; j++)
        {
            int loseteam = j;
            if (loseteam>n)
                loseteam = loseteam%n;
            printf("%d %d\n", i, loseteam);
        }
    }
    return 0;
}