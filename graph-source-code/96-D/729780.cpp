//Language: GNU C++


#include <set>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int64; //NOTES:int64
typedef unsigned long long uint64; //NOTES:uint64
const double pi = acos(-1.0); //NOTES:pi
const double eps = 1e-11; //NOTES:eps
const int MAXI = 1111111111;

#define FORN(i,a,b)     for (int i=(a),_b=(b); i<_b; i++)
#define RFORN(i,b,a)    for (int i=(b)-1,_a=(a); i>=_a; i--)
#define RESET(a,b)      memset((a),(b),sizeof(a))

#define SC(x)           scanf("%d",&x)
#define SC2(x,y)        scanf("%d%d",&x,&y)
#define PR(x)           printf("%d ",x)
#define PR2(x,y)        printf("%d %d ",x,y)
#define PRS(x)          printf("%s",x)
#define END             printf("\n")
#define EXIT(x)         {PRS(x);return 0;}
#define DBG(x)          {cerr << "--> " << #x << " = " << x << endl;}

#define fi              first
#define se              second
#define PB              push_back
#define ALL(x)          (x).begin(),(x).end()
#define MP(X,Y)         make_pair(X,Y)//NOTES:MP(
#define TR(c, i)        for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x)   ((c).find(x) != (c).end())

int compare (const void *a, const void *b){
    return (*(int*)a-*(int*)b);
}

template<class T> inline void DebM(T A[], T ii, T jj){//Debug sequence
    END;PRS("----------------DEBUG----------------");END;
    FORN (i,ii,jj) cout<<A[i]<<" ";
    END;PRS("-------------------------------------");END;
}
//Template code by ACRush
template<class T> inline bool isPrimeNumber(T n)//NOTES:isPrimeNumber(
{
    if (n <= 1)return false;
    for (T i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

template<class T> inline void checkmin(T &a, T b) {
    if (b < a) a = b;
}//NOTES:checkmin(

template<class T> inline void checkmax(T &a, T b) {
    if (b > a) a = b;
}//NOTES:checkmax(

template<class T> inline T sqr(T x) {
    return x*x;
}//NOTES:sqr

template<class T> inline T lowbit(T n) {
    return (n^(n - 1))&n;
}//NOTES:lowbit(

template<class T> inline int countbit(T n) {
    return (n == 0) ? 0 : (1 + countbit(n & (n - 1)));
}//NOTES:countbit(
//Numberic Functions

template<class T> inline T gcd(T a, T b)//NOTES:gcd(
{
    if (a < 0)return gcd(-a, b);
    if (b < 0)return gcd(a, -b);
    return (b == 0) ? a : gcd(b, a % b);
}

template<class T> inline T lcm(T a, T b)//NOTES:lcm(
{
    if (a < 0)return lcm(-a, b);
    if (b < 0)return lcm(a, -b);
    return a * (b / gcd(a, b));
}

template<class T> inline T euclide(T a, T b, T &x, T &y)//NOTES:euclide(
{
    if (a < 0) {
        T d = euclide(-a, b, x, y);
        x = -x;
        return d;
    }
    if (b < 0) {
        T d = euclide(a, -b, x, y);
        y = -y;
        return d;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        T d = euclide(b, a % b, x, y);
        T t = x;
        x = y;
        y = t - (a / b) * y;
        return d;
    }
}

template<class T> inline vector<pair<T, int> > factorize(T n)//NOTES:factorize(
{
    vector<pair<T, int> > R;
    for (T i = 2; n > 1;) {
        if (n % i == 0) {
            int C = 0;
            for (; n % i == 0; C++, n /= i);
            R.push_back(make_pair(i, C));
        }
        i++;
        if (i > n / i) i = n;
    }
    if (n > 1) R.push_back(make_pair(n, 1));
    return R;
}

template<class T> inline T eularFunction(T n)//NOTES:eularFunction(
{
    vector<pair<T, int> > R = factorize(n);
    T r = n;
    for (int i = 0; i < R.size(); i++)r = r / R[i].first * (R[i].first - 1);
    return r;
}

//Matrix Operations
const int MaxMatrixSize = 40; //NOTES:MaxMatrixSize

template<class T> inline void showMatrix(int n, T A[MaxMatrixSize][MaxMatrixSize])//NOTES:showMatrix(
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cout << A[i][j];
        cout << endl;
    }
}

template<class T> inline T checkMod(T n, T m) {
    return (n % m + m) % m;
}//NOTES:checkMod(

template<class T> inline void identityMatrix(int n, T A[MaxMatrixSize][MaxMatrixSize])//NOTES:identityMatrix(
{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) A[i][j] = (i == j) ? 1 : 0;
}

