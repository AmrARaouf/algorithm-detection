//Language: GNU C++


#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define MAX_N (5 * 1e4)

using namespace std;

int nodes[(int)MAX_N + 1];
int n, r1, r2;

void reverse(int act){
	if(act == r1) return;
	
	reverse(nodes[act]);
	nodes[nodes[act]] = act;
}

int main(){
	#ifdef APAAPA
		freopen("test2.in", "r", stdin);
	#endif
	
	cin >> n >> r1 >> r2;
	
	for(int i = 1; i < r1; i++){
		cin >> nodes[i];
	}
	
	for(int i = r1 + 1; i <= n; i++){
		cin >> nodes[i];
	}
	
	reverse(r2);
	
	for(int i = 1; i < r2; i++){
		cout << nodes[i] << " ";
	}
	
	for(int i = r2 + 1; i < n; i++){
		cout << nodes[i] << " ";
	}
	
	if(r2 < n){
		cout << nodes[n];
	}
	
	return 0;
}
