// 1973D 1D Ластик
#include <iostream>
#include <string>

int main() {
	int t = 0; std::cin >> t;
	while (t--) {
		int n = 0, k = 0; std::cin >> n >> k;
		std::string s = ""; std::cin >> s;
		int i = 0;
		int cnt = 0;
		while (i < n) {
			if (s[i] == 'B') {
				cnt += 1;
				i += k;
			} else {
				i += 1;
			}
		}
		std::cout << cnt << '\n';
	}
}
