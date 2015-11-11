//Language: MS C++




#include <iostream>

using namespace std;


int main() {
	int n, k;
	cin >> n >> k;
	int min = 0;
	while (k > n) {
		if (k % 2 == 0)  k /= 2;
		else k++;
		min += 1;
	}
	min += n - k;
	cout << min;

}

