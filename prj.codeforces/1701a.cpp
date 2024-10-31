#include <iostream>

int main() {
    int t = 0;
    std::cin >> t;
    while(t--) {
        int cnt = 0;
        for (int i = 0; i < 4; ++i) {
            int a = 0;
            std::cin >> a;
            cnt += a; 
        }
        if (cnt == 0) {
            std::cout << '0' << '\n';
        } else if (cnt < 4) {
            std::cout << '1' << '\n';
        } else if (cnt == 4) {
            std::cout << '2' << '\n';
        }
    }
}