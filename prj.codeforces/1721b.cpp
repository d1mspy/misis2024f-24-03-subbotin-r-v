// 1721B смертоносный лазер
#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0, m = 0, sx = 0, sy = 0, d = 0;
		std::cin >> n >> m >> sx >> sy >> d;
		if ((sx - d <= 1 && sx + d >= n) || (sy - d <= 1 && sy + d >= m) || (sx + d >= n && sy + d >= m) || (sx - d <= 1 && sy - d <= 1)) {
			std::cout << -1 << "\n";
		} else {
			std::cout << std::abs(m - 1) + std::abs(n - 1) << "\n";
		}
	}
}
