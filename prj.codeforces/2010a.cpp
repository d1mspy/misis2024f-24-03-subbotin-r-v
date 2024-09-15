// 2010A - альтерированная сумма чисел
#include <iostream>

int main() {
	int t;
	std::cin >> t;
	for (int i = 0; i < t; ++i){
		int n, sum = 0;
		std::cin >> n;
		for (int j = 0; j < n; ++j) {
			int a;
			std::cin >> a;
			if (j % 2 == 0){
				sum += a;
			} else {
				sum -= a;
			}
		}
		std::cout << sum << "\n";
	}
}
