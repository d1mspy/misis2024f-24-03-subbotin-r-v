// 1330A Dreamoon и сбор мест
#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0, x = 0;
		std::cin >> n >> x;
		std::vector<int> places(1000, 0);
		for (int i = 1; i <= n; ++i) {
			int a = 0;
			std::cin >> a;
			places[a] = 1;
		}
		for (int i = 1; i <= 1000; ++i) {
			if (x != 0) {
				x -= (places[i] == 0);
			}
			if (x == 0 && places[i+1] == 0) {
				std::cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
