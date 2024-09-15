// 2005b1 строгая учительница (простая версия)
#include <iostream>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n, m, q;
		std::cin >> n >> m >> q;
		int b1, b2;
		std::cin >> b1 >> b2;
		int a;
		std::cin >> a;
		if ((b1 < a && a < b2) || (b2 < a && a < b1)) {
			std::cout << abs(b2 - b1) / 2 << "\n";
		} else if (a < b1 && a < b2) {
			if (b1 < b2) {
				std::cout << b1 - 1 << "\n";
			} else {
				std::cout << b2 - 1 << "\n";
			}
		} else {
			if (b1 > b2) {
				std::cout << n - b1 << "\n";
			} else {
				std::cout << n - b2 << "\n";
			}
		}
	}
	return 0;
}
