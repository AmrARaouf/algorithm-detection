//Language: MS C++


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long n, m;
long a[200001];

void f(long p){
	while (p < m * 2){
		if (a[p * 2] == -1 || a[p * 2] > a[p] + 1){
			a[p * 2] = a[p] + 1;
			p *= 2;
		}
		else break;
	}
}

int main(){
	cin >> n >> m;
	if (n >= m){
		cout << n - m;
		return 0;
	}
	for (int i = 0; i < m * 2; ++i) a[i] = -1;
	a[n] = 0;
//	for (int i = 0; n - i > 0; ++i){
//		a[n - i] = i;
//	}
	long p;
//	for (int i = 1; i < n; i++){
//		p = i;
//		f(p);
//	}
	for (int i = 1; i <= m * 2; ++i){
		if (a[i] == -1) continue;
		p = a[i];
		f(i);
		for (int j = i; j > 0; --j, p++){
			if (a[j] == -1) {
				a[j] = p;
				f(j);
			}
			if (a[j] > p) {
				a[j] = p;
				f(j);
			}
		}
	}
	cout << a[m];
	return 0;
}