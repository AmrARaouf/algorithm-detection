//Language: GNU C++


#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;

typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<string, int> msi;
typedef map<string, string> mss;

#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())

#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define forjn forj(n)
#define forjm forj(m)
#define forkm fork(m)
#define foria(a) fori(sz(a))
#define foriv foria(v)
#define foris fori(len(s))
#define forja(a) forj(sz(a))
#define forjv forj(v)
#define forjs forj(len(s))
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

#define read cin>>
#define write cout<<
#define writeln write endl

#define readt int aaa; read aaa;
#define gett (bbb+1)
#define fort forr(bbb,aaa)

#define issa(a,s) istringstream a(s);
#define iss(s) issa(ss,s);

ld dis(ld x, ld y) {return sqrt(x*x+y*y);}
const ld PI = acos(ld(0.0))*2;
const int INF = 1<<30;

bool is_palindrome(const string &s, int start, int end) {
  int siz = end - start + 1;
  if (siz % 2 == 0) {
    int middle = start + siz/2;
    int i;
    for (i = 0; middle - 1 - i >= 0 && middle+i <= end && s[middle-1-i] == s[middle+i]; i++);
    if (middle - i - 1 < 0 || middle+i > end)
      return true;
  } else {
    int middle = start + siz/2;
    int i;
    for (i = 1; middle - i >= 0 && middle+i <= end && s[middle-i]==s[middle+i]; i++);
    if (middle - i < 0 || middle+i > end)
      return true;
  }
  return false;
}
//Polya-Burnside theory : (n^6+3n^4+12n^3+8n^2)/24
int euclidd,euclidx,euclidy;
void extendedeuclid(int a,int b)
{
  if(b==0)
  {
    euclidd=a;
    euclidx=1;
    euclidy=0;
    return ;
  }
  extendedeuclid(b,a%b);
  int d1,x1,y1;
  d1=euclidd;
  x1=euclidx;
  y1=euclidy;
  euclidx=y1;
  euclidy=x1-((a/b)*y1);
}
double dist_2point(double x1,double y1,double x2,double y2)
{
  double d;
  d=sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
  return d;
}
int binary_search(int a[],int n,int l,int u)
{
  int mid;
  if(l>u)
    return 0;
  mid=floor(l+u)/2;
  if(a[mid]==n)
    return mid;
  else if(a[mid]>n)
    return binary_search(a,n,l,mid-1);
  else
    return binary_search(a,n,mid+1,u);
}
long gcd(long a,long b)
{
  while(b>0) {
    a=a%b;
    a=a^b;
    b=b^a;
    a=a^b;
  }
  return a;
}
long lcm(long a,long b)
{
  long x=(a*b)/gcd(a,b);
  return x;
}
long is_prime(long n)
{
  long ii;
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;
  if (n%2 == 0)
    return 0;
  for (ii=3;ii*ii<=n;ii=ii+2)
    if (n%ii == 0)
      return 0;
  return 1;
}
long long bigmod(long long b,long long p,long long m)
{
  if(b==0) return 0;
  long long x,power;
  x=1;
  power=b%m;
  while(p)
  {
    if(p%2==1)
      x=(x*power)%m;
    power=(power*power)%m;
    p=p/2;
  }
  return x;
}
void assert(bool b)
{
  if (!b)
    throw 0;
}
template <int n>
struct nbest
{
  vector<pair<ll, int> > p;
  nbest():p(n+1)
  {
    foria(p) p[i].first = p[i].second = -1;
  }
  void add(ll value, int key)
  {
    p[n] = make_pair(value, key);
    sort(rall(p));
  }
  ll getValue(int pos, int exceptKey = -2)
  {
    if (exceptKey == -1)
      exceptKey = -2;
    if (p[pos].second == exceptKey)
      ++pos;
    return p[pos].first;
  }
  int getKey(int pos, int exceptKey = -2)
  {
    if (exceptKey == -1)
      exceptKey = -2;
    if (p[pos].second == exceptKey)
      ++pos;
    return p[pos].second;
  }
  bool has(int pos, int exceptKey = -2)
  {
    if (exceptKey == -1)
      exceptKey = -2;
    if (p[pos].second == exceptKey)
      ++pos;
    return p[pos].second != -1;
  }
};

template <typename T>
void dumpContents(const vector<T>& v,
                  const string& msg="")
{
  cerr << "### " << msg << " ###\n";
  if (v.empty())
    return;

  for (typename vector<T>::const_iterator it=v.begin();
       it != v.end(); ++it) {
    cerr << *it << " ";
  }
  cerr << endl;
}

void printBit(ull S, int n=64){
  for(int i=n-1; i>=0; i--){
    if(S>>i & 1) cout << 1;
    else cout << 0;
  }
  cout << endl;
}

void subsetCombination(int n, int k){
  ull S = (1ULL << k) - 1ULL;
  ull E = ~((1ULL << n) - 1ULL);
  while(!(S & E)){
    printBit(S, n);
    ull smallest = S & -S;
    ull ripple = S + smallest;
    ull nsmallest = ripple & -ripple;
    S = ripple | (((nsmallest / smallest) >> 1) - 1);
  }
}

