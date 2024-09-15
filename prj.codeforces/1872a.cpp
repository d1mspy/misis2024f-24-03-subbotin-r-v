// 1872A два сосуда
#include <iostream>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		std::cout << int((abs(a - b) * 1.0) / (2 * c)) + bool(int((abs(a - b) * 1.0) / (2 * c)) != (abs(a - b) * 1.0) / (2 * c)) << "\n";
	}
}
