// 1717B мадока и подпольные соревнования
#include <iostream>
#include <vector>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		int n = 0, k = 0, r = 0, c = 0;
		std::cin >> n >> k >> r >> c;
		r--;
		c--;
		std::vector<std::vector<char>> matrix(n, std::vector<char>(n));
		std::vector<std::vector<int>> v(k, std::vector<int>(k, 0));
		for (int i = 0; i < k; ++i) {
			v[i][i] = int(i != r % k && i != c % k);
		}
		v[r % k][c % k] = 1;
		v[c % k][r % k] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; j++) {
				if (v[i % k][j % k] == 1) {
					matrix[i][j] = 'X';
				} else {
					matrix[i][j] = '.';
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cout << matrix[i][j];
			}
			std::cout << "\n";
		}
	}
}
