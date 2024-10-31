#include <iostream>
#include <string>

int main() {
	int t = 0;
	std::cin >> t;
	while (t--) {
		std::string s = "";
		std::cin >> s;
		if (s.size() < 2 || (s.size() == 2 && s[0] != s[1])|| s.substr(0, 1) == "ab" 
        || s.substr(0, 1) == "ba" || s.substr(s.size()-2, s.size()-1) == "ab" 
        || s.substr(s.size()-2, s.size()-2) == "ba") {
			std::cout << "NO" << '\n';
		} else {
			bool flag = true;
			for (int i = 0; i < s.size()-2; ++i) {
				if (s.substr(i, i+2) == "aba" || s.substr(i, i+2) == "bab") {
					flag = false;
					std::cout << "NO" << '\n';
					break;
				}
			}
			if (flag == true) {
				std::cout << "YES" << '\n';
			}
		}
	}
}