//Language: GNU C++


//venk13
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <cassert>

using namespace std;

#define sz(a) (int)(a.size())
#define len(a) (int)(a.length())
#define pb push_back

string bits(int a) {
	string ret = "";
	if(a == 0) ret += '0';
	while(a) ret += (a & 1) + '0', a >>= 1;
	return ret;
}

bool graph[91][91];

int main() {
	ios_base::sync_with_stdio(0);
	int k; cin >> k;
	if(k == 1) {
		cout << "2\nNY\nYN\n";
		return 0;
	}
	graph[90][2] = graph[89][2] = graph[2][89] = graph[2][90] = 1;
	for(int i=88; i>=34; i-=2) {
		graph[i][i + 1] = graph[i][i + 2] = graph[i + 1][i] = graph[i + 2][i] = 1;
		graph[i - 1][i + 1] = graph[i - 1][i + 2] = graph[i + 1][i - 1] = graph[i + 2][i - 1] = 1;
	}
	graph[1][3] = graph[3][1] = 1;
	for(int i=4; i<=32; i++)
		graph[i][i - 1] = graph[i - 1][i] = 1;
	string bin = bits(k);
	int two = 1;
	vector <int> pws;
	for(int i=0; i<len(bin); i++, two<<=1)
		if(bin[i] == '1') pws.pb(two);
	int incr = rint(log2(pws[sz(pws) - 1]));
	int connect = 90 - 2 * (incr - 1), our = 1;
	//printf("incr = %d, connect = %d, our = %d\n", incr, connect, our);
	graph[our][connect] = graph[our][connect - 1] = graph[connect][our] = graph[connect - 1][our] = 1;
	for(int i=sz(pws)-2; i>=0; i--) {
		incr = rint(log2(pws[i + 1] / pws[i]));
		connect += 2 * incr;
		if(our == 1) our++;
		our += incr;
		//printf("incr = %d, connect = %d, our = %d\n", incr, connect, our);
		if(connect > 90) {
			connect = 2;
			graph[our][connect] = graph[connect][our] = 1;
		}
		else {
			graph[our][connect] = graph[connect][our] = graph[our][connect - 1] = graph[connect - 1][our] = 1;
		}
	}
	cout << 90 << '\n';
	for(int i=1; i<=90; i++) {
		for(int j=1; j<=90; j++)
			cout << (graph[i][j] ? 'Y' : 'N');
		cout << '\n';
	}
	return 0;
}