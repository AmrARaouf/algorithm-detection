//Language: GNU C++


#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
int n;
vector <int> v[100000 + 5];
map<int, int> m;
set<int> s;
int k = 0;
int arr[100000 + 5];
void f(int num) {
	set<int>::iterator it;
	it = s.find(num);
	if (it != s.end())
		return;
	s.insert(num);
	m[num] = k;
	arr[k++] = num;
}
int main() {
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		f(a);
		f(b);
		v[m[a]].push_back(m[b]);
		v[m[b]].push_back(m[a]);
		// printf("%d %d\n", m[a], m[b]);
	}
	int start, pre = -1;
	for (int i = 0;; i++)
		if (v[i].size() == 1) {
			start = i;
			break;
		}
	printf("%d ", arr[start]);
	while (true) {
		int next = v[start][0];
		if (next == pre)
			next = v[start][1];
		printf("%d ", arr[next]);
		if (v[next].size() == 1)
			break;
		pre = start;
		start = next;
	}
	// printf("\n");
	// for (int i = 0; i < k; i++)
	// 	printf("%d %d\n", i, arr[i]);
	return 0;
}
 		 	   		 	    	 		   		    		