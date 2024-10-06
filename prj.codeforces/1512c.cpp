// 1512c A-B палиндром
#include <iostream>
#include <string>

int main() {
	int t = 0; std::cin >> t;
	while (t--) {
		int a = 0, b = 0; std::cin >> a >> b;
		int n = a + b;
		std::string s = ""; std::cin >> s;
		for (int i = 0; i < n; ++i) {
			a -= (s[i] == '0');
			b -= (s[i] == '1');
		}
		for (int i = 0; i < n / 2; ++i) {
			if ((s[i] == '?' && s[n-i-1] != '?') || (s[i] != '?' && s[n-i-1] == '?')) {
				if (s[i] == '?') {
					if (s[n-i-1] == '0') {
						s[i] = '0';
						a--;
					} else {
						s[i] = '1';
						b--;
					}
				}	else {
					if (s[i] == '0') {
						s[n-i-1] = '0';
						a--;
					} else {
						s[n-i-1] = '1';
						b--;
					}
				}
			}
		}
		for (int i = 0; i < n / 2; ++i) {
			if (s[i] == s[n-i-1] && s[i] == '?') {
				if (a >= b) {
					s[i] = '0';
					s[n-i-1] = '0';
					a -= 2;
				} else {
					s[i] = '1';
					s[n-i-1] = '1';
					b -= 2;
				}
			}
		}
		if (n % 2 != 0 && s[n/2] == '?') {
			if (a > b) {
				s[n / 2] = '0';
				a--;
			} else {
				s[n / 2] = '1';
				b--;
			}
		}
		if (a < 0 || b < 0) {
			std::cout << "-1" << '\n';
		} else {
			bool flag = true;
			for (int i = 0; i < n / 2; ++i) {
				if (s[i] != s[n-i-1]) {
					flag = false;
					break;
				}
			}
			if (flag == false) {
				std::cout << "-1" << '\n';
			} else {
				std::cout << s << '\n';
			}
		}
	}
}
