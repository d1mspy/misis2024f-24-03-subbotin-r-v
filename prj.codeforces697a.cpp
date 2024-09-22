// 697A случай с ананасом
#include <iostream>

int main() {
	unsigned long long int t = 0, s = 0, x = 0;
	std::cin >> t >> s >> x;
	if ((x % s == t % s || x % s == (t + 1) % s) && x != t + 1 && x >= t) {
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
}
