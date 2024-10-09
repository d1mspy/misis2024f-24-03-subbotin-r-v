// 1873C стрельба по мишени
#include <iostream>
#include <vector>

int main() {
	int t = 0; std::cin >> t;
	while (t--) {
		std::vector<std::vector<char>> aim (10, std::vector<char>(10));
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j) {
				char a = ' '; std::cin >> a;
				aim[i][j] = a;
			}
		}
		int sum = 0;
		int k = 9;
		while (k > 4) {
			for (int i = 9 - k; i < k+1; ++i) {
				if (i == k || i == 9 - k) {
					for (int j = 9 - k; j < k+1; ++j) {
						if (aim[i][j] == 'X') {
							sum += 10 - k;
						}
						if (i == k && j == k) {
							k--;
						}
					}
				} else {
					if (aim[i][9 - k] == 'X') {
						sum += 10 - k;
					}
					if (aim[i][k] == 'X') {
						sum += 10 - k;	
					}
				}
			}
		}
		std::cout << sum << '\n';
	}
}