template<class T> inline void addMatrix(int n, T C[MaxMatrixSize][MaxMatrixSize], T A[MaxMatrixSize][MaxMatrixSize], T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addMatrix(
{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = A[i][j] + B[i][j];
}

template<class T> inline void subMatrix(int n, T C[MaxMatrixSize][MaxMatrixSize], T A[MaxMatrixSize][MaxMatrixSize], T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subMatrix(
{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = A[i][j] - B[i][j];
}

template<class T> inline void mulMatrix(int n, T C[MaxMatrixSize][MaxMatrixSize], T _A[MaxMatrixSize][MaxMatrixSize], T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulMatrix(
{
    T A[MaxMatrixSize][MaxMatrixSize], B[MaxMatrixSize][MaxMatrixSize];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) A[i][j] = _A[i][j], B[i][j] = _B[i][j], C[i][j] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) C[i][j] += A[i][k] * B[k][j];
}

template<class T> inline void addModMatrix(int n, T m, T C[MaxMatrixSize][MaxMatrixSize], T A[MaxMatrixSize][MaxMatrixSize], T B[MaxMatrixSize][MaxMatrixSize])//NOTES:addModMatrix(
{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = checkMod(A[i][j] + B[i][j], m);
}

template<class T> inline void subModMatrix(int n, T m, T C[MaxMatrixSize][MaxMatrixSize], T A[MaxMatrixSize][MaxMatrixSize], T B[MaxMatrixSize][MaxMatrixSize])//NOTES:subModMatrix(
{
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = checkMod(A[i][j] - B[i][j], m);
}

template<class T> inline T multiplyMod(T a, T b, T m) {
    return (T) ((((int64) (a)*(int64) (b) % (int64) (m))+(int64) (m)) % (int64) (m));
}//NOTES:multiplyMod(

template<class T> inline void mulModMatrix(int n, T m, T C[MaxMatrixSize][MaxMatrixSize], T _A[MaxMatrixSize][MaxMatrixSize], T _B[MaxMatrixSize][MaxMatrixSize])//NOTES:mulModMatrix(
{
    T A[MaxMatrixSize][MaxMatrixSize], B[MaxMatrixSize][MaxMatrixSize];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) A[i][j] = _A[i][j], B[i][j] = _B[i][j], C[i][j] = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) C[i][j] = (C[i][j] + multiplyMod(A[i][k], B[k][j], m)) % m;
}

template<class T> inline T powerMod(T p, int e, T m)//NOTES:powerMod(
{
    if (e == 0)return 1 % m;
    else if (e % 2 == 0) {
        T t = powerMod(p, e / 2, m);
        return multiplyMod(t, t, m);
    } else return multiplyMod(powerMod(p, e - 1, m), p, m);
}
//Point&Line

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}//NOTES:dist(

double distR(double x1, double y1, double x2, double y2) {
    return sqr(x1 - x2) + sqr(y1 - y2);
}//NOTES:distR(

template<class T> T cross(T x0, T y0, T x1, T y1, T x2, T y2) {
    return (x1 - x0)*(y2 - y0)-(x2 - x0)*(y1 - y0);
}//NOTES:cross(

int crossOper(double x0, double y0, double x1, double y1, double x2, double y2)//NOTES:crossOper(
{
    double t = (x1 - x0)*(y2 - y0)-(x2 - x0)*(y1 - y0);
    if (fabs(t) <= eps) return 0;
    return (t < 0) ? -1 : 1;
}

bool isIntersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)//NOTES:isIntersect(
{
    return crossOper(x1, y1, x2, y2, x3, y3) * crossOper(x1, y1, x2, y2, x4, y4) < 0 && crossOper(x3, y3, x4, y4, x1, y1) * crossOper(x3, y3, x4, y4, x2, y2) < 0;
}

bool isMiddle(double s, double m, double t) {
    return fabs(s - m) <= eps || fabs(t - m) <= eps || (s < m) != (t < m);
}//NOTES:isMiddle(
//Translator

bool isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}//NOTES:isUpperCase(

bool isLowerCase(char c) {
    return c >= 'a' && c <= 'z';
}//NOTES:isLowerCase(

bool isLetter(char c) {
    return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}//NOTES:isLetter(

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}//NOTES:isDigit(

char toLowerCase(char c) {
    return (isUpperCase(c)) ? (c + 32) : c;
}//NOTES:toLowerCase(

char toUpperCase(char c) {
    return (isLowerCase(c)) ? (c - 32) : c;
}//NOTES:toUpperCase(

template<class T> string toString(T n) {
    ostringstream ost;
    ost << n;
    ost.flush();
    return ost.str();
}//NOTES:toString(

int toInt(string s) {
    int r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}//NOTES:toInt(

int64 toInt64(string s) {
    int64 r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}//NOTES:toInt64(

double toDouble(string s) {
    double r = 0;
    istringstream sin(s);
    sin >> r;
    return r;
}//NOTES:toDouble(

