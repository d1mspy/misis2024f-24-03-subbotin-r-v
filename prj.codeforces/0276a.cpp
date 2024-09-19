// 276A проблемные обеды
#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	int res = -1000000000;
	int f, t;
	for (int i = 0; i < n; ++i) {
		std::cin >> f >> t;
		int pleasure;
		if (t > k) {
			pleasure = f - t + k;
		} else {
			pleasure = f;
		}
		if (pleasure > res) {
			res = pleasure;
		}
	}
	std::cout << res;
	return 0;
}
