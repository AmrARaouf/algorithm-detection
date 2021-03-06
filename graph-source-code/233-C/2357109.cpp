//Language: GNU C++


#include <iostream>

using namespace std;

int matrix[100][100];

int main(int argc, char **argv)
{
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			matrix[i][j] = 0;
		}
	}
	int k, N = 0;
	cin >> k;

	while (k > 0) {
		int n = 0;
		while (n < N && n * (n + 1) / 2 <= k) {
			matrix[N][n] = 1;
            matrix[n][N] = 1;
			n++;
		}
		N++;
		k -= n * (n - 1) / 2;
	}

	cout << N << endl;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << matrix[i][j];
		}
		cout << endl;
	}

	return 0;
}
