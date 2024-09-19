// 978A удаление дубликатов
#include <iostream>
#include <vector>

int main() {
	int n;
	std::vector<int> data, numbers(10000, 0);
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		data.push_back(a);
	}
	int s = data.size();
	for (int i = data.size() - 1; i >= 0; --i) {
		numbers[data[i]] += 1;
		if (numbers[data[i]] > 1) {
			data[i] = -1;
			s--;
		}
	}
	std::cout << s << "\n";
	for (int i = 0; i < data.size(); ++i) {
		if (data[i] != -1) {
			std::cout << data[i] << " ";
		}
	}
}
