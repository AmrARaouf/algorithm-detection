//Language: MS C++


#include <iostream>

int main() {
	int n, k;

	std::cin >> n >> k;

	if (n < (2 * k + 1)) {
		std::cout << -1;
		return 0;
	}

	std::cout << n * k << "\n";

	for (int i = 1; i <= n; i++) {
		int num = 1;
		for (int j = 1; j <= k; j++) {
			if ((i + j) > n) {
				std::cout << i << " " << num;
				num++;
			}
			else {
				std::cout << i << " " << i + j;
			}
			if ((i != n) || (j != k))
				std::cout << "\n";
		}
	}

	return 0;
}