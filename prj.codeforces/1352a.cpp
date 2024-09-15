// 1352A сумма круглых чисел
#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int t;
	std::vector<int> in;
	std::cin >> t;
	std::vector<std::vector<int>> res(t, std::vector<int>(0));
	for (int i = 0; i < t; ++i) {
		int x;
		std::cin >> x;
		in.push_back(x);
	}
	for (int i = 0; i < t; ++i) {
		int n = in[i];
		int k = 0;
		if (n == 10000) {
			res[i].push_back(1);
			res[i].push_back(10000);
		}
		else {
			std::vector numb = {n % 10, n % 100 / 10, n / 100 % 10, n / 1000};
			for (int j = 0; j < 4; ++j) {
				if (numb[j] != 0) {
					k += 1;
					res[i].push_back(numb[j] * pow(10, j));
				}
			}
			res[i].insert(res[i].begin(), k);
		}
	}
	for (int i = 0; i < t; ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			if (j == 0) {
				std::cout << res[i][j] << "\n";
			} else {
				std::cout << res[i][j] << " ";
			}
		}
		std::cout << "\n";
	}
}
