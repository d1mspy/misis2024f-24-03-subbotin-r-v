// 1404A сбалансированная бинарная строка
#include <iostream>
#include <string>

int main() {
	int t = 0; std::cin >> t;
	while (t--) {
		int n = 0, k = 0; std::cin >> n >> k;
		std::string s = ""; std::cin >> s;
		std::string ks = "";
		for (int i = 0; i < k; ++i) {
			ks += '?';
		}
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			if (s[i] != '?' && ks[i % k] == '?') {
				ks[i % k] = s[i];
			} else if (s[i] != '?' && ks[i % k] != '?' && s[i] != ks[i % k]) {
				flag = false;
				break;
			}
		}
		if (flag == false) {
			std::cout << "NO" << '\n';
		} else {
			int a = k/2, b = k/2;
			for (int i = 0; i < k; ++i) {
				a -= (ks[i] == '0');
				b -= (ks[i] == '1'); 
			}
			for (int i = 0; i < k; ++i) {
				if (ks[i] == '?') {
					if (a > b) {
						ks[i] = '0';
						a--;
					} else {
						ks[i] = '1';
						b--;
					}
				}
			}
			if (a == b && a == 0) {
				for (int i = s.size()-k; i < n; ++i) {
					if (s[i] == '?') {
						s[i] = ks[i % k];
					}
					a += (s[i] == '0');
					b += (s[i] == '1');
				}
				if (a == b) {
					std::cout << "YES" << '\n';
				} else {
					std::cout << "NO" << '\n';
				}
			} else {
				std::cout << "NO" << '\n';
			}
		}
	}
}
