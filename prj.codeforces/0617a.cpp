// 617A Слоник
#include <iostream>
 
int main(){
int x = 0;
std::cin >> x;
if (0 == x % 5) {
    std::cout << x / 5;
    }
    else {
    std::cout << x / 5 + 1; 
    }
}
