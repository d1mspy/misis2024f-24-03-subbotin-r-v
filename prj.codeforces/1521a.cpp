// 1521A Настя и почти хорошие числа
#include <iostream>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		unsigned long long int a = 0, b = 0;
		std::cin >> a >> b;
		if (b == 1) {
			std::cout << "NO" << "\n";
		} else {
			std::cout << "YES" << "\n";
			std::cout << a*b << " " << a << " " << a*b+a << "\n";
		}
	}
}
