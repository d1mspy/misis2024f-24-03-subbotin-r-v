// 2005A простой палиндром
#include <iostream>
#include <vector>

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::string s1(n/5, 'a'), s2(n/5, 'e'), s3(n/5, 'i'), s4(n/5, 'o'), s5(n/5, 'u');
		std::vector<std::string> strs = {s1, s2, s3, s4, s5};
		std::vector<char> letters = {'a', 'e', 'i', 'o', 'u'};
		int ost = n % 5;
		for (int i = 0; i < ost; ++i) {
			strs[i] += letters[i];
		}
		std::cout << strs[0] + strs[1] + strs[2] + strs[3] + strs[4] << "\n";
	}
}