template<class T> void stoa(string s, int &n, T A[]) {
    n = 0;
    istringstream sin(s);
    for (T v; sin >> v; A[n++] = v);
}//NOTES:stoa(

template<class T> void atos(int n, T A[], string &s) {
    ostringstream sout;
    for (int i = 0; i < n; i++) {
        if (i > 0)sout << ' ';
        sout << A[i];
    }
    s = sout.str();
}//NOTES:atos(

template<class T> void atov(int n, T A[], vector<T> &vi) {
    vi.clear();
    for (int i = 0; i < n; i++) vi.push_back(A[i]);
}//NOTES:atov(

template<class T> void vtoa(vector<T> vi, int &n, T A[]) {
    n = vi.size();
    for (int i = 0; i < n; i++)A[i] = vi[i];
}//NOTES:vtoa(

template<class T> void stov(string s, vector<T> &vi) {
    vi.clear();
    istringstream sin(s);
    for (T v; sin >> v; vi.push_bakc(v));
}//NOTES:stov(

template<class T> void vtos(vector<T> vi, string &s) {
    ostringstream sout;
    for (int i = 0; i < vi.size(); i++) {
        if (i > 0)sout << ' ';
        sout << vi[i];
    }
    s = sout.str();
}//NOTES:vtos(
//Fraction

template<class T> struct Fraction {
    T a, b;
    Fraction(T a = 0, T b = 1);
    string toString();
}; //NOTES:Fraction

template<class T> Fraction<T>::Fraction(T a, T b) {
    T d = gcd(a, b);
    a /= d;
    b /= d;
    if (b < 0) a = -a, b = -b;
    this->a = a;
    this->b = b;
}

template<class T> string Fraction<T>::toString() {
    ostringstream sout;
    sout << a << "/" << b;
    return sout.str();
}

template<class T> Fraction<T> operator+(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.b + q.a * p.b, p.b * q.b);
}

template<class T> Fraction<T> operator-(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.b - q.a * p.b, p.b * q.b);
}

template<class T> Fraction<T> operator*(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.a, p.b * q.b);
}

template<class T> Fraction<T> operator/(Fraction<T> p, Fraction<T> q) {
    return Fraction<T > (p.a * q.b, p.b * q.a);
}
//Template code by ACRush

/*thuat toan: tu dinh bat dau (x), chinh lai cac dinh thanh duong di ngan nhat, neu tu dinh 
khoang cach tu cac dinh t den dinh x nho hon do dai taxi di duoc thi ta cap nhat t = x cho den
khi gap lai dinh y*/

typedef pair<int64, int> ii;
#define MAXN 1005

priority_queue <ii, vector<ii>, greater<ii> > heap;
queue<int> Q;
int last[MAXN], vertex[2 * MAXN], cost[2 * MAXN], next[2 * MAXN], edge;
int n, m, x, y, u, v, w, z, far[MAXN], money[MAXN], Kcach[MAXN];
bool reach[MAXN], visited[MAXN];

void addEdge(int a, int b, int c){
    vertex[edge] = b;
    cost[edge] = c;
    next[edge] = last[a];
    last[a] = edge;
    edge++;
}

void Input(){
    SC2(n, m);
    SC2(x, y);
    RESET(last, -1);
    edge = 0;
    while (m--){
        SC2(u, v);
        SC(w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    FORN (i, 1, n + 1) SC2(far[i], money[i]);
}

bool Extend(int now, int64 pre_money){
    FORN (i, 1, n + 1) Kcach[i] = far[now] + 1, visited[i] = false;
    Kcach[now] = 0; visited[now] = true; Q.push(now);
    int a, b, c;
    while (!Q.empty()){
        a = Q.front(); Q.pop();
        for (int i = last[a]; i != -1; i = next[i]){
            b = vertex[i];
            if (Kcach[b] > (int64)(Kcach[a] + cost[i])){
                Kcach[b] = (int64)(Kcach[a] + cost[i]);
                if (!visited[b]){
                    visited[b] = true;
                    Q.push(b);
                }
            }
        }
        visited[a] = false;
    }
    if (Kcach[y] <= far[now]){
        printf("%I64d", pre_money);
        return true;
    }
    FORN (i, 1, n + 1)
        if (Kcach[i] <= far[now] && !reach[i]){
            reach[i] = true;
            heap.push(ii(pre_money + money[i], i));
        }
    return false;
}

void Solve(){
    if (x == y){
        PRS("0");
        return;
    }
    RESET(reach, 0);
    reach[x] = true;
    heap.push(ii(money[x], x));
    while (!heap.empty()){
        if (Extend(heap.top().se, heap.top().fi)) return;
        heap.pop();
    }
    PRS("-1");
}

int main(){
    //freopen ("INP.txt", "r", stdin);
    Input();
    Solve();
}