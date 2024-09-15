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
	for (int i = data.size() - 1; i >= 0; --i) {
		numbers[data[i]] += 1;
		if (numbers[data[i]] > 1) {
			data.erase(data.begin() + i);
		}
	}
	std::cout << data.size() << "\n";
	for (int elem : data) {
		std::cout << elem << " ";
	}
}
