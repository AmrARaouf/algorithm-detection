//Language: MS C++


#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
using namespace std;

#define C(_a, _v) memset(_a,_v,sizeof(_a))
#define ALL(_obj) (_obj).begin(),(_obj).end()
#define FORB(_i,_a,_b) for((_i)=(_a);(_i)<(_b);++(_i))
#define FOR(_i,_n) FORB(_i,0,_n)
#define FORS(_i,_obj) FOR(_i,(_obj).size())
#define ADJ(_i,_v) for((_i)=kick[_v];(_i)>=0;(_i)=foll[_i])

typedef long long i64;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef complex<double> cd;

template<typename T>inline bool remin(T&c,const T&n){if(c>n){c=n;return 1;}return 0;}
template<typename T>inline bool remax(T&c,const T&n){if(c<n){c=n;return 1;}return 0;}

int _in;int in(){scanf("%d",&_in);return _in;}

// stuff cutline

const int N = 1e5;

int state[N];

struct way {
	way(int v, int f) : used(v), graph(v), forbid(f) { }
	int forbid;
	vector<bool> used;
	vector<vi> graph;
	void dfs(int v) {
		used[v] = true;
		if (state[v] != forbid) {
			vi& cg = graph[v];
			int i;
			FORS (i, cg)
				if (!used[cg[i]])
					dfs(cg[i]);
		}
	}
};

//  0 ������������� �������������, 1 � ������������ ��������, 2 � �������������.

int main() {
	int v, e, i, a, b;
	v = in();
	e = in();
	FOR (i, v) state[i] = in();
	way one(v, -1), two(v, 1);
	FOR (i, e) {
		a = in() - 1;
		b = in() - 1;
		one.graph[a].push_back(b);
		two.graph[b].push_back(a);
	}
	FOR (i, v) {
		if (state[i] == 1) one.dfs(i);
		if (state[i] == 2) two.dfs(i);
	}
	FOR (i, v)
		puts(one.used[i] && two.used[i] ? "1" : "0");
	return 0;
}