void grayCode(int n){
  int N = 1 << n;
  ull G = 0;
  for(int i=0; i<N; i++){
    G = i ^ (i >> 1ULL);
    printBit(G, n);
  }
}

int bitCount(ull n)
{
  int cnt = 0;
  while(n != 0) {
    cnt += 1;
    n &= (n-1); // the lowest 1 is turned to 0.
  }
  return cnt;
}

// ========== end of template ==========

// === global variables

const int WHITE = 0;
const int BLACK = 1;
const int EMPTY = 2;

int n;
vi node_colors;
vll node_values;
typedef std::multimap<ll,int> nodes_t;
nodes_t black_nodes;
nodes_t white_nodes;

int black_remains = 0;
int white_remains = 0;
std::stack<std::string> results;


// === functions

void output();

void initialize()
{
  // count black and white nodes
  for (int i=0; i<n; ++i) {
    if (node_colors[i] == BLACK)
      black_remains += 1;
    else if (node_colors[i] == WHITE)
      white_remains += 1;
  }
}

void solve()
{
  // the smaller group should have a leaf
  int leaf_color = EMPTY;
  if (black_remains < white_remains)
    leaf_color = WHITE;
  else if (white_remains < black_remains)
    leaf_color = BLACK;

  for (int v=0; v<n; ++v) {
    const int color = node_colors[v];
    if (color == EMPTY) continue;
    if (leaf_color != EMPTY && leaf_color != color) continue;
    const ll  value = node_values[v];

    // check finish
    if (value == 0 &&
        (black_remains + white_remains) == 1) {
      output();
      exit(0);
    }

    // try one of the next node candidates
    for (int c=0; c<n; ++c) {
      if (c==v ||
          node_colors[c] == EMPTY ||
          node_colors[c] == color ||
          node_values[c] < value) {
        continue;
      }

      // push the next node
      node_colors[v] = EMPTY;
      node_values[c] -= value;
      if (color == BLACK)
        black_remains -= 1;
      else
        white_remains -= 1;
      ostringstream out;
      out << v+1 << " " << c+1 << " " << value;
      results.push(out.str());
      
      solve();

      // pop the next node
      node_colors[v] = color;
      node_values[c] += value;
      if (color == BLACK)
        black_remains += 1;
      else
        white_remains += 1;
      results.pop();
    }
  }
}

void output()
{
  while (!results.empty()) {
    std::cout << results.top() << "\n";
    results.pop();
  }
}

void select_black()
{
  nodes_t::iterator smallest = black_nodes.begin();
  const ll black_smallest = smallest->first;
  const int black_node    = smallest->second;
  black_nodes.erase(smallest);

  nodes_t::iterator largest = --white_nodes.end();
  const ll value     = largest->first;
  const int node     = largest->second;
//std::cerr << black_node << "[" << black_smallest << "] - " <<
//             node       << "[" << value          << "]\n";
  assert(value >= black_smallest);
  const ll new_value = value - black_smallest;
  white_nodes.erase(largest);
  white_nodes.insert(make_pair(new_value, node));

  ostringstream out;
  out << black_node+1 << " " << node+1 << " " << black_smallest;
  results.push(out.str());
}

void select_white()
{
  nodes_t::iterator smallest = white_nodes.begin();
  const ll white_smallest = smallest->first;
  const int white_node    = smallest->second;
  white_nodes.erase(smallest);

  nodes_t::iterator largest = --black_nodes.end();
  const ll value = largest->first;
  const int node = largest->second;
//std::cerr << white_node << "[" << white_smallest << "] - " <<
//             node       << "[" << value          << "]\n";
  assert(value >= white_smallest);
  const ll new_value = value - white_smallest;
  black_nodes.erase(largest);
  black_nodes.insert(make_pair(new_value,node));

  ostringstream out;
  out << white_node+1 << " " << node+1 << " " << white_smallest;
  results.push(out.str());
}

void solve2()
{
  // check finish
  if ((black_nodes.empty() && white_nodes.size()==1) ||
      (white_nodes.empty() && black_nodes.size()==1)) {
    output();
    return;
  }
     
  // select the smaller group
  if (black_nodes.size() < white_nodes.size())
    select_white();
  else if (white_nodes.size() < black_nodes.size())
    select_black();
  else if (black_nodes.begin()->first < white_nodes.begin()->first)
    select_black();
  else
    select_white();

  solve2();
}


int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  //string line;

  // the first line
  {
    read n;
    node_colors.resize(n);
    node_values.resize(n);
    for (int i=0; i<n; ++i) {
      cin.ignore(); // skip carriage return
      int color;
      ll  value;
      read color;
      read value;
      node_colors[i] = color;
      node_values[i] = value;
      if (color == BLACK)
        black_nodes.insert(make_pair(value, i));
      else
        white_nodes.insert(make_pair(value, i));
    }
  }

  initialize();
  solve2();

  return 0;
}
