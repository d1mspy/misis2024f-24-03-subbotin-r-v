// 339B Ксюша и кольцевая дорога
#include <iostream>
#include <vector>

int main() {
	int n = 0, m = 0; std::cin >> n >> m;
	std::vector<int> business(0, m);
	for (int i = 0; i < m; ++i) {
		int a = 0; std::cin >> a;
		business.push_back(a-1);
	}
	unsigned long long int sum = business[0];
	for (int i = 1; i < m; ++i) {
		if (business[i] >= business[i-1]) {
			sum += business[i] - business[i-1];
		} else {
			sum += n - business[i-1] + business[i];
		}
	}
	std::cout << sum << '\n';
}
