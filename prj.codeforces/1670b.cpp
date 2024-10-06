// 1670B общажные войны
#include <iostream>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	int t = 0; std::cin >> t;
	while (t--) {
		int n = 0; std::cin >> n;
		std::string s = ""; std::cin >> s;
		int k = 0; std::cin >> k;
		std::string unic = "";
		for (int i = 0; i < k; ++i) {
			char c = ' '; std::cin >> c;
			unic += c;
		}
		std::string b = "";
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			int cnt = 1;
			flag = false;
			for (int j = 0; j < k; ++j) {
				if (s[i] == unic[j]) {
					flag = true;
					break;
					}
				}
			if (flag == true) {
				b += '1';
			} else {
				b += '0';
			}
		}
		int mx = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i] == '1' || i == 0) {
				for (int j = i+1; j < n; ++j) {
					if (b[j] == '1') {
						if (j - i > mx) {
							mx = j - i;
						}
						break;
					}
				}
			}
		}
		std::cout << mx << '\n';
	}
}
