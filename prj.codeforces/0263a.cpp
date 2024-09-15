// 263A красивая матрица
#include <iostream>
#include <cmath>

int main() {
	int res;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			int x;
			std::cin >> x;
			if (x == 1) {
				res = abs(i - 2) + abs(j - 2);
			}
		}
	}
	std::cout << res;
	return 0;
}
