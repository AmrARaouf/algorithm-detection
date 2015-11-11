//Language: MS C++


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>


using namespace std;

#define mp make_pair
#define fr first
#define sc second
#define pb push_back
#define LL long long
#define forn(a,b) for(LL a = 0; a < b; a++)
#define FOR1(a,b) for(LL a = 1; a <= b;a++)
typedef pair<long long, long long> pii;

#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int p[3001];
int used[3001];

void dfs(int v){
	used[v] = 1;
	if (!used[p[v]])
		dfs(p[v]);
}

int main(){

	//file;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i];
	}

	int m;
	cin >> m;

	int c = 0;

	for (int i = 1; i <= n; i++){
		if (!used[i])
			dfs(i), c++;
	}


	int k = (n - m - c);
	cout << abs(k) << endl;

	if (k == 0)
		return 0;

	for (int i = 1; i <= n; i++)
		used[i] = 0;

	while (k > 0){
		for (int i = 1; i <= n; i++){
			if (i != p[i]){
				int  q = p[i];
				int  t = p[i];
				while (q != i){
					t = min(t, q);
					q = p[q];
				}
				cout << i << ' ' << t << ' ';
				k--;
				swap(p[i], p[t]);
				break;
			}
		}

	}


	if(k < 0){
		dfs(1);
		k = abs(k);
		for(int i = 2; i <= n && k > 0; i++){
			if(!used[i]){
				cout << 1 << ' ' << i << ' ';
				dfs(i);
				k--;
			}
		}
	}
	//system("pause");
}