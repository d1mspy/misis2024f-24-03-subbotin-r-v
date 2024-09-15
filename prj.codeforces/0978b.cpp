// 978B имя файла
#include <iostream>

int main() {
	int n, cnt = 0;
	std::string name;
	std::cin >> n >> name;
	for (int i = 0; i < n - 2; ++i) {
		if (name.substr(i, 3) == "xxx") {
			cnt += 1;
		}
	}
	std::cout << cnt;
}
