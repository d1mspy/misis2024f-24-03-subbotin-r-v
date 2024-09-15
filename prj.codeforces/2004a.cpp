// 2004A ближайшая точка
#include <iostream>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;
		if (n > 2) {
			for (int j = 0; j < n; ++j) {
				int a;
				std::cin >> a;
			}
			std::cout << "NO" << "\n";
		} else {
			int a, b;
			std::cin >> a >> b;
			if (abs(a - b) > 1) {
				std::cout << "YES" << "\n";
			} else {
				std::cout << "NO" << "\n";
			}
		}
	}
	return 0;
}
